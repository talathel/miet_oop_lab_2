#pragma once
#include "Letter.h"
#include <iostream>
#include <fstream>
using namespace std;
// Печать информации о письмах с определенным индексом
void filter_by_ind(Letter* &_letter_box, int &_ind);
// Замена местами двух объектов класса Letter
void letter_swap(Letter &_l1, Letter &_l2);
// Сортировка массива писем по возрастанию стоимости письма
void sort_by_cost_increase(Letter* &_letter_box);
// Функция для проверки необходимости расширения массива объектов класса Letter
/*bool check_needing_for_expand(Letter* &_letter_box);*/
// Функция для расширения массива объектов класса Letter
void expand_letter_box(Letter* &_letter_box);
// Функция добавления объекта класса Letter в массив объектов этого класса
void add_letter_into_box(Letter* &_letter_box);
// Функция печати массива объектов класса Letter
void show_letter_box(Letter*& _letter_box);
// Функция печати меню на экран
void show_menu();
// Функция проверки ввода
bool check_input();
// Функция загрузки информации из файла
bool open_and_load(Letter* &_pack, fstream &_box);
// Функция сохранения информации в файл
void save_box(Letter* &_pack, fstream &_box);
// Функция управления работой программы
void control_work(Letter* &_pack, fstream &_box);