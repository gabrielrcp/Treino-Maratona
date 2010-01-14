/****************** 
 * Problema:
 * Fonte:
 * Palavra-chave:
 *****************/

#include <set>
#include <map>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

#define all(x) x.begin(), x.end()
#define rep(i, N) for(int i=0;i<N;++i)
#define repd(i, N) for(int i=N-1;i>=0;--i)
#define rep3(i, j, N) for(int i=(j);i<(N);++i)
#define repd3(i, j, N) for(int i=(N)-1;i>=(j);--i)
#define foreach(it, cont) for(__typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); ++it)
#define size(x) (int((x).size()))

using namespace std;

typedef long long ll;

template <class T>
ostream& operator<<(ostream& stream, const vector<T>& v) {
    stream << size(v) << endl;
    rep(i, size(v)) {
        stream << v[i] << endl;
    }
    return stream;
}

template <class T>
istream& operator>>(istream& stream, vector<T>& v) {
    int N;
    stream >> N;
    v.resize(N);
    rep(i, size(v)) {
        stream >> v[i];
    }
    return stream;
}

void read_lines(vector<string>& v) {
	string tmp;
	int N;
	cin >> N;
	getline(cin, tmp);
	v.resize(N);
	rep(i, N) {
		getline(cin, v[i]);
	}
}

const int MAXN = 15;
const int MAXM = 25;
const int INF = 0x3f3f3f3f;

int n;
int th;
int g[MAXN][MAXN], gg[MAXN][MAXN];
int m;
int a[MAXM][3];
int vis[MAXN];
int can[MAXN][MAXN];

int main(void) {
	int T;
	cin >> T;
	rep(t, T) {
		scanf("%d", &m);

		memset(g,INF,sizeof g);
		rep(i,MAXN) g[i][i]=0;

		int res = 0;
		rep(i,m) {
			int u,v,l,c;
			scanf("%d %d %d %d", &u, &v, &l, &c);
			a[i][0] = u;
			a[i][1] = v;
			a[i][2] = c;
			g[u][v] = g[v][u] = l;
			res += c;
		}

		scanf("%d %d", &n, &th);

		int all_edges = (1<<m);
		rep(mask,all_edges) {
			int cost = 0;
			memset(can,0,sizeof can);
			memcpy(gg,g,sizeof gg);
			rep(j,m) {
				if (mask&(1<<j)) {
					cost += a[j][2];
					can[a[j][0]][a[j][1]] = can[a[j][1]][a[j][0]] = 1;
				} else {
					gg[a[j][0]][a[j][1]] = gg[a[j][1]][a[j][0]] = INF;
				}
			}
			if (cost < res) {
				rep(k,n) rep(i,n) rep(j,n) {
					if (gg[i][j]>gg[i][k]+gg[k][j]) {
						gg[i][j] = gg[i][k] + gg[k][j];
					}
				}
				int ok = 1;
				rep(i,n) rep(j,n) {
					if (i!=j && gg[i][j]>th) {
						ok = 0;
						i=j=n;
					}
				}
				if(ok) res = cost;
			}
		}

		printf("%d\n", res);
	}
	return 0;
}
