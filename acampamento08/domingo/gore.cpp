
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100001

#define ABS(X) ((X < 0) ? -(X) : (X))

struct node
{
  int v, i;
};

int c[MAX];
struct node v1[MAX];
struct node v2[MAX];
int iv1[MAX];
int iv2[MAX];

bool compara(const node &a, const node &b)
{
  if (a.v != b.v)
    return a.v < b.v;
  else
    return a.i < b.i;
}

int main()
{
  int instances;
  
  scanf(" %d", &instances);

  while (instances--)
    {
      int i, j;
      int N, D;

      scanf(" %d %d", &N, &D);
      
      for (i = 0; i < N; i++)
	{
	  int x, y;

	  scanf(" %d %d", &x, &y);
	  v1[i].v = x + y;
	  v2[i].v = x - y;
	  v1[i].i = v2[i].i = i;
	  c[i] = 0;
	}

      sort(v1, v1 + N, compara);
      sort(v2, v2 + N, compara);

      for (i = 0; i < N; i++)
	{
	  iv1[v1[i].i] = i;
	  iv2[v2[i].i] = i;
	}

      for (i = 0; i < N; i++)
	for (j = i + 1; j < N; j++)
	  if (ABS(v1[i].v - v1[j].v) <= D)
	    {
	      if (ABS(v2[iv2[v1[i].i]].v - v2[iv2[v1[j].i]].v) <= D)
		{
		  c[v1[i].i]++;
		  c[v1[j].i]++;
		}
	    }
	  else
	    break;
      
      printf("%d", c[0]);
      for (i = 1; i < N; i++)
	printf(" %d", c[i]);
      printf("\n");
    }

  return 0;
}

