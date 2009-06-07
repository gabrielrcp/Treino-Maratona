/*
ID: gabriel9
LANG: C
TASK: friday
*/

#include <stdio.h>

int main()
{
  
  FILE *fin = fopen("friday.in", "r");
  FILE *fout = fopen("friday.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  int  i;
  int freq[7];
  int n;
  int dia=1, mes=1, ano=1900;
  int ds = 2; /*segunda*/

  fscanf(fin, " %d", &n);
  
  for(i=0; i<7; i++)
    freq[i] = 0;

  while(ano <= 1899 + n){
    dia++;
    ds++;
    ds %= 7;
    switch(dia){
      case 13: freq[ds]++; break;
      case 30:
        switch(mes){
  	  case 4:
          case 6:
          case 9:
          case 11:
	    mes++;
	    dia = 0;
	  default: break;
	}
	break;
      case 31:
        switch(mes){
	  case 12:
	    ano++;
	    mes = 0;
          case 1:
          case 3:
          case 5:
          case 7:
          case 8:
          case 10:
	    mes++;
	    dia = 0;
	  default: break;
	}
	break;
      case 28:
	if(mes == 2){
	  if(ano % 4 == 0){
	    if(ano % 100 == 0 && ano % 400 != 0){
	      mes++;
	      dia = 0;
	    }
	  }
	  else{
	    mes++;
	    dia = 0;
	  }
	}
	break;
      case 29:
	if(mes == 2){
	  mes++;
	  dia = 0;
	}
      default:
	break;
    }
  }
  for(i=0; i<6; i++)
    fprintf(fout, "%d ", freq[i]);
  fprintf(fout, "%d\n", freq[6]);

  return 0;
}

