#include <cstdio>
#include <cstring>

int n;
char line[1010][1010];

int main() {
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; ++i) {
			scanf("%s", line[i]);
		}

		int len = strlen(line[0]);

		for (int j = len - 1; j >= 0; --j) {
			for (int i = n - 1; i >= 0; --i) {
				if (j == 0) {
					bool ok = false;
					for (int k = i; k >= 0; --k) {
						if (line[k][j] != '_' && line[k][j] != '\\') {
							ok = true;
							break;
						}
					}
					if (!ok) break;
				}
				if (line[i][j] == '\\') {
					putchar('\n');
				} else if (line[i][j] == '_') {
					putchar(' ');
				} else {
					putchar(line[i][j]);
				}
			}
		}
		puts("\n");
	}
	return 0;
}
