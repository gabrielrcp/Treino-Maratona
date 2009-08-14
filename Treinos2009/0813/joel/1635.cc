#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

char t1[3010], t2[3010];
int l1, l2;

int p1, p2;
vector<int> v1, v2;

vector<int> go(vector<int> v) {
	if (v.size()<4) return v;

	vector< vector<int> > p;
	int ini = v[0];
	int pos = 1;

	for (int i = 1; i < v.size(); ++i) {
		if (v[i] == ini) {
			p.push_back(go(vector<int>(v.begin()+pos, v.begin()+i)));
			pos = i+1;
		}
	}

	sort(p.begin(), p.end());

	vector<int> res;

	res.push_back(ini);
	for (int i = 0; i < p.size(); ++i) {
		for (int j = 0; j < p[i].size(); ++j) {
			res.push_back(p[i][j]);
		}
		res.push_back(ini);
	}
	return res;
}

int main() {
	int t;

	for (scanf("%d", &t); t--;) {
		scanf("%s %s", t1, t2);

		l1 = strlen(t1);
		l2 = strlen(t2);

		if (l1 != l2) {
			puts("different");
			continue;
		}

		p1 = p2 = 0;
		v1.clear();
		for (int i = 0; i <= l1; ++i) {
			//printf("%d ", p1);
			v1.push_back(p1);
			if (t1[i] == '0') ++p1;
			else --p1;
		}//puts("");
		v2.clear();
		for (int i = 0; i <= l2; ++i) {
			//printf("%d ", p2);
			v2.push_back(p2);
			if (t2[i] == '0') ++p2;
			else --p2;
		}//puts("");

		//for (int i = 0; i < v1.size(); ++i) printf("%d ", v1[i]); puts("");
		//for (int i = 0; i < v2.size(); ++i) printf("%d ", v2[i]); puts("");

		v1 = go(v1);
		v2 = go(v2);

		//for (int i = 0; i < v1.size(); ++i) printf("%d ", v1[i]); puts("");
		//for (int i = 0; i < v2.size(); ++i) printf("%d ", v2[i]); puts("");

		if (v1 != v2) puts("different");
		else puts("same");
	}

	return 0;
}
