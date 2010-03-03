typedef long long ll;

#define ABS(x) ((x)>=0?(x):-(x))

struct geometry {
    ll x,y,w;
    geometry() : x(0), y(0), w(1) { }
    geometry(ll x, ll y, ll w=1) :x(x), y(y), w(w) {
    }
    ll escalar(const geometry& g) {return x*g.x+y*g.y+w*g.w;}
    geometry operator*(const geometry& r) {
        return geometry(y*r.w-w*r.y,w*r.x-x*r.w,x*r.y-y*r.x);
    }
    geometry operator+(const geometry& r) {
        return geometry(r.w*x+w*r.x,r.w*y+w*r.y,w*r.w);
    }
    geometry operator-(const geometry& r) {
        return geometry(r.w*x-w*r.x,r.w*y-w*r.y,w*r.w);
    }
    geometry perpendicular() {
        return geometry(-y,x,w);
    }
    geometry passa_por(const geometry& g) {
        return geometry(x*g.w,y*g.w,-x*g.x-y*g.y);
    }
    geometry operator*(ll k) {
        return geometry(x*k,y*k,w);
    }
    geometry operator/(ll k) {
        return geometry(x,y,w*k);
    }
    geometry inv() const {
        return geometry(-x,-y,-w);
    }
    geometry dist2(const geometry& g) {
        geometry tmp = *this-g;
        return geometry(tmp.x*tmp.x+tmp.y*tmp.y,0,tmp.w*tmp.w);
    }
    bool operator<(const geometry& g) const {
        geometry g1=*this;
        geometry g2=g;
        assert(g1.w>=0);
        assert(g2.w>=0);
        if(g1.w<g2.w) return true;
        if(g1.w>g2.w) return false;
        if(g1.x<g2.x) return true;
        if(g1.x>g2.x) return false;
        if(g1.y<g2.y) return true;
        if(g1.y>g2.y) return false;
        return false;
    }
    bool operator==(const geometry& g) const {
        return x==g.x and y==g.y and w==g.w;
    }
    geometry unique() const {
        geometry r = *this;
        ll m=mdc(ABS(x),ABS(y),ABS(w));
        if(this->w<0 or (this->w==0 and this->y<0) or
            (this->w==0 and this->y==0 and this->x<0))
            m=-m;
        r.x/=m;
        r.y/=m;
        r.w/=m;
        return r;
    }
    geometry norm() const {
        return geometry(x/w, y/w);
    }
};

ostream& operator <<(ostream& stream, const geometry& g) {
    return stream << g.x << ',' << g.y << ',' << g.w;
}
