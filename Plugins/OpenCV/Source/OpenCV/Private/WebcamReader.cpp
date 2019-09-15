
#include "OpenCVPrivatePCH.h"
#include "OpenCV.h"
#include "WebcamReader.h"

Webcam::Webcam(TArray<FColor>* fd)
{
	UE_LOG(LogTemp, Warning, TEXT("Webcam constructor"));

	FaceData = fd;

	// Initialize OpenCV and webcam properties
	CameraID = 0;
	IsStreamOpen = false;
	VideoSize = FVector2D(0, 0);
	ShouldResize = false;
	ResizeDimensions = FVector2D(320, 240);
	Stream = cv::VideoCapture();
	Frame = cv::Mat();

	// Window for testing
	// cv::namedWindow("AViS Video Capture Debuggin", cv::WINDOW_AUTOSIZE);

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

		Frame(cv::Rect(10, 10, 100, 100)).copyTo(CroppedFrame); // image will be 100x100
		cv::Size s = CroppedFrame.size();

		// UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::Printf(TEXT(">> Image size: %d X %d"), s.height, s.width));

		CompressionParams.push_back(cv::IMWRITE_JPEG_QUALITY);
		CompressionParams.push_back(90);

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

		UE_LOG(LogTemp, Warning, TEXT("%s bytes"), *FString::Printf(TEXT("%d"), FrameNumberOfBytes));

		char * x = (char*) malloc(FrameNumberOfBytes);

		for (int i=0; i<CompressedFrame.size(); i++)
		{
			x[i] = CompressedFrame[i];
		}

		return x;
	}

	return 0;
}

int Webcam::GetFrameNumberOfBytes()
{
	return FrameNumberOfBytes;
}

// This function is not a member function of the Webcam class
// It's executed from another thread, so that the stream
// service doesn't clog the main program.
// void Listen(bool * KeepServing)
// {
	// UE_LOG(LogTemp, Warning, TEXT("THREAD Listen START"));

	// std::chrono::milliseconds timespan(2000);
	// while (*KeepServing)
	// {		
		// TODO: listen to income connections here
	// }

	// UE_LOG(LogTemp, Warning, TEXT("THREAD Listen STOP"));
// }

//void Webcam::StartStreamService()
//{
//	KeepServing = true;
//	// StreamServer = std::thread(Listen, &KeepServing);
//}

void Webcam::TurnOff()
{
	Stream.release();
}
