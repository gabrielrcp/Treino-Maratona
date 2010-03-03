#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXV 5000
#define MAXE 60000

typedef long long ll;

int grafo[MAXV];

int next[MAXE];
int vertice[MAXE];
int flow[MAXE];

int edge_count;

void _add_edge(int u, int v, int f) {
    int e = edge_count++;
    next[e] = grafo[u];
    vertice[e] = v;
    flow[e] = f;
    grafo[u] = e;
}

void add_edge(int u, int v, int f1, int f2 = 0) {
    _add_edge(u, v, f1);
    _add_edge(v, u, f2);
}

int dist[MAXV];
int fila[MAXV];

int nedge[MAXV];

bool bfs(int s, int d) {
    int ffila=0, ifila=0;
    memset(dist, -1, sizeof(dist));
    fila[ffila++] = s;
    dist[s] = 0;
    while(ifila != ffila) {
        int u = fila[ifila++];
        for(int e = grafo[u]; e != -1; e = next[e]) {
            int w = vertice[e];
            if(flow[e] > 0 and dist[w] == -1) {
                fila[ffila++] = w;
                dist[w] = dist[u] + 1;
            }
        }
    }
    return dist[d] != -1;
}

ll dfs(int v, int d, ll mf = 1ll<<62) {
    if(v == d) return mf;
    ll ret = 0;
    for(int& e = nedge[v]; e != -1; e = next[e]) {
        int w = vertice[e];
        if(flow[e] > 0 and dist[w] == dist[v] + 1) {
            ll tmp = dfs(w, d, min(mf - ret, ll(flow[e])));
            if(tmp > 0) {
                flow[e] -= tmp;
                flow[e^1] += tmp;
                ret += tmp;
                if(ret == mf) break;
            }
        }
    }
    return ret;
}

ll max_flow(int s, int d) {
    ll resp = 0;
    while(bfs(s, d)) {
        memcpy(nedge, grafo, sizeof(nedge));
        resp += dfs(s, d);
    }
    return resp;
}

int main(void) {
    int N, M;
    scanf("%d%d", &N, &M);
    memset(grafo, -1, sizeof(grafo));
    edge_count = 0;

    for(int i = 0; i < M; ++i) {
        int u, v, f;
        scanf("%d%d%d", &u, &v, &f);
        add_edge(u-1, v-1, f, f);
    }

    ll resp = max_flow(0, N-1);
    printf("%lld\n", resp);
    return 0;
}
