#include<iostream> 
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	float x, y, z, fi, fi1, fi2;
	x = -0.0235;
	y = 2.23;
	z = 15.221;
	fi1 = (exp(abs(x - y)) * pow(abs(x - y), (x + y))) / (atan(x) + atan(z));
	fi2 = pow((pow(x, 6) + pow(log(y), 2)), 1. / 3);
	fi = fi1 + fi2;
	printf("Fi = %lf\n", fi);
	system("pause");
	return 0;
}