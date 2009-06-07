#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

char buf[10010];
vector<int> v;
int soma;

void ler()
{
  v.clear();
  int at = 0;
  while(1){
    if(scanf(" %s", buf) != 1){
      if(at != 0)
	v.push_back(at);

      soma = 0;
      for(int i = 0; i < v.size(); i++)
	soma += v[i] + 1;
      return;
    }
    switch(buf[0]){
    case ',':
    case '.':
    case '!':
    case '?':
      at += strlen(buf);
      break;
    default:
      if(at != 0)
	v.push_back(at);
      at = strlen(buf);
      break;
    }
  }

}

#define INF (1<<30)

int area(int n)
{
  int m = 1;
  int c = 0;
  
  for(int i = 0; i < v.size(); i++){
    if(v[i] > n)
      return INF;
    if(c + v[i] <= n)
      c += v[i] + 1;
    else{
      c = v[i] + 1;
      m++;
    }
  }
  return (n+2) * (m+2);
}


int main()
{

  ler();
  int resp = INF;
  for(int n = 1; n <= soma; n++)
    resp = min(resp, area(n));
  printf("%d\n", resp);
  return 0;
}
