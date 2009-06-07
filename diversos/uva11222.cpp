#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

#define tr(it, M) for(set<int>::iterator (it) = (M).begin(); (it) != (M).end(); (it)++)

using namespace std;

struct Pessoa{
  int num;
  set<int> probs;
  bool operator < (const Pessoa &p) const{
    if(probs.size() == p.probs.size())
      return (num < p.num);
    return(probs.size() > p.probs.size());
  }
};

vector <Pessoa> pes(3);

bool achei(int i, int p){
  bool ret = false;
  for(int j = i + 1; j < 3; j++){
    if(pes[j].probs.find(p) != pes[j].probs.end()){
      pes[j].probs.erase(p);
      ret = true;
    }
  }
  return ret;
}


int main()
{
  int casos, h;
  scanf(" %d", &casos);
  for(h = 1; h <= casos; h++){
    for(int i = 0; i < 3; i++){
      pes[i].num = i + 1;
      pes[i].probs.clear();
      int s;
      scanf(" %d", &s);
      while(s--){
	int x;
	scanf(" %d", &x);
	pes[i].probs.insert(x);
      }
    }

    for(int i = 0; i < 2; i++){
      set<int> &p = pes[i].probs;
      set<int>::iterator it = p.begin();
      while(it != p.end()){
	if(achei(i, *it)){
	  set<int>::iterator morto = it;
	  it++;
	  p.erase(morto);
	}
	else
	  it++;
      }
    }

    sort(pes.begin(), pes.end());
    printf("Case #%d:\n", h);
    for(int i = 0; i < 3; i++){
      if(i == 0 || pes[i-1].probs.size() == pes[i].probs.size()){
	printf("%d %d", pes[i].num, pes[i].probs.size());
	tr(it, pes[i].probs)
	  printf(" %d", *it);
	printf("\n");
      }
      else
	break;
    }

  }
  return 0;
}
