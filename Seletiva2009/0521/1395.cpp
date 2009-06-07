#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 10010
int tam[500];
int n;

bool possiveis[MAX];
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
  for(int i = 0; i < MAX; i++)
    possiveis[i] = false;

  queue<int> Q;
  int x, y;

  possiveis[1] = true;
  Q.push(1);

  while(!Q.empty()){
    x = Q.front();
    Q.pop();

    for(int i = 0; i < n; i++){
      y =  x * tam[i];
      if(y >= MAX) continue;
      if(!possiveis[y]){
	possiveis[y] = true;
	Q.push(y);
      }
    }
  }
}

bool consegue(int a, int b)
{
  for(int k = 1; a*k < MAX && b*k < MAX; k++)
    if(possiveis[a*k] && possiveis[b*k])
      return true;
  return false;
}

void afina()
{
  sort(tam, tam+n);
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(tam[j] % tam[i] == 0)
	tam[j] /= tam[i];
    }
  }
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

    afina();
    geratodos();
    
    printf("Scenario #%d:\n", h);
    int numresp;
    scanf(" %d", &numresp);
    while(numresp--){
      frac f;
      int a, b;
      scanf(" %d %d", &a, &b);
      f = reduz(make_pair(a, b));
      if(!consegue(f.first, f.second))
	printf("Gear ratio %d:%d cannot be realized.\n", a, b);
      else
	printf("Gear ratio %d:%d can be realized.\n", a, b);
    }
    printf("\n");
  }
  return 0;
}
