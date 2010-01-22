#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int grafo[1010];
int next[40400];
int vertice[40400];
int cost[40400];
int is_path[40400];
double dist[1010];

int buffer = 0;

void add_edge(int u, int v, int c) {
    int e = buffer++;
    next[e] = grafo[u];
    vertice[e] = v;
    cost[e] = c;
    grafo[u] = e;
}



double min_path(int u, int v, double delta) {
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > fila;

    for(int i = 0; i < 1010; ++i) dist[i] = -1.0;
    dist[u] = 0.0;

    fila.push(make_pair(0, u));
    while(not fila.empty()) {
        pair<double, int> p = fila.top();
        fila.pop();
        double d = dist[p.second];
        for(int e = grafo[p.second]; e != -1; e = next[e]) {
            int w = vertice[e];
            double d2 = d;
            if(is_path[e]) {
                d2 += max(1.0, cost[e]-delta);
            } else {
                d2 += cost[e]+delta;
            }
            if(dist[w] == -1.0 or dist[w] > d2) {
                dist[w] = d2;
                fila.push(make_pair(d, w));
            }
        }
    }

    return dist[v];

}

int tenta(double delta, int N) {
    double path = 0.0;
    for(int i = 0; i < buffer; i+=2) {
        if(is_path[i]) {
            path += max(1.0, cost[i] - delta);
        }
    }
    return min_path(0, N-1, delta) >= path;
}

int main(void) {

    freopen("lateagain.in", "r", stdin);
    freopen("lateagain.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);

    memset(grafo, -1, sizeof(grafo));

    for(int i = 0; i < M; ++i) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        add_edge(x-1, y-1, c);
        add_edge(y-1, x-1, c);
    }

    int K;
    scanf("%d", &K);
    for(int  i =0 ; i < K; ++i) {
        int p;
        scanf("%d", &p);
        is_path[(p-1)*2] = 1;
        is_path[(p-1)*2+1] = 1;
    }

    double inicio = 0.0, fim = 1.0;
    while(not tenta(fim, N)) {
        fim *= 2.0;
    }
    for(int R = 0; R < 100; ++ R) {
        double meio = (inicio + fim) * 0.5;
        if(tenta(meio, N)) {
            fim = meio;
        } else {
            inicio = meio;
        }
    }

    double resp = (inicio+fim) * 0.5;
    printf("%.8f\n", resp);

    for(int i = 0; i < buffer; i += 2) {
        double d;
        if(is_path[i]) {
            d = max(1.0, cost[i] -resp);
        } else {
            d = cost[i] +resp;
        }
        printf("%.8f ", d);
    }
    printf("\n");



    return 0;
}
