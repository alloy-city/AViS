// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenCV.h"
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
void Listen()
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

	char buffer[1024];
	int clientAddrSize = sizeof(clientAddr);
	if ((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
	{
		UE_LOG(LogTemp, Warning, TEXT("THREAD Client connected!"));
		recv(client, buffer, sizeof(buffer), 0);

		// std::cout << "Client says: " << buffer << std::endl;

		memset(buffer, 0, sizeof(buffer));
		closesocket(client);
		UE_LOG(LogTemp, Warning, TEXT("THREAD Client disconnected."));
	}
}

void StreamService::StartStreamService()
{
	// KeepServing = true;
	StreamServer = std::thread(Listen);
}

void StreamService::StopStreamService()
{
	// KeepServing = false;
}
