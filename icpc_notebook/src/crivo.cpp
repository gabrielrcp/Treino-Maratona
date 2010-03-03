#define MAX_NUMBERS 100000

bool crivo[MAX_NUMBERS];

int primos[MAX_NUMBERS];
int n_primos;

void init_crivo(int last) {
    memset(crivo, true, sizeof(crivo));
    crivo[0]=crivo[1]=false;
    int m = int(sqrt(last)+1);
    for(int i=2;i<=m;i++) {
        if(crivo[i]) {
            for(int j=i*i; j <= last; j+=i) {
                crivo[j]=false;
            }
        }
    }
    n_primos=0;
    for(int i=2;i<=last;++i) {
        if(crivo[i]) {
            primos[n_primos++]=i;
        }
    }
}

