int grafo[MAXTAM][MAXTAM];
bool visitado[MAXTAM];
int cost[MAXTAM];

/* O(N^3) */
int mincut(int N) {
    int resp = INF;
    bzero(cost, sizeof(cost));
    for(;N>1;--N) {
        int cut = 0;
        bzero(visitado, sizeof(visitado[0])*N);
        int l1=0, l2=0;
        for(int i=0;i<N;++i) {
            int v=-1, c=-1;
            for(int u=0;u<N;++u) if(not visitado[u] and cost[u]>c)
                c=cost[v=u];
            visitado[v] = true;
            cut -= cost[v];
            cost[v]=0;
            for(int u=0;u<N;++u) if(not visitado[u]) {
                cost[u] += grafo[u][v];
                cut += grafo[u][v];
            }
            l2=l1; l1=v;
            if(i==N-2 and cut<resp)
                resp=cut;
        }
        grafo[l1][l2]=grafo[l2][l1]=0;
        for(int i=0;i<N;++i) {
            grafo[i][l1] = (grafo[l1][i] += grafo[l2][i]);
            grafo[l2][i] = grafo[i][l2] = 0;
        }
        for(int i=0;i<N;++i) {
            grafo[i][l2] = grafo[l2][i] = grafo[N-1][i];
        }
    }
    return resp;
}
