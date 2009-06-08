
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 1001
#define XMAX 20012
#define XMIN -10002

struct no
{
  int v;
  int i;
};

struct point
{
  int x, y;
  int next, prev;
};

point v[MAX];

no w[MAX];

int vx[XMAX];
int vy[XMAX];

bool comp(const no &a, const no &b)
{
  if (a.v != b.v)
    return a.v < b.v;

  return a.i < b.i;
}

void swap(int i)
{
  int aux = v[i].next;
  v[i].next = v[i].prev;
  v[i].prev = aux;
}

char getNext(int cur, int &next)
{
  char c;

  next = v[cur].next;

  if (v[next].prev != cur)
    swap(next);

  if (v[cur].x == v[next].x && v[cur].y < v[next].y)
    c = 'N';
  else if (v[cur].x < v[next].x && v[cur].y == v[next].y)
    c = 'E';
  else if (v[cur].x == v[next].x && v[cur].y > v[next].y)
    c = 'S';
  else if (v[cur].x > v[next].x && v[cur].y == v[next].y)
    c = 'W';

  return c;
}

void links(int i, int j)
{
  if (v[i].next == -1)
    v[i].next = j;
  else
    v[i].prev = j;
  if (v[j].next == -1)
    v[j].next = i;
  else
    v[j].prev = i;
}

int main()
{
  int N;

  while (scanf(" %d", &N) == 1 && N > 0)
    {
      int i, k;

      for (i = 0; i < N; i++)
	{
	  scanf(" %d %d", &v[i].x, &v[i].y);
	  v[i].next = v[i].prev = -1;
	  w[i].v = v[i].x + v[i].y;
	  w[i].i = i;
	  vx[v[i].x - XMIN] = -1;
	  vy[v[i].y - XMIN] = -1;
	}

      sort(w, w + N, comp);

      for (k = 0; k < N; k++)
	{
	  i = w[k].i;
	  if (vx[v[i].x - XMIN] == -1)
	    vx[v[i].x - XMIN] = i;
	  else
	    {
	      links(i, vx[v[i].x - XMIN]);
	      vx[v[i].x - XMIN] = -1;
	    }
	  if (vy[v[i].y - XMIN] == -1)
	    vy[v[i].y - XMIN] = i;
	  else
	    {
	      links(i, vy[v[i].y - XMIN]);
	      vy[v[i].y - XMIN] = -1;
	    }
	}

      int next;
      int cur = w[0].i;
      int first = N-1;
      int count = 0;
      string partialRes = "";

      if (v[v[cur].next].x != v[cur].x)
	swap(cur);

      partialRes += getNext(cur, next);
      //printf("%d %d %d\n", w[0].i, cur, next);
      while (next != w[0].i)
	{
	  if (cur == 0){
	    first = count;
	    //printf("a");
	  }
	  count++;
	  cur = next;
	  partialRes += getNext(cur, next);
	}
      //printf("%d\n", first);
      string res = "";
      res += partialRes.substr(first, partialRes.size() - first);
      res += partialRes.substr(0, first);

      printf("%s\n", res.c_str());
    }

  return 0;
}
