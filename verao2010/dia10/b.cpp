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
#include <iostream>
#include <algorithm>
#include <functional>

#define all(x) x.begin(), x.end()
#define rep(i, N) for(int i=0;i<N;++i)
#define repd(i, N) for(int i=N-1;i>=0;--i)
#define rep3(i, j, N) for(int i=(j);i<(N);++i)
#define repd3(i, j, N) for(int i=(N)-1;i>=(j);--i)
#define foreach(it, cont) for(__typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); ++it)
#define size(x) (int((x).size()))

using namespace std;

typedef long long ll;

template <class T>
ostream& operator<<(ostream& stream, const vector<T>& v) {
    stream << size(v) << endl;
    rep(i, size(v)) {
        stream << v[i] << endl;
    }
    return stream;
}

template <class T>
istream& operator>>(istream& stream, vector<T>& v) {
    int N;
    stream >> N;
    v.resize(N);
    rep(i, size(v)) {
        stream >> v[i];
    }
    return stream;
}

istream& operator>>(istream& stream, vector<string>& v) {
    string tmp;
    int N;
    cin >> N;
    getline(stream, tmp);
    v.resize(N);
    rep(i, N) {
        getline(stream, v[i]);
    }
    return stream;
}

int seq[2000100];
ll accum[2000100];

int vetorzao[2000100];

ll tipo[2000100];

int pos[2000100];

int bit[1000100];
int bit_tam;
int tudo;

inline void add(int pos, int v) {
    int inicio = 0, fim = bit_tam-1;
    while(inicio<=fim) {
        int meio = (inicio + fim) / 2;
        if(meio <= pos) {
            bit[meio] += v;
        }
        if(pos < meio) {
            fim = meio - 1;
        } else if(pos > meio) {
            inicio = meio + 1;
        } else {
            break;
        }
    }
}

inline int get(int pos) {
    int inicio = 0, fim = bit_tam-1;
    int resp = 0;
    while(inicio<=fim) {
        int meio = (inicio + fim) / 2;
        if(meio >= pos) {
            resp += bit[meio];
        }
        if(pos < meio) {
            fim = meio - 1;
        } else if(pos > meio) {
            inicio = meio + 1;
        } else {
            break;
        }
    }
    return resp;
}

inline int maior() {
    int inicio = 0, fim = bit_tam-1;
    int ret = 0;
    while(inicio<=fim) {
        int meio = (inicio + fim) / 2;
        if(bit[meio] > 0) {
            ret = meio;
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return ret;
}

int main(void) {
    int T;
    cin >> T;
    rep(t, T) {
        int a, b, c, d, N;
        cin >> a >> b >> c >> d >> N;
        int seed = 0;
        ll soma = 0;
        rep(i, N) {
            seed = (seed * ll(a) + b) % 32768;
            seq[i] = (seed * ll(c)) / 32768 - d;
            soma += seq[i];
        }
        rep(i, N) {
            seq[i+N] = seq[i];
        }
        accum[N*2] = 0;
        for(int i = N*2-1;i>=0; --i) {
            accum[i] = seq[i] + accum[i+1];
        }
        rep(i, N*2) tipo[i] = accum[i];
        sort(tipo, tipo+N*2);
        int M = unique(tipo, tipo+N*2) - tipo;

        rep(i, 2*N) {
            pos[i] = lower_bound(tipo, tipo+M, accum[i]) - tipo;
        }

        int resp = 0;
        memset(bit, 0, sizeof(bit));
        tudo = 0;
        bit_tam = M;

        rep(i, N) {
            add(pos[i], 1);
        }

        ll melhor = seq[0];
        rep(i, N) {
            int p = maior();
            ll tmp = tipo[p] - accum[i+N];
            if(tmp > melhor) {
                melhor = tmp;
                resp = 0;
            }
            if(tmp == melhor) {
                resp += get(p);
            }
            add(pos[i], -1);
            add(pos[i+N], 1);
        }
        if(soma == melhor) {
            resp -= N-1;
        }
        vector<int> r(2);
        r[0] = melhor;
        r[1] = resp;
        cout << r << endl;
    }
    return 0;
}
