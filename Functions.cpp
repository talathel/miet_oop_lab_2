#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
#include "Letter.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#define path "data.txt"
using namespace std;
void filter_by_ind(Letter* &_letter_box, int &_ind)
{
	for (int i = 0; i < _letter_box->count; i++)
	{
		if (_letter_box[i].ind_recipient == _ind)
		{
			_letter_box[i].letter_print();
		}
	}
}
void letter_swap(Letter &_l1, Letter &_l2)
{
	Letter temp(_l1);
	_l1.get_recipient().set_name(_l2.get_recipient().get_name());
	_l1.get_recipient().set_adr(_l2.get_recipient().get_adr());
	_l1.get_sender().set_name(_l2.get_sender().get_name());
	_l1.get_sender().set_adr(_l2.get_sender().get_adr());
	_l1.cost = _l2.cost;
	_l1.ind_recipient = _l2.ind_recipient;
	_l2.get_recipient().set_name(temp.get_recipient().get_name());
	_l2.get_recipient().set_adr(temp.get_recipient().get_adr());
	_l2.get_sender().set_name(temp.get_sender().get_name());
	_l2.get_sender().set_adr(temp.get_sender().get_adr());
	_l2.cost = temp.cost;
	_l2.ind_recipient = temp.ind_recipient;
}
void sort_by_cost_increase(Letter* &_letter_box)
{
	int min, size = _letter_box->count;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (_letter_box[min].cost > _letter_box[j].cost)
			{
				min = j;
			}
		}
		letter_swap(_letter_box[i], _letter_box[min]);
	}
}

/*bool check_needing_for_expand(Letter* &_letter_box)
{
	return _letter_box->count == _letter_box->reserved_space;
}*/

void expand_letter_box(Letter* &_letter_box)
{
	int size = _letter_box->count;
	Letter* temp = new Letter[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i].get_recipient().set_name(_letter_box[i].get_recipient().get_name());
		temp[i].get_recipient().set_adr(_letter_box[i].get_recipient().get_adr());
		temp[i].get_sender().set_name(_letter_box[i].get_sender().get_name());
		temp[i].get_sender().set_adr(_letter_box[i].get_sender().get_adr());
		temp[i].cost = _letter_box[i].cost;
		temp[i].ind_recipient = _letter_box[i].ind_recipient;
	}
	delete[] _letter_box;
	_letter_box = temp;
}

void add_letter_into_box(Letter*& _letter_box)
{
	char buff[100];
	cout << "Введите данные получателя" << endl;
	cout << "Введите индекс получателя" << endl;
	do
	{
		cin >> _letter_box[_letter_box->count - 1].ind_recipient;
	} while (check_input());
	cout << "Введите имя получателя" << endl;
	cin >> buff;
	_letter_box[_letter_box->count - 1].recipient.set_name(buff);
	cout << "Введите адрес получателя" << endl;
	cin >> buff;
	_letter_box[_letter_box->count - 1].recipient.set_adr(buff);
	cout << "Введите данные отправителя" << endl;
	cout << "Введите имя отправителя" << endl;
	cin >> buff;
	_letter_box[_letter_box->count - 1].sender.set_name(buff);
	cout << "Введите адрес отправителя" << endl;
	cin >> buff;
	_letter_box[_letter_box->count - 1].sender.set_adr(buff);
	cout << "Введите стоимость письма" << endl;
	do
	{
		cin >> _letter_box[_letter_box->count - 1].cost;
	} while (check_input());
}

void show_letter_box(Letter*& _letter_box)
{
	cout << ("___________________________________________________________________________________________________________________") << endl;
	cout << ("Индекс получателя Адрес получателя          Имя получателя Адрес отправителя     Имя отправителя   Стоимость письма") << endl;
	for (int i = 0; i < _letter_box->count; i++)
		_letter_box[i].letter_print();
	cout << ("___________________________________________________________________________________________________________________") << endl;
}

