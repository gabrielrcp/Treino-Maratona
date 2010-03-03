#define MAX_TAM 20

double matriz[MAX_TAM][MAX_TAM];
int pmatriz[MAX_TAM][MAX_TAM];
int nmatriz[MAX_TAM];

double PD[1<<MAX_TAM];

bitset<1<<MAX_TAM> visitado;

int mat_tam;

void init(int N) {
    mat_tam = N;
    memset(nmatriz, 0, sizeof(nmatriz));
    visitado.reset();
}

void add(int l, int c, double v) {
    matriz[l][nmatriz[l]] = v;
    pmatriz[l][nmatriz[l]++]=c;
}

inline double det(int mask=0, int p=0) {
    if(p==N) return 1.0;
    double resp = 0.0;
    if(visitado[mask]) {
        return PD[mask];
    }
    visitado.set(mask);
    for(int i=0;i<nmatriz[p];++i) {
        if(((1<<pmatriz[p][i])&mask)==0) {
            int d = pmatriz[p][i];
            d -= __builtin_popcount(mask>>d);
            if(d%2==0) {
                resp += det(mask | (1<<pmatriz[p][i]),p+1) * matriz[p][i];
            } else {
                resp -= det(mask | (1<<pmatriz[p][i]),p+1) * matriz[p][i];
            }
        }
    }
    return PD[mask] = resp;
}
