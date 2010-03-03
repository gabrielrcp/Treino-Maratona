typedef long long ll;

ll mdc(ll a, ll b) {
    return (b==0)?a:mdc(b,a%b);
}
ll mmc(ll a, ll b) {
    return (a / mdc(a, b)) * b;
}
struct Fracao {
    ll a, b;
    Fracao() : a(0), b(1) { }
    Fracao(ll _a, ll _b=1) : a(_a), b(_b) {
        ll m = mdc(a, b);
        a /= m; b/= m;
        if(b<0) a=-a, b=-b;
        if(a==0) b=1;
    }
    Fracao operator+(const Fracao& f) const {
        ll m1 = mdc(b, f.b);
        return Fracao((f.b/m1)*a+(b/m1)*f.a,(b/m1)*f.b);
    }
    Fracao& operator+=(const Fracao& f) {
        *this = *this + f;
        return *this;
    }
    Fracao operator-(const Fracao& f) const {
        ll m1 = mdc(b, f.b);
        return Fracao((f.b/m1)*a-(b/m1)*f.a,(b/m1)*f.b);
    }
    Fracao& operator-=(const Fracao& f) {
        *this = *this - f;
        return *this;
    }
    Fracao operator*(const Fracao& f) const {
        ll m1 = mdc(a, f.b);
        ll m2 = mdc(b, f.a);
        return Fracao((a/m1)*(f.a/m2),(b/m2)*(f.b/m1));
    }
    Fracao& operator*=(const Fracao& f) {
        *this = *this * f;
        return *this;
    }
    Fracao operator/(const Fracao& f) const {
        ll m1 = mdc(a, f.a);
        ll m2 = mdc(b, f.b);
        return Fracao((a/m1)*(f.b/m2),(b/m2)*(f.a/m1));
    }
    Fracao& operator/=(const Fracao& f) {
        *this = *this / f;
        return *this;
    }
    bool operator==(ll n) const { return a==n and b==1; }
    bool operator!=(ll n) const { return a!=n or b!=1; }
    Fracao inv() const { return Fracao(b, a); }
    ll floor() const { return a/b; }
    ll ceil() const { return (a+b-1)/b; }
};

Fracao mmc(Fracao f1, Fracao f2) {
    ll m1 = mdc(f1.b, f2.b);
    ll m2 = mmc((f2.b/m1) * abs(f1.a), (f1.b/m1) * abs(f2.a));
    return Fracao(m2, (f1.b/m1) * f2.b);
}
