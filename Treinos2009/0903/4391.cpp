#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

#define MAX 101000

int X[MAX];
int Y[MAX];
int ordem[MAX];

int ponto[MAX];
int px[MAX];
int py[MAX];
int left[MAX], right[MAX];
int pos;

bool cmp_x(int i, int j) {
    return X[i]<X[j];
}

bool cmp_y(int i, int j) {
    return Y[i]<Y[j];
}

int build_tree(int *pontos, int k, int dim = 0) {
    if(k==0) return -1;
    int pivo = k/2;
    if(dim == 0) {
        nth_element(pontos, pontos+pivo, pontos+k, cmp_x);
    } else {
        nth_element(pontos, pontos+pivo, pontos+k, cmp_y);
    }
    int node = pos++;
    ponto[node] = pontos[pivo];
    px[node] = X[pontos[pivo]];
    py[node] = Y[pontos[pivo]];
    left[node] = build_tree(pontos, pivo, (dim+1)%2);
    right[node] = build_tree(pontos+pivo+1, k-pivo-1, (dim+1)%2);
    return node;
}

#define Q(x) ((ll(x))*(ll(x)))

typedef long long ll;

ll dist;

inline ll calc_dist(int i, int j) {
    return Q(X[i]-X[j]) + Q(Y[i]-Y[j]);
}

int p, x, y;

inline void search1(int node);

inline void search(int node) {
    if(p != ponto[node]) {
        dist = min(dist, calc_dist(p, ponto[node]));
    }

    if(x <= px[node]) {
        if(left[node]!=-1) {
            search1(left[node]);
        }
        if(right[node] != -1 and Q(x - px[node]) < dist) {
            search1(right[node]);
        }
    } else {
        if(right[node]!=-1) {
            search1(right[node]);
        }
        if(left[node] != -1 and Q(x - px[node]) < dist) {
            search1(left[node]);
        }
    }
}

inline void search1(int node) {
    if(p != ponto[node]) {
        dist = min(dist, calc_dist(p, ponto[node]));
    }

    if(y <= py[node]) {
        if(left[node]!=-1) {
            search(left[node]);
        }
        if(right[node] != -1 and Q(y - py[node]) < dist) {
            search(right[node]);
        }
    } else {
        if(right[node]!=-1) {
            search(right[node]);
        }
        if(left[node] != -1 and Q(y - py[node]) < dist) {
            search(left[node]);
        }
    }
}

int main(void) {

    int T;
    scanf("%d", &T);
    for(int t=0;t<T;++t) {
        int N;
        scanf("%d", &N);
        for(int i=0;i<N;++i) {
            scanf("%d%d", X+i, Y+i);
            ordem[i] = i;
        }
        pos = 0;
        int root = build_tree(ordem, N);
        for(int i=0;i<N;++i) {
            dist = Q(2000000000ll);
            p = i;
            x = X[p];
            y = Y[p];
            search(root);
            printf("%lld\n", dist);
        }
    }

    return 0;
}

