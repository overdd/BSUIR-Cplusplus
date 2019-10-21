#include<iostream> 
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double x, z, y;
	int count;
	
	enterz: printf("Введите значение z:");
	cin >> z;
	if (z == -1.5) { 
		printf("Введено некорретное значение! Прошу повторить ввод!\n");
		goto enterz;
	} 
	if (z < -1) {
		count = 1;
		x = -(z/3.0);
	}
	else {
		count = 9;
		x = abs(z);
	}
	y = log(x + 0.5) + (exp(x) + exp(-x));
	printf("Результат y= %.3lf\n", y);
	(count == 1) ? printf("Введенное значение Z<-1\n") : printf("Введенное значение Z>=-1\n");
	   
	system("pause");
	return 0;
}