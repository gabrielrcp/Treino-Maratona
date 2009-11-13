#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

pair<ll, ll> mdc_ext(ll a, ll b) {
    if(b==0) {
        return make_pair(1, 0);
    } else {
        pair<ll, ll> p = mdc_ext(b, a%b);
        return make_pair(p.second, p.first-p.second*(a/b));
    }
}

ll mdc(ll a, ll b) {
    return b==0?a:mdc(b, a%b);
}

ll inv(ll a, ll m) {
    pair<ll, ll> p = mdc_ext(a, m);
    return ((p.first) % m + m) % m;
}

bool invertivel(ll a, ll m) {
    return mdc(a, m) == 1;
}

bool testa(int x, int y, int W, int H) {

    if(not ((x<=W and y<=H) or (y<=W and x<=H))) return false;
    
    ll k = mdc(mdc(W, x), y);
    if(not invertivel(y/k, x/k)) return false;
    ll t = ((W * inv(y/k, x/k)) % (x/k));
    if(W - t*y < 0) return false;

    k = mdc(mdc(H, x), y);
    if(not invertivel(y/k, x/k)) return false;
    t = ((H * inv(y/k, x/k)) % (x/k));
    if(H - t*y < 0) return false;

    return true;

}

int main(void) {

    int T;
    scanf("%d", &T);

    for(int t=0;t<T;++t) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);

        printf("%s\n", testa(a, b, c, d)?"YES":"NO");


    }

    return 0;
}

