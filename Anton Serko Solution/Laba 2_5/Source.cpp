#include<iostream> 
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double c, k, t2;
entry: printf("Введите c:");
	cin >> c;
	printf("Введите k:");
	cin >> k;

	if (abs(c + k) > 2) {
		t2 = tan(c - 2 * k) * tan(c - 2 * k);
		printf("При c=%.4lf и k=%.4lf ветка |c+k|>2 t2=%.4lf \n", c, k, t2);
	}
	else {
		if ((c + k) > 0.5 && (c + k) <= 2) {
			t2 = log(abs(c - 2 * k)) - sin(c / 2 * k);
			printf("При c=%.4lf и k=%.4lf ветка 0.5<|c+k|<=2 t2=%.4lf \n", c, k, t2);
		}
		else
		{
			printf("При c=%lf и k=%lf функция не имеет решения \n", c, k);
			printf("Перенаправляю на начало программы...\n");
			goto entry;
		}


	}
	system("pause");
	return 0;
}