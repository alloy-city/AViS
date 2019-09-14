#pragma once

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"	
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "Runtime/Core/Public/Math/Color.h"
#include "Runtime/Core/Public/Math/Vector2D.h"

class OPENCV_API Webcam
{
public:
	// Constructor
	Webcam(TArray<FColor>*);

	// Propreties
	bool ShouldResize, IsStreamOpen;
	FVector2D VideoSize, ResizeDimensions;
	int8 CameraID;
	cv::Mat Frame;
	cv::VideoCapture Stream;
	cv::Size Size;
	TArray<FColor>* FaceData;

	// Methods
	void UpdateFrame();
	void TurnOff();
	void Listen();
};
