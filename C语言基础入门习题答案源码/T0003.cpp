//$T0003.cpp$
#include <stdio.h>// �ݹ麯������ x �� n �η�

double power(double x, int n) {
	// ���������n Ϊ 0 ʱ������ 1
	if (n == 0)
		return 1;
	// �ݹ��������� n Ϊ������ת��Ϊ�������������
	else if (n < 0)
		return 1 / power(x, -n);
	// �ݹ���� (x �� n-1 �η�) * x
	else
		return x * power(x, n - 1);
}

int main() {
	double x;
	int n;
	// ���� x �� n
	printf("������һ������ x: ");
	scanf("%lf", &x);
	printf("������һ��ָ���������� n: ");
	scanf("%d", &n);
	// ���� x �� n �η�
	double result = power(x, n);
	// ������
	printf("%.2lf �� %d �η��� %.2lf\n", x, n, result);
	return 0;
}