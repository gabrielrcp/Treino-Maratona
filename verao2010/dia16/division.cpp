#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

const int MAXN = 110;
const int INF = 10010;

struct Point {
	int x,y;
	int id;
	Point(int x=0, int y=0, int id=0) : x(x), y(y), id(id) {}
	bool operator<(const Point& other) const {
		if (x!=other.x) return x<other.x;
		return y<other.y;
	}
};

int n;
Point p[MAXN];
int par[MAXN][MAXN][2];
int dp[MAXN][MAXN][MAXN];
int sol[MAXN][MAXN][MAXN];

int pvc(Point& a, Point& b, Point& c) {
	assert(a.x!=b.x);
	int p = a.x*b.y+b.x*c.y+c.x*a.y;
	int n = a.y*b.x+b.y*c.x+c.y*a.x;
	return p-n;
}

int main() {
	freopen("division.in", "r", stdin);
	freopen("division.out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].id = i + 1;
	}

	sort(p,p+n);

	memset(dp,0,sizeof dp);
	memset(sol,-1,sizeof sol);

	for (int i = 0; i < n; ++i) {
		Point pp(-INF,p[i].y);
		int a = 0, b = 0;
		for (int j = 0; j < i; ++j) {
			if (p[j].x>=p[i].x) break;
			int v = pvc(pp,p[i],p[j]);
			if (v>0) ++a;
			else if (v<0) ++b;
		}
		dp[i][a][b] = 1;
		sol[i][a][b] = -2;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (p[i].x==p[j].x) continue;
			int a = 0, b = 0;
			for (int k = 0; k < i; ++k) {
				if (p[k].x < p[j].x) continue;
				if (p[k].x >= p[i].x) continue;
				int v = pvc(p[j],p[i],p[k]);
				if (v>0) ++a;
				else if (v<0) ++b;
			}
			par[j][i][0] = a;
			par[j][i][1] = b;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (p[i].x==p[j].x) continue;
			for (int a = 0; a <= j; ++a) {
				for (int b = 0; b <= j - a; ++b) {
					if (dp[j][a][b]) {
						int aa = a + par[j][i][0];
						int bb = b + par[j][i][1];
						if (!dp[i][aa][bb]) {
							dp[i][aa][bb] = 1;
							sol[i][aa][bb] = j;
						}
					}
				}
			}
		}
	}

	int fim, A,B,diff = n+1;
	for (int i = 0; i < n; ++i) {
		Point pp(INF,p[i].y);
		int aa = 0, bb = 0;
		for (int j = 0; j < n; ++j) {
			if (p[j].x<p[i].x) continue;
			int v = pvc(p[i],pp,p[j]);
			if (v>0) ++aa;
			else if (v<0) ++bb;
		}
		for (int a = 0; a <= n; ++a) {
			for (int b = 0; b <= n; ++b) {
				if (dp[i][a][b]) {
					int v1 = a + aa;
					int v2 = b + bb;
					int v3 = n - v1 - v2;
					int v = max(v1,max(v2,v3))-min(v1,min(v2,v3));
					if (v < diff) {
						diff = v;
						fim = i;
						A = a;
						B = b;
					}
				}
			}
		}
	}

	set<Point> v;

	for (int i = fim; i < n; ++i) {
		if (p[i].y == p[fim].y) {
			v.insert(p[i]);
		}
	}

	while (1) {
		v.insert(p[fim]);
		int j = sol[fim][A][B];
		if (j==-2) {
			for (int i = 0; i < n; ++i) {
				if (p[i].y == p[fim].y && p[i].x <= p[fim].x) {
					v.insert(p[i]);
				}
			}
			break;
		}
		for (int i = 0; i < n; ++i) {
			if (pvc(p[j],p[fim],p[i])==0 && p[j].x<=p[i].x && p[i].x<=p[fim].x) {
				v.insert(p[i]);
			}
		}
		A -= par[j][fim][0];
		B -= par[j][fim][1];
		fim = j;
	}

	printf("%d\n", v.size());

	for (set<Point>::iterator it = v.begin(); it != v.end(); ++it) printf("%d ", it->id); puts("");

	return 0;
}
