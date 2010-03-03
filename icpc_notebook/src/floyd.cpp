
#define MAX_VERTICES 256
#define INF 0x7f7f7f7f

int dist[MAX_VERTICES][MAX_VERTICES];

void floyd(int size) {
    for(int k=0;k<size;++k)
        for(int u=0;u<size;++u)
            for(int v=0;v<size;++v) if(dist[u][k] != INF and dist[k][v] != INF)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
}
