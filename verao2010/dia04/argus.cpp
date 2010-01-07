//PKU: 2051

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


int tempo[1100];
int id[1100];
int next[1100];


int main(void) {

    char str[1000];
    int N = 0;
    while(scanf("%s", str) != EOF and str[0] != '#') {
        scanf("%d %d", id+N, tempo+N);
        next[N] = tempo[N];
        N++;
    }
    int K;
    scanf("%d", &K);

    int last_tempo = -1, last_id = -1;

    for(int i = 0; i < K; ++i) {
        int t = 1000000000, x = 1000000000, p = -1;
        for(int j = 0; j < N; ++j) {
            if(next[j] >= last_tempo or (next[j] == last_tempo and id[j] >= last_id)) {
                if(next[j] < t or (next[j] == t and id[j] < x)) {
                    t = next[j];
                    x = id[j];
                    p = j;
                }
            }
        }
        last_tempo = t;
        last_id = x;
        next[p] += tempo[p];
        printf("%d\n", x);
    }

    return 0;
}
