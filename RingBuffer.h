#pragma once
class RingBuffer
{
private:
	/// <summary>
	/// ���������� ��� ������� ������� �������
	/// </summary>
	int _capacity;

	/// <summary>
	/// ��������� ������
	/// </summary>
	int _freeCells;

	/// <summary>
	/// ������ ��� ������
	/// </summary>
	int _indexForWrite;

	/// <summary>
	/// ������ ��� ������ ��������
	/// </summary>
	int _indexForRead;

	/// <summary>
	/// ������ �����
	/// </summary>
	int* _array;


	public:
	/// <summary>
	/// ������ ����� � �������� ��� ����
	/// </summary>
	RingBuffer(int capacityOfBuffer);
	
	/// <summary>
	/// ������ �����
	/// </summary>
	~RingBuffer();

	/// <summary>
	/// ����� ������� �������
	/// </summary>
	/// <returns>������ �������</returns>
	int GetCapacity();

	/// <summary>
	/// ����� �������� �� �������
	/// </summary>
	/// <param name="IndexOfElement">������</param>
	/// <returns>������� �� ����������� �������</returns>
	int GetValue(int IndexOfElement);

	/// <summary>
	/// ���������� ��������
	/// </summary>
	/// <param name="valueToPush">����������� ������</param>
	/// <returns>0</returns>
	int Push(int valueToPush);

	/// <summary>
	/// ������ ��������
	/// </summary>
	/// <returns>������� �������</returns>
	int Pop();

	/// <summary>
	/// ������� ������������ ���-�� ������ �����
	/// </summary>
	/// <returns>���-�� ������ �����</returns>
	int GetFreeCells();

	/// <summary>
	/// ������� ������������ ���-�� ����������������� �����
	/// </summary>
	/// <returns>���-�� ����������������� �����</returns>
	int GetReservedCells();
};
