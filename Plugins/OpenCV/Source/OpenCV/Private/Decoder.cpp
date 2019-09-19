
#include "Decoder.h"

Decoder::Decoder()
{
	// Window for testing
	cv::namedWindow("AViS Receiving", cv::WINDOW_NORMAL);
}

Decoder::~Decoder()
{
	cv::destroyAllWindows();
}

void Decoder::Decode(TArray<uint8>* buffer)
{
	// UE_LOG(LogTemp, Warning, TEXT("[Decoder::Decode]"));

	if (buffer == nullptr || buffer == NULL) return;

	// UE_LOG(LogTemp, Warning, TEXT("[Decoder::Decode] Buffer is not NULL"));
	
	int size = buffer->Num();
	uchar * x = (uchar*) malloc(size);
	x = buffer->GetData();
	
	rawData = cv::Mat(1, size, CV_8UC1, (void*)x);
	cv::Mat decodedImage = cv::imdecode(rawData, cv::IMREAD_COLOR);

	if (decodedImage.data == NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("[Decoder::Decode] Error reading JPG image from buffer"));
	}
	else {
		// UE_LOG(LogTemp, Warning, TEXT("[Decoder::Decode] Successfully read JPG image from buffer"));
		cv::imshow("AViS Receiving", decodedImage);
	}
}

void Decoder::UpdateTexture(UTexture2D* Face)
{

}
