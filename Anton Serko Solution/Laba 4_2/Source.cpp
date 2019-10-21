#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <stdio.h>
#include <array>

using namespace std;

int n, counter, *a, b, sumA;
int arrayHandler(int a[]);

int main() {
	setlocale(LC_ALL, "Russian");

	enter: printf("Введите количество значений в массиве :");
		cin >> n;
		a = (int*)(malloc(n * sizeof(int)));
		if (!a) {
			printf("Память перегружена! \nВведите количество значений в массиве А и массиве В повторно\n");
			goto enter;
		};

	
	printf("Введите элемент массива:\n");
	for (int i = 0; i < n; i++) {
		printf("[%d] =", i);
		cin >> a[i];
	};
	
	arrayHandler(a);
	printf("Сумма элементов массива после последнего отрицательного элемента = %d \n", sumA);
	system("pause");
	return 0;
}

int arrayHandler(int a[]) {
		// сначала найдем индекс последнего отрицательного элемента
	int lastNegativeIndex = 0;
	sumA = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			lastNegativeIndex = i;   // !!!!!!!!! нужно предусмотреть случай, если у массива нет отрицательных элементов
		};
	// теперь суммируем все элементы после последнего отрицательного значения
	}
	for (int i = lastNegativeIndex+1; i < n; i++) {
		sumA = sumA + a[i];
	}
	return sumA;
}