
#include "OpenCVPrivatePCH.h"
#include "OpenCV.h"
#include "WebcamReader.h"

Webcam::Webcam(TArray<FColor>* fd)
{
	UE_LOG(LogTemp, Warning, TEXT("Webcam constructor"));

	cv::namedWindow("AViS Sending", cv::WINDOW_NORMAL);

	// Load Face Detaction Cascades
	// cv::String face_cascade_name = cv::samples::findFile("C:\AViS\Plugins\OpenCV\Resources\Data\haarcascades\haarcascade_frontalface_default.xml");
	// cv::String eyes_cascade_name = cv::samples::findFile("C:\AViS\Plugins\OpenCV\Resources\Data\haarcascades\haarcascade_eye.xml");
	//-- 1. Load the cascades

	// cv::String face_cascade_name("C:/AViS/Plugins/OpenCV/Resources/Data/haarcascades/haarcascade_frontalface_default.xml");
	cv::String face_cascade_name("C:/AViS/Plugins/OpenCV/Resources/Data/haarcascades/haarcascade_frontalface_alt_tree.xml");
	cv::String eyes_cascade_name("C:/AViS/Plugins/OpenCV/Resources/Data/haarcascades/haarcascade_eye.xml");

	if (!face_cascade.load(face_cascade_name))
	{
		UE_LOG(LogTemp, Warning, TEXT("[Face Detaction] Error loading face cascade"));
	};
	if (!eyes_cascade.load(eyes_cascade_name))
	{
		UE_LOG(LogTemp, Warning, TEXT("[Face Detaction] Error loading eye cascade"));
	};
	// ****************************************************

	// Initialize OpenCV and webcam properties
	CameraID = 0;
	IsStreamOpen = false;
	VideoSize = FVector2D(0, 0);
	ShouldResize = false;
	ResizeDimensions = FVector2D(320, 240);
	Stream = cv::VideoCapture();
	Frame = cv::Mat();
	FaceData = fd;

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

		Stream.read(Frame);

		cv::imshow("AViS Sending", Frame);

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

		/* ----------------------WIP-------------------- */
		// cv::Mat clone = Frame.clone();
		// DetectFace(clone);
		// detectAndDraw(clone, face_cascade, eyes_cascade, 4, true);
		/* --------------------------------------------- */

		Frame(cv::Rect(70, 70, 100, 100)).copyTo(CroppedFrame); // image will be 100x100
		cv::Size s = CroppedFrame.size();

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

void Webcam::DetectFace(cv::Mat& Frame)
{
	cv::Mat frame_gray;
	cv::cvtColor(Frame, frame_gray, cv::COLOR_BGR2GRAY);
	cv::equalizeHist(frame_gray, frame_gray);
	
	//-- Detect faces
	std::vector<cv::Rect> faces;
	// face_cascade.detectMultiScale(frame_gray, faces);






	std::vector<double> weights;
	std::vector<int> levels;
	std::vector<cv::Rect> detections;



	if (face_cascade.empty())
	{
		UE_LOG(LogTemp, Warning, TEXT("[Webcam::DetectFace] Cascade is empty"));
	}
	else {
		// WIP Segmentation fault here
		face_cascade.detectMultiScale(frame_gray, faces);
		
		
		for (size_t i = 0; i < faces.size(); i++)
		{
			cv::Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
			cv::ellipse(Frame, center, cv::Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, cv::Scalar(255, 0, 255), 4);


			// cv::Mat faceROI = frame_gray(faces[i]);
			/*
			//-- In each face, detect eyes
			std::vector<cv::Rect> eyes;
			eyes_cascade.detectMultiScale(faceROI, eyes);

			for (size_t j = 0; j < eyes.size(); j++)
			{
				cv::Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
				int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
				cv::circle(Frame, eye_center, radius, cv::Scalar(255, 0, 0), 4);
			}
			*/
		}

	}





	// cv::CascadeClassifier model("/path/to/your/model.xml");
	// model.detectMultiScale(img, detections, levels, weights, 1.1, 3, 0, Size(), Size(), true);







	

	//-- Display
	cv::imshow("AViS Sending", Frame);
	// cv::imshow("AViS Grey", frame_gray);
}

void Webcam::detectAndDraw(
	cv::Mat& img,
	cv::CascadeClassifier& cascade,
	cv::CascadeClassifier& nestedCascade,
	double scale,
	bool tryflip )
{
	double t = 0;
	std::vector<cv::Rect> faces, faces2;
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
	resize(gray, smallImg, cv::Size(), fx, fx, 5);
	equalizeHist(smallImg, smallImg);
	t = (double)cv::getTickCount();
	cascade.detectMultiScale(smallImg, faces,
		1.1, 2, 0
		//|CASCADE_FIND_BIGGEST_OBJECT
		//|CASCADE_DO_ROUGH_SEARCH
		| cv::CASCADE_SCALE_IMAGE,
		cv::Size(30, 30));
	if (tryflip)
	{
		flip(smallImg, smallImg, 1);
		cascade.detectMultiScale(smallImg, faces2,
			1.1, 2, 0
			//|CASCADE_FIND_BIGGEST_OBJECT
			//|CASCADE_DO_ROUGH_SEARCH
			| cv::CASCADE_SCALE_IMAGE,
			cv::Size(30, 30));
		for (std::vector<cv::Rect>::const_iterator r = faces2.begin(); r != faces2.end(); ++r)
		{
			faces.push_back(cv::Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
		}
	}
	t = (double)cv::getTickCount() - t;

	UE_LOG(LogTemp, Warning, TEXT("[Webcam::detectAndDraw] Detection time: %g ms"), *FString::Printf(TEXT("%d"), t * 1000 / cv::getTickFrequency()));

	for (size_t i = 0; i < faces.size(); i++)
	{
		cv::Rect r = faces[i];
		cv::Mat smallImgROI;
		std::vector<cv::Rect> nestedObjects;
		cv::Point center;
		cv::Scalar color = colors[i % 8];
		int radius;
		double aspect_ratio = (double)r.width / r.height;
		if (0.75 < aspect_ratio && aspect_ratio < 1.3)
		{
			center.x = cvRound((r.x + r.width*0.5)*scale);
			center.y = cvRound((r.y + r.height*0.5)*scale);
			radius = cvRound((r.width + r.height)*0.25*scale);
			circle(img, center, radius, color, 3, 8, 0);
		}
		else
			rectangle(img, cv::Point(cvRound(r.x*scale), cvRound(r.y*scale)),
				cv::Point(cvRound((r.x + r.width - 1)*scale), cvRound((r.y + r.height - 1)*scale)),
				color, 3, 8, 0);
		if (nestedCascade.empty())
			continue;
		smallImgROI = smallImg(r);
		nestedCascade.detectMultiScale(smallImgROI, nestedObjects,
			1.1, 2, 0
			//|CASCADE_FIND_BIGGEST_OBJECT
			//|CASCADE_DO_ROUGH_SEARCH
			//|CASCADE_DO_CANNY_PRUNING
			| cv::CASCADE_SCALE_IMAGE,
			cv::Size(30, 30));
		for (size_t j = 0; j < nestedObjects.size(); j++)
		{
			cv::Rect nr = nestedObjects[j];
			center.x = cvRound((r.x + nr.x + nr.width*0.5)*scale);
			center.y = cvRound((r.y + nr.y + nr.height*0.5)*scale);
			radius = cvRound((nr.width + nr.height)*0.25*scale);
			circle(img, center, radius, color, 3, 8, 0);
		}
	}
	imshow("AViS Sending", img);
}
