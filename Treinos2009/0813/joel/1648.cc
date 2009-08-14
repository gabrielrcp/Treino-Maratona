#include <cstdio>
#include <algorithm>
using namespace std;

struct P {
	double x, y;
	P(double x = 0, double y = 0) : x(x), y(y) { }
};

struct S {
	P a, b;
	S(P a = P(), P b = P()) : a(a), b(b) {}
	bool contain(P &p) {
		if (min(a.x,b.x) > p.x || p.x > max(a.x,b.x)) return false;
		if (min(a.y,b.y) > p.y || p.y > max(a.y,b.y)) return false;
		return true;
	}
};

struct L {
	double X, Y, W;
	L(P a = P(), P b = P()) {
		W = a.x * b.y - a.y * b.x;
		X = a.y - b.y;
		Y = -(a.x - b.x);
	}
	bool inter(L l, P& p) {
		double x = Y * l.W - W * l.Y;
		double y = -(X * l.W - W * l.X);
		double w = X * l.Y - Y * l.X;

		if (w == 0) return false;
		p = P(x/w,y/w);
		return true;
	}
};

int n, w, e;

int onSeg(S s) {
	P p;
	L l1(P(0,w), P(100*n, e)), l2(s.a, s.b);

	if (l1.inter(l2, p)) {
		if (s.contain(p)) return 1;
	}

	return 0;
}

int inside(int x1, int y1, int x2, int y2, int x, int y) {
	if (x1 > x || x > x2) return 0;
	if (y1 > y || y > y2) return 0;
	return 1;
}

bool estate(int i, int j) {
	int x1 = i * 100, x2 = (i+1) * 100;
	int y1 = j * 100, y2 = (j+1) * 100;
	int cnt = 0;

	cnt += onSeg(S(P(x1,y1),P(x1,y2)));
	cnt += onSeg(S(P(x1,y2),P(x2,y2)));
	cnt += onSeg(S(P(x2,y1),P(x2,y2)));
	cnt += onSeg(S(P(x1,y1),P(x2,y1)));
	cnt += inside(x1,y1,x2,y2,0,w);
	cnt += inside(x1,y1,x2,y2,n*100,e);

	return cnt > 0;
}

int main() {

	scanf("%d %d %d", &n, &w, &e);

	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			res += estate(i,j);
		}
	}

	printf("%d\n", res);

	return 0;
}
