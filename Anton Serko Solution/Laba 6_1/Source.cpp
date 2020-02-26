#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale>
#include <windows.h>
#include <string>
#include<iostream>
using namespace std;
using std::string;

using namespace std;
//Точка входа (Entry point) в программу
void charCreator(char* a, char* b, int n)
{
	for (int i = 0; i < n; i++)
		*(a + i) = *(b + i);
}
void charsSwapper(char* ch)
{

	string s, s1, s2, s3;
	s = (const char*)ch;
	if (s.length() != 0) {
		if (s.length() % 4 == 0) {
			s1 = s.substr(0, s.length() / 2);
			s2 = s.substr(s.length() / 2, s.length() / 2);
			s3 = s2.append(s1);
			cout << "Строка после преобразования: " << s3 << endl;
		}
		else {
			cout << "Строка не кратна 4-ем!\n";
		}

	}
	else
		cout << "Пустая строка!\n";

}
int main()
{
	setlocale(LC_ALL, "Russian");
	char str[256];
	printf("Введите строку:\n");
#pragma warning(disable:4996);
	SetConsoleCP(1251);
	fflush(stdin);
	gets_s(str);
	char* ch = new char[strlen(str - 1)];
	charCreator(ch, str, strlen(str) + 1);
#pragma warning(enable:4996);
	SetConsoleCP(866);
	charsSwapper(ch);
	delete[]ch;

	system("pause");
	return 0;
}