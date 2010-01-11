#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 210;
const int MAXB = 55;

const int INF = 0x3f3f3f3f;

struct P {
	int x,y;
	P(int x=0, int y=0) : x(x), y(y) {}
	P operator-(const P& o) const { return P(x-o.x,y-o.y); }
	double ang() const { return atan2(y,x); }
	bool operator<(const P& o) const { return ang() < o.ang(); }
	int operator%(const P& o) const { return x*o.y-y*o.x; }
};

int b,n;
P p[MAXN];
int area2[MAXN][MAXN];
int dp[MAXB][MAXN][MAXN];

bool left(const P& a, const P& b, const P& c) {
	int p = a.x*b.y+b.x*c.y+c.x*a.y;
	int n = a.y*b.x+b.y*c.x+c.y*a.x;
	return p-n<0;
}

int vai(int bb, int i, int j)
{
	if(bb == 0) return (i == j ? 0 : INF);
	if(bb == 1) return (i == j ? INF : area2[i][j]);
	int &r = dp[bb][i][j];
	if(r != -1) return r;
	r = INF;
	for(int k = i + 1; k+1 < j; k++)
		r = min(r, vai(bb-1, i, k) + area2[k+1][j]);
	return r;
}

int main() {

	while (scanf("%d %d", &b, &n) == 2 && (n+b)) {
		P o;

		scanf("%d %d", &o.x, &o.y);

		--n;

		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &p[i].x, &p[i].y);
			p[i] = (p[i]-o);
		}

		sort(p,p+n);

		for (int i = 0; i < n; ++i) p[i+n] = p[i];

		memset(area2,INF,sizeof area2);

		P aux[MAXN];
		int nn;
		for (int i = 0; i < 2*n; ++i) {
			area2[i][i] = INF;
			aux[0] = P(0,0);
			aux[1] = p[i];
			nn = 2;
			int tmp = 0;
			for (int j = i + 1; j<2*n && j < i+n; ++j) {
				while (nn>1 && left(aux[nn-2], aux[nn-1],p[j])) { tmp -= (aux[nn-2]%aux[nn-1]); --nn; }
				aux[nn++] = p[j];
				tmp += (aux[nn-2]%aux[nn-1]);
				if (left(aux[0],aux[1],aux[nn-1])) {area2[i][j] = INF; break;}
				else area2[i][j] = tmp;
				//for(int k=0;k<nn;++k)printf(">> %d %d\n", aux[k].x,aux[k].y);
				//printf("%d %d %d [%d]\n", i,j,tmp, nn);
			}
		}

		memset(dp,-1,sizeof dp);
		/*
		for (int i = 0;i<2*n;++i) 
			dp[0][i][i]=dp[0][i][i-1]=0;
		for (int bb = 1; bb <= b; ++bb) {
			for (int i = 0; i < n; ++i) {
				for (int j = i+1; j < i+n; ++j) {
					dp[bb][i][j] = dp[bb-1][i][j];
					for (int k = i; k < j; ++k) {
						dp[bb][i][j] = min(dp[bb][i][j], dp[bb-1][i][k-1] + area2[k][j]);
					}
				}
			}
		}
*/
		int res = INF;
		for (int i = 0; i < n; ++i) {
			res = min(res, vai(b, i, i+n-1));
		}

		printf("%.2f\n", res/2.0);
	}

	return 0;
}
