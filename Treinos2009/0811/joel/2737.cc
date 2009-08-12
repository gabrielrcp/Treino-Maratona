#include <cstdio>
#include <algorithm>
using namespace std;

struct P {
	int x,y;
	P(int x=0, int y=0) : x(x), y(y) {}
	bool operator<(const P& o) const {
		if (x != o.x) return x < o.x;
		return y < o.y;
	}
};

const int MAXN = 1010;

int n;
P p[MAXN];
int ord[MAXN];

int pvc(P& a, P& b, P& c) {
	int p = a.x * b.y + b.x * c.y + c.x * a.y;
	int n = a.y * b.x + b.y * c.x + c.y * a.x;
	return p - n;
}

P pivot;
bool cmp(const int a, const int b) {
	return pvc(pivot,p[a],p[b])<0;
}

int main() {
	int pho = 0;
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &p[i].x, &p[i].y);
		}

		sort(p,p+n);

		int res = 0;
		for (int i = 0; i < n; ++i) {
			int nn = n;
			for (int j = 0; j < nn; ++j) ord[j] = j;
			
			swap(p[i],p[0]);
			pivot = p[0];
			sort(ord+1, ord + nn, cmp);

			int cnt = 2;
			for (int j = 2; j < nn; ++j) {
				if (pvc(pivot,p[ord[j-1]], p[ord[j]]) == 0) ++cnt;
				else {
					res = max(res, cnt);
					cnt = 2;
				}
			}
			res = max(res,cnt);
			swap(p[i],p[0]);
		}

		printf("Photo %d: %d points eliminated\n", ++pho, res>3?res:0);
	}
	return 0;
}
