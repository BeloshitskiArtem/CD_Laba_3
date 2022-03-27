#pragma once
#include "RingBuffer.h"

class RingQueue
{
private:
	/// <summary>
	/// указатель на циклический буфер 
	/// </summary>
	RingBuffer* _ringBuffer;

public:
	/// <summary>
	/// создаём циклический буфер заданного размера
	/// <param name="bufferCapacity">размер циклического буфера</param>
	/// </summary>
	RingQueue(int bufferCapacity);

	/// <summary>
	/// Очищаем очередь
	/// </summary>
	~RingQueue();

	/// <summary>
	/// Функция возвращающая кол-во пустых ячеек
	/// </summary>
	/// <returns>кол-во пустых ячеек</returns>
	int GetFreeCells();
	
	/// <summary>
	/// Добавление в очередь
	/// </summary>
	/// <param name="valueToPush">Добавляемое значение</param>
	/// <returns>добавленный элемент</returns>
	int Enqueue(int valueToPush);

	/// <summary>
	/// исключение из очереди
	/// </summary>
	/// <returns>исключённый элемент</returns>
	int Unqueue();

	/// <summary>
	/// Функция возвращает длинну очереди
	/// </summary>
	/// <returns>длинну очереди</returns>
	int GetRingQueueLength();
};