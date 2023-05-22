#include <stdio.h>

int main() {
	double a = 1.5;
	float b = a;
	int c = b;
	long d = c;

	printf("a = %lf\n", a);
	printf("b = %f\n", b);
	printf("c = %d\n", c);
	printf("d = %ld\n", d);
}