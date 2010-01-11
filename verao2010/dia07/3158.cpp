/****************** 
 * Problema:
 * Fonte:
 * Palavra-chave:
 *****************/

#include <set>
#include <map>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <functional>

#define rep(i, N) for(int i=0;i<(N);++i)
#define repd(i, N) for(int i=(N)-1;i>=0;--i)
#define rep3(i, j, N) for(int i=(j);i<(N);++i)
#define repd3(i, j, N) for(int i=(N)-1;i>=(j);--i)
#define foreach(it, cont) for(__typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); ++it)

using namespace std;

struct rect_t {
    int x1, y1, x2, y2;
};

rect_t rects[2100];

bool cmp_x(int i, int j) {
    return rects[i].x1 < rects[j].x1;
}

bool cmp_y(int i, int j) {
    return rects[i].y1 < rects[j].y1;
}

int ordem1[2100];
int ordem2[2100];

struct node_t {
    node_t *f1, *f2;
    rect_t corte;
};

node_t buffer[10000];
int buffer_size;

int tmp[2100];

node_t* corta(int* ordem1, int* ordem2, int N) {
    if(N == 1) return 0;
    int k = -1;
    int menor_x=-100000, maior_x=-100000, menor_y=-100000, maior_y=-100000;
    node_t* ret = buffer + (buffer_size++);
    rep(i, N) {
        int id = ordem2[i];
        if(menor_x==-100000 or menor_x>rects[id].x1) menor_x = rects[id].x1;
        if(menor_y==-100000 or menor_y>rects[id].y1) menor_y = rects[id].y1;
        if(maior_x==-100000 or maior_x<rects[id].x2) maior_x = rects[id].x2;
        if(maior_y==-100000 or maior_y<rects[id].y2) maior_y = rects[id].y2;
    }
    int pos = rects[ordem2[0]].y2;
    rep(i, N) {
        int id = ordem2[i];
        if(rects[id].y1 < pos) {
            pos = max(pos, rects[id].y2);
        } else {
            k = i;
            break;
        }
    }

    if(k != -1) {
        rep(i, N) tmp[i] = ordem1[i];
        int p1 = 0, p2 = k;
        rep(i, N) {
            int id = tmp[i];
            if(rects[id].y1 < pos) {
                ordem1[p1++] = id;
            } else {
                ordem1[p2++] = id;
            }
        }
        ret->f1 = corta(ordem1, ordem2, k);
        ret->f2 = corta(ordem1+k, ordem2+k, N-k);
        ret->corte.y1 = ret->corte.y2 = pos;
        ret->corte.x1 = menor_x;
        ret->corte.x2 = maior_x;
        return ret;
    }
    pos = rects[ordem1[0]].x2;
    rep(i, N) {
        int id = ordem1[i];
        if(rects[id].x1 < pos) {
            pos = max(pos, rects[id].x2);
        } else {
            k = i;
            break;
        }
    }

    if(k != -1) {
        rep(i, N) tmp[i] = ordem2[i];
        int p1 = 0, p2 = k;
        rep(i, N) {
            int id = tmp[i];
            if(rects[id].x1 < pos) {
                ordem2[p1++] = id;
            } else {
                ordem2[p2++] = id;
            }
        }
        ret->f1 = corta(ordem1, ordem2, k);
        ret->f2 = corta(ordem1+k, ordem2+k, N-k);
        ret->corte.x1 = ret->corte.x2 = pos;
        ret->corte.y1 = menor_y;
        ret->corte.y2 = maior_y;
        return ret;
    }
    assert(0);
    return 0;
}

node_t* fila[2100];

int main(void) {

    int N;
    while(scanf("%d", &N) and N>0) {
        buffer_size= 0 ;
        rep(i, N) scanf("%d%d%d%d", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2);
        rep(i, N) ordem1[i]=i;
        rep(i, N) ordem2[i]=i;

        sort(ordem1, ordem1+N, cmp_x);
        sort(ordem2, ordem2+N, cmp_y);

        node_t* root = corta(ordem1, ordem2, N);

        int M = 1;
        fila[0] = root;
        while(M>0) {
            int id = 0;
            node_t* n;
            rep3(i, 1, M) {
                if((fila[i]->corte.x1 < fila[id]->corte.x1) or
                        (fila[i]->corte.x1 == fila[id]->corte.x1 and
                         fila[i]->corte.y1 < fila[id]->corte.y1)) {
                    id = i;
                }
            }
            n = fila[id];
            fila[id] = fila[--M];
            printf("%d %d %d %d\n", n->corte.x1, n->corte.y1, n->corte.x2, n->corte.y2);
            if(n->f1) {
                fila[M++] = n->f1;
            }
            if(n->f2) {
                fila[M++] = n->f2;
            }
        }
        printf("\n");
    }
    return 0;
}
