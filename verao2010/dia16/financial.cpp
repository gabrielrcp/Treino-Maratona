#include <cstdio>
#include <algorithm>

using namespace std;

int values[100100];

int all_v[100100];

int next[100100];

struct node_t {
    node_t* left, *right;
    int maior;
    int inicio, fim;
    int id;
};

node_t buffer[200200];
int buffer_pos = 0;

node_t* build(int inicio, int fim) {
    if(inicio > fim) return 0;
    node_t* node = buffer+(buffer_pos++);
    node->maior = 0;
    node->inicio = inicio;
    node->fim = fim;
    node->id = -1;
    if(inicio < fim) {
        int meio = (inicio+fim)/2;
        node->left = build(inicio, meio);
        node->right = build(meio+1, fim);
    } else {
        node->left = node->right = 0;
    }
    return node;
}

int search(node_t* node, int inicio, int fim, int& id) {
    if(node->inicio >= inicio and  node->fim<=fim) {
        id = node->id;
        return node->maior;
    } else if(node->fim < inicio or node->inicio > fim) {
        return 0;
    } else {
        int tmp1, tmp2;
        int v1 = search(node->left, inicio, fim, tmp1);
        int v2 = search(node->right, inicio, fim, tmp2);
        if(v1 > v2) {
            id = tmp1;
            return v1;
        } else {
            id = tmp2;
            return v2;
        }
    }
}

void insert(node_t* node, int val, int pos, int id) {
    if(node == 0 or pos > node->fim or pos < node->inicio) {
        return;
    } else {
        if(node->maior < val) {
            node->id = id;
            node->maior = val;
        }
        insert(node->left, val, pos, id);
        insert(node->right, val, pos, id);
    }
}

int main(void) {

    freopen("financial.in", "r", stdin);
    freopen("financial.out", "w", stdout);

    int N, K;
    scanf("%d%d", &N, &K);

    for(int i = 0; i < N; ++i) {
        scanf("%d", values+i);
        all_v[i] = values[i];
    }

    sort(all_v, all_v+N);
    int M = unique(all_v, all_v+N) - all_v;

    node_t* root = build(0, N);

    for(int i = N-1; i>= 0; --i) {
        int v1 = lower_bound(all_v, all_v+M, values[i]+K) - all_v;
        int v2 = upper_bound(all_v, all_v+M, values[i]-K) - all_v - 1;
        int v3 = lower_bound(all_v, all_v+M, values[i]) - all_v;
        int id1, id2, r1, r2, r3;
        r1 = search(root, v1, N, id1) + 1; 
        r2 = search(root, 0, v2, id2) + 1;
        if(r1 > r2) {
            next[i] = id1;
            r3 = r1;
        } else {
            next[i] = id2;
            r3 = r2;
        }
        if(r3 == 1) {
            next[i] = -1;
        }
        insert(root, r3, v3, i);
    }

    int first;
    int resp = search(root, 0, N, first);
    printf("%d\n", resp);
    for(; first != -1; first = next[first]) {
        printf("%d ", values[first]);
    }
    printf("\n");

    return 0;
}
