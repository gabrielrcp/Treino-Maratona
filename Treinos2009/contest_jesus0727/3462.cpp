#include <cstdio>
#include <algorithm>

using namespace std;

struct frac{
  long long num, den;
  bool operator< (const frac &outro) const{
    return num*outro.den < outro.num*den;
  }
  bool operator<= (const frac &outro) const{
    return num*outro.den <= outro.num*den;
  }
};

#define MAX 110

pair<frac, frac> interva[MAX];
int numint;
long long xl, yl;



long long gdc(long long a, long long b)
{
  if(a == 0 || b == 0)
    return 1;
  if(a < 0LL || b < 0LL)
    return gdc(abs(a), abs(b));
  if(a < b)
    return gdc(b, a);
  if(a % b == 0)
    return b;
  return gdc(b, a%b);
}

void simplifica(frac &f)
{
  long long x = gdc(f.num, f.den);
  f.num /= x;
  f.den /= x;
}

frac soma(frac f1, frac f2)
{
  frac f;
  f.den = f1.den*f2.den;
  f.num = f1.num*f2.den + f2.num*f1.den;
  simplifica(f);
  return f;
}

frac cruza(long long x, long long y)
{
  frac f, g;
  if(x == xl){
    f.num = x;
    f.den = 1;
    return f;
  }
  f.num = -y*(xl - x);
  f.den = yl - y;
  g.num = x;
  g.den = 1;
  return soma(f, g);
}


void novo()
{
  long long x, y, u, v;
  scanf(" %lld %lld %lld %lld", &x, &y, &u, &v);
  frac f1, f2;
  f1 = cruza(x, y);
  f2 = cruza(u, v);

  if(f2 < f1)
    swap(f1, f2);

  for(int i = 0; i < numint; i++){
    if((interva[i].first <= f1 && f1 <= interva[i].second) ||
       (interva[i].first <= f2 && f2 <= interva[i].second) ||
       (f1 <= interva[i].first && interva[i].second <= f2)){
      if(interva[i].first < f1)
	f1 = interva[i].first;
      if(f2 < interva[i].second)
	f2 = interva[i].second;
      numint--;
      interva[i] = interva[numint];
      i--;
    }
  }
  interva[numint] = make_pair(f1, f2);
  numint++;
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    scanf(" %d %lld %lld", &n, &xl, &yl);
    numint = 0;
    while(n--)
      novo();
    printf("%d\n", numint+1);
  }
  return 0;
}
