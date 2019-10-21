#include<iostream> 
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double x, y, a, vi;
	entry: printf("Введите х:");
	cin >> x;
	printf("Введите y:");
	cin >> y;
	
	if (x == y || y == 0 || x == 0 || x+y == 0) {
		printf("Введенные значения x и y равны нулю или между собой. Просьба ввести значения заново\n");
		goto entry;
	}
	a = ((x - y) < (y - x)) ? (x - y) : (y - x);
	vi = a > 0 ? a : 0;
	printf("Нужно число - %.3lf", vi);
	system("pause");
	return 0;
}