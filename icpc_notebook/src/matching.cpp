#define MAXV 1000
#define MAXE 10000

int grafo[MAXV];

int next[MAXE];
int vertice[MAXE];

int edge_count;

int match[MAXV];
int visited[MAXV];
int mark;

inline void init() {
    memset(grafo, -1, sizeof(grafo));
    edge_count = 0;
}

inline void add_edge(int u, int v) {
    int e1 = edge_count++;
    vertice[e1] = v;
    next[e1] = grafo[u];
    grafo[u] = e1;

    int e2 = edge_count++;
    vertice[e2] = u;
    next[e2] = grafo[v];
    grafo[v] = e2;
}

bool dfs(int v) {
    if(visited[v] == mark) return false;
    visited[v] = mark;
    for(int e = grafo[v]; e != -1; e = next[e]) {
        int u = vertice[e];
        if(match[u] == -1 or dfs(match[u])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int max_matching() {
    memset(visited, 0, sizeof(visited));
    memset(match, -1, sizeof(match));
    mark = 1;
    int total = 0;
    for(int i = 0; i < N; ++i) if(match[i] == -1) {
        if(dfs(i)) {
            ++total;
            ++mark;
        }
    }
    return total;
}
