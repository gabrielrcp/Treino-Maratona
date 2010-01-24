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
#include <deque>

using namespace std;

vector < deque<int> > fila;
int ini;

map<int, int> tim;
map<int, int> pos;

void insere(int x)
{
  int t = tim[x];
  if(pos[t] == -1){
    pos[t] = fila.size();
    fila.push_back( deque<int> (1, x));
  } else{
    fila[pos[t]].push_back(x);
  }
}

int retira()
{
  int x = fila[ini].front();
  fila[ini].pop_front();
  if(fila[ini].size() == 0){
    ini++;
    pos[tim[x]] = -1;
  }
  return x;
}

char buf[100];

int main()
{
#ifndef LOCAL
  freopen("team.in", "r", stdin);
  freopen("team.out", "w", stdout);
#endif

  int times;
  for(int h = 1; scanf(" %d", &times) && times > 0; h++){
    fila.clear();
    tim.clear();
    pos.clear();
    ini = 0;
    for(int i = 0; i < times; i++){
      int n; scanf(" %d", &n);
      pos[i] = -1;
      while(n--){
	int x;
	scanf(" %d", &x);
	tim[x] = i;
      }
    }
    printf("Scenario #%d\n", h);

    while(1){
      scanf(" %s", buf);
      if(buf[0] == 'S')
	break;
      switch(buf[0]){
      case 'E':
	int x;
	scanf(" %d", &x);
	insere(x);
	break;
      case 'D':
	printf("%d\n", retira());
	break;
      }
    }
    printf("\n");
  }

  return 0;
}

