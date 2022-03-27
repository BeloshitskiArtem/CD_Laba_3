#include "Stack.h"
#include "iostream"

Stack::Stack()
{
    _topElement = nullptr;
    _bufferOfPointers = nullptr;
    _stackLength = 0;
}

Stack::~Stack()
{
    for (int i = 0; i < _stackLength; i++)
    {
        _bufferOfPointers = _topElement;
        _topElement = _topElement->GetPointerOfPreviousElement();
        if (_topElement == nullptr)
        {
            return;
        }
        delete _bufferOfPointers;
        _bufferOfPointers = nullptr;
    }
}

int Stack::StackLength()
{
    return _stackLength;
}

int Stack::Push(int valueToPush)
{
    _bufferOfPointers = _topElement;
    _topElement = new StackNode;
    _topElement->SetValue(valueToPush);
    _topElement->SetPointerOfPreviousElement(_bufferOfPointers);
    _stackLength++;
    return 0;
}

int Stack::Pop()
{
    if (StackLength() == 0)
    {
        return 0;
    }
    int valueToPop = _topElement->GetValue();
    _bufferOfPointers = _topElement;
    _topElement = _topElement->GetPointerOfPreviousElement();
    delete _bufferOfPointers;
    _bufferOfPointers = nullptr;
    _stackLength--;
    return valueToPop;
}
