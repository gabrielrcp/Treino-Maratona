#include <cstdio>
#include <set>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

set<string> naoconta;
vector<string> palavras;
string abrev;

#define MAX 155

char *proxima(char *s, string &r)
{
  while(*s == ' ')
    s++;
  if(*s == '\n' || *s == '\0')
    return NULL;
  while(*s != ' ' && *s != '\n' && *s != '\0'){
    r += *s;
    s++;
  }
  return s;
}

void troca(string &s)
{
  for(int i = 0; i < s.size(); i++)
    if('a' <= s[i] && s[i] <= 'z')
      s[i] = s[i] - 'a' + 'A';
    else if('A' <= s[i] && s[i] <= 'Z')
      s[i] = s[i] - 'A' + 'a';
}

bool ler(char *buf)
{
  palavras.clear();
  if(strcmp(buf, "LAST CASE\n") == 0)
    return false;

  abrev = "";
  buf = proxima(buf, abrev);
  troca(abrev);
  if(buf == NULL)
    return true;
  while(1){
    string s = "";
    buf = proxima(buf, s);
    if(buf == NULL)
      break;
    if(naoconta.find(s) == naoconta.end())
      palavras.push_back(s);
  }

  return true;
}


long long memo[MAX][MAX][MAX][2];

long long vai(int l, int p, int lp, int usei)
{
  if(l == abrev.size()){
    if(p == palavras.size())
      return 1;
    if(usei && p+1 == palavras.size())
      return 1;
    return 0;
  }
  if(p == palavras.size())
    return 0;

  if(lp == palavras[p].size()){
    if(usei)
      return vai(l, p+1, 0, 0);
    else
      return 0;
  }
  long long &r = memo[l][p][lp][usei];

  if(r != -1)
    return r;

  r = 0;
  if(palavras[p][lp] == abrev[l])
    r += vai(l+1, p, lp+1, 1);
  r += vai(l, p, lp+1, usei);

  return r;
}


int main()
{
  char buf[210];
  while(1){
    int insig;
    scanf(" %d", &insig);
    if(insig == 0) break;

    naoconta.clear();
    while(insig--){
      scanf(" %s\n", buf);
      naoconta.insert(buf);
    }
    while(1){
      fgets(buf, 200, stdin);
      //printf("--%s--\n", buf);
      if(!ler(buf))
	break;


      for(int i = 0; i <= abrev.size(); i++)
	for(int j = 0; j < palavras.size(); j++)
	  for(int k = 0; k <= palavras[j].size(); k++)
	    for(int l = 0; l < 2; l++)
	      memo[i][j][k][l] = -1;

      long long r = vai(0, 0, 0, 0);
      troca(abrev);      
      if(r == 0)
	printf("%s is not a valid abbreviation\n", abrev.c_str());
      else
	printf("%s can be formed in %lld ways\n", abrev.c_str(), r);
      
      /*
      cout << "|" << abrev << "|";
      for(int i = 0; i < palavras.size(); i++)
	cout << " |" << palavras[i] << "|";
      cout << endl;
      */
    }

  }
  return 0;
}

