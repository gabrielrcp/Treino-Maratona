#include <cstdio>
#include <vector>
#include <cstring>
#include <cassert>
using namespace std;

const int MAXN = 55;
const int INF = 0x3f3f3f3f;

int idx(char c) {
	if (c>='a') return c - 'a';
	return c - 'A' + 26;
}

int n, m;
vector<int> g[MAXN];
char gg[MAXN][MAXN];
int p;
char start,end;

int go() {
	int d[MAXN];
	char vivo[MAXN];
	memset(d,0x3f,sizeof d);
	memset(vivo,1,sizeof vivo);
	d[end] = p;
	while (1) {
		int v = -1;
		for (int i = 0; i < MAXN; ++i) {
			if (vivo[i] && (v==-1 || d[v]>d[i])) {
				v = i;
			}
		}
		if (v==-1 || d[v]==INF) break;
		if (v == start) return d[v];
		vivo[v] = 0;
		for (int i = 0; i < g[v].size(); ++i) {
			int u = g[v][i];
			int tmp = (d[v]*20+18)/19;
			if (v<26) tmp = d[v]+1;
			else {
				while (1) { 
					int aux = tmp - (tmp+19)/20; 
					if (aux > d[v]) --tmp; 
					else if (aux < d[v]) tmp++; 
					else break; 
				}
			}
			if (d[u]>tmp) {
				d[u] = tmp;
			}
		}
	}
	assert(0);
	return -1;
}

int main() {
	freopen("toll.in", "r", stdin);
	freopen("toll.out", "w", stdout);

	int test = 0;

	while (scanf("%d", &m) == 1 && m != -1) {
		n = MAXN;

		for (int i = 0; i < n; ++i) g[i].clear();

		memset(gg,0,sizeof gg);
		for (int i = 0; i < m; ++i) {
			char a,b;
			scanf(" %c %c", &a, &b);
			a = idx(a);
			b = idx(b);
			if (gg[a][b]) continue;
			gg[a][b] = gg[b][a] = 1;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		scanf("%d %c %c", &p, &start, &end);

		start = idx(start);
		end = idx(end);

		printf("Case %d: %d\n", ++test, go());
	}

	return 0;
}
