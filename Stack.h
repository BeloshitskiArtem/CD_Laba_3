#pragma once
#include "StackNode.h"

class Stack
{
private:
	/// <summary>
	/// Указатель на верхний элемент
	/// </summary>
	StackNode* _topElement;

	/// <summary>
	/// Просто буфер, добавлен сюда т.к. используется в 
	/// большей части всех функций стека
	/// </summary>
	StackNode* _bufferOfPointers;

	/// <summary>
	/// Длинна стека
	/// </summary>
	int _stackLength;

public:
	/// <summary>
	/// Cоздаём стек, все указалители на начало, длинна 0
	/// В деструкторе чистим стек
	/// </summary>
	Stack();

	//TODO: XML
	/// <summary>
	/// Очищаем стек
	/// </summary>
	~Stack();

	/// <summary>
	/// Добавить значение
	/// </summary>
	/// <param name="valueToPush">добавляемое значение</param>
	/// <returns>0</returns>
	int Push(int valueToPush);

	/// <summary>
	/// удаление элемента(только с конца)
	/// </summary>
	/// <returns>Вынутый элемент</returns>
	int Pop();

	/// <summary>
	/// Возвращет длинну стека
	/// </summary>
	/// <returns>длинна стека</returns>
	int StackLength();
};
