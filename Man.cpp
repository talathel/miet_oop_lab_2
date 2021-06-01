#define _CRT_SECURE_NO_WARNINGS
#include "Man.h"
#include <cstring>

Man::Man()
{
	this->adr = new char[2]; // ��������� ������ ��� ������
	this->name = new char[2]; // ��������� ������ ��� �����
	strcpy(this->adr, "A"); // ��� ��������� ������ � ���� ������
	strcpy(this->name, "N"); // ��� ��������� ������ � ���� �����
}

Man::~Man()
{
	delete[] this->adr; // ������������ ������, ���������� ��� �����
	delete[] this->name; // ������������ ������, ���������� ��� ���
}

Man::Man(const Man& _obj)
{
	this->adr = new char[strlen(_obj.adr) + 1]; // ��������� ������ ��� ������
	this->name = new char[strlen(_obj.name) + 1]; // ��������� ������ ��� �����
	strcpy(this->adr, _obj.adr); // ����������� � ���� ������
	strcpy(this->name, _obj.name); // ����������� � ���� �����
}

char* Man::get_adr()
{
	return this->adr; 
}

char* Man::get_name()
{
	return this->name;
}

void Man::set_adr(char* _adr)
{
	delete[] this->adr;
	this->adr = new char[strlen(_adr) + 1];
	strcpy(this->adr, _adr);
}

void Man::set_name(char* _name)
{
	delete[] this->name;
	this->name = new char[strlen(_name) + 1];
	strcpy(this->name, _name);
}
