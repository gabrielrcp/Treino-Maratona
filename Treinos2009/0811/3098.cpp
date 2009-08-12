#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define INF (1<<30)

using namespace std;

vector<string> palavras;
vector<int> codigos;
char buf[100];

struct termo{
  int letras;
  int pos;
  int neg;
};


termo codaterm(string s)
{
  termo t;
  t.letras = t.pos = t.neg = 0;
  int i = 0;
  while(i < s.size()){
    if(s[i] == '+'){
      int j = s[i+1] - 'a';
      t.pos |= (1 << j);
      i += 2;
    }
    else if(s[i] == '-'){
      int j = s[i+1] - 'a';
      t.neg |= (1 << j);
      i += 2;
    }
    else{
      int j = s[i] - 'a';
      t.letras |= (1 << j);
      i++;
    }
  }
  return t;
}

int codapal(string s)
{
  int r = 0;
  for(int i = 0; i < s.size(); i++){
    int j = s[i] - 'a';
    r |= (1 << j);
  }
  return r;
}

bool bate(termo t, int pal)
{
  if((t.letras != 0) && ((t.letras & pal) == 0))
    return false;
  if((t.pos & pal) != t.pos)
    return false;
  if((t.neg != 0) && ((t.neg & pal) != 0))
    return false;
  return true;
}

int paltermo(char *trm)
{
  termo t = codaterm(trm);
  for(int i = 0; i < palavras.size(); i++)
    if(bate(t, codigos[i]))
      return i;
  return INF;
}


int resolve(char *qrt)
{
  int r = INF;
  int i, j;
  i = 0;
  bool para = false;
  while(!para){
    j = i + 1;
    while(qrt[j] != '\0' && qrt[j] != '|')
      j++;
    if(qrt[j] == '\0')
      para = true;
    qrt[j] = '\0';
    r = min(r, paltermo(qrt+i));
    i = j + 1;
  }
  return r;
}

int main()
{
  while(1){
    scanf(" %s", buf);
    if(buf[0] == '#')
      break;
    palavras.clear();
    palavras.push_back(buf);

    while(1){
      scanf(" %s", buf);
      if(buf[0] == '*')
	break;
      palavras.push_back(buf);
    }

    sort(palavras.begin(), palavras.end());
    codigos.clear();
    for(int i = 0; i < palavras.size(); i++)
      codigos.push_back(codapal(palavras[i]));

    /*
    for(int i = 0; i < palavras.size(); i++)
      cout << palavras[i] << endl;
    cout << endl;
    */

    while(1){
      scanf(" %s", buf);
      if(buf[0] == '*')
	break;
      int i = resolve(buf);
      if(i == INF)
	printf("NONE\n");
      else
	printf("%s\n", palavras[i].c_str());
    }
    printf("$\n");
  }
  return 0;
}
