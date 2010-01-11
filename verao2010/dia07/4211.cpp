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

typedef long long ll;

using namespace std;

#define MAX 40

void soma_pol(ll *p1, ll* p2, ll* p3) {
    ll tmp[MAX];
    rep(i, MAX) tmp[i] = p2[i] + p3[i];
    rep(i, MAX) p1[i] = tmp[i];
}

void sub_pol(ll *p1, ll* p2, ll* p3) {
    ll tmp[MAX];
    rep(i, MAX) tmp[i] = p2[i] - p3[i];
    rep(i, MAX) p1[i] = tmp[i];
}

void zero_pol(ll *p1) {
    rep(i, MAX) p1[i] = 0;
}

void mul_pol(ll *p1, ll* p2, ll* p3) {
    ll tmp[MAX];
    zero_pol(tmp);
    rep(i, MAX) {
       rep(j, MAX) {
           if(i+j < MAX) tmp[i+j] += p2[i] * p3[j];
       }
    }
    rep(i, MAX) p1[i] = tmp[i];
}

int raiz_pol(ll* p1, ll v) {
    ll soma = 0;
    rep(i, MAX) {
        soma += p1[i];
        if(soma % v != 0) return 0;
        soma /= v;
    }
    return 1;
}

void ident_pol(ll *p1) {
    zero_pol(p1);
    p1[0]=1;
}

void mul_pol(ll *p1, ll v) {
    rep(i, MAX) p1[i] *= v;
}

int main(void) {

    char str[100];
    while(scanf("%s", str) and str[0]!='=') {
        int N = strlen(str);
        ll pol1[MAX], pol2[MAX], pol3[MAX];
        zero_pol(pol1);
        ident_pol(pol2);
        zero_pol(pol3);
        int sinal = 1;
        int invertido = 1;
        for(int  i = 0; i <= N;) {
            if(isdigit(str[i])) {
                zero_pol(pol3);
                int K = 0;
                for(K = 0; isdigit(str[i]); ++K,++i) {
                    pol3[K] = str[i] - '0';
                }
                reverse(pol3, pol3+K);
                mul_pol(pol2, pol2, pol3);
            } else if(str[i] == '+'or str[i] == '-' or str[i] == '=' or str[i] == 0) {
                mul_pol(pol2, sinal*invertido);
                soma_pol(pol1, pol1, pol2);
                ident_pol(pol2);
                if(str[i]=='+') sinal = 1;
                if(str[i]=='-') sinal = -1;
                if(str[i]=='=') invertido = -1, sinal = 1;
                ++i;
            } else if(str[i] == '*') {
                ++i;
            }
        }
        int zero = 1;
        rep(i, MAX) {
            if(pol1[i] != 0) {
                zero = 0;
                break;
            }
        }
        int menor = 2;
        rep(i, N) if(isdigit(str[i])) {
            int d = str[i] - '0';
            menor = max(menor, d+1);
        }
        if(zero == 1) {
            printf("%d+\n", menor);
        } else {
            ll resps[1000];
            int M = 0;
            ll r = 1, b;
            rep(i, MAX) {
                if(pol1[i] != 0) {
                    b = pol1[i];
                    break;
                }
            }
            if(b<0) b=-b;
            for(;r*r <= b;r++) {
                if(b%r == 0) {
                    if(raiz_pol(pol1, r)) {
                        if(r >= menor) {
                            resps[M++]  = r;
                        }
                    }
                    if(raiz_pol(pol1, b/r)) {
                        if(b/r >= menor) {
                            resps[M++]  = b/r;
                        }
                    }
                }
            }
            sort(resps, resps+M);
            M = unique(resps, resps+M) - resps;
            if(M == 0) {
                printf("*");
            } else {
                rep(i, M) {
                    if(i>0) printf(" ");
                    printf("%lld", resps[i]);
                }
            }
            printf("\n");
        }



    }

    return 0;
}
