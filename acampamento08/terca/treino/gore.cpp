
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX  100010
#define XMAX 200020

struct node{
  int ind;
  int x, y;
  bool operator < (const node &outro) const{
    if(x == outro.x){
      if(y == outro.y)
	return ind < outro.ind;
      return y < outro.y;
    }
    return x < outro.x;
  }
};

node v[MAX];
int tree[XMAX];
int resp[MAX];

int soma(int i)
{
  int r = 0;
  if(i >= XMAX)
    i = XMAX - 1;
  if(i < 0)
    return 0;
  while(i > 0){
    r += tree[i];
    i -= i & (-i);
  }
  return r;
}

void atualiza(int i, int v)
{
  while(i < XMAX){
    tree[i] += v;
    i += i & (-i);
  }
}


int main()
{
  int instances;
  
  scanf(" %d", &instances);

  while (instances--)
    {
      int N, D;

      scanf(" %d %d", &N, &D);
      
      for (int i = 0; i < N; i++){
	int x, y;
	scanf(" %d %d", &x, &y);
	v[i].x = x-y;
	v[i].y = x+y+1;
	v[i].ind = i;
      }

      sort(v, v + N);
      for(int i = 0; i < XMAX; i++)
	tree[i] = 0;

      int i, j;
      i = 0; j = 0;
      while(j < N && v[j].x - v[i].x <= D){
	atualiza(v[j].y, 1);
	j++;
      }
      j--;
     
      resp[v[0].ind] = soma(v[0].y + D) - soma(v[0].y - D - 1) - 1;
      for(int k = 1; k < N; k++){
	while(i < N && v[k].x - v[i].x > D){
	  atualiza(v[i].y, -1);
	  i++;
	}
	j++;
	while(j < N && v[j].x - v[k].x <= D){
	  atualiza(v[j].y, 1);
	  j++;
	}
	j--;
	resp[v[k].ind] = soma(v[k].y + D) - soma(v[k].y - D - 1) - 1;
      }
      printf("%d", resp[0]);
      for (i = 1; i < N; i++)
	printf(" %d", resp[i]);
      printf("\n");
    }

  return 0;
}

