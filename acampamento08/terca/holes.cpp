#include <cstdio>

int main()
{
	int n;
	while(scanf(" %d",&n) == 1){
		if (n == 0)
			printf("1\n");
		else if (n == 1)
			printf("0\n");
		else
		{
				  if (n%2)
				  {
							 putchar('4');
							 n--;
				  }
				  int i;
				  i = n/2;
				  while (i--)
							 putchar('8');
		  		  putchar('\n');
		}
	}
	return 0;
}
