#pragma once
class Man
{
private:
	char* adr; // �����
	char* name; // ���
public:
	// �����������
	Man(); 
	// ����������
	~Man(); 
	// ����������� �����������
	Man(const Man& _obj);
	// ����� ��������� ������
	char* get_adr(); 
	// ����� ��������� �����
	char* get_name(); 
	// ��������� ������
	void set_adr(char* _adr); 
	// ��������� �����
	void set_name(char* _name);

	friend class Letter;
};