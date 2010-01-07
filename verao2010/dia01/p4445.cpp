#include <cstdio>
#include <algorithm>

using namespace std;

int A[8], B[8];
int ordem[8];

int main(void) {
    int N, C = 0;

    while(scanf("%d", &N) != -1 and N > 0) {
        for(int i=0;i<N;++i) {
            scanf("%d%d", A+i, B+i);
            ordem[i] = i;
        }
        double resp = 0.0;
        do {
            double inicio = 0.0, fim = 1440.0;
            for(int T = 0; T < 100; ++T) {
                double meio = (inicio + fim) * 0.5;
                double tempo = A[ordem[0]];
                bool fail = false;
                for(int i = 1; i < N; ++i) {
                    int id = ordem[i];
                    tempo = max(tempo + meio, double(A[id]));
                    if(tempo > B[id]) {
                        fail = true;
                        break;
                    }
                }
                if(fail) {
                    fim = meio;
                } else {
                    inicio = meio;
                }
            }
            resp = max(resp, (inicio + fim) * 0.5);
        } while(next_permutation(ordem, ordem+N));

        int minutos = resp;
        int segundos = (resp - minutos) * 60 + 0.5;
        printf("Case %d: %d:%02d\n", ++C, minutos, segundos);

    }

    return 0;
}
