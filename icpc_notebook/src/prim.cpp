int grafo[MAXV];
int in_tree[MAXV];

int next[MAXE];
int vertice[MAXE];
int cost[MAXE];

typedef pair<int, int> pii;

int agm(int u, int v) {

    priority_queue<pii, vector<pii>, greater<pii> > fila; 
    fila.push(pii(0, u));
    memset(menor, 0x7f, sizeof(menor));
    memset(in_tree, 0, sizeof(in_tree));
    menor[u] = 0;

    int cost = 0;

    while(not fila.empty()) {
        int w = fila.top().second;
        if(in_tree[w]) continue;
        in_tree[w] = 1;
        cost += menor[w];
        fila.pop();
        for(int e = grafo[w]; e != -1; e = next[e]) {
            int x = vertice[e];
            if(cost[e] < menor[x]) {
                menor[x] = cost[e];
                fila.push(pii(cost[e], x));
            }
        }
    }

    return cost;
}
