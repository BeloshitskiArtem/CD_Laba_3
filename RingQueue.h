#pragma once
#include "RingBuffer.h"

class RingQueue
{
private:
	/// <summary>
	/// ��������� �� ����������� ����� 
	/// </summary>
	RingBuffer* _ringBuffer;

public:
	/// <summary>
	/// ������ ����������� ����� ��������� �������
	/// <param name="bufferCapacity">������ ������������ ������</param>
	/// </summary>
	RingQueue(int bufferCapacity);

	/// <summary>
	/// ������� �������
	/// </summary>
	~RingQueue();

	/// <summary>
	/// ������� ������������ ���-�� ������ �����
	/// </summary>
	/// <returns>���-�� ������ �����</returns>
	int GetFreeCells();
	
	/// <summary>
	/// ���������� � �������
	/// </summary>
	/// <param name="valueToPush">����������� ��������</param>
	/// <returns>����������� �������</returns>
	int Enqueue(int valueToPush);

	/// <summary>
	/// ���������� �� �������
	/// </summary>
	/// <returns>����������� �������</returns>
	int Unqueue();

	/// <summary>
	/// ������� ���������� ������ �������
	/// </summary>
	/// <returns>������ �������</returns>
	int GetRingQueueLength();
};