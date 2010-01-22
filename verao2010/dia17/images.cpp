#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

#define MAX 200
char str1[MAX], str2[MAX];

int code1[500];
int code2[500];

int code3[100000];

char output[100000];

int decode(char* str, int* code) {
    int N = strlen(str), M = 0;
    for(int i = 0 ; i < N; ++i) {
        int n;
        if(isdigit(str[i])) {
            n = str[i]- '0';
        } else {
            n = str[i]- 'A' + 10;
        }
        for(int j = 0; j < 4; ++j) {
            code[M++] = (n >> (3-j)) & 1;
        }
    }
    return M;
}

struct node_t {
    int tipo;
    node_t* child[4];
};

node_t buffer[100000];
int buffer_pos;

node_t* alloc_node() {
    return buffer + (buffer_pos++);
}

node_t* build_tree(int *code, int& pos) {
    node_t* node = alloc_node();
    if(code[pos] == 1) {
        node->tipo = 1 + code[pos+1];
        pos +=2;
    } else {
        node->tipo = 0;
        pos++;
        for(int i = 0 ; i < 4; ++i) {
            node->child[i] = build_tree(code, pos);
        }
    }
    return node;
}

node_t* intersect_tree(node_t* node1, node_t* node2) {
    if(node1->tipo == 1 or node2->tipo == 2) {
        return node1;
    } else if(node2->tipo == 1 or node1->tipo == 2) {
        return node2;
    } else {
        node_t* node = alloc_node();
        node->tipo = 0;
        for(int i = 0; i < 4; ++i) {
            node->child[i] = intersect_tree(node1->child[i], node2->child[i]);
        }
        int t = 3;
        for(int i = 0; i < 4; ++i) {
            t &= node->child[i]->tipo;
        }
        if(t != 0) {
            node->tipo = t;
        }
        return node;
    }
}

int encode_tree(node_t* node, int* code) {
    if(node->tipo != 0) {
        code[0] = 1;
        code[1] = node->tipo - 1;
        return 2;
    } else {
        code[0] = 0;
        int pos = 1;
        for(int i = 0; i < 4; ++i) {
            pos += encode_tree(node->child[i], code+pos);
        }
        return pos;
    }
}

int main(void) {

    int T = 0;

    freopen("images.in", "r", stdin);
    freopen("images.out", "w", stdout);

    while(scanf("%s%s", str1, str2) and (str1[0] != '0' or str2[0] != '0')) {

        buffer_pos = 0;

        decode(str1, code1);
        decode(str2, code2);

        int pos;

        pos = 0;
        while(code1[pos] == 0) pos++;
        pos++;
        node_t* node1 = build_tree(code1, pos);

        pos = 0;
        while(code2[pos] == 0) pos++;
        pos++;
        node_t* node2 = build_tree(code2, pos);

        node_t* node3 = intersect_tree(node1, node2);

        int t = encode_tree(node3, code3+1) + 1;
        code3[0] = 1;
        while(t % 4 != 0) {
            for(int i = t; i > 0; --i) {
                code3[i] = code3[i-1];
            }
            code3[0]=0;
            ++t;
        }
        int R = 0;
        for(int i = 0; i < t; i += 4) {
            int n = code3[i+3] + 2*(code3[i+2] + 2*(code3[i+1] + 2*code3[i])); 
            if(n < 10) {
                output[R] = n + '0';
            } else {
                output[R] = n-10 + 'A';
            }
            ++R;
        }

        output[R] = 0;

        if(T>0) printf("\n");
        printf("Image %d:\n%s\n", ++T, output);




    }
    
    return 0;
}
        
