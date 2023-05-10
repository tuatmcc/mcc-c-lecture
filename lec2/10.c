#include <stdio.h>

int main(void)
{
	int a = 334;
	int *ap = 1919810;

	printf("a Address is %p\n", ap);
	printf("a = %d\n", a);

	*ap = 114514;

	printf("a = %d\n", a);
}