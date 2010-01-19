#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 210;
const int MAXM = 2 * MAXN;

int n, m;
int d[MAXN];
int l[MAXM][MAXN];

int start, end;
int C[MAXN+MAXM][MAXN+MAXM];
vector<int> G[MAXN+MAXM];
int vis[MAXN+MAXM], mark;

int dfs(int v, int end) {
	if (vis[v]==mark) return 0;
	vis[v] = mark;
	if (v == end) return 1;
	for (int i = 0; i < G[v].size(); ++i) {
		int u = G[v][i];
		if (C[v][u]>0) {
			if (dfs(u,end)) {
				//printf("> %d\n", u);
				C[v][u]--;
				C[u][v]++;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	freopen("show.in","r",stdin);
	freopen("show.out","w",stdout);

	memset(vis,0,sizeof vis);
	memset(C,0,sizeof C);
	mark = 1;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", &d[i]);

	scanf("%d", &m);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &l[i][j]);
			if (l[i][j] == d[j]) {
				G[i].push_back(m+j);
				G[m+j].push_back(i);
				C[i][m+j] = 1;
			}
		}
	}


	start = m+n;
	end = m+n+1;

	for (int i = 0; i < m; ++i) {
		G[start].push_back(i);
		G[i].push_back(start);
		C[start][i] = 1;
	}

	for (int i = m; i < m+n; ++i) {
		G[i].push_back(end);
		G[end].push_back(i);
		C[i][end] = 1;
	}

	int cnt = 0;
	while (dfs(start, end)==1) ++cnt, ++mark;

	if (cnt == n) {
		printf("YES\n");
		for (int i = m; i < m+n; ++i) {
			for (int j = 0; j < G[i].size(); ++j) {
				int k = G[i][j];
				if (C[i][k]>0) {
					printf("%d", k+1);
					if (i < m+n-1) printf(" ");
					break;
				}
			}
		}
		printf("\n");
	} else printf("NO\n");
	
	return 0;
}
