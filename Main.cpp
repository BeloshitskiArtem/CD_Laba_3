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
		Input("Введено некоректное значение\nВведите значение заново: ", value);
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
	cout << "Вас приветствует программа для работы с абстрактными "
		<< "структурами данных." << endl << endl;
	cout << "В программе представлены 4 типа структур:" << endl;
	cout << "\t1. Стэк;" << endl;
	cout << "\t2. Кольцевой буфер;" << endl;
	cout << "\t3. Очередь на кольцевом буфере;" << endl;
	cout << "\t4. Очередь на двух стэках." << endl;
	cout << "Для работы со структурой, введите её номер из списка выше: "
		<< endl;
}

void StackMenu()
{
	cout << "Для работы со стеком, используйте следующий список операций"<< endl;
	cout << "\t1 - создание стека;" << endl;
	cout << "\t2 - помещение элемента в стек;" << endl;
	cout << "\t3 - извлечение элемента из стека;" << endl;
	cout << "\t0 - удаление стека и очистка памяти;" << endl;

	int operationCode;
	Stack* stackUnit = nullptr;
	while (true)
	{

		Input("Введите код операции: ", operationCode);

		while (operationCode < 0 && operationCode > 3 && operationCode != 100)
		{
			cout << "Введён некорректный код операции. Для вызова справки," << " введите 100." << endl;
			Input("Введите код операции: ", operationCode);

		}
		switch (operationCode)
		{
			
			case 1:
			{
				if (stackUnit != nullptr)
				{
					cout << "Ошибка. Стек уже создан." << endl;
					break;
				}
				else
				{
					stackUnit = new Stack;
					cout << "Стек успешно создан." << endl;
					break;
				}
			}

			case 2:
			{
				if (CreationCheck(stackUnit, "Ошибка. Стек не создан."))
				{
					break;
				}
				else
				{
					int valueToPush;
					Input("Введите число, помещаемое в стек: ", valueToPush);

					stackUnit->Push(valueToPush);
					cout << "Число " << valueToPush << " помещено в стек." << endl;
					break;
				}
			}
			case 3:
			{
				if (CreationCheck(stackUnit, "Ошибка. Стек не создан."))
				{
					break;
				}
				else
				{
					if (stackUnit->StackLength() > 0)
					{
						cout << "Из стека извлечено число " << stackUnit->Pop() << '.' << endl;
						break;
					}
					else
					{
						cout << "Ошибка. Стек пуст!" << endl;
						break;
					}
				}
			}
			case 0:
			{
				DeleteElement(stackUnit, "Стек успешно удалён.");
				return;
			}
			case 100:
			{
				cout << "Для работы со стеком, используйте следующий список операций:" << endl;
				cout << "\t1 - создание стека;" << endl;
				cout << "\t2 - помещение элемент в стек;" << endl;
				cout << "\t3 - извлечение элемента из стека;" << endl;
				cout << "\t0 - удаление стека и очистка памяти." << endl;
			}
		}
	}
}

