#include <cstdio>
#include <set>

using namespace std;

#define MAX 110

int n;
int prob[MAX];
int precos[MAX];


long long vaiesq(int l, int p)
{
  for(int i = 1; i <= l; i++)
    if(precos[i] < p)
      return 0;

  long long resp = prob[l+1] * p;
  for(int k = l+2; k <= n; k++){
    if(precos[k-1] <= p)
      break;
    resp += (long long)prob[k] * p;
  }
  return resp;
}

long long vaidir(int l, int p)
{
  l = n - l;
  for(int i = 1; i <= l; i++)
    if(precos[n+1-i] < p)
      return 0;

  long long resp = p * prob[l+1];
  for(int k = l+2; k <= n; k++){
    if(precos[n+2-k] <= p)
      break;
    resp += (long long)prob[k] * p;
  }
  return resp;
}


long long vai(int l, int p)
{
  return vaiesq(l, p) + vaidir(l,p);
}

int main()
{
  set<int> allP;
  scanf(" %d", &n);
  for(int i = 1; i <= n; i++){
    scanf(" %d", precos+i);
    allP.insert(precos[i]);
    allP.insert(precos[i]-1);
    allP.insert(precos[i]+1);
  }
  for(int i = 1; i <= n; i++)
    scanf(" %d", prob+i);

  int ml, mp;
  long long m = -1;
  for(int l = 1; l < n; l++){
    for(set<int>::iterator it = allP.begin(); it != allP.end(); it++){
      long long t = vai(l, *it);
      if(t > m){
	ml = l;
	mp = *it;
	m = t;
      }
    }
  }

  printf("%d %d\n", ml, mp);
  return 0;
}
