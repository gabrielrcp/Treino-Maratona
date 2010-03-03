#define MAXV 10000
#define MAXE 20000000

int grafo[MAXV];
int next[MAXE];
int vertice[MAXE];
int cost[MAXE];

int edge_count;

int menor[MAXV];

typedef pair<int, int> pii;

void add_edge(int u, int v, int c) {
    int e = edge_count++;
    next[e] = grafo[u];
    vertice[e] = v;
    cost[e] = c;
    grafo[u] = e;
}

int menor_caminho(int u, int v) {

    priority_queue<pii, vector<pii>, greater<pii> > fila; 
    fila.push(pii(0, u));
    memset(menor, 0x7f, sizeof(menor));
    menor[u] = 0;

    while(not fila.empty()) {
        int w = fila.top().second;
        fila.pop();
        if(w == v) {
            break;
        }
        for(int e = grafo[w]; e != -1; e = next[e]) {
            int x = vertice[e];
            int tmp = menor[w] + cost[e];
            if(tmp < menor[x]) {
                menor[x] = tmp;
                fila.push(pii(tmp, x));
            }
        }
    }

    return menor[v];
}
