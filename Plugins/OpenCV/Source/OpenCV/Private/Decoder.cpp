
#include "Decoder.h"

Decoder::Decoder(UTexture2D* vt)
{
	// Window for testing
	// cv::namedWindow("AViS Receiving", cv::WINDOW_NORMAL);

	VideoTexture = vt;
	VideoUpdateTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, 128, 128);
	Pixels.Init(FColor(0, 0, 0, 255), 128 * 128);
}

Decoder::~Decoder()
{
	cv::destroyAllWindows();
}

void Decoder::Decode(TArray<uint8>* buffer, UTexture2D* vt)
{
	// UE_LOG(LogTemp, Warning, TEXT("[Decoder::Decode]"));

	if (buffer == nullptr || buffer == NULL) return;

	// UE_LOG(LogTemp, Warning, TEXT("[Decoder::Decode] Buffer is not NULL"));
	
	int size = buffer->Num();
	uchar * x = (uchar*) malloc(size);
	x = buffer->GetData();
	
	rawData = cv::Mat(1, size, CV_8UC1, (void*)x);
	decodedImage = cv::imdecode(rawData, cv::IMREAD_COLOR);

	if (decodedImage.data == NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("[Decoder::Decode] Error reading JPG image from buffer"));
	}
	else {
		// UE_LOG(LogTemp, Warning, TEXT("[Decoder::Decode] Successfully read JPG image from buffer"));
		// cv::imshow("AViS Receiving", decodedImage);

		/*UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::Printf(
			TEXT("%d %d"),
			decodedImage.rows,
			decodedImage.cols
		));*/

		for (int y = 0; y < decodedImage.rows; y++)
		{
			for (int x = 0; x < decodedImage.cols; x++)
			{
				int i = x + (y * decodedImage.rows);
				Pixels[i].B = decodedImage.data[i * 3 + 0];
				Pixels[i].G = decodedImage.data[i * 3 + 1];
				Pixels[i].R = decodedImage.data[i * 3 + 2];
			}
		}

		// UpdateTexture();
		/*
		vt->UpdateTextureRegions(
			(int32)0,
			(uint32)1,
			VideoUpdateTextureRegion,
			(uint32)(4 * VideoSize.X),
			(uint32)4,
			(uint8*)Pixels.GetData(),
			false
		);
		*/

		UpdateTextureRegions(
			vt,
			(int32)0,
			(uint32)1,
			VideoUpdateTextureRegion,
			(uint32)(4 * 128),
			(uint32)4,
			(uint8*)Pixels.GetData(),
			false
		);
	}
}

void Decoder::UpdateTexture()
{
	if (VideoTexture == NULL || VideoTexture == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[Decoder::UpdateTexture] VideoTexture is null"));
	}

	/*VideoTexture->UpdateTextureRegions(
		(int32)0,
		(uint32)1,
		VideoUpdateTextureRegion,
		(uint32)(4 * decodedImage.rows),
		(uint32)4,
		(uint8*)Pixels.GetData(),
		false
	);*/
}










void Decoder::UpdateTextureRegions(
	UTexture2D* Texture,
	int32 MipIndex,
	uint32 NumRegions,
	FUpdateTextureRegion2D* Regions,
	uint32 SrcPitch,
	uint32 SrcBpp,
	uint8* SrcData,
	bool bFreeData
) {
	if (Texture->Resource)
	{
		struct FUpdateTextureRegionsData
		{
			FTexture2DResource* Texture2DResource;
			int32 MipIndex;
			uint32 NumRegions;
			FUpdateTextureRegion2D* Regions;
			uint32 SrcPitch;
			uint32 SrcBpp;
			uint8* SrcData;
		};

		FUpdateTextureRegionsData* RegionData = new FUpdateTextureRegionsData;

		RegionData->Texture2DResource = (FTexture2DResource*)Texture->Resource;
		RegionData->MipIndex = MipIndex;
		RegionData->NumRegions = NumRegions;
		RegionData->Regions = Regions;
		RegionData->SrcPitch = SrcPitch;
		RegionData->SrcBpp = SrcBpp;
		RegionData->SrcData = SrcData;

		ENQUEUE_UNIQUE_RENDER_COMMAND_TWOPARAMETER(
			UpdateTextureRegionsData,
			FUpdateTextureRegionsData*, RegionData, RegionData,
			bool, bFreeData, bFreeData,
			{
			for (uint32 RegionIndex = 0; RegionIndex < RegionData->NumRegions; ++RegionIndex)
			{
				int32 CurrentFirstMip = RegionData->Texture2DResource->GetCurrentFirstMip();
				if (RegionData->MipIndex >= CurrentFirstMip)
				{
					RHIUpdateTexture2D(
						RegionData->Texture2DResource->GetTexture2DRHI(),
						RegionData->MipIndex - CurrentFirstMip,
						RegionData->Regions[RegionIndex],
						RegionData->SrcPitch,
						RegionData->SrcData
						+ RegionData->Regions[RegionIndex].SrcY * RegionData->SrcPitch
						+ RegionData->Regions[RegionIndex].SrcX * RegionData->SrcBpp
						);
				}
			}
			if (bFreeData)
			{
				FMemory::Free(RegionData->Regions);
				FMemory::Free(RegionData->SrcData);
			}
			delete RegionData;
			}
		);
	}
}
