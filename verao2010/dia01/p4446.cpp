#include <cstdio>
#include <cstring>

int value[50];

char type[50];

int inputs[50][2];

int output[50];

int expect[50];

int possible[50][3];

int error_gate, error_type;

int decode(char* name) {
    char c;
    int id;
    sscanf(name,  "%c%d", &c, &id);
    --id;
    if(c=='g') id += 8;
    return id;
}

int computa(int porta) {
    if(value[porta] != -1) return value[porta];
    int v1 = computa(inputs[porta][0]);
    int v2 = type[porta] != 'n' ? computa(inputs[porta][1]):0;
    int v3;
    if(type[porta] == 'a') {
        v3 = v1 & v2;
    } else if(type[porta] == 'o') {
        v3 = v1 | v2;
    } else if(type[porta] == 'x') {
        v3 = v1 ^ v2;
    } else if(type[porta] == 'n') {
        v3 = v1 ^ 1;
    }
    if(error_gate == porta) {
        if(error_type == 1) {
            v3 = v3 ^ 1;
        } else if(error_type == 2) {
            v3 = 0;
        } else if(error_type == 3) {
            v3 = 1;
        }
    }
    return value[porta] = v3;
}

int N, G, U;
int testa() {
    for(int i = 0; i < G; ++i) value[i+8] = -1;
    for(int i = 0; i < U; ++i) {
        if(computa(output[i]) != expect[i]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int C = 0;
    while(scanf("%d%d%d", &N, &G, &U) and (N != 0 or G != 0 or U != 0)) {
        memset(type, 0, sizeof(type));
        for(int i = 0; i < G; ++i) {
            char s1[8], s2[8], s3[8];
            scanf("%s%s", s1, s2);
            int id = i + 8;
            type[id] = s1[0];
            inputs[id][0] = decode(s2);
            if(type[id] != 'n') {
                scanf("%s", s3);
                inputs[id][1] = decode(s3);
            }
        }
        for(int i= 0; i < U; ++i) {
            scanf("%d", output+i);
            output[i] += 8 - 1;
        }

        int B;
        int ok = 1;
        int conta = G*3;
        scanf("%d", &B);
        memset(possible, 1, sizeof(possible));
        for(int k = 0; k < B; ++k) {
            for(int i = 0; i < N; ++i) {
                scanf("%d", value+i);
            }
            for(int i = 0; i < U; ++i) {
                scanf("%d", expect+i);
            }
            error_type = 0;
            ok = ok and testa();
            for(int i = 0; i < G; ++i) {
                for(int j = 0; j < 3; ++j) {
                    if(not possible[i][j]) continue;
                    error_gate = i + 8;
                    error_type = j + 1;
                    if(not testa()) {
                        possible[i][j] = 0;
                        conta --;
                    }
                }
            }
        }
        printf("Case %d: ", ++C);
        if(ok) {
            printf("No faults detected");
        } else if(conta > 1) {
            printf("Unable to totally classify the failure");
        } else {
            for(int i = 0; i < G; ++i) {
                for(int j = 0; j < 3; ++j) {
                    if(possible[i][j]) {
                        printf("Gate %d is failing; output ", i+1);
                        if(j == 0) {
                            printf("inverted");
                        } else if(j == 1) {
                            printf("stuck at 0");
                        } else {
                            printf("stuck at 1");
                        }
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
