#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

char string[200200];
char target[200200];

int prev1[200200];
int prev2[200200];

int table[200200];

int resp[200200];

int last[256];

void computa_prev(char* str, int* prev) {
    memset(last, -1, sizeof(last));
    for(int i = 0; str[i] != 0; ++i) {
        prev[i] = last[int(str[i])];
        last[int(str[i])] = i;
    }
}


int main(void) {

    freopen("substring.in", "r", stdin);
    freopen("substring.out", "w", stdout);

    scanf("%s", string);
    scanf("%s", target);

    int N = strlen(string);
    int M = strlen(target);

    computa_prev(string, prev1);
    computa_prev(target, prev2);

    table[0] = -1;
    for(int i = 1; i < M; ++i) {
        int p = table[i-1] + 1;
        while(42) {
            int p1 = prev2[i] - (i-p);
            if(p1 < 0) p1 = -1;
            if(p < 0 or p1 == prev2[p]) {
                break;
            }
            p = table[p];
        }
        table[i] = p;
    }

    int K = 0;

    for(int i = 0, p = 0; i < N; ++i) {
        while(42) {
            int p1 = prev1[i] - (i-p);
            if(p1 < 0) p1 = -1;
            if(p < 0 or p1 == prev2[p]) {
                if(p == M-1) {
                    resp[K++] = i - M + 1;
                } else {
                    break;
                }
            }
            p = table[p];
        }
        ++p;
    }

    printf("%d\n", K);
    for(int i = 0; i < K; ++i) {
        printf("%d ", resp[i]+1);
    }
    printf("\n");

    return 0;
}
