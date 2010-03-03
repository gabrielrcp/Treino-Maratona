#define MOD 57

typedef long long ll;

ll table[MOD];

/* Computa fatoriais modulo MOD */
void init() {
    table[0]=1;
    for(int i=1;i<MOD;++i) {
        table[i] = (table[i-1] * i) % MOD;
    }

}

/* inverso multiplicativo no Zm */
ll inverse(ll a, ll m) {
    a = a%m;
    if(a == 1) return 1;
    return ((1-inverse(m, a)*m)/a+m)%m;
}

ll fat(int a) {
    ll resp = 1;
    for(int i = 2; i <= a; ++i) {
        resp *= i;
    }
    return resp;
}

ll fat(int a, ll m) {
    //return table[a];
    ll resp = 1;
    for(int i = 2; i <= a; ++i) {
        resp = (resp * i) % m;
    }
    return resp;
}

ll choose(ll a, ll b) {
    return fat(a) / fat(b) / fat(a-b);
}

ll choose(ll a, ll b, ll m) {
    if(b < 0 or a < b) {
        return 0;
    } else if(a < m) {
        return (fat(a,m)*inverse(fat(b,m)*fat(a-b,m),m)) % m;
    } else {
        return (choose(a%m, b%m, m) * choose(a/m, b/m, m)) % m;
    }
}
