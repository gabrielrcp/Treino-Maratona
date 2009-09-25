#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXM = 30;
const int MAXN = 30;

int m, n;
int l[MAXM][MAXN], r[MAXM][MAXN];
int l2r[MAXM], r2l[MAXN];

char mans[MAXM], woms[MAXN];
int mmap[256], nmap[256];

void stable_marriage() {
	int p[128];
	memset(r2l, -1, sizeof r2l);
	memset(p, 0, sizeof p);

	for (int i = 0; i < m; ++i) {
		int man = i%n;
		while (man>=0) {
			int wom;
			while (p[man]<n) {
				wom = l[man][p[man]++];
				if (r2l[wom]<0 || r[wom][man]>r[wom][r2l[wom]]) break;
			}

			int hubby = r2l[wom];

			r2l[l2r[man] = wom] = man;

			man = hubby;
		}
	}
}

int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		scanf("%d", &n);
		m = n;

		for (int i = 0; i < m; ++i) {
			char ch;
			scanf(" %c", &ch);
			mans[i] = ch;
			mmap[ch] = i;
		}
		for (int i = 0; i < n; ++i) {
			char ch;
			scanf(" %c", &ch);
			woms[i] = ch;
			nmap[ch] = i;
		}

		for (int i = 0; i < m; ++i) {
			char ch1;
			scanf(" %c :",&ch1);
			for (int j = 0; j < n; ++j) {
				char ch2;
				scanf(" %c", &ch2);
				l[mmap[ch1]][j] = nmap[ch2];
			}
		}

		for (int i = 0; i < n; ++i) {
			char ch1;
			scanf(" %c :",&ch1);
			for (int j = 0; j < m; ++j) {
				char ch2;
				scanf(" %c", &ch2);
				r[nmap[ch1]][mmap[ch2]] = n-1-j;
			}
		}

		stable_marriage();

		for (int i = 0; i < m; ++i) {
			printf("%c %c\n", mans[i], woms[l2r[i]]);
		}
		if (t) puts("");
	}
	return 0;
}
