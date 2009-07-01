#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

map<string, string> pai;
set<string> pessoas;
set<string> interno;
set<string> contei;

map<string, int> numdesc;



void vai(string at, int d)
{
  bool chega = false;
  int conta = 0;

  for(int i = 0; i < d; i++){
    if(pai.find(at) == pai.end())
      return;
    if((!chega) && contei.find(at) == contei.end()){
      conta++;
      contei.insert(at);
    }
    else
      chega = true;
    at = pai[at];
  }

  for(int k = 0; k < conta; k++){
    numdesc[at]++;
    if(pai.find(at) == pai.end())
      break;
    if((!chega) && contei.find(at) == contei.end()){
      conta++;
      contei.insert(at);
    }
    else
      chega = true;
    at = pai[at];
  }
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    if(h != 1) printf("\n");
    printf("Tree %d:\n", h);

    int n, d;
    scanf(" %d %d", &n, &d);
    pessoas.clear();
    pai.clear();
    interno.clear();
    numdesc.clear();
    contei.clear();

    while(n--){
      string at;
      char buf[20];
      int m;
      scanf(" %s %d", buf, &m);
      at = buf;
      pessoas.insert(at);
      if(m > 0)
	interno.insert(at);
      numdesc[at] = 0;
      while(m--){
	scanf(" %s", buf);
	pai[buf] = at;
	pessoas.insert(buf);
	numdesc[at] = 0;
      }
    }

    for(set<string>::iterator it=pessoas.begin(); it != pessoas.end(); it++){
      if(interno.find(*it) != interno.end())
	continue;
      vai(*it, d);
    }

    vector<  pair<int, string>  > final;
    map<string, int>::iterator it;
    for(it = numdesc.begin(); it != numdesc.end(); it++){
      if(it->second != 0)
	final.push_back(make_pair(- it->second, it->first));
    }
    sort(final.begin(), final.end());

    for(int i = 0; i < final.size(); i++){
      if(i >= 3 && final[i-1].first != final[i].first)
	break;
      printf("%s %d\n", final[i].second.c_str(), -final[i].first);
    }

  }
  return 0;
}
