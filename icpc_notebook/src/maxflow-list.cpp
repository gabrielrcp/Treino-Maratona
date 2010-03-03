int grafo[MAXV];

int next[MAXE];
int vertice[MAXE];
int flow[MAXE];

int edge_count;

int pai[MAXV];
int fila[MAXV];
int cflow[MAXV];

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

int max_flow(int source, int sink) {
    int resp = 0;
    while(1) { 
        memset(pai, -1, sizeof(pai));
        int ifila = 0, ffila = 0;
        fila[ffila++] = source;
        pai[source] = -2;
        cflow[source] = 0x7fffffff;
        while(ifila != ffila and pai[sink] == -1) {
            int v = fila[ifila++];
            for(int e = grafo[v]; e != -1; e = next[e]) if(flow[e] > 0) {
                int u = vertice[e];
                if(pai[u] != -1) continue;
                pai[u] = e^1;
                fila[ffila++] = u;
                cflow[u] = min(cflow[v], flow[e]);
            }
        }
        if(pai[sink]==-1) break;
        int f = cflow[sink];
        for(int v = sink; pai[v] != -2; v = vertice[pai[v]]) {
            flow[pai[v]] += f;
            flow[pai[v]^1] -= f;
        }
        resp += f;
    }
    return resp;
}
