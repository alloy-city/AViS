
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
	int size = buffer->Num();
	uchar * x = (uchar*) malloc(size);
	x = buffer->GetData();
	cv::Mat rawData(40, 40, CV_8UC3, (void*)x);
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