void RingBufferMenu()
{
	cout << "Для работы с кольцевым буфером, используйте следующий список операций:" << endl;
	cout << "1 - создать буфер;" << endl;
	cout << "2 - добавить элемент в кольцевой буфер;" << endl;
	cout << "3 - взять элемент из кольцевого буфера;" << endl;
	cout << "4 - вывести на экран свободное место;" << endl;
	cout << "5 - вывести на экран занятое место;" << endl;
	cout << "6 - вывести на экран весь буфер;" << endl;
	cout << "0 - удаление кольцевого буфера и очистка памяти;" << endl;

	int operationCode;
	RingBuffer* ringBufferUnit = nullptr;
	while (true)
	{
		cout << "Введите код операции: ";
		cin >> operationCode;
		
		while(operationCode < -1 && operationCode > 6 && operationCode != 100)
		{
			cout << "Введён некорректный код операции. Для вызова справки, введите 100." << endl;
			cout << "Введите код операции: ";
			cin >> operationCode;
		}
		switch (operationCode)
		{

			case 1:
			{
				if (ringBufferUnit != nullptr)
				{
					cout << "Ошибка. Кольцевой буфер уже создан." << endl;
					break;
				}
				else
				{
					int bufferSize;
					Input("Введите целое количество элементов буфера: ", bufferSize);
					while (bufferSize <= 0)
					{
						Input("Ошибка. Введите положительное число элементов.", bufferSize);
					}
					ringBufferUnit = new RingBuffer(bufferSize);
					cout << "Кольцевой буфер успешно создан." << endl;
					break;
				}
			}
			case 2:
			{
				if (CreationCheck(ringBufferUnit, "Ошибка. Кольцевой буфер не создан."))
				{ 
					break;
				}
				else
				{
					int valueToPush;
					Input("Введите число, помещаемое в Кольцевой буфер: ", valueToPush);
					ringBufferUnit->Push(valueToPush);
					cout << "Число " << valueToPush << " помещено в кольцевой"
						<< " буфер." << endl;
					break;
				}
			}
			case 3:
			{
				if (CreationCheck(ringBufferUnit, "Ошибка. Кольцевой буфер не создан."))
				{
					break;
				}
				else
				{
					if (ringBufferUnit->GetReservedCells() > 0)
					{
						cout << "Из кольцевого буфера извлечено число "
						<< ringBufferUnit->Pop() << '.' << endl;
						break;
					}
					else
					{
						cout << "Ошибка. Кольцевой буфер пуст!" << endl;
						break;
					}
				}
			}
			case 4:
			{
				cout << "В буфере " << ringBufferUnit->GetFreeCells() << " свободных ячеек." << endl;
				break;
			}
			case 5:
			{
				cout << "В буфере " << ringBufferUnit->GetReservedCells()
					<< " зарезервированых ячеек." << endl;
				break;
			}
			case 6:
			{
				if (CreationCheck(ringBufferUnit, "Ошибка. Кольцевой буфер не создан."))
				{
					break;
				}
				else
				{
					cout << "Буфер содержит сдледующие элементы:" << endl;
					for (int i = 0; i < ringBufferUnit->GetCapacity(); i++)
					{
						cout << ringBufferUnit->GetValue(i);
					}
					break;
				}
			}
			case 0:
			{
				DeleteElement(ringBufferUnit, "Кольцевой буфер успешно удалён.");
				return;
			}
			case 100:
			{
				cout << "Для работы с кольцевым буфером, используйте следующий список операций" << endl;
				cout << "1 - создать буфер;" << endl;
				cout << "2 - добавить элемент в кольцевой буфер;" << endl;
				cout << "3 - взять элемент из кольцевого буфера;" << endl;
				cout << "4 - вывести на экран свободное место;" << endl;
				cout << "5 - вывести на экран занятое место;" << endl;
				cout << "0 - удаление кольцевого буфера и очистка памяти;" << endl;
			}
		}
	}
}

void StacksQueueMenu()
{
	cout << "Для работы с очередью на двух стеках, используйте следующий список операций:" << endl;
	cout << "\t1 - создание очереди;" << endl;
	cout << "\t2 - помещение элемента в очередь;" << endl;
	cout << "\t3 - извлечение элемента из очереди;" << endl;
	cout << "\t0 - удаление очереди и очистка памяти;" << endl;
	int operationCode;
	StacksQueue* StacksQueueUnit = nullptr;
	while (true)
	{
		Input("Введите код операции: ", operationCode);
		
		while (operationCode < 0 && operationCode > 3 && operationCode != 100)
		{
			cout << "Введён некорректный код операции. Для вызова справки, введите 100." << endl;
			Input("Введите код операции: ", operationCode);
		}
		switch (operationCode)		
		{	
		
			case 1:
			{
				if (StacksQueueUnit != nullptr)
				{
					cout << "Ошибка. Очередь уже создана." << endl;
					break;
				}
				else
				{
					StacksQueueUnit = new StacksQueue;
					cout << "Очередь успешно создана." << endl;
					break;
				}
			}
			case 2:
			{
				if (CreationCheck(StacksQueueUnit, "Ошибка. Очередь не создана."))
				{
					break;
				}
				else
				{
					int valueToPush;
					Input("Введите число, помещаемое в очередь: ", valueToPush);
					StacksQueueUnit->Enqueue(valueToPush);
					cout << "Число " << valueToPush << " помещено в очередь."
						<< endl;
					break;
				}
			}
			case 3:
			{
				if (CreationCheck(StacksQueueUnit, "Ошибка. Очередь не создана."))
				{
					break;
				}
				else
				{
					if (StacksQueueUnit->GetCountOfNodes() > 0)
					{
						cout << "Из очереди извлечено число "
							<< StacksQueueUnit->Unqueue() << '.' << endl;
						break;
					}
					else
					{
						cout << "Ошибка. Очередь пуста!" << endl;
						break;
					}
				}
			}
			case 0:
			{
				DeleteElement(StacksQueueUnit, "Очередь успешно удалена.");
				return;
			}
			case 100:
			{
				cout << "Для работы со стеком, используйте следующий"
					<< " список операций" << endl;
				cout << "\t1 - создание очереди;" << endl;
				cout << "\t2 - помещение элемента в очередь;" << endl;
				cout << "\t3 - извлечение элемента из очереди;" << endl;
				cout << "\t0 - удаление очереди и очистка памяти." << endl;
			}
		}
	}
}

