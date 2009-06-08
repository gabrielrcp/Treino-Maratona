
#include <cstdio>

using namespace std;

int sd(long long x)
{
  int counter = 0;

  while (x > 0)
    {
      counter += x % 10;
      x /= 10;
    }

  return counter;
}

bool f(long long m, int sdaux, long long n)
{
  long long x = m * sdaux; // numero multiplo de sdaux

  return (x <= n && sd(x) == sdaux);
}

long long acha(int sdaux, long long n)
{
  long long e = 0;
  long long d = n;
  long long m;

  while (e < d)
    {
      m = e + (d - e + 1) / 2;

      if (f(m, sdaux, n))
	e = m;
      else
	d = m - 1;
    }

  return e;
}

int main()
{
  long long n;

  printf("*******%d %Ld\n", 1, acha(1, 11));
  printf("*******%d %Ld\n", 2, acha(2, 11));
  printf("*******%d %Ld\n", 2, acha(2, 13));
 
  while(scanf(" %Ld", &n) == 1)
    {
      long long sum = 0;

      for (int i = 1; i < 120; i++)
	{
	  long long x = acha(i, n);

	  //	  printf("*******%d %Ld\n", i, x);
	  sum += x;
	}

      printf("%Ld\n", sum);
    }
}
