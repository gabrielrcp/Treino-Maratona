#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int n;
string c, d;
char a[110],b[110], dd[210];
set<string> s;

void shuffle(string& c) {
	string cc;
	for (int i = 0; i < n; ++i) {
		cc += c[n+i];
		cc += c[i];
	}
	c = cc;
}

int main() {
	int t,nt = 0;;
	
	for (scanf("%d", &t); t--;) {
		scanf("%d", &n);
		scanf("%s %s %s", a, b, dd);
		d = dd;

		c = a;
		c += b;

		s.clear();

		int res = 0;
		while (s.find(c) == s.end() && c != d) {
			//puts(c.c_str());
			++res;
			s.insert(c);
			shuffle(c);
		}

		if (c != d) printf("%d -1\n", ++nt);
		else printf("%d %d\n", ++nt, res);
	}
	return 0;
}
