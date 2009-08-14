#include <cstdio>
#include <map>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 20010;

int n, m;
char w[25];
map<string,int> mapa;
int qtd[MAX];

int main() {

	while (scanf("%d %d", &n, &m) == 2 && (n+m)) {
		mapa.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%s", w);
			mapa[w]++;
		}

		memset(qtd,0,sizeof qtd);
		for (map<string,int>::iterator it = mapa.begin(); it != mapa.end(); ++it) qtd[it->second]++;

		for (int i = 1; i <= n; ++i) printf("%d\n", qtd[i]);
	}

	return 0;
}
