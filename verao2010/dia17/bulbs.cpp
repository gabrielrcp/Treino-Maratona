#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str1[200];
char str2[200];

int initial[500];
int target[500];

int current[500];

int push[500];

int melhor[500];


int decode(char* str, int *v) {
    int N = strlen(str);
    for(int i = 0; i < N; ++i) {
        str[i] -= '0';
    }

    int M = 0;
    while(42) {
        int resto = 0;
        bool achei = false;
        for(int i = 0; i < N; ++i) {
            int tmp = str[i] + resto*10;
            str[i] = tmp / 2;
            resto = tmp %2;
            if(str[i] != 0) {
                achei = true;
            }
        }
        v[M] = resto;
        M++;
        if(not achei) {
            break;
        }
    }

    return M;

}

#define MAXT 200

int bignumber[MAXT];

void encode(char* str, int *v, int N) {
    for(int i = 0; i < MAXT; ++i) bignumber[i] = 0;
    for(int i = 0; i < N; ++i) {
        int vai = v[N-i-1];
        for(int j = 0; j < MAXT; ++j) {
            int tmp =bignumber[j]*2 + vai;
            bignumber[j] = tmp % 10;
            vai =  tmp /10;
        }
    }
    int M;
    for(M = MAXT-1; bignumber[M] == 0 and M >= 0; --M);
    if(M == -1) {
        str[0] = '0';
        str[1] = 0;
        return;
    }
    for(int p = M; p >= 0; --p) {
        str[p] = bignumber[p] +  '0';
    }

    reverse(str, str+M+1);
    str[M+1] = 0;

}

int main(void) {

    int T = 0;

    freopen("bulbs.in", "r", stdin);
    freopen("bulbs.out", "w", stdout);

    while(scanf("%s%s", str1, str2) and (str1[0]!='0' or str2[0] != '0')) {

        memset(initial, 0, sizeof(initial));
        memset(target, 0, sizeof(target));

        int A = decode(str1, initial);
        int B = decode(str2, target);
        int N = max(A, B);

        bool achei = false;

        if(N >= 2) {
            int resp = 1000000000;
            for(int f = 0; f < 2;++f) {
                int conta = 0;
                for(int i = 0; i < N; ++i) current[i] = initial[i];
                if(f) {
                    current[0] ^= 1;
                    current[1] ^= 1;
                }
                push[0] = f;
                conta = f;
                for(int i = 0; i < N-1; ++i) {
                    if(current[i] != target[i]) {
                        current[i] ^= 1;
                        current[i+1] ^= 1;
                        current[i+2] ^= 1;
                        push[i+1] = 1;
                        conta ++;
                    } else {
                        push[i+1] = 0;
                    }
                }
                if(target[N-1] == current[N-1]) {
                    achei = true;
                    if(conta < resp) {
                        resp = conta;
                        for(int i= 0; i < N; ++i) melhor[i] = push[i];
                    }
                    if(conta == resp) {
                        int df = 0;
                        for(int i = N-1; i >= 0; ++i) {
                            if(melhor[i] != push[i]) {
                                df = i;
                                break;
                            }
                        }
                        if(push[df] < melhor[df]) {
                            for(int i= 0; i < N; ++i) melhor[i] = push[i];
                        }
                    }
                }
            }
        } else {
            melhor[0] = initial[0] == target[0]?0:1;
            achei = true;
        }

        if(T>0) printf("\n");
        if(achei) {
            encode(str1, melhor, N);
            printf("Case Number %d: %s\n", ++T, str1);
        } else {
            printf("Case Number %d: impossible\n", ++T);
        }



    
    }
    
    return 0;
}
        
