#include <cstdio>
#include <cstring>

int grafo[200][1000];
int grau[200];

int visitado[200];

void add_edge(int u, int v) {
    grafo[u][grau[u]++] = v;
}

int dfs(int u) {
    visitado[u] = 1;
    if(visitado[u^1]) return 0;
    for(int i = 0; i < grau[u]; ++i) {
        int v = grafo[u][i];
        if(visitado[v] == 0 and dfs(v) == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int N, M, C=0;
    while(scanf("%d%d", &N, &M) and (N != 0 or M != 0)) {
        memset(grau, 0, sizeof(grau));

        for(int i = 0; i < M; ++i) {
            int k;
            int tmp[4];
            scanf("%d", &k);
            for(int j = 0; j < k; ++j) {
                char c;
                scanf("%d %c", tmp+j, &c);
                tmp[j] = tmp[j]*2-2 + (c=='y'?1:0);
            }
            if(k > 2) {
                for(int j = 0; j < k; ++j) {
                    for(int l = 0; l < k; ++l) if(j != l) {
                        add_edge(tmp[j]^1, tmp[l]);
                    }
                }
            } else {
                for(int j = 0; j < k; ++j) {
                    add_edge(tmp[j]^1, tmp[j]);
                }
            }
        }

        char resp[210];
        bool fail = false;

        for(int i = 0; i < N; ++i) {
            memset(visitado, 0, sizeof(visitado));
            int v1 = dfs(i*2);
            memset(visitado, 0, sizeof(visitado));
            int v2 = dfs(i*2+1);
            if(v1 == 0 and v2 == 0) {
                fail = true; break;
            } else if(v1 == 0) {
                resp[i] = 'y';
            } else if(v2 == 0) {
                resp[i] = 'n';
            } else {
                resp[i] = '?';
            }
        }

        resp[N] = 0;

        printf("Case %d: ", ++C);

        if(fail) {
            printf("impossible");
        } else {
            printf("%s", resp);
        }

        printf("\n");
    }
    return 0;
}
