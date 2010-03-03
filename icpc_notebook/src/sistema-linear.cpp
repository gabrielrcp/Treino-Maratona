#define MAXTAM 32

double matriz[MAXTAM][MAXTAM];
double variables[MAXTAM];

void solve(int N) {
    for(int i=0;i<N;++i) {
        int m = i;
        for(int j=i+1;j<N;++j) {
            if(abs(matriz[j][i]) > abs(matriz[m][i]))
                m = j;
        }
        for(int j=i;j<=N;++j) {
            swap(matriz[i][j], matriz[m][j]);
        }
        for(int j=i+1;j<N;++j) {
            if(abs(matriz[j][i])<1e-9) continue;
            double f = matriz[j][i]/matriz[i][i];
            for(int k=i;k<=N;++k) {
                matriz[j][k] -= matriz[i][k] * f;
            }
        }
    }
    variables[N] = 1.0;
    for(int i=N-1;i>=0;--i) {
        double soma = 0.0;
        for(int j=i+1;j<=N;++j) {
            soma += matriz[i][j] * variables[j];
        }
        variables[i] = -soma / matriz[i][i];
    }
}

