#include<iostream> 
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double c, k, t2;
entry: printf("������� c:");
	cin >> c;
	printf("������� k:");
	cin >> k;

	if (abs(c + k) > 2) {
		t2 = tan(c - 2 * k) * tan(c - 2 * k);
		printf("��� c=%.4lf � k=%.4lf ����� |c+k|>2 t2=%.4lf \n", c, k, t2);
	}
	else {
		if ((c + k) > 0.5 && (c + k) <= 2) {
			t2 = log(abs(c - 2 * k)) - sin(c / 2 * k);
			printf("��� c=%.4lf � k=%.4lf ����� 0.5<|c+k|<=2 t2=%.4lf \n", c, k, t2);
		}
		else
		{
			printf("��� c=%lf � k=%lf ������� �� ����� ������� \n", c, k);
			printf("������������� �� ������ ���������...\n");
			goto entry;
		}


	}
	system("pause");
	return 0;
}