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
	Decoder(UTexture2D* vt);
	~Decoder();

	FVector2D VideoSize = FVector2D(128, 128);
	UTexture2D* VideoTexture;
	TArray<uint8>* Buffer;
	cv::Mat Frame, decodedImage;
	std::vector<int> CompressionParams;
	cv::Mat rawData;
	TArray<FColor> Pixels;
	FUpdateTextureRegion2D* VideoUpdateTextureRegion;

	void Decode(TArray<uint8>*, UTexture2D* vt);
	void UpdateTexture();



	void UpdateTextureRegions(
		UTexture2D* Texture,
		int32 MipIndex,
		uint32 NumRegions,
		FUpdateTextureRegion2D* Regions,
		uint32 SrcPitch,
		uint32 SrcBpp,
		uint8* SrcData,
		bool bFreeData
	);
};
