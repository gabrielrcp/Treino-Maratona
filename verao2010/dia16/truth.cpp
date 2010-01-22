#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int tipo[100100];

int val[100100];

int conta[100100][2];

bool solve(int N) {
    memset(conta, 0, sizeof(conta));
    int maior = 0;
    for(int i = 0; i < N; ++i) {
        if(tipo[i] < 0) continue;
        maior = max(maior, tipo[i]);
        for(int v = 0; v < 2; ++v) {
            int last = v;
            conta[tipo[i]][v] += last;
            for(int j = (i-1+N)%N; tipo[j]<0; j = (j-1+N)%N) {
                if(tipo[j] == -2) {
                    last = last^1;
                }
                conta[tipo[i]][v] += last;
            }
        }
    }

    int soma = 0;
    for(int i = 0; i <= max(maior, N); ++i) {
        soma += conta[i][0];
    }

    for(int i = 0; i <= N; ++i) {
        int k = soma - conta[i][0] + conta[i][1];
        if(k == i) {
            for(int j = 0; j < N; ++j) {
                if(tipo[j] < 0) continue;
                int last = val[j] = (i==tipo[j])?1:0;
                for(int k = (j-1+N)%N; tipo[k]<0; k = (k-1+N)%N) {
                    if(tipo[k] == -2) {
                        last = last^1;
                    }
                    val[k] = last;
                }
            }
            return true;
        }
    }
    return false;
}

int main(void) {

    freopen("truth.in", "r", stdin);
    freopen("truth.out", "w", stdout);

    int N;
    scanf("%d", &N);

    int k = -1;

    for(int i = 0; i < N; ++i) {
        char tmp[16];
        scanf("%s", tmp);
        if(tmp[0] == '+') {
            tipo[i] = -1;
        } else if(tmp[0] == '-') {
            tipo[i] = -2;
        } else {
            scanf("%d", &tipo[i]);
            k = i;
        }
    }

    bool achei = false;
    if(k == -1) {
        tipo[N] = tipo[0];
        for(int i = 0; i < 2; ++i) {
            val[0] = i;
            for(int j = 1; j <= N; ++j) {
                if(tipo[j-1] == -1) {
                    val[j] = val[j-1];
                } else if(tipo[j-1] == -2) {
                    val[j] = val[j-1] ^ 1;
                }
            }
            if(val[0] == val[N]) {
                achei = true;
                break;
            }
        }
    } else {
        achei = solve(N);
    }

    if(not achei) {
        printf("inconsistent\n");
    } else {
        printf("consistent\n");
        for(int i = 0; i < N; ++i) {
            printf("%s", val[i]==1?"t":"f");
        }
        printf("\n");
    }

    return 0;
}
