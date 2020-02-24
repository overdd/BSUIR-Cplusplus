#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <ctime> 

using namespace std;

int n, counter, * mA, b, sumA, m, * arrayForBubbleSorting, * arrayForHoarSorting;
int arrayHandler(int a[]);
void bubbleSorter(int*, int);
void hoarSorter(int*, int, int);

int main() {
	setlocale(LC_ALL, "Russian");

enter: printf("Введите количество значений в массиве: ");
	scanf("%d", &n);
	mA = (int*)(malloc(n * sizeof(int)));
	if (!mA) {
		printf("Память перегружена! \nВведите количество значений в массиве повторно\n");
		goto enter;
	};


	printf("Введите элемент массива:\n");
	for (int i = 0; i < n; i++) {
		printf("[%d] = ", i);
		scanf("%d", &mA[i]);
	};

	arrayHandler(mA);
	printf("Сумма элементов массива после последнего отрицательного элемента = %d \n", sumA);

	printf("Введите количество элементов массива для сортировки: ");
	scanf("%d", &m);
	arrayForBubbleSorting = new int[m];
	arrayForHoarSorting = new int[m];
	if (!arrayForBubbleSorting || !arrayForHoarSorting)
	{
		printf("Память перегружена! \nВведите количество значений в массиве повторно\n");
		goto enter;
	}
	for (int i = 0; i < m; i++)							//Автоматическое заполнение массива
	{
		*(arrayForBubbleSorting + i) = rand();
		*(arrayForHoarSorting + i) = rand();
	}


	int start_time_bubble = clock();
	bubbleSorter(arrayForBubbleSorting, m);
	int end_time_bubble = clock();
	printf("Время выполнения сортировки методом пузырька	=	%d\n", end_time_bubble - start_time_bubble);
	int start_time_hoar = clock();
	hoarSorter(arrayForHoarSorting, 0, m - 1);
	int end_time_hoar = clock();
	printf("Время выполнения сортировки методом Хоара	=	%d\n", end_time_hoar - start_time_hoar);

	delete[]arrayForBubbleSorting;
	delete[]arrayForHoarSorting;
	system("pause");

}


void bubbleSorter(int* arr, int m)
{
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = (m - 1); j > i; j--)		
		{
			if (*(arr + j - 1) > * (arr + j))		
			{
				int temp = *(arr + j - 1);		
				*(arr + j - 1) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}

void hoarSorter(int* s_arr, int first, int last)
{
	int i = first, j = last, x = s_arr[(first + last) / 2];

	do {
		while (s_arr[i] < x) i++;
		while (s_arr[j] > x) j--;

		if (i <= j) {
			if (s_arr[i] > s_arr[j]) swap(s_arr[i], s_arr[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		hoarSorter(s_arr, i, last);
	if (first < j)
		hoarSorter(s_arr, first, j);
}



//void hoarSorter(int* arr, int n0, int m)
//{
//	int i = n0, j = m, d;
//	int a = *(arr + (n0 + m) / 2);
//	while (i <= j) {
//		for (; *(arr + i) < a; i++);
//		{
//			for (; *(arr + j) > a; j--);
//			{
//				if (i <= j)
//				{
//					d = *(arr + i);
//					*(arr + i++) = *(arr + j);
//					*(arr + j--) = d;
//				}
//			}
//		}
//	}
//	if (n0 < j)
//	{
//		hoarSorter(arr, n0, j);
//	}
//	if (i < m)
//	{
//		hoarSorter(arr, i, m);
//	}
//
//	for (int i = 0; i < m; i++) {
//		printf("%d \n", arr[i]);
//	};
//}

int arrayHandler(int mA[]) {

	int lastNegativeIndex = 0;
	sumA = 0;
	for (int i = 0; i < n; i++) {
		if (mA[i] < 0) {
			lastNegativeIndex = i; 
		};
	}
	for (int i = lastNegativeIndex + 1; i < n; i++) {
		sumA = sumA + mA[i];
	}
	return sumA;
}