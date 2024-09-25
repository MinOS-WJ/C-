//$T0003.cpp$
#include <stdio.h>// 递归函数计算 x 的 n 次方

double power(double x, int n) {
	// 基本情况：n 为 0 时，返回 1
	if (n == 0)
		return 1;
	// 递归情况：如果 n 为负数，转换为处理正数的情况
	else if (n < 0)
		return 1 / power(x, -n);
	// 递归计算 (x 的 n-1 次方) * x
	else
		return x * power(x, n - 1);
}

int main() {
	double x;
	int n;
	// 输入 x 和 n
	printf("请输入一个底数 x: ");
	scanf("%lf", &x);
	printf("请输入一个指数（整数） n: ");
	scanf("%d", &n);
	// 计算 x 的 n 次方
	double result = power(x, n);
	// 输出结果
	printf("%.2lf 的 %d 次方是 %.2lf\n", x, n, result);
	return 0;
}