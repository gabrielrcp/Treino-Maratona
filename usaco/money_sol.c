/*
PROG: money
ID: rsc001
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXTOTAL 10000

long long nway[MAXTOTAL+1];

int main(void)
{
	FILE *fin, *fout;
	int i, j, n, v, c;

	fin = fopen("money.in", "r");
	fout = fopen("money.out", "w");
	assert(fin != NULL && fout != NULL);

	fscanf(fin, "%d %d", &v, &n);

	nway[0] = 1;
	for(i=0; i<v; i++) {
		fscanf(fin, "%d", &c);

		for(j=c; j<=n; j++)
			nway[j] += nway[j-c];
	}

	fprintf(fout, "%lld\n", nway[n]);
	return 0;
}
