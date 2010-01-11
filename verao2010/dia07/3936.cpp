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

#define MAXV 51000
#define MAXE 210000

int grafo[MAXV];
int next[MAXE];
int vertice[MAXE];
int grau[MAXV];
int buffer;

int ordem[MAXV];
int pos[MAXV];

void _add_edge(int u, int v) {
    int e = buffer++;
    next[e] = grafo[u];
    vertice[e] = v;
    grafo[u] = e;
    grau[u]++;
}

void add_edge(int u, int v) {
    _add_edge(u, v);
    _add_edge(v, u);
}

bool compara(int u, int v) {
    return grau[u] > grau[v];
}

int main(void) {

    int N, M;
    while(scanf("%d%d", &N, &M) and N>0) {
        memset(grafo, -1, sizeof(grafo));
        memset(grau, 0, sizeof(grau));
        buffer = 0;

        rep(i, M) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u; --v;
            add_edge(u, v);
        }
        rep(i, N) ordem[i] = i;
        sort(ordem ,ordem+N, compara);
        rep(i, N) pos[ordem[i]] = i;

        int ultimo = -1;
        rep(i, N) {
            int id = ordem[i];
            int conta = 0;
            for(int e = grafo[id]; e != -1; e = next[e]) {
                int w = vertice[e];
                if(pos[w] < i) {
                    conta ++;
                }
            }
            if(conta < i) {
                break;
            } else {
                ultimo = i;
            }
        }
        bool fail = false;

        rep3(i, ultimo+1, N) {
            int id = ordem[i];
            for(int e = grafo[id]; e != -1; e = next[e]) {
                int w = vertice[e];
                if(pos[w] > ultimo) {
                    fail = true;
                    break;
                }
            }
        }

        printf("%s\n", fail?"N":"Y");

    }


    return 0;
}
