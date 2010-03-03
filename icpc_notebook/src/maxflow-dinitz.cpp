int grafo[MAXV];

int next[MAXE];
int vertice[MAXE];
int flow[MAXE];

int dist[MAXV];
int fila[MAXV];

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

int nedge[MAXV];

int dfs(int v, int d, int mf = 1<<30) {
    if(v == d) return mf;
    int ret = 0;
    for(int& e = nedge[v]; e != -1; e = next[e]) {
        int w = vertice[e];
        if(flow[e] > 0 and dist[w] == dist[v] + 1) {
            int tmp = dfs(w, d, min(mf - ret, flow[e]));
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

int max_flow(int s, int d) {
    int resp = 0;
    while(bfs(s, d)) {
        memcpy(nedge, grafo, sizeof(nedge));
        resp += dfs(s, d);
    }
    return resp;
}
