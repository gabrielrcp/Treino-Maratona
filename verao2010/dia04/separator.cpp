//PKU: 2056

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

int N, M;
char table[300][300];

int visitado[300*300];

int fila[300*300];

int dx[] = {1, -1, 0};
int dy[] = {0, 0, 1};

int main(void) {
    while(scanf("%d%d", &N, &M) and N>0) {
        rep(i, N) scanf("%s", table[i]);


        memset(visitado, -1, sizeof(visitado));

        int ifila = 0, ffila = 0;
        rep3(i, 1, M) {
            if(table[0][i] == 'S' or table[0][i-1] == 'S') {
                fila[ffila++] = i;
                visitado[i] = 1;
            }
        }
        while(ifila != ffila) {
            int id = fila[ifila++];
            int x3 = id %M;
            int y3 = id/M;
            rep(i, 3) {
                int x4 = x3+dx[i];
                int y4 = y3+dy[i];
                int code = x4+y4*M;
                if(x4 <0 or x4>= M or y4 >=N) continue;
                if(visitado[code] == -1 and x4 > 0 and (table[y4][x4] == 'S' or table[y4][x4-1] == 'S' )) {
                    visitado[code] = visitado[id]+1;
                    fila[ffila++] = code;
                }
            }
        }

        int resp = 1000000000;
        rep(i, M) {
            if(table[N-1][i] == 'S' or table[N-1][i-1] == 'S') {
                resp = min(resp, visitado[i+ (N-1)*M]);
            }
        }
        printf("%d\n", resp);


    }

    return 0;
}
