#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h> 
#include <math.h>
#include <process.h>
#include <locale.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, h, x, y, s, delta, pi;
	int n, k;
	pi = 3.14;
	system("cls");  fflush(stdin);
	printf("¬ведите начальное значение отрезка a:");
	scanf("%lf", &a);
	printf("¬ведите конечное значение отрезка b:");
	scanf("%lf", &b);
	printf("¬ведите шаг h:");
	scanf("%lf", &h);
	printf("¬ведите n:");
	scanf("%d", &n);
	printf("\n");
	puts("   x  |   S(x)   |   Y(x)  | |Y(x)-S(x)||");
	puts("----------------------------------------- ");
	x = a;
	while (x <= b) {
		s = 0.;
		for (k = 1; k <= n; k++) {
			s += (pow(-1, k) * cos(k * x) / (k * k));
		}
		y = ((x * x) - ((pi * pi) / 3)) / 4;

		delta = fabs(y - s);
		printf("\n %3.2lf | %8.5lf | %8.5lf|  %8.5lf  | \n", x, s, y, delta);
		x += h;
	}
	system("pause");
	return 0;
}