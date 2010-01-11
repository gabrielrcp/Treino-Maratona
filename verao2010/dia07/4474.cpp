/****************** 
 * Problema:
 * Fonte:
 * Palavra-chave:
 *****************/

#include <set>
#include <map>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <functional>

#define rep(i, N) for(int i=0;i<(N);++i)
#define repd(i, N) for(int i=(N)-1;i>=0;--i)
#define rep3(i, j, N) for(int i=(j);i<(N);++i)
#define repd3(i, j, N) for(int i=(N)-1;i>=(j);--i)
#define foreach(it, cont) for(__typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); ++it)

using namespace std;

char str[1100];

#define MAXR 20

int table[1100][MAXR*2+1];
int N;

int conta(int p, int rot) {
    if(p == N) {
        int resp = rot*26;
        if(resp < 0) resp = -resp;
        return resp;
    }
    if(table[p][rot+MAXR] != -1) return table[p][rot+MAXR];
    int resp = 1000000000;
    for(int i = -MAXR; i <= MAXR; ++i) {
        int t = conta(p+1, i);
        int r1 = i*26 - str[p+1];
        int r2 = rot*26 - str[p];
        if(r1*r2 < 0) {
            if(r2<0) r2 = -r2;
            resp = min(resp, t + r2);
        } else {
            if(r1<0) r1 = -r1;
            if(r2<0) r2 = -r2;
            int delta = r2 - r1;
            if(delta < 0) delta = 0;
            resp = min(resp, t + delta);
        }
    }
    return table[p][rot+MAXR] = resp;
}


int main(void) {

    while(scanf("%s", str) and str[0] != '*') {
        memset(table, -1, sizeof(table));
        N = strlen(str);
        rep(i, N) str[i] -= 'a';
        int resp = 1000000000;
        rep3(i, -MAXR, MAXR+1) {
            resp = min(resp, conta(0, i));
        }
        printf("%d\n", resp);

    }

    return 0;
}