void RingQueueMenu()
{

	cout << "Для работы с очередью на кольцевом буфере, используйте следующий список операций:" << endl;
	cout << "\t1 - создание очереди;" << endl;
	cout << "\t2 - помещение элемента в очередь;" << endl;
	cout << "\t3 - извлечение элемента из очереди;" << endl;
	cout << "\t0 - удаление очереди и очистка памяти;" << endl;
	//TODO: RSDN
	int operationCode;
	RingQueue* ringQueueUnit = nullptr;
	while (true)
	{
		Input("Введите код операции: ", operationCode);
		
		while (operationCode < 0 && operationCode > 5 && operationCode != 100)
		{
			cout << "Введён некорректный код операции. Для вызова справки, введите 100." << endl;
			Input("Введите код операции: ", operationCode);
		}
		switch (operationCode)
		{

			case 1:
			{
				if (ringQueueUnit != nullptr)
				{
					cout << "Ошибка. Очередь уже создана." << endl;
					break;
				}
				else
				{
					int queueCapacity;
					Input("Введите размер очереди: ", queueCapacity);
					while (queueCapacity <= 0)
					{
						cout << "Ошибка. Введите положительное число элементов";
						cin >> queueCapacity;
					}
					ringQueueUnit = new RingQueue(queueCapacity);
					cout << "Очередь успешно создана." << endl;
					break;
				}
			}
			case 2:
			{
				if (CreationCheck(ringQueueUnit, "Ошибка. Очередь не создана."))
				{
					break;
				}
				else
				{
					if (!ringQueueUnit->GetFreeCells())
					{
						cout << "Ошибка. Очередь заполнена!" << endl;
						break;
					}
					if (ringQueueUnit->GetRingQueueLength() > 0)
					{
						int valueToPush;
						Input("Введите число, помещаемое в очередь: ", valueToPush);

						ringQueueUnit->Enqueue(valueToPush);
						cout << "Число " << valueToPush <<
							" помещено в очередь." << endl;
						break;
					}
					int valueToPush;
					Input("Введите число, помещаемое в очередь: ", valueToPush);
					ringQueueUnit->Enqueue(valueToPush);
					cout << "Число " << valueToPush << " помещено в очередь."
						<< endl;
					break;
				}
			}
			case 3:
			{
				if (CreationCheck(ringQueueUnit, "Ошибка. Очередь не создана."))
				{
					break;
				}
				else
				{
					if (ringQueueUnit->GetRingQueueLength() > 0)
					{
						cout << "Из очереди извлечено число "
							<< ringQueueUnit->Unqueue() << '.' << endl;
						break;
					}
					else
					{
						cout << "Ошибка. Очередь пуста!" << endl;
						break;
					}
				}
			}
			case 0:
			{
				if (ringQueueUnit != nullptr)
				{
					DeleteElement(ringQueueUnit, "Очередь успешно удалена.");
					return;
				}
				else
				{
					return;
				}
			}
			case 100:
			{
				cout << "Для работы с очередью, используйте следующий список операций" << endl;
				cout << "\t1 - создание очереди;" << endl;
				cout << "\t2 - помещение элемента в очередь;" << endl;
				cout << "\t3 - извлечение элемента из очереди;" << endl;
				cout << "\t0 - удаление очереди и очистка памяти." << endl;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Вас приветствует программа для работы с абстрактными "
		<< "структурами данных." << endl << endl;
	cout << "В программе представлены 4 типа структур, для работы с которыми "
		<< "введите соответствующий ей номер из списка." << endl;

	int structureCode;
	while (true)
	{
		cout << "Список структур:" << endl;
		cout << "\t1. Стэк;" << endl;
		cout << "\t2. Кольцевой буфер;" << endl;
		cout << "\t3. Очередь на кольцевом буфере;" << endl;
		cout << "\t4. Очередь на двух стэках." << endl;
		cout << "Чтобы выйти из программы, введите 0." << endl;
		cout << "Введите номер структуры: ";
		cin >> structureCode;

		while (structureCode < 0 && structureCode > 4)
		{
			Input("Неверный номер структуры. Повторите ввод: ", structureCode);
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
				cout << "Программа завершила работу." << endl;
				return 0;
			}
		}
	}
	return 0;
}