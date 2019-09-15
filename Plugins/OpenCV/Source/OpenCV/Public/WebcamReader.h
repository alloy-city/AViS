#pragma once

// Move to StreamService class
#include <iostream>
#include <thread>
//

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"	
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/imgcodecs.hpp>
#include "Runtime/Core/Public/Math/Color.h"
#include "Runtime/Core/Public/Math/Vector2D.h"

class OPENCV_API Webcam
{
public:
	// Constructor
	Webcam(TArray<FColor>*);

	// Propreties
	bool ShouldResize, IsStreamOpen, KeepServing;
	FVector2D VideoSize, ResizeDimensions;
	int8 CameraID;
	cv::Mat Frame;
	cv::Mat CroppedFrame;
	std::vector<uchar> CompressedFrame;
	std::vector<int> CompressionParams;
	cv::Size SmallestSize = cv::Size(10, 10);
	cv::VideoCapture Stream;
	cv::Size Size;
	TArray<FColor>* FaceData;
	std::thread StreamServer;
	int FrameNumberOfBytes;

	// Methods
	void UpdateFrame();
	void TurnOff();
	char* GetFrame();
	int GetFrameNumberOfBytes();
	// void StartStreamService();
};
