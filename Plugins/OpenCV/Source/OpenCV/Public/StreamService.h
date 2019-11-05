
#pragma once

// #if PLATFORM_WINDOWS
#include "AllowWindowsPlatformTypes.h"
#include <winsock2.h>
#include "HideWindowsPlatformTypes.h"

#include "WebcamReader.h"
// #endif

#include <iostream>
#include <thread>
#include <assert.h>
#include <future>
#include "CoreMinimal.h"

class OPENCV_API StreamService
{
public:
	StreamService();
	~StreamService();

	std::promise<void> exitSignal;

// #if PLATFORM_WINDOWS
	std::thread StreamServer;
	Webcam* Camera;
// #endif

	void StartStreamService();
	void StopStreamService();
};
