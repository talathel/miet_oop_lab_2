#include <iostream>
#include "Functions.h"
#include "Letter.h"
#include "Man.h"
#include <fstream>
#define path "data.txt"
#include <clocale>
using namespace std;
int Letter::count = 0; // Инициализация счетчика count
int main()
{
	setlocale(0, "");
	fstream _box;
	Letter* box = NULL;
	control_work(box, _box);
	return 0;
}