#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char matrix[60][60];

int componente[60][60];

int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int dx4[] = {1, 0, -1, 0};
int dy4[] = {0, 1, 0, -1};

int dx2[] = {0, 0, -1, -1};
int dy2[] = {0, -1, 0, -1};

int N, M, K, E;

struct edge_t {
    int v, u, c;
    bool operator<(const edge_t& e) const {
        return c < e.c;
    }
};

edge_t edge[60*60*60*60];

int pai[60*60];

int find(int i) {
    return pai[i] == i? i : pai[i] = find(pai[i]);
}

void dfs(int x, int y, int c) {
    componente[y][x] = c;
    for(int d = 0; d < 8; ++d) {
        int x2 = x + dx[d];
        int y2 = y + dy[d];
        if(x2 < 0 or y2 < 0 or x2 >= M or y2 >= N) {
            continue;
        }
        if(matrix[y2][x2] == '#' and componente[y2][x2] == -1) {
            dfs(x2, y2, c);
        }
    }
}

int main(void) {

    int T = 0;

    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);

    while(scanf("%d%d", &N, &M) and N>0) {

        for(int i = 0; i < N; ++i) {
            scanf("%s", matrix[i]);
        }

        memset(componente, -1, sizeof(componente));

        K = 0;

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(matrix[i][j] == '#' and componente[i][j] == -1) {
                    dfs(j, i, K);
                    ++K;
                }
            }
        }

        E = 0;

        /*
        for(int i = 0; i < N; ++i) {

            for(int j = 0; j < M; ++j) {
                if(componente[i][j] == -1) continue;
                for(int d = 0; d < 4; ++d) {
                    int d1 = (d+1)%4;
                    for(int k = 1; k<60; ++k) {
                        int i2 = i + dy4[d]*k;
                        int j2 = j + dx4[d]*k;
                        if(i2 < 0 or j2 < 0 or i2 >= N or j2>=M) break;
                        for(int k2 = -1; k2 <= 1; k2++) {
                            int i3 = i2 + dy4[d1]*k2;
                            int j3 = j2 + dx4[d1]*k2;
                            if(i3 < 0 or j3 < 0 or i3 >= N or j3>=M) continue;
                            if(componente[i3][j3] != -1 and componente[i3][j3] != componente[i][j]) {
                                edge[E].u = componente[i][j];
                                edge[E].v = componente[i3][j3];
                                edge[E].c = k - 1;
                                ++E;
                            }
                        }
                    }
                }
            }
        }
        */

        for(int i = 0; i <= N; ++i) {
            for(int j = 0; j <= M; ++j) {
                int comp1 = -1;
                for(int d = 0; d < 4; ++d) {
                    int i2 = i + dy2[d];
                    int j2 = j + dx2[d];
                    if(i2 < 0 or j2 < 0 or i2 >= N or j2>=M) continue;
                    comp1 = max(comp1, componente[i2][j2]);
                }

                if(comp1 == -1) continue;
                for(int d = 0; d < 2; ++d) {
                    for(int k = 1; k<60; ++k) {
                        int i2 = i + dy4[d]*k;
                        int j2 = j + dx4[d]*k;
                        int comp2 = -1;
                        for(int d1 = 0; d1 < 4; ++d1) {
                            int i3 = i2 + dy2[d1];
                            int j3 = j2 + dx2[d1];
                            if(i3 < 0 or j3 < 0 or i3 >= N or j3 >= M) continue;
                            comp2 = max(comp2, componente[i3][j3]);
                        }
                        if(comp2 != -1 and comp1 != comp2) {
                            edge[E].u = comp1;
                            edge[E].v = comp2;
                            edge[E].c = k;
                            ++E;
                        }
                        if(comp2 != -1) break;
                    }
                }
            }
        }

        for(int i = 0; i < K; ++i) {
            pai[i]=i;
        }

        int edges = 0;
        int cost = 0;
        sort(edge, edge+E);
        for(int i =0; i < E; ++i) {
            int p1 = find(edge[i].u);
            int p2 = find(edge[i].v);
            if(p1 != p2) {
                pai[p1] = p2;
                edges++;
                cost += edge[i].c;
            }

        }

        if(T > 0) {
            printf("\n");
        }
        printf("City %d\n", ++T);
        if(K <= 1) {
            printf("No bridges are needed.\n");
        } else if(edges == 0) {
            printf("No bridges are possible.\n");
        } else {
            printf("%d bridge%s of total length %d\n", edges, edges == 1 ? "" : "s", cost);
        }
        if(K-edges > 1) {
            printf("%d disconnected groups\n", K-edges);
        }


    }
    
    return 0;
}
        
