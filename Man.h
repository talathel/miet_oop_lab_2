#pragma once
class Man
{
private:
	char* adr; // Адрес
	char* name; // Имя
public:
	// Конструктор
	Man(); 
	// Деструктор
	~Man(); 
	// Конструктор копирования
	Man(const Man& _obj);
	// Метод получения адреса
	char* get_adr(); 
	// Метод получения имени
	char* get_name(); 
	// Установка адреса
	void set_adr(char* _adr); 
	// Установка имени
	void set_name(char* _name);

	friend class Letter;
};