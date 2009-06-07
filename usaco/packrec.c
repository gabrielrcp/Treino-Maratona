/*
ID: gabriel9
LANG: C
TASK: packrec
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int ret[4][2];

int **sols;
int numsol = 0;

int usado[4] = {0, 0, 0, 0};
int usar[4][2];

int min = 10001;

FILE *fin;
FILE *fout;

int max2(int a, int b){
  return ( (a > b) ? a : b );
}
int max3(int a, int b, int c){
  return max2(max2(a, b), c);
}
int max4(int a, int b, int c, int d){
  return max2(max3(a, b, c), d);
}


int min2(int a, int b){
  return ( (a < b) ? a : b );
}

int min3(int a, int b, int c){
  return min2(min2(a, b), c);
}

int min4(int a, int b, int c, int d){
  return min2(min3(a, b, c), d);
}

/*
int problema()
{
  
  int i, j;
  for(i=0; i<4; i++){
    if(i == 0 || i == 2)
      j = i+1;
    else
      j = i-1;
    if(usar[i][0] > usar[(i+2)%4][0] && usar[i][1] > usar[j][1])
      return 1;
  }
  
  return 0;
}
*/

void gerapermut(int ini)
{
  int i;
  int w, h;

  if(ini == 4){


    w = 0;
    for(i=0; i<4; i++)
      w += usar[i][0];
    h = max4(usar[0][1], usar[1][1], usar[2][1], usar[3][1]);
    if(h * w < min){
      numsol = 1;
      sols[0][0] = min2(h, w);
      sols[0][1] = max2(h, w);
      min = h*w;
    }
    else if(h*w == min){
      sols[numsol][0] = min2(h, w);
      sols[numsol][1] = max2(h, w);
      numsol++;
    }


    w = 0;
    for(i=0; i<3; i++)
      w += usar[i][0];
    w = max2(usar[3][0], w);

    h = max3(usar[0][1], usar[1][1], usar[2][1]);
    h += usar[3][1];
    if(h * w < min){
      numsol = 1;
      sols[0][0] = min2(h, w);
      sols[0][1] = max2(h, w);
      min = h*w;
    }
    else if(h * w == min){
      sols[numsol][0] = min2(h, w);
      sols[numsol][1] = max2(h, w);
      numsol++;
    }


    w = usar[2][0];
    w += max2(usar[0][0] + usar[1][0], usar[3][0]);
    h = max2(max2(usar[0][1], usar[1][1]) + usar[3][1], usar[2][1]);
    if(h * w < min){
      numsol = 1;
      sols[0][0] = min2(h, w);
      sols[0][1] = max2(h, w);
      min = h*w;
    }
    else if(h * w == min){
      sols[numsol][0] = min2(h, w);
      sols[numsol][1] = max2(h, w);
      numsol++;
    }


    w = usar[0][0] + usar[3][0];
    w += max2(usar[1][0], usar[2][0]);
    h = max3(usar[0][1], usar[1][1] + usar[2][1], usar[3][1]);
    if(h * w < min){
      numsol = 1;
      sols[0][0] = min2(h, w);
      sols[0][1] = max2(h, w);
      min = h*w;
    }
    else if(h * w == min){
      sols[numsol][0] = min2(h, w);
      sols[numsol][1] = max2(h, w);
      numsol++;
    }



    w = usar[2][0] + usar[3][0];
    w += max2(usar[0][0], usar[1][0]);
    h = max3(usar[0][1] + usar[1][1], usar[2][1], usar[3][1]);
    if(h * w < min){
      numsol = 1;
      sols[0][0] = min2(h, w);
      sols[0][1] = max2(h, w);
      min = h*w;
    }
    else if(h * w == min){
      sols[numsol][0] = min2(h, w);
      sols[numsol][1] = max2(h, w);
      numsol++;
    }


    /*
    if(problema()){
      w = max2(usar[0][0], usar[2][0]) + max2(usar[1][0], usar[3][0]);
      h = max2(usar[0][1], usar[1][1]) + max2(usar[2][1], usar[3][1]);
    }
    else{
      w = max2(usar[0][0] + usar[1][0], usar[2][0] + usar[3][0]);
      h = max2(usar[0][1] + usar[2][1], usar[1][1] + usar[3][1]);
    }
    */


    w = max2(usar[0][0], usar[2][0]) + max2(usar[1][0], usar[3][0]);
    h = max2(usar[0][1], usar[1][1]) + max2(usar[2][1], usar[3][1]);
    if(h * w < min){
      numsol = 1;
      sols[0][0] = min2(h, w);
      sols[0][1] = max2(h, w);
      min = h*w;
    }
    else if(h * w == min){
      sols[numsol][0] = min2(h, w);
      sols[numsol][1] = max2(h, w);
      numsol++;
    }

    
    if(usar[0][1] <= usar[1][1] && usar[1][0] <= usar[3][0] &&
       usar[3][1] <= usar[2][1]){
      w = max2(usar[0][0] + usar[1][0], usar[2][0] + usar[3][0]);
      h = max2(usar[0][1] + usar[2][1], usar[1][1] + usar[3][1]);
      if(h * w < min){
	numsol = 1;
	sols[0][0] = min2(h, w);
	sols[0][1] = max2(h, w);
	min = h*w;
      }
      else if(h * w == min){
	sols[numsol][0] = min2(h, w);
	sols[numsol][1] = max2(h, w);
	numsol++;
      }
    }
    
    return;
  }

  for(i=0; i<4; i++){
    if(usado[i])
      continue;
    usado[i] = 1;

    usar[ini][0] = ret[i][0];
    usar[ini][1] = ret[i][1];
    gerapermut(ini+1);

    usar[ini][0] = ret[i][1];
    usar[ini][1] = ret[i][0];
    gerapermut(ini+1);

    usado[i] = 0;
  }

}


int compara(const void *p1, const void *p2)
{
  int **a = (int **)p1;
  int **b = (int **)p2;
  return (**a - **b);
}


int main()
{
  int i, j;
  
  fin = fopen("packrec.in", "r");
  fout = fopen("packrec.out", "w");
  /*fin = stdin;
    fout = stdout;*/

  for(i=0; i<4; i++)
    fscanf(fin, " %d %d", &ret[i][0], &ret[i][1]);

  sols = (int **)malloc(MAX*sizeof(int *));
  for(i=0; i<MAX; i++)
    sols[i] = malloc(2*sizeof(int));  

  gerapermut(0);
  qsort(sols, numsol, sizeof(int *), compara);

  j = -1;
  fprintf(fout, "%d\n", min);
  for(i=0; i<numsol; i++){
    if(sols[i][0] != j){
      fprintf(fout, "%d %d\n", sols[i][0], sols[i][1]);
      j = sols[i][0];
    }
  }


  return 0;
}
