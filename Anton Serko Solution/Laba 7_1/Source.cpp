#include <iostream>
#include <locale>
#include<stdio.h>
#include<io.h>
#include <stdlib.h>
#include <windows.h>


using namespace std;
#pragma warning(disable:4996);


void menu() {
	printf("Меню программы:\n");
	printf("1 – Сформировать с клавиатуры строку  и записать в файл (строка может содержать пробелы);\n");
	printf("2 –  Считать строку из файла и распечатать;\n");
	printf("3 – Зашифровать строку и записать в файл;\n");
	printf("4 – Расшифровать строку и записать в файл;\n");
	printf("5 – Выход.\n");



}
void menuSection1()
{
	char stringInputed[255];
	printf("Введите строку:\n");
	fflush(stdin);
	SetConsoleCP(1251);
	gets_s(stringInputed);
	gets_s(stringInputed);
	FILE* fileWithInput = fopen("input.txt", "w+");
	if (fileWithInput == NULL)
	{
		printf("Файл открыть невозможно.\n");
		exit(1);
	}
	SetConsoleCP(866);
	fprintf(fileWithInput, stringInputed);
	fclose(fileWithInput);
}
void menuSection2()
{
	FILE* fileWithInput = fopen("input.txt", "r");
	if (fileWithInput == NULL)
	{
		printf("Файл открыть невозможно.\n");
		exit(1);
	}
	printf("Содержимое файла:\n");
	char ch;
	ch = getc(fileWithInput);
	while (ch != EOF)
	{
		putchar(ch);
		ch = getc(fileWithInput);
	}
	fclose(fileWithInput);
	printf("\n");

}
void menuSection3()
{
	char stringToBeEncrypted[255], ch, stringEncrypted[1000];
	int i = 0, j = 0;
	FILE* fileWithInput = fopen("input.txt", "r+");
	if (fileWithInput == NULL)
	{
		printf("Файл открыть невозможно.\n");
		exit(1);
	}

	SetConsoleCP(866);
	ch = getc(fileWithInput);
	for (int i = 0; i < 255; i++) { stringToBeEncrypted[i] = NULL; } //очищаем от мусора
	while (ch != EOF) {
		stringToBeEncrypted[i] = ch;
		i++;
		j = i;// количество символов в строке
		ch = getc(fileWithInput);

	}

	cout << stringToBeEncrypted;
	printf("\n");
	fclose(fileWithInput);
	for (int i = 0; i < 1000; i++) { stringEncrypted[i] = NULL; }
	for (i = j = 0;i <= sizeof(stringToBeEncrypted) + 1;i++)
	{
		if (stringToBeEncrypted[i] == 'а' || stringToBeEncrypted[i] == 'А' || stringToBeEncrypted[i] == 'е' || stringToBeEncrypted[i] == 'Е' || stringToBeEncrypted[i] == 'ё' || stringToBeEncrypted[i] == 'Ё' || stringToBeEncrypted[i] == 'и' || stringToBeEncrypted[i] == 'И' || stringToBeEncrypted[i] == 'о' || stringToBeEncrypted[i] == 'О' || stringToBeEncrypted[i] == 'у' || stringToBeEncrypted[i] == 'У' || stringToBeEncrypted[i] == 'ы' || stringToBeEncrypted[i] == 'Ы' || stringToBeEncrypted[i] == 'э' || stringToBeEncrypted[i] == 'Э' || stringToBeEncrypted[i] == 'ю' || stringToBeEncrypted[i] == 'Ю' || stringToBeEncrypted[i] == 'я' || stringToBeEncrypted[i] == 'Я')
		{
			stringEncrypted[j] = stringToBeEncrypted[i];
			stringEncrypted[j + 1] = 'л';
			stringEncrypted[j + 2] = 'а';
			j = j + 3;
		}
		else {
			stringEncrypted[j] = stringToBeEncrypted[i];
			j = j + 1;
		}
	}


	printf("Зашифрованная строка: %s \n", stringEncrypted);
	FILE* fileEncrypted = fopen("cript.txt", "w+");
	if (fileEncrypted == NULL)
	{
		printf("Файл открыть невозможно.\n");
		exit(1);
	}
	fputs(stringEncrypted, fileEncrypted);
	printf("Строка зашифрована и записана в файл\n");
	fclose(fileEncrypted);

}
void menuSection4()
{
	char stringEncrypted[255], ch, stringDecrypted[255];
	int i = 0, j = 0, k = 0;
	FILE* fileWithEncrypted = fopen("cript.txt", "r+");
	if (fileWithEncrypted == NULL)
	{
		printf("Файл открыть невозможно.\n");
		exit(1);
	}
	for (int i = 0; i < 255; i++) { stringEncrypted[i] = NULL; }
	SetConsoleCP(866);
	ch = getc(fileWithEncrypted);
	while (ch != EOF) {
		stringEncrypted[i] = ch;
		i++;
		j = i;// количество символов в строке
		ch = getc(fileWithEncrypted);

	}
	fclose(fileWithEncrypted);
	for (int i = 0; i < 255; i++) { stringDecrypted[i] = NULL; }

	for (j = 0; j <= sizeof(stringEncrypted + 3);)
	{
		if ((stringEncrypted[j] == 'л') && (stringEncrypted[j + 1] == 'а'))
		{
			j = j + 2;
		}
		else {
			stringDecrypted[k] = stringEncrypted[j];
			j++;
			k++;
		}
	}

	printf("Расшифрованная строка: %s \n", stringDecrypted);

	FILE* fileDecrypted = fopen("decript.txt", "w+");
	if (fileDecrypted == NULL)
	{
		printf("Файл открыть невозможно.\n");
		exit(1);
	}
	fputs(stringDecrypted, fileDecrypted);
	printf("Строка расшифрована и записана в файл\n");
	fclose(fileDecrypted);
}
void main()
{
#pragma warning(disable:4996);
	int n;
	setlocale(LC_ALL, "Rus");
inputPoint:
	menu();
	printf("Ваш выбор:");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
	{
		menuSection1();
		system("pause");
		system("cls");
		goto inputPoint;
		break;
	}
	case 2:
	{
		menuSection2();
		system("pause");
		system("cls");
		goto inputPoint;
		break;
	}
	case 3:
	{
		menuSection3();
		system("pause");
		system("cls");
		goto inputPoint;
		break;
	}
	case 4:
		menuSection4();
		system("pause");
		system("cls");
		goto inputPoint;
		break;
	case 5:
	{
		printf("Осуществляется выход из программы\n");
		system("pause");
		exit(1);
	}
	break;
	default:
		break;
	}
	system("pause");
}