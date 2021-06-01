#define _CRT_SECURE_NO_WARNINGS
#include "Letter.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std; 
Letter::Letter()
{
	this->cost = 0.0;
	this->ind_recipient = 0;
	this->count++;
}

Letter::~Letter()
{
	this->count--;
}

Letter::Letter(Letter& _obj)
{
	this->count++;
	this->cost = _obj.cost;
	this->ind_recipient = _obj.ind_recipient;
	this->recipient.set_adr(_obj.recipient.get_adr());
	this->recipient.set_name(_obj.recipient.get_name());
	this->sender.set_adr(_obj.sender.get_adr());
	this->sender.set_name(_obj.sender.get_name());
}

Letter::Letter(int& _ind_recipient, Man& _recipient, Man& _sender, double &_cost)
{
	this->ind_recipient = _ind_recipient;
	this->recipient.set_name(_recipient.name);
	this->recipient.set_adr(_recipient.adr);
	this->sender.set_name(_sender.name);
	this->sender.set_adr(_sender.adr);
	this->cost = _cost;
	this->count++;
}

Man& Letter::get_sender()
{
	return this->sender;
}

Man& Letter::get_recipient()
{
	return this->recipient;
}

double Letter::get_cost()
{
	return this->cost;
}

void Letter::set_cost(double _cost)
{
	this->cost = _cost;
}

void Letter::letter_print()
{
	cout << this->ind_recipient << setw(4) << this->get_recipient().get_name() << setw(4) << this->get_recipient().get_adr() << setw(4) << this->get_sender().get_name() << setw(4) << this->get_sender().get_name() << setw(4) << this->get_cost() << endl;
}

void Letter::find_by_sender(Letter* &_letter_box, char* _sender)
{
	bool check = false;
	int i = 0;
	do
	{
		if (strcmp(_letter_box->sender.get_name(), _sender) == 1)
		{
			check = true;
			_letter_box[i].letter_print();
			i++;
			//return _letter_box[i];
		}
	} while ((check == false) && (i < count));
	if (check == false)
		cout << "Писем по данному отправителю не найдено." << endl;
}