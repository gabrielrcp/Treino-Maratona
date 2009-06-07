#include <cstdio>
#include <queue>
#include <map>

using namespace std;

struct Estado{
  int n[3];
  bool operator <(const Estado &a) const{
    for(int i = 0; i < 3; i++){
      if(n[i] != a.n[i])
	return n[i] < a.n[i];
    }
    return false;
  }
};


int main()
{
  queue<Estado> Q;
  map<Estado, Estado> prox;
  Estado at, novo;

  for(int num = 20; num > 0; num--){
    at.n[0] = at.n[1] = at.n[2] = num;
    Q.push(at);
    while(!Q.empty()){
      Estado at, novo;
      int a, b, c;

      at = Q.front();
      Q.pop();

      for(int i = 0; i < 3; i++){
	for(int j = 0; j < 3; j++){
	  if(i == j || (at.n[j]%2 == 1)) continue;
	  int k = at.n[j] / 2;
	  novo.n[0] = at.n[0];
	  novo.n[1] = at.n[1];
	  novo.n[2] = at.n[2];
	  novo.n[i] += k;
	  novo.n[j] -= k;
	  if(prox.find(novo) == prox.end()){
	    prox[novo] = at;
	    Q.push(novo);
	  }
	}
      }
    }
  }

  
  int a, b, c;
  while(!feof(stdin) && scanf(" %d %d %d", &a, &b, &c) > 0){
    printf("%4d%4d%4d\n", a, b, c);
   
    at.n[0] = a;
    at.n[1] = b;
    at.n[2] = c;

    if(prox.find(at) != prox.end()){
      while(at.n[0] != at.n[1] || at.n[1] != at.n[2]){
	at = prox[at];
	printf("%4d%4d%4d\n", at.n[0], at.n[1], at.n[2]);
      }
    }
    printf("============\n");
  }
  
  return 0;
}
