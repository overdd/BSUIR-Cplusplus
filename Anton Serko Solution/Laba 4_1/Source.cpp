#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
using namespace std;

int n, m, counter, sumA, sumB, * mA, * mB;
int arrayHandler(int a[], int b[]);

int main() {
	setlocale(LC_ALL, "Russian");

enter: printf("������� ���������� �������� � ������� �:");
	scanf("%d", &n);
	printf("������� ���������� �������� � ������� b:");
	scanf("%d", &m);
	mA = (int*)(malloc(n * sizeof(int)));
	mB = (int*)(malloc(m * sizeof(int)));
	if (!mA || !mB) {
		printf("������ �����������! \n������� ���������� �������� � ������� � � ������� � ��������\n");
		goto enter;
	};
	//int a[3] = { 1, 2, 3 };
	//int b[4] = { 1, 45, 2, -1 };

	printf("������� ������� ������� �:\n");
	for (int i = 0; i < n; i++) {
		printf("[%d] = ", i);
		scanf("%d", &mA[i]);
	};
	printf("������� ������� ������� B:\n");
	for (int i = 0; i < m; i++) {
		printf("[%d] =", i);
		scanf("%d", &mB[i]);
	};
	arrayHandler(mA, mB);
	printf("������� ������ � ���������� ����������� ������������� ���������, ���� �� ���������: \n");
	switch (counter)
	{
	case 1: {
		printf("������ ������� ������ �. � ��� %d ������������� ��������� \n", sumA);
		for (int i = 0; i < n; i++) {
			printf("a[%d] = %d \n", i, mA[i]);
		};
		printf("� ������ ������ �. � ��� %d ������������� ��������� \n", sumB);
		for (int i = 0; i < m; i++) {
			printf("b[%d] = %d \n", i, mB[i]);
		};
		break;
	};
	case 0: {
		printf("������ ������� ������ B. � ��� %d ������������� ��������� \n", sumB);
		for (int i = 0; i < m; i++) {
			printf("b[%d] = %d \n", i, mB[i]);
		};
		printf("� ������ ������ A. � ��� %d ������������� ��������� \n", sumA);
		for (int i = 0; i < n; i++) {
			printf("a[%d] = %d \n", i, mA[i]);
		};
		break;
	case 9: {
		printf("��� ������� �������� ���������� ���������� ������������� ���������. ������ ������� ��� �������.\n");
		for (int i = 0; i < n; i++) {
			printf("a[%d] = %d \n", i, mA[i]);
		};
		for (int i = 0; i < m; i++) {
			printf("b[%d] = %d \n", i, mB[i]);
		};
	}
	}
		  system("pause");
		  return 0;
	}
}
int arrayHandler(int a[], int b[]) {
	for (int i = 0; i < n; i++) {
		(a[i] < 0) ? sumA = sumA + 1 : 0;
	};
	for (int i = 0; i < m; i++) {
		(b[i] < 0) ? sumB = sumB + 1 : 0;
	};
	if (sumA < sumB) {
		counter = 1;
	}
	else {
		counter = 0;
	};
	(sumA == sumB) ? counter = 9 : 0;
	return counter, sumA, sumB;
}