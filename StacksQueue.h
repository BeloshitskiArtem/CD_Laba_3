#pragma once
#include "Stack.h"
#include "RingBuffer.h"

class StacksQueue
{
private:
	/// <summary>
	/// указатель на первый стэк
	/// </summary>
	Stack* _firstStack;

	/// <summary>
	/// указатель на второй стэк
	/// </summary>
	Stack* _secondStack;

	/// <summary>
	/// колличество узлов
	/// </summary>
	int _countOfNodes;

public:
	/// <summary>
	/// Создание указателей на два стека nullptr по умолчанию
	/// кол-во узлов 0
	/// </summary>
	StacksQueue();
	
	/// <summary>
	/// чистим оба стека
	/// </summary>
	~StacksQueue();

	/// <summary>
	/// Добавление в очередь
	/// </summary>
	/// <param name="valueToPush">Добавляемое значение</param>
	/// <returns>0</returns>
	int Enqueue(int valueToPush); 

	/// <summary>
	/// Исключение из очереди
	/// </summary>
	/// <returns>Изьятое значение</returns>
	int Unqueue();

	/// <summary>
	/// Кол-во узлов в очереди
	/// </summary>
	/// <returns>Кол-во узлов в очереди</returns>
	int GetCountOfNodes();
};


