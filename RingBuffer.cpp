#include "RingBuffer.h"

RingBuffer::RingBuffer(int lengthOfBuffer)
{
	_capacity = _freeCells = lengthOfBuffer;
	_indexForRead = 0;
	_indexForWrite = 0;
	_array = new int[_capacity];
}

RingBuffer::~RingBuffer()
{
	delete[] _array;
}

int RingBuffer::GetCapacity()
{
	return _capacity;
}

int RingBuffer::GetValue(int IndexOfElement)
{
	return _array[IndexOfElement];
}

int RingBuffer::Push(int valueToPush)
{
	_array[_indexForWrite] = valueToPush;
	if (_indexForWrite == _capacity - 1)
	{
		_indexForWrite = 0;
	}
	else
	{
		_indexForWrite++;
	}
	_freeCells--;
	return 0;
}

int RingBuffer::Pop()
{
	int valueToPop = _array[_indexForRead];
	if (_indexForRead == _capacity - 1)
	{
		_indexForRead = 0;
	}
	else
	{
		_indexForRead++;
	}
	_freeCells++;
	return valueToPop;
}

int RingBuffer::GetFreeCells()
{
	return _freeCells;
}

int RingBuffer::GetReservedCells()
{
	return _capacity - _freeCells;
}