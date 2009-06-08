#include <stdio.h>

int main()
{
	int n;
  	int v;

	int i;
	char *ch;

	char buf[110];
	char var[26];

	while(scanf(" %d\n", &n) == 1)
	{
			  v = 0;

			  for(i=0; i<n; i++)
			  {
						 gets(buf);
/*						 printf("--%s\n",buf);*/
						 ch = buf;
						 while (*ch < 'A' || *ch > 'Z')
									ch++;
						 var[v++] = *ch;
			  }
			  printf("Yes\n");
			  putchar('(');
			  for(i=0;i<v;i++)
			  {
						 putchar(var[i]);
						 if(i+1<v)
									putchar('&');
			  }
			  putchar(')');
			  printf(" <=> ");
			  putchar('(');
			  for(i=0;i<v;i++)
			  {
						 putchar(var[i]);
						 if(i+1<v)
									putchar('&');
			  }
			  putchar(')');
			  putchar('\n');
	}
	return 0;
}
