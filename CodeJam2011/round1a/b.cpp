#include <cstdio>
#include <string>
#include <iostream>
#include <list>

using namespace std;

int N;
string dic[110];

int tem_letra(char c, int rev, string s)
{
  for(int i = 0; i < (int)s.size(); i++){
    if(rev & (1 << i)) continue;
    if(s[i] == c)
      return 1;
  }
  return 0;
}

int possivel(char c, list<string> &pode)
{
  for(list<string>::iterator it = pode.begin(); it != pode.end(); it++){
    if(tem_letra(c, 0, *it))
      return 1;
  }
  return 0;
}
void tira_letra(char c, int rev, list<string> &pode)
{
  list<string>::iterator it, morto;
  it = pode.begin();
  while(it != pode.end()){
    if(tem_letra(c, rev, *it)){
      morto = it;
      it++;
      pode.erase(morto);
    } else {
      it++;
    }
  }
}

int iguais(int rev, string a, string b)
{
  for(int i = 0; i < (int)a.size(); i++){
    if(rev & (1 << i)){
      if(a[i] != b[i])
	return 0;
    }
  }
  return 1;
}

void atualiza(int rev, string pal, list<string> &pode)
{
  list<string>::iterator it, morto;
  it = pode.begin();
  while(it != pode.end()){
    if(!iguais(rev, pal, *it)){
      morto = it;
      it++;
      pode.erase(morto);
    } else{
      it++;
    }
  }
}

int pontuacao(string L, string pal)
{
  int r = 0;
  list<string> pode;
  int rev = 0;
  for(int i = 0; i < N; i++){
    if(dic[i].size() == pal.size()){
      pode.push_back(dic[i]);
    }
  }

  for(int i = 0; i < 26; i++){
    if(!possivel(L[i], pode)) continue;
    char achei = 0;
    for(int j = 0; j < (int)pal.size(); j++){
      if(pal[j] == L[i]){
	achei = 1;
	rev |= (1 << j);
      }
    }
    if(!achei){
      r++;
    } else{
      atualiza(rev, pal, pode);
    }
    tira_letra(L[i], rev, pode);
  }
  return r;
}

string vai(string L)
{
  int r = 0;
  int p = pontuacao(L, dic[0]);
  for(int i = 1; i < N; i++){
    int x = pontuacao(L, dic[i]);
    if(x > p){
      p = x;
      r = i;
    }
  }
  return dic[r];   
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int m;
    scanf(" %d %d", &N, &m);
    for(int i = 0; i < N; i++)
      cin >> dic[i];

    printf("Case #%d:", h);
    while(m--){
      string L;
      cin >> L;
      cout << " " << vai(L);
    }
    cout << endl;
  }
  return 0;
}
