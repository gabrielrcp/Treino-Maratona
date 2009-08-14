#include <cstdio>
#include <queue>
#include <cstring>
#include <set>
#include <cctype>

using namespace std;

int n;

struct S {
	char g[8][8];
	int i,j;
	S(char gg[8][8], int ii, int jj) {
		i = ii; j = jj;
		memcpy(g,gg,sizeof g);
	}
	bool operator<(const S& o) const {
		if (i != o.i) return i < o.i;
		if (j != o.j) return j < o.j;
		return memcmp(g, o.g, sizeof g) < 0;
	}
};

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
#define valid(x,y) (x>=0 && x<n && y>=0 && y<n)

int bfs(S s) {
	queue< pair<int,S> > q;
	set<S> vis;

	q.push(make_pair(0,s));
	vis.insert(s);

	while (!q.empty()) {
		int c = q.front().first;
		s = q.front().second; q.pop();

		if (s.g[s.i][s.j] == 'E') return c;

		for (int d = 0; d < 4; ++d) {
			int ii = s.i + dx[d];
			int jj = s.j + dy[d];

			if (!valid(ii,jj)) continue;

			S ss(s.g, ii, jj);

			if (s.g[ii][jj] != '.') {
				if (vis.find(ss) == vis.end()) {
					q.push(make_pair(c+1,ss));
					vis.insert(ss);
				}
			}

			if (!isdigit(s.g[s.i][s.j])) continue;

			bool ok = 1;
			for (int k = 1; k <= s.g[s.i][s.j]-'0'; ++k) {
				int iii = s.i + k * dx[d], jjj = s.j + k * dy[d];
				if (!valid(iii,jjj) || s.g[iii][jjj] != '.') {
					ok = 0;
					break;
				}
				ss.g[iii][jjj] = 'x';
			}
			ss.g[s.i][s.j] = '.';

			if (ok && vis.find(ss) == vis.end()) {
				q.push(make_pair(c + 1, ss));
				vis.insert(ss);
			}
		}
	}

	return -1;
}

int main() {
	char g[8][8];
	int x, y;

	while (scanf("%d %d %d", &n, &x, &y) == 3 && (n+x+y)) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf(" %c", &g[i][j]);
			}
		}

		int res = bfs(S(g,x-1,y-1));
		if (res != -1) printf("%d\n", res);
		else puts("Impossible.");
	}

	return 0;
}
