#include <iostream>
#include <locale>
#include<stdio.h>
#include<io.h>
#include <stdlib.h>
#include <windows.h>


using namespace std;
#pragma warning(disable:4996);


void menu() {
	printf("���� ���������:\n");
	printf("1 � ������������ � ���������� ������  � �������� � ���� (������ ����� ��������� �������);\n");
	printf("2 �  ������� ������ �� ����� � �����������;\n");
	printf("3 � ����������� ������ � �������� � ����;\n");
	printf("4 � ������������ ������ � �������� � ����;\n");
	printf("5 � �����.\n");



}
void menuSection1()
{
	char stringInputed[255];
	printf("������� ������:\n");
	fflush(stdin);
	SetConsoleCP(1251);
	gets_s(stringInputed);
	gets_s(stringInputed);
	FILE* fileWithInput = fopen("input.txt", "w+");
	if (fileWithInput == NULL)
	{
		printf("���� ������� ����������.\n");
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
		printf("���� ������� ����������.\n");
		exit(1);
	}
	printf("���������� �����:\n");
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
		printf("���� ������� ����������.\n");
		exit(1);
	}

	SetConsoleCP(866);
	ch = getc(fileWithInput);
	for (int i = 0; i < 255; i++) { stringToBeEncrypted[i] = NULL; } //������� �� ������
	while (ch != EOF) {
		stringToBeEncrypted[i] = ch;
		i++;
		j = i;// ���������� �������� � ������
		ch = getc(fileWithInput);

	}

	cout << stringToBeEncrypted;
	printf("\n");
	fclose(fileWithInput);
	for (int i = 0; i < 1000; i++) { stringEncrypted[i] = NULL; }
	for (i = j = 0;i <= sizeof(stringToBeEncrypted) + 1;i++)
	{
		if (stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�' || stringToBeEncrypted[i] == '�')
		{
			stringEncrypted[j] = stringToBeEncrypted[i];
			stringEncrypted[j + 1] = '�';
			stringEncrypted[j + 2] = '�';
			j = j + 3;
		}
		else {
			stringEncrypted[j] = stringToBeEncrypted[i];
			j = j + 1;
		}
	}


	printf("������������� ������: %s \n", stringEncrypted);
	FILE* fileEncrypted = fopen("cript.txt", "w+");
	if (fileEncrypted == NULL)
	{
		printf("���� ������� ����������.\n");
		exit(1);
	}
	fputs(stringEncrypted, fileEncrypted);
	printf("������ ����������� � �������� � ����\n");
	fclose(fileEncrypted);

}
void menuSection4()
{
	char stringEncrypted[255], ch, stringDecrypted[255];
	int i = 0, j = 0, k = 0;
	FILE* fileWithEncrypted = fopen("cript.txt", "r+");
	if (fileWithEncrypted == NULL)
	{
		printf("���� ������� ����������.\n");
		exit(1);
	}
	for (int i = 0; i < 255; i++) { stringEncrypted[i] = NULL; }
	SetConsoleCP(866);
	ch = getc(fileWithEncrypted);
	while (ch != EOF) {
		stringEncrypted[i] = ch;
		i++;
		j = i;// ���������� �������� � ������
		ch = getc(fileWithEncrypted);

	}
	fclose(fileWithEncrypted);
	for (int i = 0; i < 255; i++) { stringDecrypted[i] = NULL; }

	for (j = 0; j <= sizeof(stringEncrypted + 3);)
	{
		if ((stringEncrypted[j] == '�') && (stringEncrypted[j + 1] == '�'))
		{
			j = j + 2;
		}
		else {
			stringDecrypted[k] = stringEncrypted[j];
			j++;
			k++;
		}
	}

	printf("�������������� ������: %s \n", stringDecrypted);

	FILE* fileDecrypted = fopen("decript.txt", "w+");
	if (fileDecrypted == NULL)
	{
		printf("���� ������� ����������.\n");
		exit(1);
	}
	fputs(stringDecrypted, fileDecrypted);
	printf("������ ������������ � �������� � ����\n");
	fclose(fileDecrypted);
}
void main()
{
#pragma warning(disable:4996);
	int n;
	setlocale(LC_ALL, "Rus");
inputPoint:
	menu();
	printf("��� �����:");
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
		printf("�������������� ����� �� ���������\n");
		system("pause");
		exit(1);
	}
	break;
	default:
		break;
	}
	system("pause");
}