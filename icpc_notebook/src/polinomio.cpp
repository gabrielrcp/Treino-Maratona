struct Polinomio {
    double coefs[MAX_POL];

    Polinomio() { clear(); }

    double& operator[](int n) { return coefs[n]; }
    const double& operator[](int n) const { return coefs[n]; }

    void clear() { for(int i=0;i<MAX_POL;++i) coefs[i] = 0; }

    Polinomio operator+(const Polinomio& p) const {
        Polinomio tmp;
        for(int i=0;i<MAX_POL;++i) tmp[i] = coefs[i] + p[i];
        return tmp;
    }
    Polinomio& operator+=(const Polinomio& p) {
        *this = *this + p;
        return *this;
    }

    Polinomio operator-(const Polinomio& p) const {
        Polinomio tmp;
        for(int i=0;i<MAX_POL;++i) tmp[i] = coefs[i] - p[i];
        return tmp;
    }
    Polinomio& operator-=(const Polinomio& p) {
        *this = *this - p;
        return *this;
    }

    Polinomio operator*(const Polinomio& p) const {
        Polinomio tmp;
        for(int i=0;i<MAX_POL;++i) for(int j=0;i+j<MAX_POL;++j) {
            tmp[i+j] += coefs[i]*p[j];
        }
        return tmp;
    }

    pair<Polinomio, Polinomio> operator/(const Polinomio& p2) const {
        Polinomio p1 = *this, resp;
        int g1=p1.grau(), g2=p2.grau();
        for(;g1>=g2;--g1) {
            Polinomio tmp;
            resp[g1-g2] = tmp[g1-g2] = p1[g1] / p2[g2];
            tmp = tmp * p2;
            p1 -= tmp;
        }
        return make_pair(resp, p1);
    }
    Polinomio derivate() const {
        Polinomio tmp;
        for(int i=1;i<MAX_POL;++i) {
            tmp[i-1] = coefs[i]*i;
        }
        return tmp;
    }
    int grau() const {
        int g;
        for(g=MAX_POL-1;abs(coefs[g])<1e-8 and g>0;--g);
        return g;
    }
};
