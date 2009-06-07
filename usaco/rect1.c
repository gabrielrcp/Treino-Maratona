/*
ID: gabriel9
LANG: C
TASK: rect1
*/

#include <stdio.h>

typedef struct{
  int lx, ly, tx, ty, c;
} RECT;

RECT rect[500000];
int cores[2500];
int nr;

int main()
{
  int a, b, n;
  int i, j, k;
  int area;

  FILE *fin = fopen("rect1.in", "r");
  FILE *fout = fopen("rect1.out", "w");

  fscanf(fin, " %d %d %d", &a, &b, &n);

  nr = 0;
  for(i=0; i<n; i++){
    fscanf(fin, " %d %d %d %d %d", &rect[nr].lx, &rect[nr].ly,
	                           &rect[nr].tx, &rect[nr].ty,
	                           &rect[nr].c);
    rect[nr].c--;
    k = 1;
    for(j=0; j < nr; j++){
      if(rect[j].lx == rect[nr].lx && rect[j].ly == rect[nr].ly &&
	 rect[j].tx == rect[nr].tx && rect[j].ty == rect[nr].ty)
	{
	  rect[j].c = rect[nr].c;
	  k = 0;
	  break;
	}
      else if(rect[j].lx >= rect[nr].tx || rect[j].tx <= rect[nr].lx ||
	      rect[j].ly >= rect[nr].ty || rect[j].ty <= rect[nr].ly)
	{
	  /* Nao vou achar nada */
	  continue;
	}
      else if(rect[nr].lx <= rect[j].lx && rect[j].tx <= rect[nr].tx &&
	      rect[nr].ly <= rect[j].ly && rect[j].ty <= rect[nr].ty)
	{
	  /*1*/
	  rect[j].lx = rect[j].ly = rect[j].tx = rect[j].ty = 0;
	}
      else if(rect[j].lx <= rect[nr].lx && rect[nr].tx <= rect[j].tx &&
	      rect[j].ly <= rect[nr].ly && rect[nr].ty <= rect[j].ty)
	{
	  /*2*/
	  rect[nr+k].lx = rect[j].lx;
	  rect[nr+k].ly = rect[nr].ty;
	  rect[nr+k].tx = rect[j].tx;
	  rect[nr+k].ty = rect[j].ty;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "22\n");
	  */
	  k++;
	  rect[nr+k].lx = rect[j].lx;
	  rect[nr+k].ly = rect[nr].ly;
	  rect[nr+k].tx = rect[nr].lx;
	  rect[nr+k].ty = rect[nr].ty;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "23\n");
	  */
	  k++;
	  rect[nr+k].lx = rect[nr].tx;
	  rect[nr+k].ly = rect[nr].ly;
	  rect[nr+k].tx = rect[j].tx;
	  rect[nr+k].ty = rect[nr].ty;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "24\n");
	  */
	  k++;
	  /*
	  rect[j].lx = rect[j].lx;
	  rect[j].ly = rect[j].ly;
	  rect[j].tx = rect[j].tx;
	  */
	  rect[j].ty = rect[nr].ly;
	  /*
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "21\n");
	  */
	}
      else if(rect[j].lx <= rect[nr].lx && rect[nr].tx <= rect[j].tx &&
	      rect[j].ly <= rect[nr].ty && rect[nr].ty <= rect[j].ty)
	{
	  /*3*/
	  rect[nr+k].lx = rect[nr].lx;
	  rect[nr+k].ly = rect[nr].ty;
	  rect[nr+k].tx = rect[nr].tx;
	  rect[nr+k].ty = rect[j].ty;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "32\n");
	  */
	  k++;
	  rect[nr+k].lx = rect[nr].tx;
	  rect[nr+k].ly = rect[j].ly;
	  rect[nr+k].tx = rect[j].tx;
	  rect[nr+k].ty = rect[j].ty;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "33\n");
	  */
	  k++;
	  /*
	  rect[j].lx = rect[j].lx;
	  rect[j].ly = rect[j].ly;
	  */
	  rect[j].tx = rect[nr].lx;
	  /*rect[j].ty = rect[j].ty;*/
	  /*
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "31\n");
	  */
	}
      else if(rect[j].ly <= rect[nr].ly && rect[nr].ty <= rect[j].ty &&
	      rect[j].lx <= rect[nr].lx  && rect[nr].lx <= rect[j].tx)
	{
	  /*4*/
	  rect[nr+k].lx = rect[j].lx;
	  rect[nr+k].ly = rect[nr].ly;
	  rect[nr+k].tx = rect[nr].lx;
	  rect[nr+k].ty = rect[nr].ty;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "42\n");
	  */
	  k++;
	  rect[nr+k].lx = rect[j].lx;
	  rect[nr+k].ly = rect[j].ly;
	  rect[nr+k].tx = rect[j].tx;
	  rect[nr+k].ty = rect[nr].ly;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "43\n");
	  */
	  k++;
	  /*rect[j].lx = rect[j].lx;*/
	  rect[j].ly = rect[nr].ty;
	  /*
	  rect[j].tx = rect[j].tx;
	  rect[j].ty = rect[j].ty;
	  */
	  /*
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "41\n");
	  */
	}

      else if(rect[j].lx <= rect[nr].lx && rect[nr].tx <= rect[j].tx &&
	      rect[j].ly <= rect[nr].ly && rect[nr].ly <= rect[j].ty)
	{
	  /*5*/
	  rect[nr+k].lx = rect[nr].lx;
	  rect[nr+k].ly = rect[j].ly;
	  rect[nr+k].tx = rect[nr].tx;
	  rect[nr+k].ty = rect[nr].ly;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "52\n");
	  */
	  k++;
	  rect[nr+k].lx = rect[nr].tx;
	  rect[nr+k].ly = rect[j].ly;
	  rect[nr+k].tx = rect[j].tx;
	  rect[nr+k].ty = rect[j].ty;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "53\n");
	  */
	  k++;
	  /*
	  rect[j].lx = rect[j].lx;
	  rect[j].ly = rect[j].ly;
	  */
	  rect[j].tx = rect[nr].lx;
	  /*rect[j].ty = rect[j].ty;*/
	  /*
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "51\n");
	  */
	}

      else if(rect[j].ly <= rect[nr].ly && rect[nr].ty <= rect[j].ty &&
	      rect[j].lx <= rect[nr].tx  && rect[nr].tx <= rect[j].tx)
	{
	  /*6*/
	  rect[nr+k].lx = rect[nr].tx;
	  rect[nr+k].ly = rect[nr].ly;
	  rect[nr+k].tx = rect[j].tx;
	  rect[nr+k].ty = rect[nr].ty;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "62\n");
	  */
	  k++;
	  rect[nr+k].lx = rect[j].lx;
	  rect[nr+k].ly = rect[j].ly;
	  rect[nr+k].tx = rect[j].tx;
	  rect[nr+k].ty = rect[nr].ly;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "63\n");
	  */
	  k++;
	  /*rect[j].lx = rect[j].lx;*/
	  rect[j].ly = rect[nr].ty;
	  /*
	  rect[j].tx = rect[j].tx;
	  rect[j].ty = rect[j].ty;
	  */
	  /*
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "61\n");
	  */
	}
      else if(rect[j].lx <= rect[nr].tx && rect[nr].tx <= rect[j].tx &&
	      rect[j].ly <= rect[nr].ly && rect[nr].ly <= rect[j].ty)      
	{
	  /*7*/
	  rect[nr+k].lx = rect[nr].tx;
	  rect[nr+k].ly = rect[j].ly;
	  rect[nr+k].tx = rect[j].tx;
	  rect[nr+k].ty = rect[j].ty;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "72\n");
	  */
	  k++;
	  /*
	  rect[j].lx = rect[j].lx;
	  rect[j].ly = rect[j].ly;
	  */
	  rect[j].tx = rect[nr].tx;
	  rect[j].ty = rect[nr].ly;
	  /*
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "71\n");
	  */
	}
      else if(rect[j].lx <= rect[nr].lx && rect[nr].lx <= rect[j].tx &&
	      rect[j].ly <= rect[nr].ly && rect[nr].ly <= rect[j].ty)      
	{
	  /*8*/
	  rect[nr+k].lx = rect[nr].lx;
	  rect[nr+k].ly = rect[j].ly;
	  rect[nr+k].tx = rect[j].tx;
	  rect[nr+k].ty = rect[nr].ly;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "82\n");
	  */
	  k++;
	  /*
	  rect[j].lx = rect[j].lx;
	  rect[j].ly = rect[j].ly;
	  */
	  rect[j].tx = rect[nr].lx;
	  /*rect[j].ty = rect[j].ty;*/
	  /*
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "81\n");
	  */
	}
      else if(rect[j].lx <= rect[nr].lx && rect[nr].lx <= rect[j].tx &&
	      rect[j].ly <= rect[nr].ty && rect[nr].ty <= rect[j].ty)      
	{
	  /*9*/
	  rect[nr+k].lx = rect[j].lx;
	  rect[nr+k].ly = rect[j].ly;
	  rect[nr+k].tx = rect[nr].lx;
	  rect[nr+k].ty = rect[j].ty;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "92\n");
	  */
	  k++;
	  rect[j].lx = rect[nr].lx;
	  rect[j].ly = rect[nr].ty;
	  /*
	  rect[j].tx = rect[j].tx;
	  rect[j].ty = rect[j].ty;  
	  */
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "91\n");
	}
      else if(rect[j].lx <= rect[nr].tx && rect[nr].tx <= rect[j].tx &&
	      rect[j].ly <= rect[nr].ty && rect[nr].ty <= rect[j].ty)      
	{
	  /*10*/
	  rect[nr+k].lx = rect[nr].tx;
	  rect[nr+k].ly = rect[j].ly;
	  rect[nr+k].tx = rect[j].tx;
	  rect[nr+k].ty = rect[j].ty;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "102\n");
	  */
	  k++;
	  /*rect[j].lx = rect[j].lx;*/
	  rect[j].ly = rect[nr].ty;
	  rect[j].tx = rect[nr].tx;
	  /*rect[j].ty = rect[j].ty;*/
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "101\n");
	}
      else if(rect[nr].ly <= rect[j].ty && rect[j].ty <= rect[nr].ty &&
	      rect[nr].lx <= rect[j].lx && rect[j].tx <= rect[nr].tx)
	{
	  /*11*/
	  /*
	  rect[j].lx = rect[j].lx;
	  rect[j].ly = rect[j].ly;
	  rect[j].tx = rect[j].tx;
	  */
	  rect[j].ty = rect[nr].ly;
	  /*
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "111\n");
	  */
	}

      else if(rect[nr].ly <= rect[j].ly && rect[j].ly <= rect[nr].ty &&
	      rect[nr].lx <= rect[j].lx && rect[j].tx <= rect[nr].tx)
	{
	  /*12*/
	  /*rect[j].lx = rect[j].lx;*/
	  rect[j].ly = rect[nr].ty;
	  /*
	  rect[j].tx = rect[j].tx;
	  rect[j].ty = rect[j].ty;
	  */
	  /*
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "121\n");
	  */
	}

      else if(rect[nr].lx <= rect[j].tx && rect[j].tx <= rect[nr].tx &&
	      rect[nr].ly <= rect[j].ly && rect[j].ty <= rect[nr].ty)
	{
	  /*13*/
	  /*
	  rect[j].lx = rect[j].lx;
	  rect[j].ly = rect[j].ly;
	  */
	  rect[j].tx = rect[nr].lx;
	  /*rect[j].ty = rect[j].ty;*/
	  /*
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "131\n");
	  */
	}
      else if(rect[nr].lx <= rect[j].lx && rect[j].lx <= rect[nr].tx &&
	      rect[nr].ly <= rect[j].ly && rect[j].ty <= rect[nr].ty)
	{
	  /*14*/
	  rect[j].lx = rect[nr].tx;
	  /*
	  rect[j].ly = rect[j].ly;
	  rect[j].tx = rect[j].tx;
	  rect[j].ty = rect[j].ty;
	  */
	  /*
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "141\n");
	  */
	}
      else if(rect[j].lx <= rect[nr].lx && rect[nr].tx <= rect[j].tx)
	{
	  /*15*/
	  rect[nr+k].lx = rect[nr].tx;
	  rect[nr+k].ly = rect[j].ly;
	  rect[nr+k].tx = rect[j].tx;
	  rect[nr+k].ty = rect[j].ty;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "152\n");
	  */
	  k++;
	  /*
	  rect[j].lx = rect[j].lx;
	  rect[j].ly = rect[j].ly;
	  */
	  rect[j].tx = rect[nr].lx;
	  /*rect[j].ty = rect[j].ty;*/
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "151\n");
	}
      else if(rect[j].ly <= rect[nr].ly && rect[nr].ty <= rect[j].ty)
	{
	  /*16*/
	  rect[nr+k].lx = rect[j].lx;
	  rect[nr+k].ly = rect[j].ly;
	  rect[nr+k].tx = rect[j].tx;
	  rect[nr+k].ty = rect[nr].ly;
	  rect[nr+k].c = rect[j].c;
	  /*
	  if(rect[nr+k].tx < rect[nr+k].lx ||
	     rect[nr+k].ty < rect[nr+k].ly)
	    fprintf(stderr, "162\n");
	  */
	  k++;
	  /*rect[j].lx = rect[j].lx;*/
	  rect[j].ly = rect[nr].ty;
	  /*
	  rect[j].tx = rect[j].tx;
	  rect[j].ty = rect[j].ty;
	  */
	  if(rect[j].tx < rect[j].lx ||
	     rect[j].ty < rect[j].ly)
	    fprintf(stderr, "161\n");
	}
      else
	{
	  fprintf(stderr, "Opa!\n");
	  fprintf(stderr, "%d %d %d %d ", rect[j].lx, rect[j].ly,
		  rect[j].tx, rect[j].ty);
	  fprintf(stderr, "%d %d %d %d\n", rect[nr].lx, rect[nr].ly,
		  rect[nr].tx, rect[nr].ty);
	  return 1;
	}
    }
    nr += k;
  }

  cores[0] = a*b;
  for(i=0; i<nr; i++){
    area = (rect[i].tx - rect[i].lx) * (rect[i].ty - rect[i].ly);
    /*
    if(area > 0 && rect[i].c != 0)
      printf("%d %d %d %d\n", rect[i].lx, rect[i].ly,
	     rect[i].tx, rect[i].ty);
    */
    cores[rect[i].c] += area;
    cores[0] -= area;   
  }

  /*
  for(i=0; i<a; i++)
    for(j=0; j<b; j++){
      char achei;
      achei = 0;
      for(k=0; k < nr; k++){
	if(rect[k].lx <= i && i < rect[k].tx && 
	   rect[k].ly <= j && j < rect[k].ty){
	  if(achei)
	    fprintf(stderr, "Ponto em + de um retangulo\n");
	  else
	    achei = 1;
	}
      }
    }
  */
  

  for(i=0; i<2500; i++)
    if(cores[i] > 0)
      fprintf(fout, "%d %d\n", i+1, cores[i]);

  return 0;
}
