#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char buf[20];

#define MOD (1LL<<32)

char num[100];

void multiplica(long long x)
{
  long long r = 0, t;
  for(int i = 0; i < 100; i++){
    t = (long long)num[i] * x + r;
    num[i] = t % 10;
    r = t / 10;
  }
}


bool termina(long long x, int k)
{
  for(int i = 0;i < 100; i++)
    num[i] = 0;
  num[0] = 1;
  multiplica(x);
  multiplica(x);
  multiplica(x);

  for(int i = 0; i < k; i++){
    if(buf[i]-'0' != num[i])
      return false;
    x /= 10;
  }
  return true;
}

long long vai()
{
  int n = strlen(buf);
  reverse(buf, buf+n);

  long long at = 0;
  long long p = 1;
  for(int i = 0; buf[i] != '\0'; i++){
    for(int k = 0; k < 10; k++)
      if(termina(at + p*k, i+1)){
	at = at + p*k;
	break;
      }
    p *= 10LL;
  }
  return at;
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %s", buf);
    long long r = vai();
    printf("%lld\n", r);
  }
  return 0;
}
