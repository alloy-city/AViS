// Fill out your copyright notice in the Description page of Project Settings.
// #if PLATFORM_WINDOWS
#include "OpenCV.h"
// #endif

#include "StreamService.h"

StreamService::StreamService()
{
}

StreamService::~StreamService()
{
}

// This function is not a member function of the Webcam class
// It's executed from another thread, so that the stream
// service doesn't clog the main program.
// #if PLATFORM_WINDOWS
void Listen(bool * KeepServing, Webcam* Camera)
{
	WSADATA WSAData;
	SOCKET server, client;
	SOCKADDR_IN serverAddr, clientAddr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7778);

	bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
	listen(server, 0);

	UE_LOG(LogTemp, Warning, TEXT("THREAD Listening for incoming connections..."));

	int clientAddrSize = sizeof(clientAddr);
	if ((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
	{
		UE_LOG(LogTemp, Warning, TEXT("THREAD Client connected!"));

		while (*KeepServing)
		{
			if (Camera->GetFrame())
			{
				send(client, Camera->GetVideoBuffer(), Camera->GetFrameNumberOfBytes(), 0);
				std::this_thread::sleep_for(std::chrono::milliseconds((long long) (1000 / Camera->FrameRate)));
			}
		}

		closesocket(client);
		UE_LOG(LogTemp, Warning, TEXT("THREAD Client disconnected."));
	}

	closesocket(server);
}
// #endif

void StreamService::StartStreamService()
{
// #if PLATFORM_WINDOWS
	KeepServing = true;
	StreamServer = std::thread(Listen, &KeepServing, Camera);
// #endif
}

void StreamService::StopStreamService()
{
// #if PLATFORM_WINDOWS
	KeepServing = false;
// #endif
}
