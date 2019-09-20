
#include "OpenCVPrivatePCH.h"
#include "OpenCV.h"
#include "WebcamReader.h"

Webcam::Webcam(TArray<FColor>* fd)
{
	UE_LOG(LogTemp, Warning, TEXT("Webcam constructor"));

	cv::namedWindow("AViS Sending", cv::WINDOW_NORMAL);

	// Initialize OpenCV and webcam properties
	CameraID = 0;
	IsStreamOpen = false;
	VideoSize = FVector2D(0, 0);
	ShouldResize = false;
	ResizeDimensions = FVector2D(320, 240);
	Stream = cv::VideoCapture();
	Frame = cv::Mat();
	FaceData = fd;

	//-- 1. Load the cascades
	FaceCascadeFile = cv::String("C:/AViS/Plugins/OpenCV/Resources/Data/haarcascades/haarcascade_frontalface_default.xml");
	EyesCascadeFile = cv::String("C:/AViS/Plugins/OpenCV/Resources/Data/haarcascades/haarcascade_eye.xml");

	if (!FaceCascade.load(FaceCascadeFile))
	{
		UE_LOG(LogTemp, Warning, TEXT("[Webcam::Webcam] Error loading face cascade"));
	};
	if (!EyesCascade.load(EyesCascadeFile))
	{
		UE_LOG(LogTemp, Warning, TEXT("[Webcam::Webcam] Error loading eye cascade"));
	};

	// Open the stream
	Stream.open(CameraID);
	if (Stream.isOpened())
	{
		// Initialize stream
		IsStreamOpen = true;
		// UpdateFrame();
		VideoSize = FVector2D(Frame.cols, Frame.rows);
		Size = cv::Size(ResizeDimensions.X, ResizeDimensions.Y);

		// Initialize data array
		FaceData->Init(FColor(0, 0, 0, 255), VideoSize.X * VideoSize.Y);
	}
}

void Webcam::UpdateFrame()
{
	UE_LOG(LogTemp, Warning, TEXT("Webcam::UpdateFrame"));

	if (Stream.isOpened())
	{
		Stream.read(Frame);
		if (ShouldResize)
		{
			cv::resize(Frame, Frame, Size);
		}
	}
	else {
		IsStreamOpen = false;
	}
}

char* Webcam::GetFrame()
{
	if (Stream.isOpened())
	{
		// UE_LOG(LogTemp, Warning, TEXT("Webcam::GetFrame"));

		Stream >> Frame;

		if (Frame.empty())
		{
			UE_LOG(LogTemp, Warning, TEXT("[Webcam::GetFrame] Frame is empty"));
			return NULL;
		}

		if (!Frame.isContinuous())
		{
			UE_LOG(LogTemp, Warning, TEXT("[Webcam::GetFrame] Frame is not continous"));
			return NULL;
		}

		// cv::imshow("AViS Sending", Frame);

		/* ----------------------WIP-------------------- */
		// cv::Mat clone = Frame.clone();
		// Face = detectAndDraw(Frame, FaceCascade, EyesCascade, 4, false);
		/* --------------------------------------------- */

		Frame(detectAndDraw(Frame, FaceCascade, EyesCascade, 4, false)).copyTo(CroppedFrame); // image will be 100x100
		// cv::Size s = CroppedFrame.size();

		// UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::Printf(TEXT(">> Image size: %d X %d"), s.height, s.width));

		CompressionParams.push_back(cv::IMWRITE_JPEG_QUALITY);
		CompressionParams.push_back(80);

		cv::imencode(".jpg", CroppedFrame, CompressedFrame, CompressionParams);

		/* -- This block proves image is decompressable before it was sent over the network --
		cv::Mat decodedImage = cv::imdecode(CompressedFrame, cv::IMREAD_COLOR);
		if (decodedImage.data == NULL)
		{
			UE_LOG(LogTemp, Warning, TEXT("[Webcam::GetFrame] Error reading JPG image from buffer"));
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("[Webcam::GetFrame] Successfully read JPG image from buffer"));
			cv::imshow("AViS Video Capture Debuggin", decodedImage);
		}
		*/

		FrameNumberOfBytes = CompressedFrame.size() * sizeof(uchar);

		// UE_LOG(LogTemp, Warning, TEXT("%s bytes"), *FString::Printf(TEXT("%d"), FrameNumberOfBytes));

		for (int i=0; i<CompressedFrame.size(); i++)
		{
			stackBuffer[i] = CompressedFrame[i];
		}

		return stackBuffer;
	}

	return 0;
}

int Webcam::GetFrameNumberOfBytes()
{
	return FrameNumberOfBytes;
}

void Webcam::TurnOff()
{
	Stream.release();
	cv::destroyAllWindows();
}

cv::Rect Webcam::detectAndDraw(
	cv::Mat& img,
	cv::CascadeClassifier& cascade,
	cv::CascadeClassifier& nestedCascade,
	double scale,
	bool tryflip )
{
	cv::Rect f(10, 10, 10, 10);
	// UE_LOG(LogTemp, Warning, TEXT("Webcam::detectAndDraw"));

	double t = 0;
	
	const static cv::Scalar colors[] =
	{
		cv::Scalar(255,0,0),
		cv::Scalar(255,128,0),
		cv::Scalar(255,255,0),
		cv::Scalar(0,255,0),
		cv::Scalar(0,128,255),
		cv::Scalar(0,255,255),
		cv::Scalar(0,0,255),
		cv::Scalar(255,0,255)
	};
	cv::Mat gray, smallImg;
	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
	double fx = 1 / scale;
	cv::resize(gray, smallImg, cv::Size(), fx, fx, cv::INTER_LINEAR_EXACT);
	cv::equalizeHist(smallImg, smallImg);

	t = (double)cv::getTickCount();
	if (cascade.empty())
	{
		UE_LOG(LogTemp, Warning, TEXT("[Webcam::detectAndDraw] Cascade is empty"));
	}
	else {
		cascade.detectMultiScale(
			smallImg,
			faces,
			1.1,
			2,
			// 0,
			// cv::CASCADE_FIND_BIGGEST_OBJECT,
			cv::CASCADE_DO_ROUGH_SEARCH,
			// | cv::CASCADE_SCALE_IMAGE,
			cv::Size(25, 25),
			cv::Size(125, 125)
		);
	}

	t = (double)cv::getTickCount() - t;
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::Printf(TEXT("%i faces detected in %f ms"), faces.size(), t * 1000 / cv::getTickFrequency()));

	if (!faces.empty())
	{
		f = cv::Rect(
			cv::Point(cvRound(faces[0].x*scale), cvRound(faces[0].y*scale)),
			cv::Point(cvRound((faces[0].x + faces[0].width - 1)*scale), cvRound((faces[0].y + faces[0].height - 1)*scale))
		);
	}

	return f;
}
