#ifndef RADIANCEREQUESTHANDLER_H
#define RADIANCEREQUESTHANDLER_H

#include "producerconsumerprogram/FrameQueue.h"

class RadianceRequestHandler
{
	FrameQueue & _queue;
	const int _sockfd;
	bool & _shouldTerminate;

	char frameBuffer[DANCE_FLOOR_WIDTH * DANCE_FLOOR_HEIGHT * sizeof (uint32_t)];

	void sendLookupCoordinates2D();
	void sendGetFrame(uint32_t delay);
	void getAndPushFrames();

public:
	
	// Don't allow copying or moving
	RadianceRequestHandler(const RadianceRequestHandler &) = delete;
	RadianceRequestHandler(RadianceRequestHandler &&) = delete;

	RadianceRequestHandler(const int sockfd, FrameQueue & queue, bool & shouldTerminate);
	~RadianceRequestHandler();

	void operator()();
};

#endif