#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

#define MAX 1001000

int altura[MAX];
int ordem[MAX];
int dias[MAX];

set<pair<int, int> > intervalo;

bool cmp(int i, int j) {
    return altura[i] < altura[j];
}

int main(void) {

    int T;
    scanf("%d", &T);
    for(int t=0;t<T;++t) {
        intervalo.clear();
        int N, D;
        scanf("%d%d", &N, &D);
        for(int i=0;i<N;++i) scanf("%d", altura+i), ordem[i]=i;
        for(int i=0;i<D;++i) scanf("%d", dias+i);
        sort(ordem, ordem+N, cmp);
        intervalo.insert(make_pair(0, N-1));
        for(int i=0, j=0; i<D;++i) {
            while(altura[ordem[j]]<=dias[i] and j < N) {
                set<pair<int, int> >::iterator it = intervalo.lower_bound(make_pair(ordem[j], 1000000000));
                --it;
                pair<int, int> p = *it;
                intervalo.erase(it);
                if(p.first < ordem[j]) {
                    intervalo.insert(make_pair(p.first, ordem[j]-1));
                }
                if(p.second > ordem[j]) {
                    intervalo.insert(make_pair(ordem[j]+1, p.second));
                }
                ++j;
            }
            printf("%d ", intervalo.size());
        }
        printf("\n");
    }

    return 0;
}

