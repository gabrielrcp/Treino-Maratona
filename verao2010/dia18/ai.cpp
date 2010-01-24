
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

char buf[10000];

int main()
{
#ifndef LOCAL
  freopen("ai.in", "r", stdin);
  freopen("ai.out", "w", stdout);
#endif

  int casos;
  scanf("%d\n", &casos);
  for(int h = 1; h <= casos; h++){
    double val[3];
    bool deu[3] = {false, false, false};
    int tipo[256];
    tipo['P'] = 0;
    tipo['U'] = 1;
    tipo['I'] = 2;

    gets(buf);
    for(int i = 0; buf[i]; i++){
      if(buf[i] == '='){
	int t = tipo[(int)buf[i-1]];
	deu[t] = true;
	sscanf(buf+i+1, "%lf", &val[t]);
	int j = i+1;
	while(isdigit(buf[j]) || buf[j] == '.')
	  j++;
	if(buf[j] == 'm')
	  val[t] *= 0.001;
	else if(buf[j] == 'k')
	  val[t] *= 1000;
	else if(buf[j] == 'M')
	  val[t] *= 1000000;
      }
    }
    double p = val[0], u = val[1], i = val[2];

    printf("Problem #%d\n", h);
    if(!deu[0]){
      p = u * i;
      printf("P=%.2fW\n", p);
    } else if(!deu[1]){
      u = p / i;
      printf("U=%.2fV\n", u);
    } else{
      i = p / u;
      printf("I=%.2fA\n", i);
    }
    printf("\n");
  }
  return 0;
}

