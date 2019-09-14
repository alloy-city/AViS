// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AllowWindowsPlatformTypes.h"
#include <winsock2.h>
#include "HideWindowsPlatformTypes.h"

#include <iostream>
#include <thread>
#include "CoreMinimal.h"

/**
 * 
 */
class OPENCV_API StreamService
{
public:
	StreamService();
	~StreamService();

	// bool KeepServing;
	std::thread StreamServer;
	void StartStreamService();
	void StopStreamService();
};
