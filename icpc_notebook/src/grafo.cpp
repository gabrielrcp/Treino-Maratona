#define MAXV 1000
#define MAXE 10000

int grafo[MAXV];
int next[MAXE];
int vertice[MAXE];
int edge_count;

void init_grafo() {
    memset(grafo, -1, sizeof(grafo));
    edge_count = 0;
}

void add_edge(int u, int v) {
    int e1 = edge_count++;
    next[e1] = grafo[u];
    vertice[e1] = v;
    grafo[v] = e1;

    int e2 = edge_count++;
    next[e2] = grafo[u];
    vertice[e2] = u;
    grafo[u] = e2;
}
