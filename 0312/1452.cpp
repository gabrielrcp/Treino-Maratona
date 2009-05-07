#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct point{
  string front;
  string m, p;
};

struct signal{
  string a, b;
};

map <string, point> pontos;
map <string, signal> sinais;
map< pair<string,string>, int > regras;

vector<string> caminho;
vector<int> direcoes;



inline bool ehponto(string nome)
{
  return (pontos.find(nome) != pontos.end());
}


bool chega(string nome, string o, string d, int dir)
{
  if(nome == d){
    if(ehponto(nome) && pontos[nome].front == o)
      return false;
    caminho.push_back(d);
    if(ehponto(nome)){
      if(pontos[nome].m == o)
	direcoes.push_back(-1);
      else
	direcoes.push_back(1);
    }
    else
      direcoes.push_back(0);
    return true;
  }
  if(nome == "XXX")
    return false;

  //estou em um ponto
  if(ehponto(nome)){
    point pt = pontos[nome];

    if(o == pt.m || o == pt.p){
      if(chega(pt.front, nome, d, 0)){
	caminho.push_back(nome);	
	if(o == pt.m)
	  direcoes.push_back(-1);
	else
	  direcoes.push_back(1);
	return true;
      }
      return false;
    }
    else{
      if(dir <= 0 && chega(pt.m, nome, d, 0)){
	caminho.push_back(nome);
	direcoes.push_back(-1);
	return true;
      }
      if(dir >= 0 && chega(pt.p, nome, d, 0)){
	caminho.push_back(nome);
	direcoes.push_back(1);
	return true;
      }
      return false;
    }
  }

  //estou em um sinal
  signal s = sinais[nome];
  if(o != s.a && chega(s.a, nome, d, 0)){
    caminho.push_back(nome);
    direcoes.push_back(0);
    return true;
  }
  if(o != s.b && chega(s.b, nome, d, 0)){
    caminho.push_back(nome);
    direcoes.push_back(0);
    return true;
  }
  return false;
}



void troca_caminho(vector<string> &cat, vector<int> &dat, int i, int j)
{
  vector<string> novoc;
  vector<int> novod;

  //printf("--> %s %s\n", caminho[i].c_str(), caminho[j].c_str());

  reverse(caminho.begin(), caminho.end());
  reverse(direcoes.begin(), direcoes.end());

  for(int k = 0; k < i; k++){
    novoc.push_back(cat[k]);
    novod.push_back(dat[k]);
  }
  for(int k = 0; k < caminho.size(); k++){
    novoc.push_back(caminho[k]);
    novod.push_back(direcoes[k]);
  }
  for(int k = j+1; k < cat.size(); k++){
    novoc.push_back(cat[k]);
    novod.push_back(dat[k]);
  }
  cat = novoc;
  dat = novod;
}


void monta_caminho()
{
  vector<string> cat = caminho;
  vector<int> dat = direcoes;
  
  reverse(cat.begin(), cat.end());
  reverse(dat.begin(), dat.end());

  caminho.clear();
  direcoes.clear();

  for(int i = 1; i < cat.size(); i++){
    if(dat[i] == 0) continue;
    if(pontos[cat[i]].front != cat[i-1]) continue;
    for(int j = i+1; j+1 < cat.size(); j++){
      if(dat[j] == 0) continue;
      if(pontos[cat[j]].front != cat[j+1]) continue;

      if(regras.find(make_pair(cat[i], cat[j])) == regras.end()) continue;
      int x = regras[make_pair(cat[i], cat[j])];
      if(dat[i] == x) break;
      if(chega(cat[i], cat[i-1], cat[j], x)){
	troca_caminho(cat, dat, i, j);
	break;
      }
    }
  }
  caminho = cat;
  direcoes = dat;
}



int main()
{
  int casos;
  char buf1[50], buf2[50], buf3[50], buf4[50];
  string origem, destino;

  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int n;

    pontos.clear();
    sinais.clear();
    regras.clear();

    caminho.clear();
    direcoes.clear();

    scanf(" %s %s %d", buf1, buf2, &n);
    origem = buf1;
    destino = buf2;

    while(n--){
      char c;
      scanf(" %c", &c);
      if(c == 'W'){
	point pt;
	scanf(" %s %s %s %s", buf1, buf2, buf3, buf4);
	pt.front = buf2;
	pt.m = buf3;
	pt.p = buf4;
	pontos[buf1] = pt;
      }
      else{
	signal s;
	scanf(" %s %s %s", buf1, buf2, buf3);
	s.a = buf2;
	s.b = buf3;
	sinais[buf1] = s;
      }
    }

    scanf(" %d", &n);
    while(n--){
      scanf("%s %s %s %s", buf1, buf2, buf3, buf4);
      if(buf4[0] == '-')
	regras[make_pair(buf2, buf3)] = -1;
      else
	regras[make_pair(buf2, buf3)] = 1;
    }

    printf("Scenario #%d:\n", h);
    if(!chega(origem, sinais[origem].a, destino, 0))
      printf("NOT POSSIBLE\n");
    else{
      monta_caminho();
      /*     
      for(int i = 0; i < caminho.size(); i++)
	printf("%s %d\n", caminho[i].c_str(), direcoes[i]);
      */
      for(int i = 0; i < caminho.size(); i++)
	if(direcoes[i]==0 && (i == 0||sinais[caminho[i]].a == caminho[i-1]))
	  printf("%s\n", caminho[i].c_str());
      for(int i = 0; i < caminho.size(); i++){
	if(direcoes[i] == 1)
	  printf("%s +\n", caminho[i].c_str());
	else if(direcoes[i] == -1)
	  printf("%s -\n", caminho[i].c_str());
      }

    }

    printf("\n");
  }

  return 0;
}
