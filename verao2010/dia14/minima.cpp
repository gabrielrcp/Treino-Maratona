#include <cstdio>
#include <set>

using namespace std;

typedef long long ll;

#define MAX 30000000

int numbers[MAX];

int pilha[MAX];

int main(void) {

#ifndef LOCAL
    freopen("minima.in", "r", stdin);
    freopen("minima.out", "w", stdout);
#endif

    int N, M, K;
    scanf("%d%d%d", &N, &M ,&K);

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    for(int i = 0; i < K; ++i) {
        scanf("%d", numbers+i);
    }

    for(int i = K; i < N; ++i) {
        numbers[i] = numbers[i-2]*a + numbers[i-1]*b + c;
    }

    /*
    for(int i = 0; i < N; ++i) {
        while(topo < N and numbers[pilha[topo+1]] > numbers[i]) {
            ++topo;
        }
        if(topo == N) {
            prev[i] = -1;
        } else {
            prev[i] = pilha[topo-1];
        }

        pilha[topo++] = i;
    }

    int topo = N;
    for(int i = N-1; i >= 0; --i) {
        while(topo < N and numbers[pilha[topo+1]] >= numbers[i]) {
            ++topo;
        }
        if(topo == N) {
            next[i] = N;
        } else {
            next[i] = pilha[topo+1];
        }
        pilha[topo++] = i;
    }

    ll resp = 0;
    for(int i = 0; i < N; ++i) {
        int inicio = max(prev[i] + 1, i-M+1);
        int fim = min(next[i], i+M);

        if(fim - inicio < M) {
            continue;
        }

        resp += numbers[i] * ll(fim - inicio - M + 1);
    }
    */

    int topo = 0, bottom = 0;

    long long resp = 0;

    for(int i = 0; i < N; ++i) {
        while(topo > bottom and numbers[i] < numbers[pilha[topo-1]]) {
            topo --;
        }
        pilha[topo++] = i;
        while(bottom < topo and pilha[bottom] <= i-M) {
            bottom++;
        }
        if(i >= M-1) {
            resp += numbers[pilha[bottom]];
        }
    }

    printf("%lld\n", resp);
    return 0;
}
