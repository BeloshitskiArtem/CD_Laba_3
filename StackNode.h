#pragma once
class StackNode
{
private:
	/// <summary>
	/// Значение элемента - узла стека
	/// </summary>
	int _value;

	/// <summary>
	/// Адресс предыдущего элемента - узла стека
	/// </summary>
	StackNode* _previousElement;

public:
	/// <summary>
	/// Конструктор, создание узла
	/// </summary>
	StackNode();

	/// <summary>
	/// Очистка стека
	/// </summary>
	~StackNode();

	/// <summary>
	/// Задаём значение узлу
	/// </summary>
	/// <param name="value">значение</param>
	void SetValue(int value);

	/// <summary>
	/// Показать значение
	/// </summary>
	/// <returns>значение</returns>
	int GetValue();

	/// <summary>
	/// Задём адресс предыдущего элемента
	/// </summary>
	/// <param name="adressToSet">адресс</param>
	void SetPointerOfPreviousElement(StackNode* adressToSet);

	/// <summary>
	/// Вернуть адресс предыдущего элемента
	/// </summary>
	/// <returns>Адресс</returns>
	StackNode* GetPointerOfPreviousElement();
};

