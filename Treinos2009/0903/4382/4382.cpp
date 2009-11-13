#include <cstdio>

const int MAXN = 3 * 1000010;
const int RAIZ = 3 * 1010; 

bool isprime[MAXN];

int crivo() {
    isprime[2] = true;
    for (int i = 3; i < MAXN; i += 2) isprime[i] = true;
    for (int i = 3; i < RAIZ; i += 2) if (isprime[i]) { 
        for (int j = i * i; j < MAXN; j += (i<<1)) isprime[j] = false;
    }
}

int n;
int dp[MAXN];

int main() {
    crivo();

    for (int i = 1; i < 1000010; ++i) {
        dp[i] += dp[i-1] + (isprime[3 * i + 7] ? 1 : 0);
    }

    int t;
    for (scanf("%d", &t); t--;) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }

    return 0;
}
