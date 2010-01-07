// PKU: 2052

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

string strings[20];

int grafo[40][40];

int N;

int table[1<<16][32];

int morto[40];

int procura(int mask, int last) {
    if(mask == (1<<N)-1) {
        return -(strings[0].size()-grafo[last][0]);
    }
    if(table[mask][last] != -1) {
        return table[mask][last];
    }
    int resp = 1000000000;
    rep(i, 2*N) if(((mask>>(i/2))&1) == 0) {
        resp = min(procura(mask | (1<<(i/2)), i) + grafo[last][i], resp);
    }
    return table[mask][last] = resp;
}

bool cmp(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

int main(void) {

    while(scanf("%d", &N) and N>0) {

        memset(table, -1, sizeof(table));
        rep(i, N) {
            char tmp[1000];
            scanf("%s", tmp);
            strings[i] = tmp;
        }

        sort(strings, strings+N);

        int progress = 1;
        while(progress) {
            progress = 0;
            rep(i, 2*N) {
                char str1[200];
                strcpy(str1, strings[i/2].c_str());
                int t1 = strlen(str1);
                if(i%2) reverse(str1, str1+t1);
                rep(j, 2*N) if(i/2 != j/2) {
                    char str2[200];
                    strcpy(str2, strings[j/2].c_str());
                    int t2 = strlen(str2);
                    if(j%2) reverse(str2, str2+t2);
                    int melhor = t2;
                    rep(k, t1) {
                        bool fail = false;
                        for(int l = k; l < t1 and l-k<t2; ++l) {
                            if(str1[l]!=str2[l-k]) {
                                fail = true;
                                break;
                            }
                        }
                        if(not fail) {
                            melhor = max(0, min(melhor, t2 - (t1-k)));
                        }
                    }
                    if(melhor == 0) {
                        strings[j/2] = strings[--N];
                        i = (i&(~1)) - 1;
                        progress = 1;
                        break;
                    }
                }
            }
        }

        rep(i, 2*N) {
            char str1[200];
            strcpy(str1, strings[i/2].c_str());
            int t1 = strlen(str1);
            if(i%2) reverse(str1, str1+t1);
            rep(j, 2*N) {
                char str2[200];
                strcpy(str2, strings[j/2].c_str());
                int t2 = strlen(str2);
                if(j%2) reverse(str2, str2+t2);
                int melhor = t2;
                rep(k, t1) {
                    if(i/2 == j/2 and k == 0) continue;
                    bool fail = false;
                    for(int l = k; l < t1 and l-k<t2; ++l) {
                        if(str1[l]!=str2[l-k]) {
                            fail = true;
                            break;
                        }
                    }
                    if(not fail) {
                        melhor = max(0, min(melhor, t2 - (t1-k)));
                    }
                }
                grafo[i][j] = melhor;
            }
        }


        int resp = procura(1, 0) + strings[0].size();
        if(resp < 2) resp = 2;

        printf("%d\n", resp);

    }

    return 0;
}
