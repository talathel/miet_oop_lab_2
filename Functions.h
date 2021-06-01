#pragma once
#include "Letter.h"
#include <iostream>
#include <fstream>
using namespace std;
// ������ ���������� � ������� � ������������ ��������
void filter_by_ind(Letter* &_letter_box, int &_ind);
// ������ ������� ���� �������� ������ Letter
void letter_swap(Letter &_l1, Letter &_l2);
// ���������� ������� ����� �� ����������� ��������� ������
void sort_by_cost_increase(Letter* &_letter_box);
// ������� ��� �������� ������������� ���������� ������� �������� ������ Letter
/*bool check_needing_for_expand(Letter* &_letter_box);*/
// ������� ��� ���������� ������� �������� ������ Letter
void expand_letter_box(Letter* &_letter_box);
// ������� ���������� ������� ������ Letter � ������ �������� ����� ������
void add_letter_into_box(Letter* &_letter_box);
// ������� ������ ������� �������� ������ Letter
void show_letter_box(Letter*& _letter_box);
// ������� ������ ���� �� �����
void show_menu();
// ������� �������� �����
bool check_input();
// ������� �������� ���������� �� �����
bool open_and_load(Letter* &_pack, fstream &_box);
// ������� ���������� ���������� � ����
void save_box(Letter* &_pack, fstream &_box);
// ������� ���������� ������� ���������
void control_work(Letter* &_pack, fstream &_box);