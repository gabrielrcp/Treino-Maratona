#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>


/* TIME LIMIT!!!!! */


using namespace std;

string saida;
map<string, int> mapa;
int maximo;

/*
inline void compara(const pair<string, int>  &s)
{
  if(s.second > maximo){
    maximo = s.second;
    saida = s.first;
  }
  //fprintf(stderr, "%s %d\n", s.first.c_str(), s.second);
}
*/

int main()
{
  int n;
  string s;
  int tam;
  int i;

  while(scanf(" %d", &n) > 0)
    {
      cin >> s;
      tam = s.size();
      maximo = 0;
      for(i=0; i+n <= tam; i++){
	if(++mapa[s.substr(i, n)] > maximo){
	  saida = s.substr(i, n);
	  maximo = mapa[saida];
	}
      }
      //for_each(mapa.begin(), mapa.end(), compara);
      printf("%s\n", saida.c_str());
      mapa.clear();
    }
}
