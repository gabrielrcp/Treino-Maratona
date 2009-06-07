#include <cstdio>
#include <string>

using namespace std;

struct dt{
  int d, m, a;
};

int dias_mes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


bool bissexto(int ano)
{

  if(ano == 2100 || ano == 2200)
    return false;
  return (ano % 4 == 0);
}

dt proximo(dt at)
{
  at.d++;
  if(at.d > dias_mes[at.m]){
    if(!(at.d == 29 && at.m == 2 && bissexto(at.a))){
      at.d = 1;
      at.m++;
      if(at.m == 13){
	at.m = 1;
	at.a++;
      }
    }
  }
  return at;
}

dt anterior(dt at)
{

  if(at.d == 1 && at.m == 3 && bissexto(at.a)){
    at.d = 29;
    at.m = 2;
  }
  else{

    at.d--;
    if(at.d == 0){
      at.m--;
      if(at.m == 0){
	at.m = 12;
	at.a--;
      }
      at.d = dias_mes[at.m];
    }
  }

  return at;
}

dt somar(dt a, int x)
{
  while(x--)
    a = proximo(a);
  return a;
}

dt subtrair(dt a, int x)
{
  while(x--)
    a = anterior(a);
  return a;
}

int depois(dt a, dt b)
{
  for(int r = 1; r <= 7; r++){
    a = proximo(a);
    if(a.d == b.d && a.m == b.m)
      return r;
  }
  return -1;
}

int antes(dt a, dt b)
{
  for(int r = 1; r <= 7; r++){
    a = anterior(a);
    if(a.d == b.d && a.m == b.m)
      return r;
  }
  return -1;
}

string dias(int x)
{
  if(x == 1)
    return "DAY";
  return "DAYS";
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    printf("%d ", h);
    dt a, b;
    scanf("%d/%d/%d %d/%d", &a.m, &a.d, &a.a, &b.m, &b.d);

    if(a.d == b.d && a.m == b.m)
      printf("SAME DAY\n");
    else{
      int x = depois(a, b);
      if(x != -1){
	dt c = somar(a, x);
	printf("%d/%d/%d IS %d %s AFTER\n", c.m, c.d, c.a, x, dias(x).c_str());
      }
      else{
	int x = antes(a, b);
	if(x != -1){
	  dt c = subtrair(a, x);
	  printf("%d/%d/%d IS %d %s PRIOR\n", c.m, c.d, c.a, x, dias(x).c_str());
	}
	else
	  printf("OUT OF RANGE\n");	
      }
    }

  }
  return 0;
}
