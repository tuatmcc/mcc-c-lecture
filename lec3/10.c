struct Point2D {
	int x, y;
};
typedef struct Point2D P2D;

typedef struct Point3D {
	int x, y, z;
} P3D;

typedef struct Vec2D {
	int x, y;
} Vec2D;

typedef struct Line2D {
	P2D from, to;
} Line2D;

int main() {
	struct Point2D p0;
	P2D p1;
	
	struct Point3D p2;
	P3D p3;

	Vec2D v0;

	Line2D line;
}