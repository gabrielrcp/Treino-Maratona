#define INF 0x7f7f7f7f

#define MAXV 1000 
#define MAXE 60000

int grafo[MAXV];

int next[MAXE];
int vertice[MAXE];
int flow[MAXE];
int cost[MAXE];

int fila[MAXV];
int nafila[MAXV];
int pai[MAXV];
int dist[MAXV];
int cflow[MAXV];

int edge_count;

void init() {
    memset(grafo, -1, sizeof(grafo));
    edge_count = -1;
}

void add_edge(int u, int v, int f1, int c) {
    int e1 = edge_count++;
    int e2 = edge_count++;

    next[e1] = grafo[u];
    vertice[e1] = v;
    flow[e1] = f1;
    cost[e1] = c;
    grafo[u] = e1;

    next[e2] = grafo[v];
    vertice[e2] = u;
    flow[e2] = 0;
    cost[e2] = -c;
    grafo[v] = e2;
}

int mincostflow(int source, int sink) {
    int resp = 0;
    while(1) {
        memset(nafila, 0, sizeof(nafila));
        memset(dist, 0x7f, sizeof(nafila));
        int ffila = 0, ifila = 0;
        fila[ffila++] = source;
        dist[source] = 0;
        nafila[source] = 1;
        cflow[source] = 1<<30;
        pai[source] = -1;
        while(ffila != ifila) {
            int u = fila[ifila];
            nafila[u] = 0;
            ifila = (ifila + 1)%MAXV;
            for(int e = grafo[u]; e != -1 ; e = next[e]) if(flow[e] > 0) {
                int v = vertice[e];
                int tmp = dist[u] + cost[e];
                if(tmp < dist[v]) {
                    dist[v] = tmp;
                    pai[v] = e^1;
                    cflow[v] = min(cflow[u], flow[e]);
                    if(nafila[v] == 0) {
                        fila[ffila] = v;
                        nafila[v] = 1;
                        ffila = (ffila + 1)%MAXV;
                    }
                }
            }
        }
        if(dist[sink] == INF) break;
        int f = cflow[sink];
        resp += dist[sink] * f;
        for(int u = sink; pai[u] != -1; u = vertice[pai[u]]) {
            flow[pai[u]^1] -= f;
            flow[pai[u]] += f;
        }
    }
    return resp;
}
