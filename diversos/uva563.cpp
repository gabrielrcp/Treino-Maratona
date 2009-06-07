#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

#define MAX 5010
#define O 5008
#define D 5009

vector < map<int, int> > G (MAX);
int s, a, b;

inline int num(int i, int j){
  if(i < 0 || i >= s || j < 0 || j >= a)
    return D;
  return 2*(i * a + j);
}

int caminho()
{
  queue<int> Q;
  vector<int> V(MAX, 0);
  vector<int> ant(MAX, -1);

  Q.push(O);
  V[O] = 1;
  ant[O] = -1;

  while(!Q.empty()){
    int at = Q.front();
    Q.pop();
    for(map<int, int>::iterator it = G[at].begin(); it != G[at].end(); it++){
      int j = it->first;
      if(it->second > 0 && !V[j]){
	V[j] = 1;
	ant[j] = at;
	if(j == D)
	  break;
	Q.push(j);
      }
    }
  }

  if(!V[D])
    return 0;
  
  int j = D;
  int i = ant[j];
  /*
  while(i != -1){
    int k = G[i][j];
    G[i].erase(j);
    G[i][j] = k - 1;
    if(G[j].find(i) != G[j].end()){
      k = G[j][i];
      G[j].erase(i);
    }
    else
      k = 0;
    G[j][i] = k + 1;
    j = i;
    i = ant[j];
  }
  */
  while(i != -1){
    G[i][j]--;
    if(G[j].find(i) != G[j].end())
      G[j][i]++;
    else
      G[j][i] = 1;
    j = i;
    i = ant[j];
  }

  /*  
  for(map<int, int>::iterator it = G[O].begin(); it != G[O].end(); it++)
    cout << it->first << " - " << it->second << endl;
  cout << endl;
  */
  return 1;
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d %d", &s, &a, &b);

    G[O].clear();
    G[D].clear();

    for(int i = 0; i < s; i++)
      for(int j = 0; j < a; j++){
	int t = num(i, j);

	G[t].clear();
	G[t + 1].clear();

	G[t][num(i, j) + 1] = 1;
	G[t + 1][num(i+1, j)] = 1;
	G[t + 1][num(i-1, j)] = 1;
	G[t + 1][num(i, j+1)] = 1;
	G[t + 1][num(i, j-1)] = 1;
	//G[t + 1][D] = 1;
      }

    for(int k = 0; k < b; k++){
      int i, j;
      scanf(" %d %d", &i, &j);
      i--; j--;
      G[O][num(i, j)] = 1;
    }
    /*
    for(int i = 0; i < MAX; i++)
      for(map<int, int>::iterator it = G[i].begin(); it != G[i].end(); it++)
	if(it->first < 0)
	  cout << "hein?!" << endl;
    */
    int fluxo = 0;
    while(caminho())
      fluxo++;;
    /*
    for(map<int, int>::iterator it = G[O].begin(); it != G[O].end(); it++)
      cout << it->first << " - " << it->second << endl;
    cout << endl;
    */
    if(fluxo == b)
      printf("possible\n");
    else
      printf("not possible\n");
  }
  return 0;
}
