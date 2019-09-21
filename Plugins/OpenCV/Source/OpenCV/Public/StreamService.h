
#pragma once

#include "AllowWindowsPlatformTypes.h"
#include <winsock2.h>
#include "HideWindowsPlatformTypes.h"

#include "WebcamReader.h"

#include <iostream>
#include <thread>
#include "CoreMinimal.h"

class OPENCV_API StreamService
{
public:
	StreamService();
	~StreamService();

	bool KeepServing;
	std::thread StreamServer;
	Webcam* Camera;
	void StartStreamService();
	void StopStreamService();
};
