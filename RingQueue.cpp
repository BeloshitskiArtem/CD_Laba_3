#include "RingQueue.h"
#include "RingBuffer.h"

RingQueue::RingQueue(int bufferCapacity)
{
	_ringBuffer = new RingBuffer(bufferCapacity);
}

RingQueue::~RingQueue()
{
	delete _ringBuffer;
}

int RingQueue::GetFreeCells()
{
	return _ringBuffer->GetFreeCells();
}

int RingQueue::Enqueue(int valueToPush)
{
	return _ringBuffer->Push(valueToPush);
}

int RingQueue::Unqueue()
{
	return _ringBuffer->Pop();
}

int RingQueue::GetRingQueueLength()
{
	return _ringBuffer->GetReservedCells();
}
