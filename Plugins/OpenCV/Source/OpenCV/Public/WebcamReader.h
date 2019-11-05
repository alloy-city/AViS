#pragma once

// Move to StreamService class
#include <iostream>

// #if PLATFORM_WINDOWS
#include "opencv2/core.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"	
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/utility.hpp>
// #endif

#include "Runtime/Core/Public/Math/Color.h"
#include "Runtime/Core/Public/Math/Vector2D.h"

#define VIDEO_BUFFER_MAX 65000

class OPENCV_API Webcam
{
public:
	// Constructor
	Webcam();

	// Propreties
	bool ShouldResize, IsStreamOpen, KeepServing;
	FVector2D VideoSize, ResizeDimensions;
	int8 CameraID;
// #if PLATFORM_WINDOWS
	cv::Mat Frame;
	cv::Mat CroppedFrame, ResizedFrame;
	std::vector<uchar> CompressedFrame;
	std::vector<int> CompressionParams;
	cv::VideoCapture Stream;
	cv::Size Size;
// #endif
	// std::thread StreamServer;
	int FrameNumberOfBytes;
	float FrameRate = 30;

	// Network buffer
	char VideoBuffer[VIDEO_BUFFER_MAX];

	// Face Detection
// #if PLATFORM_WINDOWS
	cv::CascadeClassifier FaceCascade, EyesCascade;
	cv::String FaceCascadeFile, EyesCascadeFile;
	std::vector<cv::Rect> faces, faces2;
	cv::Rect Face = cv::Rect(0, 0, 10, 10);
	cv::Mat smallImgROI;
	cv::Point center;
	cv::Scalar color;
// #endif
	int radius;
	float Margin = 0.2;
// #if PLATFORM_WINDOWS
	cv::Size FaceResolution = cv::Size(128, 128);
// #endif
	int CompressionQuality = 80;
	bool Debug = false;

	// Methods
	void UpdateFrame();
	void TurnOff();
	bool GetFrame();
	int GetFrameNumberOfBytes();
	// void StartStreamService();
// #if PLATFORM_WINDOWS
	bool DetectFace(cv::Mat& img, cv::CascadeClassifier& ccFace, cv::CascadeClassifier& ccEye, double scale, bool tryflip);
// #endif

	char* GetVideoBuffer();
};
