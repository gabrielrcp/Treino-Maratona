/*
ID: gabriel9
LANG: C
TASK: ratios
*/

#include <stdio.h>

typedef struct{
  int x, y, z;
} Mistura;

Mistura obj;
Mistura base[3];
Mistura total;

int min(int a, int b)
{
  return (a < b ? a : b);
}

int main()
{
  int i, j, k, soma;
  int l;
  FILE *fin = fopen("ratios.in", "r");
  FILE *fout = fopen("ratios.out", "w");

  fscanf(fin, " %d %d %d", &obj.x, &obj.y, &obj.z);
  for(i=0; i<3; i++)
    fscanf(fin, " %d %d %d", &base[i].x, &base[i].y, &base[i].z);

  for(soma = 1; soma < 300; soma++){
    for(i=0; i <= min(soma, 99); i++){
      for(j=0; j <= min(soma-i, 99); j++){
	k = soma - i - j;
	if(k > 100)
	  continue;
	total.x = i * base[0].x + j * base[1].x + k * base[2].x;
	total.y = i * base[0].y + j * base[1].y + k * base[2].y;
	total.z = i * base[0].z + j * base[1].z + k * base[2].z;
	if(total.x % obj.x != 0)
	  continue;
	l = total.x / obj.x;
	if(total.y != l * obj.y)
	  continue;
	if(total.z == l * obj.z){
	  fprintf(fout, "%d %d %d %d\n", i, j, k, l);
	  return 0;
	}
      }
    }
  }

  fprintf(fout, "NONE\n");
  return 0;
}
