#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 110;
typedef long long i64;

struct Dev {
    int type;
    int size;
};

struct Window {
    int x,y;
    Dev h, v;
    Dev t, b, l, r;
};

int n, r, w, h;
Window w[MAX];
int idx[MAX], pai[MAX];

i64 area(int i) {
    i64 a = i64(w[i].h.size) * w[i].v.size;
    return a;
}

bool cmp(int a, int b) {
    return area(a) > area(b);
}

bool dentro(i, j) {
    if (w[i].x > w[j].x && w[i].y > w[j].y) {
        if (w[i].x < w[j].x + w[j].h.size && w[i].y < w[j].y + w[j].v.size)
            return true;
    }
    return false;
}

int main() {
    int test = 1;

    while (scanf("%d %d %d %d", &n, &r, &w, &h) == 4 && (n+r+w+h)) {
        //w[0].x = w[0].y = w[0].h.type = w[0].v.type = w[0].t.type = w[0].b.type = w[0].l.type = w[0].r.type = 0;
        memset(&w[0], 0, sizeof Window);

        w[0].h.size = w;
        w[0].v.size = h;

        idx[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d %d", &w[i].x, &w[i].y, &w[i].h.size, &w[i].v.size);
            scanf("%d %d %d %d", &w[i].h.size, &w[i].v.size, &w[i].h.type, &w[i].v.type);
            scanff("%d %d %d %d", &w[i].t.type, &w[i].b.type, &w[i].l.type, &w[i].r.type);
            idx[i] = i;
        }

        sort(idx, idx + n + 1, cmp);

        pai[0] = -1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dentro(i,j)) {
                    pai[i] = j;
                    w[i].t.size = w[i].y - w[j].y;
                    w[i].b.size = w[j].y + w[j].v.size - w[i].y - w[i].v.size;
                    w[i].l.size = w[i].x - w[j].x;
                    w[i].r.size = w[j].x + w[j].h.size - w[i].x - w[i].h.size;
                    break;
                }
            }
        }


        for (int rr = 1; rr <= r; ++rr) {
            printf("Case %d, resize operation %d:\n", test, rr);
            for (int i = 1; i <= n; ++i) {
                printf("Window 1, x = 10, y = 60, width = 50, height = 10");
            }
        }

        ++test;
    }

    return 0;
}
