#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 1010

int ld[MAX];
int lf[MAX];
int n;

bool consigo(int a, int b, int *v)
{
  for(int i = a+1; i < b; i++){
    if(v[i] != -1 && (v[i] < a || v[i] > b))
      return false;
  }
  return true;
}

int main()
{
  int m;
  scanf(" %d %d", &n, &m);

  memset(ld, -1, sizeof ld);
  memset(lf, -1, sizeof lf);

  bool fail = false;
  while(m--){
    int a, b;
    scanf(" %d %d", &a, &b);
    if(b < a) swap(a, b);

    if(consigo(a, b, ld)){
      ld[a] = b;
      ld[b] = a;
    }
    else if(consigo(a, b, lf)){
      lf[a] = b;
      lf[b] = a;
    }
    else
      fail = true;
  }
  if(!fail)
    puts("panda is telling the truth...");
  else
    puts("the evil panda is lying again");
  return 0;
}
