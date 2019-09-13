
#include "OpenCVPrivatePCH.h"
#include "OpenCV.h"
#include "WebcamReader.h"

Webcam::Webcam(TArray<FColor>* fd) {
	FrameData = fd;

	UE_LOG(LogTemp, Warning, TEXT("Webcam constructor"));

	// Initialize OpenCV and webcam properties
	CameraID = 0;
	RefreshRate = 15;
	IsStreamOpen = false;
	VideoSize = FVector2D(0, 0);
	ShouldResize = false;
	ResizeDimensions = FVector2D(320, 240);
	RefreshTimer = 0.0f;
	Stream = cv::VideoCapture();
	Frame = cv::Mat();

	// Open the stream
	Stream.open(CameraID);
	if (Stream.isOpened())
	{
		// Initialize stream
		IsStreamOpen = true;
		UpdateFrame();
		VideoSize = FVector2D(Frame.cols, Frame.rows);
		Size = cv::Size(ResizeDimensions.X, ResizeDimensions.Y);

		// Initialize data array
		FrameData->Init(FColor(0, 0, 0, 255), VideoSize.X * VideoSize.Y);

		// Do first frame
		DoProcessing();
		OnNextFrame();
	}
}

void Webcam::UpdateFrame()
{
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

void Webcam::DoProcessing()
{

}

void Webcam::OnNextFrame()
{
	UE_LOG(LogTemp, Warning, TEXT("On Next Frame"));
}
