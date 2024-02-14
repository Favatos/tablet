#include <iostream>
#include <string>
using namespace std;

/*Написать свою лямбда-функцию, принимающую
два параметра - ширина и высота таблички.
На табличке надпись:

******************************
*                            *
*     разыскивается          *
*    Маленькая Разбойница    *
*                            *  
******************************

(имя взято из внешней переменной
без возможности модификации)
Нужно запоминать, сколько табличек
напечатано.*/


int main() {
	setlocale(LC_ALL, "RU");

	string text = "Табличка";
	int counter = 0;

	auto print{ [&counter, text](int width, int length) {
		counter++;
		cout << string(width, '*') << endl;

		for (int i{ 0 }; i < length - 2; i++) {
			if (i==(length-2)/2) {
				string space = string(((width - text.length()) / 2)-1, ' ');
				cout << '*' << space << text << space + string((width - text.length()) % 2, ' ') << '*' << endl;
			}
			else{
				cout << '*' << string(width - 2, ' ') << '*' << endl;
			}
		}

		cout << string(width, '*') << endl;
		cout << "Всего напечатано табличек: " << counter << endl;
		} };

	print(27, 7);
	print(24, 5);

	return 0;
}