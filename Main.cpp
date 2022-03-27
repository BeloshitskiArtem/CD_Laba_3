#include <iostream>
#include <string>
#include "Stack.h"
#include "RingBuffer.h"
#include "RingQueue.h"
#include "StacksQueue.h"

using namespace std;

void Input(string iputInformation, int & value)
{
	cout << iputInformation;

	string string;
	cin >> string;
	try
	{
		value = stoi(string);
	}
	catch (std::exception& e)
	{
		Input("������� ����������� ��������\n������� �������� ������: ", value);
	}
}

template <typename T>
bool CreationCheck(T * bufferUnit, const char* error)
{
	if (bufferUnit == nullptr)
	{
		cout << error << endl;
	}
	return bufferUnit == nullptr;
}

template <typename T>
void DeleteElement(T* bufferUnit, const char* charArray)
{
	delete bufferUnit;
	cout << charArray << endl;
}

void Hello()
{
	cout << "��� ������������ ��������� ��� ������ � ������������ "
		<< "����������� ������." << endl << endl;
	cout << "� ��������� ������������ 4 ���� ��������:" << endl;
	cout << "\t1. ����;" << endl;
	cout << "\t2. ��������� �����;" << endl;
	cout << "\t3. ������� �� ��������� ������;" << endl;
	cout << "\t4. ������� �� ���� ������." << endl;
	cout << "��� ������ �� ����������, ������� � ����� �� ������ ����: "
		<< endl;
}

void StackMenu()
{
	cout << "��� ������ �� ������, ����������� ��������� ������ ��������"<< endl;
	cout << "\t1 - �������� �����;" << endl;
	cout << "\t2 - ��������� �������� � ����;" << endl;
	cout << "\t3 - ���������� �������� �� �����;" << endl;
	cout << "\t0 - �������� ����� � ������� ������;" << endl;

	int operationCode;
	Stack* stackUnit = nullptr;
	while (true)
	{

		Input("������� ��� ��������: ", operationCode);

		while (operationCode < 0 && operationCode > 3 && operationCode != 100)
		{
			cout << "����� ������������ ��� ��������. ��� ������ �������," << " ������� 100." << endl;
			Input("������� ��� ��������: ", operationCode);

		}
		switch (operationCode)
		{
			
			case 1:
			{
				if (stackUnit != nullptr)
				{
					cout << "������. ���� ��� ������." << endl;
					break;
				}
				else
				{
					stackUnit = new Stack;
					cout << "���� ������� ������." << endl;
					break;
				}
			}

			case 2:
			{
				if (CreationCheck(stackUnit, "������. ���� �� ������."))
				{
					break;
				}
				else
				{
					int valueToPush;
					Input("������� �����, ���������� � ����: ", valueToPush);

					stackUnit->Push(valueToPush);
					cout << "����� " << valueToPush << " �������� � ����." << endl;
					break;
				}
			}
			case 3:
			{
				if (CreationCheck(stackUnit, "������. ���� �� ������."))
				{
					break;
				}
				else
				{
					if (stackUnit->StackLength() > 0)
					{
						cout << "�� ����� ��������� ����� " << stackUnit->Pop() << '.' << endl;
						break;
					}
					else
					{
						cout << "������. ���� ����!" << endl;
						break;
					}
				}
			}
			case 0:
			{
				DeleteElement(stackUnit, "���� ������� �����.");
				return;
			}
			case 100:
			{
				cout << "��� ������ �� ������, ����������� ��������� ������ ��������:" << endl;
				cout << "\t1 - �������� �����;" << endl;
				cout << "\t2 - ��������� ������� � ����;" << endl;
				cout << "\t3 - ���������� �������� �� �����;" << endl;
				cout << "\t0 - �������� ����� � ������� ������." << endl;
			}
		}
	}
}

