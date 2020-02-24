#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h> 
#include <math.h>
#include <process.h>
#include <locale.h>
#define EPS 1e-4 

void iterator(double, double*);
void splitter(double, double&);

double xi;
int ji;
double xs;
int ks;

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	system("cls");  fflush(stdin);
	double x1, x2, y1, y2, a, b, h;
	double& xl = x2;	
	int i;
	a = -4.;
	b = 0.;
	h = (b - a) / 20.;
	puts("----------------------------------------------------");
	puts("| Функция       ||   Y(x)   || Количество итераций");
	puts("====================================================");
	for (i = 0; i <= 20; i++)
	{
		x1 = a + i * h;
		x2 = a + (double(i) + 1) * h;
		y1 = sin(x1) * sin(x1) - x1 / 5 - 1;
		y2 = sin(x2) * sin(x2) - x1 / 5 - 1;
		if (fabs(y1 * y2) != y1 * y2)
		{
			printf("|	Для интервала [%lf,%lf]   	    |\n", x1, x2);
			puts("-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
			iterator(x1, &x2); 
			printf("| Iterator:	|| %8.5lf ||	%d	     	    |\n", xi, ji + 1);
			splitter(x1, xl);
			printf("| Splitter:	|| %8.5lf ||	%d	    	    |\n", xs, ks + 1);
			puts("=====================================================");
		}
	}
	system("pause");
}

void  iterator(double n, double* m)
{
	double a = n, b = *m, x1, x2, y1, y2;
	for (int j = 0; j <= (b - a) / EPS; j++)
	{
		x1 = a + j * EPS;
		x2 = a + (double(j) + 1) * EPS;
		y1 = sin(x1) * sin(x1) - x1 / 5 - 1;
		y2 = sin(x2) * sin(x2) - x2 / 5 - 1;
		if (fabs(y1 * y2) != y1 * y2)
		{
			xi = x1;
			ji = j;
		}
	}
}

void splitter(double n, double& m)
{
	double x1 = n, x2 = m, y1, y2, h;
	int k = 0;
	h = x2 - x1;
	do {
		y1 = sin(x1) * sin(x1) - x1 / 5 - 1;
		y2 = sin(x2) * sin(x2) - x1 / 5 - 1;
		if (fabs(y1 * y2) == y1 * y2)
		{
			x1 = x1 + h;
			xs = x1;
			ks = k;
		}
		++k;
		h = h / 2.;
		x2 = x1 + h;
	} while (h > EPS);
}