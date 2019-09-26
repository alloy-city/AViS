
#include "OpenCVPrivatePCH.h"
#include "OpenCV.h"
#include "WebcamReader.h"

Webcam::Webcam()
{
	UE_LOG(LogTemp, Warning, TEXT("Webcam constructor"));

	// cv::namedWindow("AViS Sending", cv::WINDOW_NORMAL);

	// Initialize OpenCV and webcam properties
	CameraID = 0;
	IsStreamOpen = false;
	VideoSize = FVector2D(0, 0);
	ShouldResize = false;
	ResizeDimensions = FVector2D(320, 240);
	Stream = cv::VideoCapture();
	Frame = cv::Mat();

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

	Stream.open(CameraID);
	if (Stream.isOpened())
	{
		IsStreamOpen = true;
		VideoSize = FVector2D(Frame.cols, Frame.rows);
		Size = cv::Size(ResizeDimensions.X, ResizeDimensions.Y);
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

char* Webcam::GetVideoBuffer()
{
	return VideoBuffer;
}

bool Webcam::GetFrame()
{
	if (Stream.isOpened())
	{
		// UE_LOG(LogTemp, Warning, TEXT("Webcam::GetFrame"));

		Stream >> Frame;

		if (Frame.empty())
		{
			UE_LOG(LogTemp, Warning, TEXT("[Webcam::GetFrame] Frame is empty"));
			return false;
		}

		if (!Frame.isContinuous())
		{
			UE_LOG(LogTemp, Warning, TEXT("[Webcam::GetFrame] Frame is not continous"));
			return false;
		}

		// If DetectFace returns false, return false
		// otherwise crop, compress, write to stackBuffer and return true
		if (DetectFace(Frame, FaceCascade, EyesCascade, 2, false))
		{
			Frame(Face).copyTo(CroppedFrame);

			// TODO: Resize frame to fixed size
			cv::resize(CroppedFrame, ResizedFrame, FaceResolution);

			CompressionParams.push_back(cv::IMWRITE_JPEG_QUALITY);
			CompressionParams.push_back(CompressionQuality);

			cv::imencode(".jpg", ResizedFrame, CompressedFrame, CompressionParams);
			FrameNumberOfBytes = CompressedFrame.size() * sizeof(uchar);

			if (FrameNumberOfBytes > VIDEO_BUFFER_MAX) return false;

			for (int i=0; i<CompressedFrame.size(); i++)
			{
				VideoBuffer[i] = CompressedFrame[i];
			}

			return true;
		}
		else {
			return false;
		}
	}
	else {
		Stream.open(CameraID);
		return false;
	}
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

bool Webcam::DetectFace(
	cv::Mat& img,
	cv::CascadeClassifier& cascade,
	cv::CascadeClassifier& nestedCascade,
	double scale,
	bool tryflip )
{
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
			cv::CASCADE_FIND_BIGGEST_OBJECT,
			// cv::CASCADE_DO_ROUGH_SEARCH,
			// cv::CASCADE_SCALE_IMAGE,
			cv::Size(scale*6, scale*6),
			cv::Size(scale*40, scale*40)
		);
	}

	t = (double)cv::getTickCount() - t;
	// UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::Printf(TEXT("%i faces detected in %f ms"), faces.size(), t * 1000 / cv::getTickFrequency()));
	// UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::Printf(TEXT("%d x %d"), img.rows, img.cols));

	if (!faces.empty())
	{
		if (faces[0].x > 20 && faces[0].y >= 20)
		{
			center.x = cvRound((faces[0].x + faces[0].width*0.5)*scale);
			center.y = cvRound((faces[0].y + faces[0].height*0.5)*scale);
			int side = cvRound((faces[0].width + faces[0].height) * 0.25 * scale * (1 + Margin)) * 2;

			Face = cv::Rect(center.x - side/2, center.y - side/2, side, side);

			// debugging
			cv::rectangle(img, Face, color, 3, 8, 0);
			/*UE_LOG(
				LogTemp,
				Warning,
				TEXT("%s"), 
				*FString::Printf(
					TEXT("Faces: %i | X: %d | Y: %d"),
					faces.size(),
					center.x,
					center.y
				)
			);*/


		}
	}

	// Debugging
	// cv::imshow("AViS Sending", img);
	// cv::waitKey(1);

	return true;
}
