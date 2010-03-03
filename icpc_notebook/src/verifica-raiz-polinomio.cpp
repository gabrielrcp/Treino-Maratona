
bool eh_raiz_inteira(const vector<int>& polinomio, int x) {
    ll tmp=0;
    if(x==0)
        return polinomio[0]==0;
    for(int i = 0;i<sz(polinomio);++i) {
        tmp += polinomio[i];
        if(tmp%x!=0)
            return false;
        tmp /= x;
    }
    return tmp==0;
}
