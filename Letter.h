#pragma once
#include "Man.h"
#include "Letter.h"
#include "Functions.h"
class Letter
{
private:
	// Отправитель
	Man sender;
	// Получатель
	Man recipient; 
	// Стоимость письма
	double cost;	
public:
	// Индекс получателя
	int ind_recipient;
	// Счетчик существующих объектов класса
	static int count;
	// Конструктор
	Letter();
	// Деструктор
	~Letter();
	// Конструктор копирования
	Letter(Letter& _obj);
	// Конструктор с параметрами
	Letter(int &_ind_recipient, Man &_recipient, Man &_sender, double &_cost);
	// Метод получения ссылки на отправителя
	Man& get_sender();
	// Метод получения ссылки на получателя
	Man& get_recipient();
	// Метод получения стоимости
	double get_cost();
	// Метод установки стоимости
	void set_cost(double _cost);
	// Печать объекта класса Letter
	void letter_print();
	// Метод поиска письма по отправителю
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