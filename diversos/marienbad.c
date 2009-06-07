#include <stdio.h>
#include <stdlib.h>

int r[2][4][6][8][10][12];

void inicia()
{
  int i0, i1, i2, i3, i4, i5;
  for(i0=0; i0<2; i0++)
    for(i1=0; i1<4; i1++)
      for(i2=0; i2<6; i2++)
	for(i3=0; i3<8; i3++)
	  for(i4=0; i4<10; i4++)
	    for(i5=0; i5<12; i5++)
	      r[i0][i1][i2][i3][i4][i5] = -1;
  i1 = 0;
  r[0][0][0][0][0][0] = 1;
}

int jogaGanha(int *p)
{
  int i, j;
  i = r[p[0]][p[1]][p[2]][p[3]][p[4]][p[5]];
  if(i != -1) return i;

  for(i=0; i< 6; i++){
    for(j=1; j <= p[i]; j++){
      p[i] -= j;
      if(jogaGanha(p) == 0){
	r[p[0]][p[1]][p[2]][p[3]][p[4]][p[5]] = 0;
	p[i] += j;
	r[p[0]][p[1]][p[2]][p[3]][p[4]][p[5]] = 1;
	return 1;
      }
      p[i] += j;
    }
  }
  r[p[0]][p[1]][p[2]][p[3]][p[4]][p[5]] = 0;
  return 0;
}

int main()
{
  int n, h, i;
  int p[6];
  scanf(" %d", &n);
  inicia();
  for(h=1; h<=n; h++){
    for(i=0; i<6; i++)
      scanf(" %d", &p[i]);
    printf("Instancia %d\n%s\n\n", h, (jogaGanha(p) ? "sim" : "nao"));
  }
  return 0;
}
