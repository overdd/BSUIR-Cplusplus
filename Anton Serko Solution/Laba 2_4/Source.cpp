#include<iostream> 
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double x, y, a, vi;
	entry: printf("������� �:");
	cin >> x;
	printf("������� y:");
	cin >> y;
	
	if (x == y || y == 0 || x == 0 || x+y == 0) {
		printf("��������� �������� x � y ����� ���� ��� ����� �����. ������� ������ �������� ������\n");
		goto entry;
	}
	a = ((x - y) < (y - x)) ? (x - y) : (y - x);
	vi = a > 0 ? a : 0;
	printf("����� ����� - %.3lf", vi);
	system("pause");
	return 0;
}