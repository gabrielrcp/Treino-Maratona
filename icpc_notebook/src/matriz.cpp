#include <iostream>
#include <cstring>

using namespace std;

#define MAX_TAM 64
#define MOD 123

#define EVAL(x) (x)
//#define EVAL(x) ((x) % MOD)

typedef int element_t;

typedef element_t vetor_t[MAX_TAM];
typedef element_t matriz_t[MAX_TAM][MAX_TAM];

void vet_cpy(vetor_t& r, const vetor_t& v, int size) {
    memcpy(r, v, sizeof(r[0])*size);
}

void mat_zero(matriz_t& r, int size) {
    for(int i=0;i<size;++i) {
        memset(r[i], 0, sizeof(r[0][0])*size);
    }
}

void mat_ident(matriz_t& r, int size) {
    mat_zero(r, size);
    for(int i=0;i<size;++i) {
        r[i][i] = 1;
    }
}

void mat_cpy(matriz_t& r, const matriz_t& m, int size) {
    for(int i=0;i<size;++i) {
        memcpy(r[i], m[i], sizeof(m[0][0])*size);
    }
}

void mat_add(matriz_t& r, const matriz_t& m, int size) {
    for(int i=0;i<size;++i) {
        for(int j=0;j<size;++j) {
            r[i][j] = EVAL(r[i][j] + m[i][j]);
        }
    }
}

void mat_add(matriz_t& r, const matriz_t& m1, const matriz_t& m2, int size) {
    mat_cpy(r, m1, size);
    mat_add(r, m2, size);
}

void mat_mul(matriz_t& r, const matriz_t& m1, const matriz_t& m2, int size) {
    for(int i=0;i<size;++i) {
        for(int j=0;j<size;++j) {
            r[i][j] = 0;
            for(int k=0;k<size;++k) {
                r[i][j] = EVAL(r[i][j] + m1[i][k] * m2[k][j]);
            }
        }
    }
}

void mat_mul(matriz_t& r, const matriz_t& m, int size) {
    matriz_t tmp;
    mat_mul(tmp, r, m, size);
    mat_cpy(r, tmp, size);
}

void vet_mul(vetor_t& r, const matriz_t& m, const vetor_t& v, int size) {
    for(int i=0;i<size;++i) {
        r[i] = 0;
        for(int j=0;j<size;++j) {
            r[i] = EVAL(r[i] + m[i][j] * v[j]);
        }
    }
}

void vet_mul(vetor_t& r, const matriz_t& m, int size) {
    vetor_t tmp;
    vet_mul(tmp, m, r, size);
    vet_cpy(r, tmp, size);
}

void mat_pow(matriz_t& r, int e, int size) {
    matriz_t b;
    mat_cpy(b, r, size);
    mat_ident(r, size);

    while(e>0) {
        if(e%2==1) {
            mat_mul(r, b, size);
        }
        mat_mul(b, b, size);
        e/=2;
    }
}

void mat_pow(matriz_t& r, const matriz_t& b, int e, int size) {
    mat_cpy(r, b, size);
    mat_pow(r, e, size);
}