void show_menu()
{
	cout << ("Что вы хотите сделать?") << endl;
	cout << ("Введите 1 для показа таблицы") << endl;
	cout << ("Введите 2 для ввода данных о новом письме") << endl;
	cout << ("Введите 3 для поиска писем определенного отправителя") << endl;
	cout << ("Введите 4 для сортировки писем по стоимости") << endl;
	cout << ("Введите 5 для фильтра писем по индексу") << endl;
	//cout << ("Введите 6 для поиска письма по отправителю") << endl;;
	cout << ("Введите 0 для выхода из программы") << endl;

}

bool check_input()
{
	if (!cin)
	{
		cin.clear();
		cout << "Ввод некорректен, введите корректное значение" << endl;
		cin.ignore(32000,'\n');
		return true;
	}
	return false;
}

bool open_and_load(Letter* &_pack, fstream &_box)
{
	//FILE* _box = fopen(path, "r");
	_box.open(path);
	if (_box.is_open())
	{
		cout << "Файл открыт, загрузка информации из файла" << endl;
		for (int i = 0; !_box.eof(); i++)
		{
			char _adr_recipient_buff[100], _name_recipient_buff[100], _adr_sender_buff[100], _name_sender_buff[100];
			double _cost;
			int _ind_recipient;
			_box >> _ind_recipient >> _adr_sender_buff >> _name_sender_buff >> _adr_recipient_buff >> _name_recipient_buff >> _cost;
			expand_letter_box(_pack);
			_pack[i].ind_recipient = _ind_recipient;
			_pack[i].get_sender().set_adr(_adr_sender_buff);
			_pack[i].get_sender().set_name(_name_sender_buff);
			_pack[i].get_recipient().set_adr(_adr_recipient_buff);
			_pack[i].get_recipient().set_name(_name_recipient_buff);
			_pack[i].set_cost(_cost);
		}
		_box.close();
		return true;
	}
	else
	{
		cout << "Не удалось открыть файл, работа программы прекращена" << endl;
		_box.close();
		return false;
	}
	return false;
}

void save_box(Letter* &_pack, fstream &_box)
{
	_box.open(path);
	_box << _pack[0].ind_recipient << " " << _pack[0].get_sender().get_adr() << " " << _pack[0].get_sender().get_name() << " " << _pack[0].get_recipient().get_adr() << " " << _pack[0].get_recipient().get_name() << " " << _pack[0].get_cost();
	for (int i = 1; i < _pack->count; i++)
	{
		_box << endl;
		_box << _pack[i].ind_recipient << " " << _pack[i].get_sender().get_adr() << " " << _pack[i].get_sender().get_name() << " " << _pack[i].get_recipient().get_adr() << " " << _pack[i].get_recipient().get_name() << " " << _pack[i].get_cost();
	}
	_box.close();
}

void control_work(Letter* &_pack, fstream &_box)
{
	if (open_and_load(_pack, _box))
	{
		int _count_0 = 0;
		//_count_0 = _pack->count;
		bool _end_function = true;
		do
		{
			//cout << _pack->count << endl;
			show_menu();
			int _switch = 0;
			int _ind = 0;
			do
			{
				cin >> _switch;
			} while (check_input());
			switch (_switch)
			{
			case 1:
				show_letter_box(_pack);
				break;
			case 2:
				expand_letter_box(_pack);
				add_letter_into_box(_pack);
				break;
			case 3:
				cout << "Введите имя отправителя" << endl;
				char buff[100];
				cin >> buff;
				_pack->find_by_sender(_pack, buff);
				break;
			case 4:
				sort_by_cost_increase(_pack);
				break;
			case 5:
				cout << "Введите индекс получателя" << endl;
				do
				{
					cin >> _ind;
				} while (check_input());
				filter_by_ind(_pack, _ind);
				break;
			default:
				_end_function = false;
				break;
			}
		} while (_end_function);
		save_box(_pack, _box);
	}
	else
	{
		int _end_control = 0;
		cout << ("Введите 0 для выхода из программы") << endl;
		do
		{
			cin >> _end_control;
		} while (check_input());
	}
}

