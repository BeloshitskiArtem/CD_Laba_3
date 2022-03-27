#include "StacksQueue.h"

StacksQueue::StacksQueue()
{
	_firstStack = new Stack;
	_secondStack = new Stack;
	_countOfNodes = 0;
}

StacksQueue::~StacksQueue()
{
	delete _firstStack;
	delete _secondStack;
}

int StacksQueue::Enqueue(int valueToPush)
{
	_firstStack->Push(valueToPush);
	_countOfNodes++;
	return 0;
}

int StacksQueue::Unqueue()
{
	if (_secondStack->StackLength() == 0 && _firstStack->StackLength() != 0)
	{
		while (_firstStack->StackLength() != 0)
		{
			_secondStack->Push(_firstStack->Pop());
		}
	}
	_countOfNodes--;
	return _secondStack->Pop();
}

int StacksQueue::GetCountOfNodes()
{
	return _countOfNodes;
}

