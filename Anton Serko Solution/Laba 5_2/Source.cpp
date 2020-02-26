#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<stdio.h>


using namespace std;

void arithmeticMeanOfColumnWithNegativeValue(int**, int*, int*);
void  tablePrinter(int**, int*, int*);
void  horizontalLineTablePrinter(int**, int*);			//my_prt_strt(array, qty column);

int main()
{
	setlocale(LC_ALL, "Russian");
	int** arr;
	int n = NULL, m = NULL, inputFlag = NULL, count = 0, errorKey = NULL;

	try
	{
		do {
			if (inputFlag == 1)
			{
				printf("Вы ввели не корректное кол-во строк.\n");
			}
			printf("Введите кол-во строк: ");
			scanf("%d", &n);
			inputFlag = 1;
		} while (n < 0);

		inputFlag = NULL;
		do {
			if (inputFlag == 1)
			{
				printf("Вы ввели не корректное кол-во столбцов.\n");
			}
			printf("Введите кол-во столбцов: ");
			scanf("%d", &m);
			inputFlag = 1;
		} while (m < 0);


		if (!(arr = (int**)malloc(sizeof(int*) * n)))
		{
			printf("Недостаточно памяти!\n");
			throw 1;
			exit(0);
		}
		for (int i = 0; i < n; i++)
		{
			if (!(*(arr + i) = (int*)malloc(sizeof(int*) * m)))
			{
				arr = NULL;
				throw 2;				//Бросаем ошибку 2
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("Введите значение № %2d (i=%d,j=%d): ", ++count, i, j);
				scanf("%d", &(*(*(arr + i) + j)));
			}
		}

		arithmeticMeanOfColumnWithNegativeValue(arr, &n, &m);

		tablePrinter(arr, &n, &m);

		free(arr);
	}
	catch (int e)						//Ловим ошибку
	{
		switch (e)						//Описание ошибок по коду
		{
		case 1:
			printf("\nError № %0*d: Exception occurred in function main(). Out of memory for array with %d elements.\n", errorKey, e, n);
			break;
		case 2:
			printf("\nError № %0*d: Exception occurred in function main(). Out of memory for array with %d elements.\n", errorKey, e, n * m);
			break;
		default:
			printf("error unknown\n"); break;
		}
	}
	system("pause");
}

void arithmeticMeanOfColumnWithNegativeValue(int** arr, int* n, int* m)
{
	for (int j = 0; j < *m; j++)
	{
		int count = 0, sum = 0;
		for (int i = 0; i < *n; i++)
		{
			if (*(*(arr + i) + j) < 0)
			{
				count++;
			}
			sum += *(*(arr + i) + j);
		}
		if (count >= 1)
			cout << "Среднее арифметическое столбца j= " << j << ": " << (double)sum / *n << endl;
	}

}


void  tablePrinter(int** arr, int* n, int* m)  //mytab(arr - array, n - qty rows or end row index, m - qty columns or end column index);
{
	//1)
	int a = 0, b = *m - 1;
	//2)
	//Beginning of table
	puts("");
	horizontalLineTablePrinter(arr, m);				//Printing horizontal line across width of table, beginning of table
	puts("");
	//Beginning of heading table
	printf("|arr[i][j]|[j= 0]|");	//Printing first column signature
	for (int k = 1; k < *m; k++)		//loop column
		printf("[j=%2d]|", k);		//Printing j-th column signature
	puts("");
	horizontalLineTablePrinter(arr, m);				//Printing horizontal line across width of table, underline of heading table
//End heading table
	puts("");
	//Beginning rows
	printf("|[i  =  0]|");				//Printing first line signature
	for (int i = 0; i < *n; i++)		//loop line
	{
		if (i != 0)
			printf("|[i  =%3d]|", i);	//Printing i-th line signature
		for (int j = 0; j < *m; j++)	//loop column in line
			printf(" %4d |", *(*(arr + i) + j)); //Printing (i,j)-th element array
//End rows
		puts("");
		horizontalLineTablePrinter(arr, m);			//Printing horizontal line across width of table, underline of row
		puts("");
	}
	puts("");
	//End table
}


//Function printing gorisontal line in table
void  horizontalLineTablePrinter(int** arr, int* m)  //mystrt(arr - array, m - qty column);
{
	try
	{
		if (*m < 0)				//Validating value 'm'
			throw 31;
		//=======================================================================
		printf("+---------");	//Width 1-th column
		for (int b = 0; b < *m; b++)
		{
			printf("+------");	//Width j-th column
		}
		printf("+");
		//=======================================================================
	}
	catch (int i)
	{
		int k = 4;
		printf("\nError № %0*d: Exception occurred in library (_my_lib_arr_p.lib) function ('mystrt'), value ", k, i);
		if (i == 31) 			//Error description
		{
			printf("'m'(%d) cannot less NULL!\n", i);
		}
		else
		{
			printf("error unknown\n");
		}
	}
}