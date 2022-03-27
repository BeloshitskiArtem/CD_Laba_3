#pragma once
#include "Stack.h"
#include "RingBuffer.h"

class StacksQueue
{
private:
	/// <summary>
	/// ��������� �� ������ ����
	/// </summary>
	Stack* _firstStack;

	/// <summary>
	/// ��������� �� ������ ����
	/// </summary>
	Stack* _secondStack;

	/// <summary>
	/// ����������� �����
	/// </summary>
	int _countOfNodes;

public:
	/// <summary>
	/// �������� ���������� �� ��� ����� nullptr �� ���������
	/// ���-�� ����� 0
	/// </summary>
	StacksQueue();
	
	/// <summary>
	/// ������ ��� �����
	/// </summary>
	~StacksQueue();

	/// <summary>
	/// ���������� � �������
	/// </summary>
	/// <param name="valueToPush">����������� ��������</param>
	/// <returns>0</returns>
	int Enqueue(int valueToPush); 

	/// <summary>
	/// ���������� �� �������
	/// </summary>
	/// <returns>������� ��������</returns>
	int Unqueue();

	/// <summary>
	/// ���-�� ����� � �������
	/// </summary>
	/// <returns>���-�� ����� � �������</returns>
	int GetCountOfNodes();
};


