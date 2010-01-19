#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX 200500

int numbers[MAX];

int bit[MAX];

int position[MAX];

int alla[MAX];

void add(int pos, int v) {
    pos ++;
    while(pos < MAX) {
        bit[pos] += v;
        pos += (pos & -pos);
    }
}

int get(int pos) {
    pos ++;
    int resp = 0;
    while(pos > 0) {
        resp += bit[pos];
        pos -= (pos & -pos);
    }
    return resp;
}

int main(void) {

#ifndef LOCAL
    freopen("mtf.in", "r", stdin);
    freopen("mtf.out", "w", stdout);
#endif

    int N;

    scanf("%d", &N);

    for(int i= 0; i < N; ++i) {
        scanf("%d", numbers+i);
        alla[i] = numbers[i];
    }
    alla[N]  = 0;
    sort(alla, alla+N+1);
    int M = unique(alla, alla+N+1) - alla;

    for(int i = 1; i < M; ++ i) {
        position[i] = i+MAX/2;
        add(i+MAX/2, alla[i] - alla[i-1]);
    }
    int next = MAX/2-1;

    for(int i = 0; i < N; ++i) {
        int p = lower_bound(alla, alla+M, numbers[i]) - alla;
        int k = position[p];
        int r = get(k);
        printf("%d ", r);
        add(k, -1);
        add(next, 1);
        position[p] = next;
        next--;
    }
    printf("\n");

    return 0;
}