void RingBufferMenu()
{
	cout << "��� ������ � ��������� �������, ����������� ��������� ������ ��������:" << endl;
	cout << "1 - ������� �����;" << endl;
	cout << "2 - �������� ������� � ��������� �����;" << endl;
	cout << "3 - ����� ������� �� ���������� ������;" << endl;
	cout << "4 - ������� �� ����� ��������� �����;" << endl;
	cout << "5 - ������� �� ����� ������� �����;" << endl;
	cout << "6 - ������� �� ����� ���� �����;" << endl;
	cout << "0 - �������� ���������� ������ � ������� ������;" << endl;

	int operationCode;
	RingBuffer* ringBufferUnit = nullptr;
	while (true)
	{
		cout << "������� ��� ��������: ";
		cin >> operationCode;
		
		while(operationCode < -1 && operationCode > 6 && operationCode != 100)
		{
			cout << "����� ������������ ��� ��������. ��� ������ �������, ������� 100." << endl;
			cout << "������� ��� ��������: ";
			cin >> operationCode;
		}
		switch (operationCode)
		{

			case 1:
			{
				if (ringBufferUnit != nullptr)
				{
					cout << "������. ��������� ����� ��� ������." << endl;
					break;
				}
				else
				{
					int bufferSize;
					Input("������� ����� ���������� ��������� ������: ", bufferSize);
					while (bufferSize <= 0)
					{
						Input("������. ������� ������������� ����� ���������.", bufferSize);
					}
					ringBufferUnit = new RingBuffer(bufferSize);
					cout << "��������� ����� ������� ������." << endl;
					break;
				}
			}
			case 2:
			{
				if (CreationCheck(ringBufferUnit, "������. ��������� ����� �� ������."))
				{ 
					break;
				}
				else
				{
					int valueToPush;
					Input("������� �����, ���������� � ��������� �����: ", valueToPush);
					ringBufferUnit->Push(valueToPush);
					cout << "����� " << valueToPush << " �������� � ���������"
						<< " �����." << endl;
					break;
				}
			}
			case 3:
			{
				if (CreationCheck(ringBufferUnit, "������. ��������� ����� �� ������."))
				{
					break;
				}
				else
				{
					if (ringBufferUnit->GetReservedCells() > 0)
					{
						cout << "�� ���������� ������ ��������� ����� "
						<< ringBufferUnit->Pop() << '.' << endl;
						break;
					}
					else
					{
						cout << "������. ��������� ����� ����!" << endl;
						break;
					}
				}
			}
			case 4:
			{
				cout << "� ������ " << ringBufferUnit->GetFreeCells() << " ��������� �����." << endl;
				break;
			}
			case 5:
			{
				cout << "� ������ " << ringBufferUnit->GetReservedCells()
					<< " ���������������� �����." << endl;
				break;
			}
			case 6:
			{
				if (CreationCheck(ringBufferUnit, "������. ��������� ����� �� ������."))
				{
					break;
				}
				else
				{
					cout << "����� �������� ���������� ��������:" << endl;
					for (int i = 0; i < ringBufferUnit->GetCapacity(); i++)
					{
						cout << ringBufferUnit->GetValue(i);
					}
					break;
				}
			}
			case 0:
			{
				DeleteElement(ringBufferUnit, "��������� ����� ������� �����.");
				return;
			}
			case 100:
			{
				cout << "��� ������ � ��������� �������, ����������� ��������� ������ ��������" << endl;
				cout << "1 - ������� �����;" << endl;
				cout << "2 - �������� ������� � ��������� �����;" << endl;
				cout << "3 - ����� ������� �� ���������� ������;" << endl;
				cout << "4 - ������� �� ����� ��������� �����;" << endl;
				cout << "5 - ������� �� ����� ������� �����;" << endl;
				cout << "0 - �������� ���������� ������ � ������� ������;" << endl;
			}
		}
	}
}

void StacksQueueMenu()
{
	cout << "��� ������ � �������� �� ���� ������, ����������� ��������� ������ ��������:" << endl;
	cout << "\t1 - �������� �������;" << endl;
	cout << "\t2 - ��������� �������� � �������;" << endl;
	cout << "\t3 - ���������� �������� �� �������;" << endl;
	cout << "\t0 - �������� ������� � ������� ������;" << endl;
	int operationCode;
	StacksQueue* StacksQueueUnit = nullptr;
	while (true)
	{
		Input("������� ��� ��������: ", operationCode);
		
		while (operationCode < 0 && operationCode > 3 && operationCode != 100)
		{
			cout << "����� ������������ ��� ��������. ��� ������ �������, ������� 100." << endl;
			Input("������� ��� ��������: ", operationCode);
		}
		switch (operationCode)		
		{	
		
			case 1:
			{
				if (StacksQueueUnit != nullptr)
				{
					cout << "������. ������� ��� �������." << endl;
					break;
				}
				else
				{
					StacksQueueUnit = new StacksQueue;
					cout << "������� ������� �������." << endl;
					break;
				}
			}
			case 2:
			{
				if (CreationCheck(StacksQueueUnit, "������. ������� �� �������."))
				{
					break;
				}
				else
				{
					int valueToPush;
					Input("������� �����, ���������� � �������: ", valueToPush);
					StacksQueueUnit->Enqueue(valueToPush);
					cout << "����� " << valueToPush << " �������� � �������."
						<< endl;
					break;
				}
			}
			case 3:
			{
				if (CreationCheck(StacksQueueUnit, "������. ������� �� �������."))
				{
					break;
				}
				else
				{
					if (StacksQueueUnit->GetCountOfNodes() > 0)
					{
						cout << "�� ������� ��������� ����� "
							<< StacksQueueUnit->Unqueue() << '.' << endl;
						break;
					}
					else
					{
						cout << "������. ������� �����!" << endl;
						break;
					}
				}
			}
			case 0:
			{
				DeleteElement(StacksQueueUnit, "������� ������� �������.");
				return;
			}
			case 100:
			{
				cout << "��� ������ �� ������, ����������� ���������"
					<< " ������ ��������" << endl;
				cout << "\t1 - �������� �������;" << endl;
				cout << "\t2 - ��������� �������� � �������;" << endl;
				cout << "\t3 - ���������� �������� �� �������;" << endl;
				cout << "\t0 - �������� ������� � ������� ������." << endl;
			}
		}
	}
}

