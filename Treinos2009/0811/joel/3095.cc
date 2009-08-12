#include <cstdio>
#include <cstring>


char str[85];
int len;

int ok(int pos, int inc) {
	if (pos == -1 || pos == len || str[pos] == '.') return 1;
	if (str[pos] == '_') return ok(pos+inc,inc);
	return 0;
}

int main() {

	while (scanf("%s", str) == 1 && strcmp(str, "#")) {
		double res = 0;
		len = strlen(str);

		for (int i = 0; i < len; ++i) {
			if (str[i] == '.') res += 100;
			else if (str[i] == '/') res += ok(i - 1, -1) * 100;
			else if (str[i] == '\\') res += ok(i + 1, +1) * 100;
			else if (str[i] == '|') res += ok(i - 1, -1) * 50 + ok(i+1,+1)*50;
		}

		printf("%d\n", int(double(res)/len));
	}

	return 0;
}
