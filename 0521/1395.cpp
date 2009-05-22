#include <cstdio>
#include <set>
#include <queue>

using namespace std;

int tam[25];
int n;

set<int> possiveis;
typedef pair<int, int> frac;


int mdc(int a, int b)
{
  if(a > b) return mdc(b, a);
  if(b % a == 0)
    return a;
  return mdc(b%a, a);
}

frac reduz(frac f)
{
  int d = mdc(f.first, f.second);
  f.first /= d;
  f.second /= d;
  return f;
}


void geratodos()
{
  possiveis.clear();
  queue<int> Q;
  int x, y;

  possiveis.insert(1);
  Q.push(1);

  while(!Q.empty()){
    x = Q.front();
    Q.pop();

    for(int i = 0; i < n; i++){
      y =  x * tam[i];
      if(y > 10000) continue;
      if(possiveis.find(y) == possiveis.end()){
	possiveis.insert(y);
	Q.push(y);
      }
    }
  }
}

bool consegue(frac f)
{
  for(int i = 0; i < n; i++)
    if(possiveis.find(f.first  * tam[i]) != possiveis.end() &&
       possiveis.find(f.second * tam[i]) != possiveis.end())
      return true;
  return false;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){

    int c = 200;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %d", tam+i);
      c = min(c, tam[i]);
    }
    for(int i = 0; i < n; i++)
      tam[i] /= c;
   

    geratodos();
    
    printf("Scenario #%d:\n", h);
    int numresp;
    scanf(" %d", &numresp);
    while(numresp--){
      frac f;
      int a, b;
      scanf(" %d %d", &a, &b);
      f = reduz(make_pair(a, b));
      if(!consegue(f))
	printf("Gear ratio %d:%d cannot be realized.\n", a, b);
      else
	printf("Gear ratio %d:%d can be realized.\n", a, b);
    }
    printf("\n");
  }
  return 0;
}
