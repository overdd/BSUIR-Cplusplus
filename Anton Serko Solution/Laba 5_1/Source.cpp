#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<stdio.h>


using namespace std;

void diagonalElementsDivider(int**, int*, int*);	 
void  tablePrinter(int**, int*, int*);
void  horizontalLineTablePrinter(int**, int*);			//my_prt_strt(array, qty column);


int main()
{
	setlocale(LC_ALL, "Russian");
	int** arr;
	int n = NULL, m = NULL, inputFlag = NULL;

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


	if (!(arr = new int* [n]))
	{
		printf("Недостаточно памяти!\n");
		throw 1;
		exit(0);
	}
	for (int i = 0; i < n; i++)
	{
		if (!(*(arr + i) = new int[m]))
		{
			printf("Недостаточно памяти!\n");
			arr = NULL;
			throw 2;
			exit(0);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			*(*(arr + i) + j) = rand();
		}
	}

	diagonalElementsDivider(arr, &n, &m);

	tablePrinter(arr, &n, &m);	

	delete[]arr;
	system("pause");
}

void diagonalElementsDivider(int** arr, int* n, int* m) 
{
	int maxElement = *(*(arr + 0) + 0);	

	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *m; j++)
		{
			if (*(*(arr + i) + j) > maxElement)
			{
				maxElement = *(*(arr + i) + j);
			}
		}
	}
	printf("Максимальный элемент массива = %d\n", maxElement);

	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *m; j++)
		{
			if (i == j)
			{
				*(*(arr + i) + j) = *(*(arr + i) + j) / maxElement;
			}
		}
	}

	for (int i = 0; i < *n; i++)
	{
		for (int j = *m; j >= 0; j--)
		{
			if ((i + j == (*m-1)))
			{
					*(*(arr + i) + j) = *(*(arr + i) + j) / maxElement;
			}
		}
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