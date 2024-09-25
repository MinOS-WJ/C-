//$T0002.cpp$
# include <stdio.h>

void printSquile() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d––%d¡–\n", a, b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int main () {
	printSquile();
	return 0;
}