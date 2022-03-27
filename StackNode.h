#pragma once
class StackNode
{
private:
	/// <summary>
	/// �������� �������� - ���� �����
	/// </summary>
	int _value;

	/// <summary>
	/// ������ ����������� �������� - ���� �����
	/// </summary>
	StackNode* _previousElement;

public:
	/// <summary>
	/// �����������, �������� ����
	/// </summary>
	StackNode();

	/// <summary>
	/// ������� �����
	/// </summary>
	~StackNode();

	/// <summary>
	/// ����� �������� ����
	/// </summary>
	/// <param name="value">��������</param>
	void SetValue(int value);

	/// <summary>
	/// �������� ��������
	/// </summary>
	/// <returns>��������</returns>
	int GetValue();

	/// <summary>
	/// ���� ������ ����������� ��������
	/// </summary>
	/// <param name="adressToSet">������</param>
	void SetPointerOfPreviousElement(StackNode* adressToSet);

	/// <summary>
	/// ������� ������ ����������� ��������
	/// </summary>
	/// <returns>������</returns>
	StackNode* GetPointerOfPreviousElement();
};

