#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <stdio.h>
#include <array>

using namespace std;

int n, counter, *a, b, sumA;
int arrayHandler(int a[]);

int main() {
	setlocale(LC_ALL, "Russian");

	enter: printf("������� ���������� �������� � ������� :");
		cin >> n;
		a = (int*)(malloc(n * sizeof(int)));
		if (!a) {
			printf("������ �����������! \n������� ���������� �������� � ������� � � ������� � ��������\n");
			goto enter;
		};

	
	printf("������� ������� �������:\n");
	for (int i = 0; i < n; i++) {
		printf("[%d] =", i);
		cin >> a[i];
	};
	
	arrayHandler(a);
	printf("����� ��������� ������� ����� ���������� �������������� �������� = %d \n", sumA);
	system("pause");
	return 0;
}

int arrayHandler(int a[]) {
		// ������� ������ ������ ���������� �������������� ��������
	int lastNegativeIndex = 0;
	sumA = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			lastNegativeIndex = i;   // !!!!!!!!! ����� ������������� ������, ���� � ������� ��� ������������� ���������
		};
	// ������ ��������� ��� �������� ����� ���������� �������������� ��������
	}
	for (int i = lastNegativeIndex+1; i < n; i++) {
		sumA = sumA + a[i];
	}
	return sumA;
}