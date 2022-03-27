#pragma once
#include "StackNode.h"

class Stack
{
private:
	/// <summary>
	/// ��������� �� ������� �������
	/// </summary>
	StackNode* _topElement;

	/// <summary>
	/// ������ �����, �������� ���� �.�. ������������ � 
	/// ������� ����� ���� ������� �����
	/// </summary>
	StackNode* _bufferOfPointers;

	/// <summary>
	/// ������ �����
	/// </summary>
	int _stackLength;

public:
	/// <summary>
	/// C����� ����, ��� ����������� �� ������, ������ 0
	/// � ����������� ������ ����
	/// </summary>
	Stack();

	//TODO: XML
	/// <summary>
	/// ������� ����
	/// </summary>
	~Stack();

	/// <summary>
	/// �������� ��������
	/// </summary>
	/// <param name="valueToPush">����������� ��������</param>
	/// <returns>0</returns>
	int Push(int valueToPush);

	/// <summary>
	/// �������� ��������(������ � �����)
	/// </summary>
	/// <returns>������� �������</returns>
	int Pop();

	/// <summary>
	/// ��������� ������ �����
	/// </summary>
	/// <returns>������ �����</returns>
	int StackLength();
};
