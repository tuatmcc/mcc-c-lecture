#include <stdio.h>
#include <stdlib.h>

typedef struct Point2D {
	int x, y;
} Point2D;


int main() {
	int length;

	printf("Input lenght: ");
	scanf("%d", &length);

	Point2D *p = (Point2D *)malloc(sizeof(Point2D) * length);
	
	for (int i = 0; i < length; i++){
		p[i].x = i;
		p[i].y = 2 * i;
	}

	for (int i = 0; i < length; i++){
		printf("p[%d].x = %d, p[%d].y = %d\n", i, p[i].x, i, p[i].y);
	}

	free(p);
}