#pragma once
class RingBuffer
{
private:
	/// <summary>
	/// Переменная для задания размера буффера
	/// </summary>
	int _capacity;

	/// <summary>
	/// Свободные ячейки
	/// </summary>
	int _freeCells;

	/// <summary>
	/// Индекс для записи
	/// </summary>
	int _indexForWrite;

	/// <summary>
	/// Индекс для взятия элемента
	/// </summary>
	int _indexForRead;

	/// <summary>
	/// Массив чисел
	/// </summary>
	int* _array;


	public:
	/// <summary>
	/// создаём буфер и обнуляем все поля
	/// </summary>
	RingBuffer(int capacityOfBuffer);
	
	/// <summary>
	/// чистим буфер
	/// </summary>
	~RingBuffer();

	/// <summary>
	/// вывод размера буффера
	/// </summary>
	/// <returns>размер буффера</returns>
	int GetCapacity();

	/// <summary>
	/// Вывод элемента по индексу
	/// </summary>
	/// <param name="IndexOfElement">индекс</param>
	/// <returns>элемент по переданному индексу</returns>
	int GetValue(int IndexOfElement);

	/// <summary>
	/// Добавление элемента
	/// </summary>
	/// <param name="valueToPush">Добавляемый лемент</param>
	/// <returns>0</returns>
	int Push(int valueToPush);

	/// <summary>
	/// взятие элемента
	/// </summary>
	/// <returns>Вынутый элемент</returns>
	int Pop();

	/// <summary>
	/// Функция возвращающая кол-во пустых ячеек
	/// </summary>
	/// <returns>кол-во пустых ячеек</returns>
	int GetFreeCells();

	/// <summary>
	/// Функция возвращающая кол-во зарезервированных ячеек
	/// </summary>
	/// <returns>кол-во зарезервированных ячеек</returns>
	int GetReservedCells();
};
