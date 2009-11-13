#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 100010;
const int MAXV = 4 * MAXN;

struct Bit {
    int v[MAXV];
    void clear() { memset(v, 0, sizeof v); }
    void add(int pos, int val) { for (++pos; pos < MAXV; pos += (pos & -pos)) v[pos] += val; }
    int count(int pos) { int ret = 0; for (++pos; pos > 0; pos -= (pos & -pos)) ret += v[pos]; return ret; }
};

int n;
int s[MAXN], e[MAXN];
map<int,int> mapa;
Bit b;

int main() {
    int t;
    for (scanf("%d", &t); t--;) {
        scanf("%d", &n);
        mapa.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &s[i], &e[i]);
            mapa[s[i]] = 0;
            mapa[e[i]] = 0;
        }

        int idx = 0;
        for (map<int,int>::iterator i = mapa.begin(); i != mapa.end(); ++i) {
            i->second = idx++;
        }
        idx *= 2;

        for (int i = 0; i < n; ++i) {
            s[i] = 2*mapa[s[i]];
            e[i] = 2*mapa[e[i]];
        }

        //if (e[0] == s[1]) ++e[0];
        //else if (e[1] == s[0]) ++e[1];

        b.clear();
        for (int i = 0; i < n; ++i) {
            b.add(s[i], 1);
            b.add(e[i]-1,-1);
        }

        int res = 2;
        for (int i = 0; i < idx; ++i) {
            int tmp = b.count(i);
            if (tmp > res) res = tmp;
        }

        //if (b.count(e[0]-1) >= res-1 && b.count(e[1]-1) >= res-1) ++res;

        printf("%d\n", res);
    }
    return 0;
}

