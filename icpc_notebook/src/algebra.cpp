typedef long long ll;

ll mdc(ll a, ll b) {
    ll c;
    while(b>0) {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

ll mdc(ll a, ll b, ll c) {
    return a==0?mdc(b,c):mdc(mdc(a,b),c);
}


/* first*a + second*b = mdc(a, b) */
pair<ll, ll> mdc_ext(ll a, ll b) {
    if(b == 0) {
        return make_pair(1, 0);
    } else {
        pair<ll, ll> p = mdc_ext(b, a%b);
        return make_pair(p.second, p.first - p.second*(a/b));
    }
}

ll mmc(ll a, ll b) {
    return (a / mdc(a, b)) * b;
}

/* a^e */
ll pot(ll a, ll e) {
    ll resp = 1;
    for(;e>0;e/=2) {
        if(e%2==1)
            resp = (resp*a);
        a = (a*a);
    }
    return resp;
}

/* (a^e)%m */
ll pot(ll a, ll e, ll m) {
    ll resp = 1;
    for(;e>0;e/=2) {
        if(e%2==1)
            resp = (resp*a) % m;
        a = (a*a)%m;
    }
    return resp;
}

/* (a1*q^0 + a1*q^1 + .. + an*q^n) % mod */
ll soma_pg_mod(ll a1, ll q, ll n, ll mod) {
    if(n<=0) {
        return 0;
    } else if((n)%2==1) {
        return (soma_pg_mod((a1 * q) % mod, q, n-1, mod) + a1) % mod;
    } else {
        return ((1 + pot_mod(q, n/2, mod)) * soma_pg_mod(a1, q, n/2, mod)) % mod;
    }
}
