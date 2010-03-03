
#define PASCAL_LINES 100
#define PASCAL_COLUMNS 100

long long comb[PASCAL_LINES][PASCAL_COLUMNS];

void pascal(void) {
    comb[0][0]=1;
    for(int i=1;i<PASCAL_COLUMNS;++i)
        comb[0][i]=0;
    for(int i=1;i<PASCAL_LINES;++i) {
        comb[i][0]=1;
        for(int j=1;j<PASCAL_COLUMNS;++j)
            comb[i][j]=(comb[i-1][j-1]+comb[i-1][j]);
    }
}
