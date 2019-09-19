// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"	
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>
#include "Runtime/Core/Public/Math/Color.h"
#include "Runtime/Core/Public/Math/Vector2D.h"

#include "Engine/Texture2D.h"
#include "CoreMinimal.h"

/**
 * 
 */
class OPENCV_API Decoder
{
public:
	Decoder();
	~Decoder();

	TArray<uint8>* Buffer;
	cv::Mat Frame;
	std::vector<int> CompressionParams;
	cv::Mat rawData;

	void Decode(TArray<uint8>*);
	void UpdateTexture(UTexture2D* Face);
};