void RingQueueMenu()
{

	cout << "��� ������ � �������� �� ��������� ������, ����������� ��������� ������ ��������:" << endl;
	cout << "\t1 - �������� �������;" << endl;
	cout << "\t2 - ��������� �������� � �������;" << endl;
	cout << "\t3 - ���������� �������� �� �������;" << endl;
	cout << "\t0 - �������� ������� � ������� ������;" << endl;
	//TODO: RSDN
	int operationCode;
	RingQueue* ringQueueUnit = nullptr;
	while (true)
	{
		Input("������� ��� ��������: ", operationCode);
		
		while (operationCode < 0 && operationCode > 5 && operationCode != 100)
		{
			cout << "����� ������������ ��� ��������. ��� ������ �������, ������� 100." << endl;
			Input("������� ��� ��������: ", operationCode);
		}
		switch (operationCode)
		{

			case 1:
			{
				if (ringQueueUnit != nullptr)
				{
					cout << "������. ������� ��� �������." << endl;
					break;
				}
				else
				{
					int queueCapacity;
					Input("������� ������ �������: ", queueCapacity);
					while (queueCapacity <= 0)
					{
						cout << "������. ������� ������������� ����� ���������";
						cin >> queueCapacity;
					}
					ringQueueUnit = new RingQueue(queueCapacity);
					cout << "������� ������� �������." << endl;
					break;
				}
			}
			case 2:
			{
				if (CreationCheck(ringQueueUnit, "������. ������� �� �������."))
				{
					break;
				}
				else
				{
					if (!ringQueueUnit->GetFreeCells())
					{
						cout << "������. ������� ���������!" << endl;
						break;
					}
					if (ringQueueUnit->GetRingQueueLength() > 0)
					{
						int valueToPush;
						Input("������� �����, ���������� � �������: ", valueToPush);

						ringQueueUnit->Enqueue(valueToPush);
						cout << "����� " << valueToPush <<
							" �������� � �������." << endl;
						break;
					}
					int valueToPush;
					Input("������� �����, ���������� � �������: ", valueToPush);
					ringQueueUnit->Enqueue(valueToPush);
					cout << "����� " << valueToPush << " �������� � �������."
						<< endl;
					break;
				}
			}
			case 3:
			{
				if (CreationCheck(ringQueueUnit, "������. ������� �� �������."))
				{
					break;
				}
				else
				{
					if (ringQueueUnit->GetRingQueueLength() > 0)
					{
						cout << "�� ������� ��������� ����� "
							<< ringQueueUnit->Unqueue() << '.' << endl;
						break;
					}
					else
					{
						cout << "������. ������� �����!" << endl;
						break;
					}
				}
			}
			case 0:
			{
				if (ringQueueUnit != nullptr)
				{
					DeleteElement(ringQueueUnit, "������� ������� �������.");
					return;
				}
				else
				{
					return;
				}
			}
			case 100:
			{
				cout << "��� ������ � ��������, ����������� ��������� ������ ��������" << endl;
				cout << "\t1 - �������� �������;" << endl;
				cout << "\t2 - ��������� �������� � �������;" << endl;
				cout << "\t3 - ���������� �������� �� �������;" << endl;
				cout << "\t0 - �������� ������� � ������� ������." << endl;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "��� ������������ ��������� ��� ������ � ������������ "
		<< "����������� ������." << endl << endl;
	cout << "� ��������� ������������ 4 ���� ��������, ��� ������ � �������� "
		<< "������� ��������������� �� ����� �� ������." << endl;

	int structureCode;
	while (true)
	{
		cout << "������ ��������:" << endl;
		cout << "\t1. ����;" << endl;
		cout << "\t2. ��������� �����;" << endl;
		cout << "\t3. ������� �� ��������� ������;" << endl;
		cout << "\t4. ������� �� ���� ������." << endl;
		cout << "����� ����� �� ���������, ������� 0." << endl;
		cout << "������� ����� ���������: ";
		cin >> structureCode;

		while (structureCode < 0 && structureCode > 4)
		{
			Input("�������� ����� ���������. ��������� ����: ", structureCode);
		}
		switch (structureCode)
		{

			case 1:
			{
				StackMenu();
				break;
			}
			case 2:
			{
				RingBufferMenu();
				break;
			}
			case 3:
			{
				RingQueueMenu();
				break;
			}
			case 4:
			{
				StacksQueueMenu();
				break;
			}
			case 0:
			{
				cout << "��������� ��������� ������." << endl;
				return 0;
			}
		}
	}
	return 0;
}