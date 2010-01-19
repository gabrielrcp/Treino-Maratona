#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int seed[1100];

#define MAX 300

#define BASE 10000

typedef int bignum_t[MAX];

void mul(bignum_t& resp, int n) {
    int vai = 0;
    for(int i = 0; i < MAX; ++i) {
        int x = n*resp[i] + vai;
        resp[i] = x%BASE;
        vai = x/BASE;
    }
}

void add(bignum_t& resp, bignum_t& n1) {
    int vai = 0;
    for(int i = 0; i < MAX; ++i) {
        int x = resp[i] + n1[i] + vai;
        resp[i] = x%BASE;
        vai = x/BASE;
    }
}

void div(bignum_t& resp, int n) {
    int resto = 0;
    for(int i = MAX-1; i >= 0; --i) {
        int x = (resp[i] + resto * BASE);
        resp[i] = x/n;
        resto = x%n;
    }
}

void zero(bignum_t& n) {
    memset(n, 0, sizeof(n));
}

void one(bignum_t& n) {
    zero(n);
    n[0]=1;
}

void print(bignum_t& n) {
    int i;
    for(i = MAX-1; i>=0 and n[i] == 0; --i);
    if(i == -1) {
        printf("0\n");
    } else {
        printf("%d", n[i]);
        for(--i; i>=0; --i) {
            printf("%04d", n[i]);
        }
        printf("\n");
    }
}

bignum_t table[110][110];

int K, N;

void computa(int pos, int q) {
    if(table[pos][q][0] != -1) return;
    bignum_t& resp = table[pos][q];
    if(pos == N) {
        if(q < K) {
            zero(resp);
        } else {
            one(resp);
        }
        return;
    }
    zero(resp);

    for(int i = 0; i <= min(q, K-1); ++i) {
        int nq = max(i+1, q);
        computa(pos+1, nq);
        add(resp, table[pos+1][nq]);
    }
}

int main(void) {

#ifndef LOCAL
    freopen("dinner.in", "r", stdin);
    freopen("dinner.out", "w", stdout);
#endif

    scanf("%d%d", &K, &N);

    memset(table, -1, sizeof(table));

    computa(0, 0);

    bignum_t& resp = table[0][0];

    for(int i = 2; i <= K; ++i) {
        mul(resp, i);
    }

    print(resp);


    return 0;
}
