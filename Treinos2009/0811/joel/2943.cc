#include <cstdio>
#include <cstring>

const int MAXN = 310;

int n, m, k[MAXN];
char mat[MAXN][MAXN];

int main() {

	while (scanf("%d %d", &n, &m) == 2 && (n + m)) {
		memset(mat,0,sizeof mat);
		for (int i = 0; i < m; ++i) {
			scanf("%d", &k[i]);
			for (int l = 0; l < k[i]; ++l) {
				int x;
				scanf("%d", &x);
				mat[i][x-1] = 1;
			}
		}

		int res = 0;
		for (int i = 0; i < m; ++i) {
			char mark[MAXN];
			memset(mark,0,sizeof mark);
			for (int j = 0; j < m; ++j) if (j != i) {
				int ok = 1;
				if (memcmp(mat[j],mat[i],sizeof mark)==0) { if (j < i) continue; memcpy(mark,mat[i],sizeof mark); break; }
				for (int l = 0; l < n; ++l) {
					if (mat[j][l] == 1 && mat[i][l] == 0) { ok = false; break; }
				}
				if (ok) {
					for (int l = 0; l < n; ++l) mark[l] |= mat[j][l];
				}
			}

			int ok = 1;
			for (int l = 0; l < n; ++l) {
				if (mark[l] != mat[i][l]) {
					ok = 0;
					break;
				}
			}

			if (ok) ++res;
		}

		printf("%d\n", res);
	}

	return 0;
}
