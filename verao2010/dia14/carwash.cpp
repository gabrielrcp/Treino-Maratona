//Incompleto
#include <cstdio>
#include <algorithm>
#include <list>

using namespace std;

struct carro{
  int id;
  int a, b;
  bool operator<(const carro &o) const{
    if(a+b == o.a+o.b){
      if(a == o.a)
	return id < o.id;
      return a < o.a;
    }
    return (a+b < o.a+o.b);
  }
};

struct conj{
  list<carro> lista;
  carro id;
  bool operator<(const conj &o) const{
    return id < o.id;
  }
};

#define MAX 10010

carro v[MAX];
int n;

int inia[MAX];
int inib[MAX];

void resolve_dificil(int tot)
{

}

void resolve_facil(int mi)
{
  inia[mi] = 0;
  inib[mi] = v[mi].a;

  int s = v[mi].a;
  for(int i = 0; i < n; i++){
    if(i != mi){
      inia[i] = s;
      s += v[i].a;
    }
  }

  s = 0;
  for(int i = 0; i < n; i++){
    if(i != mi){
      inib[i] = s;
      s += v[i].b;
    }
  }
}

int main()
{
  freopen("carwash.in", "r", stdin);
  freopen("carwash.out", "w", stdout);

  scanf(" %d", &n);
  int sa = 0, sb = 0, mi = 0;
  for(int i = 0; i < n; i++){
    v[i].id = i;
    scanf(" %d %d", &v[i].a, &v[i].b);
    sa += v[i].a;
    sb += v[i].b;
    if(v[mi].a + v[mi].b < v[i].a + v[i].b)
      mi = i;
  }

  int t = max(max(sa, sb), v[mi].a+v[mi].b);
  printf("%d\n", t);

  if(t == v[mi].a + v[mi].b)
    resolve_facil(mi);
  else
    resolve_dificil(t); 

  return 0;
}
