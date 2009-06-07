/*
ID: gabriel9
LANG: C
TASK: pprime
*/

#include <stdio.h>

#define MAX 100000

int validos[MAX];
int numval;


int ehprimo(int n)
{
  int i;
  for(i=2; i*i <= n; i++)
    if(n % i == 0)
      return 0;
  return 1;
}


int main()
{

  int d1, d2, d3, d4;
  int num;
  int a, b;
  
  FILE *fin = fopen("pprime.in", "r");
  FILE *fout = fopen("pprime.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  numval = 0;

  for(d1 = 5; d1<10; d1++){
    if(ehprimo(d1)){
      validos[numval] = d1;
      numval++;
    }
  }

  for(d1 = 1; d1 < 10; d1++){
    num = 10*d1+d1;
    if(ehprimo(num)){
      validos[numval] = num;
      numval++;
    }
  }


  for(d1 = 1; d1 < 10; d1++){
    for(d2 = 0; d2 < 10; d2++){
      num = 100*d1+ 10*d2 + d1;
      if(ehprimo(num)){
	validos[numval] = num;
	numval++;
      }
    }
  }

  for(d1 = 1; d1 < 10; d1++){
    for(d2 = 0; d2 < 10; d2++){
      num = 1000*d1+ 100*d2 + 10*d2 + d1;
      if(ehprimo(num)){
	validos[numval] = num;
	numval++;
      }
    }
  }

  for(d1 = 1; d1 < 10; d1++){
    for(d2 = 0; d2 < 10; d2++){
      for(d3 = 0; d3 < 10; d3++){
	num = 10000*d1+ 1000*d2 + 100*d3 + 10*d2 + d1;
	if(ehprimo(num)){
	  validos[numval] = num;
	  numval++;
	}
      }
    }
  }

  for(d1 = 1; d1 < 10; d1++){
    for(d2 = 0; d2 < 10; d2++){
      for(d3 = 0; d3 < 10; d3++){
	num = 100000*d1+ 10000*d2 + 1000*d3 + 100*d3  + 10*d2 + d1;
	if(ehprimo(num)){
	  validos[numval] = num;
	  numval++;
	}
      }
    }
  }


  for(d1 = 1; d1 < 10; d1++){
    for(d2 = 0; d2 < 10; d2++){
      for(d3 = 0; d3 < 10; d3++){
	for(d4 = 0; d4 < 10; d4++){
	  num = 1000000*d1 +
	        100000*d2 +
	        10000*d3 +
	        1000*d4 +
	        100*d3 +
	        10*d2 +
	         d1;
	  if(ehprimo(num)){
	    validos[numval] = num;
	    numval++;
	  }
	}
      }
    }
  }

  
  for(d1 = 1; d1 < 10; d1++){
    for(d2 = 0; d2 < 10; d2++){
      for(d3 = 0; d3 < 10; d3++){
	for(d4 = 0; d4 < 10; d4++){
	  num = 
	    10000000*d1 +
	    1000000*d2 +
	    100000*d3 +
	    10000*d4 +
	    1000*d4 +
	    100*d3 +
	    10*d2 +
	    d1;
	  if(ehprimo(num)){
	    validos[numval] = num;
	    numval++;
	  }
	}
      }
    }
  }

  fscanf(fin, " %d %d", &a, &b);
  num = 0;
  while(num < numval && validos[num] < a)
    num++;
  while(num < numval && validos[num] <= b){
    fprintf(fout, "%d\n", validos[num]);
      num++;
  }

  return 0;
}
