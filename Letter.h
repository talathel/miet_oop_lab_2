#pragma once
#include "Man.h"
#include "Letter.h"
#include "Functions.h"
class Letter
{
private:
	// �����������
	Man sender;
	// ����������
	Man recipient; 
	// ��������� ������
	double cost;	
public:
	// ������ ����������
	int ind_recipient;
	// ������� ������������ �������� ������
	static int count;
	// �����������
	Letter();
	// ����������
	~Letter();
	// ����������� �����������
	Letter(Letter& _obj);
	// ����������� � �����������
	Letter(int &_ind_recipient, Man &_recipient, Man &_sender, double &_cost);
	// ����� ��������� ������ �� �����������
	Man& get_sender();
	// ����� ��������� ������ �� ����������
	Man& get_recipient();
	// ����� ��������� ���������
	double get_cost();
	// ����� ��������� ���������
	void set_cost(double _cost);
	// ������ ������� ������ Letter
	void letter_print();
	// ����� ������ ������ �� �����������
	void find_by_sender(Letter* &_letter_box, char* _sender);

	friend void filter_by_ind(Letter* &_letter_box, int &_ind);
	friend void sort_by_cost_increase(Letter* &_letter_box);
	friend void letter_swap(Letter &_l1, Letter &_l2);
	/*friend bool check_needing_for_expand(Letter* &_letter_box);*/
	friend void expand_letter_box(Letter* &_letter_box);
	friend void add_letter_into_box(Letter* &_letter_box);
	friend void show_letter_box(Letter*& _letter_box);
	//friend bool save_box(Letter* _pack, fstream _box, int _number_init);
};