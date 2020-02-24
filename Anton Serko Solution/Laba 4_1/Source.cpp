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

enter: printf("введите количество значений в массиве а:");
	scanf("%d", &n);
	printf("введите количество значений в массиве b:");
	scanf("%d", &m);
	mA = (int*)(malloc(n * sizeof(int)));
	mB = (int*)(malloc(m * sizeof(int)));
	if (!mA || !mB) {
		printf("память перегружена! \nвведите количество значений в массиве а и массиве в повторно\n");
		goto enter;
	};
	//int a[3] = { 1, 2, 3 };
	//int b[4] = { 1, 45, 2, -1 };

	printf("Введите элемент массива А:\n");
	for (int i = 0; i < n; i++) {
		printf("[%d] = ", i);
		scanf("%d", &mA[i]);
	};
	printf("Введите элемент массива B:\n");
	for (int i = 0; i < m; i++) {
		printf("[%d] =", i);
		scanf("%d", &mB[i]);
	};
	arrayHandler(mA, mB);
	printf("Выводим массив с наименьшим количеством отрицательных элементов, если он определен: \n");
	switch (counter)
	{
	case 1: {
		printf("Сейчас выведем массив А. В нем %d отрицательных элементов \n", sumA);
		for (int i = 0; i < n; i++) {
			printf("a[%d] = %d \n", i, mA[i]);
		};
		printf("А теперь массив Б. В нем %d отрицательных элементов \n", sumB);
		for (int i = 0; i < m; i++) {
			printf("b[%d] = %d \n", i, mB[i]);
		};
		break;
	};
	case 0: {
		printf("Сейчас выведем массив B. В нем %d отрицательных элементов \n", sumB);
		for (int i = 0; i < m; i++) {
			printf("b[%d] = %d \n", i, mB[i]);
		};
		printf("А теперь массив A. В нем %d отрицательных элементов \n", sumA);
		for (int i = 0; i < n; i++) {
			printf("a[%d] = %d \n", i, mA[i]);
		};
		break;
	case 9: {
		printf("Оба массива содержат одинаковое количество отрицательных элементов. Сейчас выведем оба массива.\n");
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