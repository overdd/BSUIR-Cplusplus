#include<iostream> 
using namespace std;

int main(){
	setlocale (LC_ALL, "Russian");
	double z1, z2, x, y;
	printf("¬ведите переменную х:");
	cin >> x;
	printf("¬ведите переменную y:");
	cin >> y;
	z1 = pow(cos(x), 4) + pow(sin(y), 2) + (pow(sin(2 * x), 2)) / 4 - 1;
	z2 = sin(y + x) * sin(y - x);
	printf("Z1 = %lf\n", z1);
	printf("Z2 = %lf\n", z2);
	system("pause");
	return 0;
}