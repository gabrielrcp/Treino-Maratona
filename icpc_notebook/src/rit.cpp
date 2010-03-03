
#define MAX_ELEMENTS 100
int soma[MAX_ELEMENTS];
int bit_tam;


void init(int N) {
    bit_tam = N;
    memset(soma, 0, sizeof(soma[0])*bit_tam);
}

/* O(lg bit_tam) */
void add(int p, int amount) {
    int inicio=0, fim = bit_tam-1, meio;
    while(inicio <= fim) {
        meio = (inicio + fim) / 2;
        if(p <= meio) {
            soma[meio] += amount;
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
}

/* O(lg bit_tam)
 * returns sumation of [0,p] */
int get(int p) {
    int inicio=0, fim = bit_tam-1, meio, ret = 0;
    while(inicio <= fim) {
        meio = (inicio + fim) / 2;
        if(p < meio) {
            fim = meio - 1;
        } else {
            ret = (soma[meio] + ret) % MOD;
            inicio = meio + 1;
        }
    }
    return ret;
}

/* O(lg bit_tam)
 * returns smaller p that get(p)>=amount */
int find(int amount) {
    int inicio=0, fim = bit_tam-1, meio, ultimo = bit_tam-1;
    while(inicio <= fim) {
        meio = (inicio + fim) / 2;
        if(soma[meio] < amount) {
            amount -= soma[meio];
            inicio = meio + 1;
        } else {
            ultimo = meio;
            fim = meio - 1;
        }
    }
    return ultimo;
}
