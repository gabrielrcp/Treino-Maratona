#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

#define MOD (10009)

struct pal{
  int conta[26];
};

pal palavras[50];
char buf[1000];


int n, K;
int ntermos;
string termo[10];

void ler()
{
  scanf(" %s %d %d", buf, &K, &n);

  for(int j = 0; buf[j]; j++)
    if(buf[j] == '+')
      buf[j] = ' ';

  istringstream iss (buf);
  ntermos = 0;  
  while(iss >> termo[ntermos]){
    for(int j = 0; j < termo[ntermos].size(); j++)
      termo[ntermos][j] -= 'a';
    ntermos++;
  }

  for(int i = 0; i < n; i++){
    scanf(" %s", buf);
    for(int j = 0; j < 26; j++)
      palavras[i].conta[j] = 0;
    for(int j = 0; buf[j]; j++)
      palavras[i].conta[buf[j]-'a']++;
  }

}

int resp[10];
int uso[20];

int calcula(string &s)
{
  int c[26];
  for(int i = 0; i < s.size(); i++)
    c[s[i]] = 0;
  for(int k = 0; uso[k] != -1; k++){
    int i = uso[k];
    for(int j = 0; j < s.size(); j++)
      if(j == 0 || s[j-1] != s[j])
	c[s[j]] += palavras[i].conta[s[j]];
  }

  int r = 1;
  for(int i = 0; i < s.size(); i++){
    r *= c[s[i]];
    r %= MOD;
  }
  //printf("-- %d\n", r);
  return r;   
}



int resolve(string &s, int d)
{
  if(d == 0)
    return calcula(s);

  int r = 0;
  for(int i = 0; i < n; i++){
    uso[d-1] = i;
    r += resolve(s, d-1);
    r %= MOD;
  }
  return r;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    ler();

    for(int i = 1; i <= K; i++)
      resp[i] = 0;

    for(int i = 0; i < ntermos; i++)
      for(int d = 1; d <= K; d++){
	uso[d] = -1;
	resp[d] += resolve(termo[i], d);
	resp[d] %= MOD;
      }

    printf("Case #%d:", h);
    for(int d = 1; d <= K; d++)
      printf(" %d", resp[d]);
    printf("\n");
  }
  return 0;
}
