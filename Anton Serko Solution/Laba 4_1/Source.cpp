#include<iostream> 
using namespace std;

int n = 3, m = 4, counter, a, b, sumA, sumB;
int arrayHandler(int a[], int b[]);

int main() {
	setlocale(LC_ALL, "Russian");

//enter: printf("������� ���������� �������� � ������� �:");
//	cin >> n;
//	printf("������� ���������� �������� � ������� B:");
//	cin >> m;
	//a = (int*)(malloc(n * sizeof(int)));
	//b = (int*)(malloc(m * sizeof(int)));
	//if (!a || !b) {
	//	printf("������ �����������! \n������� ���������� �������� � ������� � � ������� � ��������\n");
	//	goto enter;
	//};
	int a[3] = {1, -2, 3};
	int b[4] = {1, 45, 2, 1};

	//printf("������� ������� ������� �:\n");
	//for (int i = 0; i < n; i++) {
	//	printf("[%d] =", i);
	//	scanf_s("[%d]", &a[i]);
	//};
	//printf("������� ������� ������� B:\n");
	//for (int i = 0; i < m; i++) {
	//	printf("[%d] =", i);
	//	scanf_s("[%d]", &b[i]);
	//};
	arrayHandler(a, b);
	printf("������� ������ � ���������� ����������� ������������� ���������, ���� �� ���������: \n");
	switch (counter)
	{
	case 1: {
			printf("������ ������� ������ �. � ��� %d ������������� ��������� \n", sumA);
			for (int i = 0; i < n; i++) {
				printf("a[%d] = %d \n", i, a[i]);
			};
		};
	case 0: {
		printf("������ ������� ������ B. � ��� %d ������������� ��������� \n", sumB);
		for (int i = 0; i < m; i++) {
			printf("b[%d] = %d \n", i, b[i]);
		};
	};
	case 9: {
			  printf("��� ������� �������� ���������� ���������� ������������� ���������. ������ ������� ��� �������.\n");
		  }
	}


	system("pause");

	return 0;
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