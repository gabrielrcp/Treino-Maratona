#include <stdio.h>

int ok(int num)
{
	int n=num;
	int soma = 0;
	while(num>0)
	{
	    soma += num%10;
	    num/=10;
	}
	if (n % soma == 0)
		return 1;
	return 0;
}

int soma(int num)
{
	/*int n=num;*/
	int soma = 0;
	while(num>0)
	{
	    soma += num%10;
	    num/=10;
	}
/*	if (n % soma == 0)
		return 1;
	return 0;*/
	return soma;
}

int main()
{
	int num;
	for(num=0;num<=10000;num++)
	{
		if (num % 10 == 0)
			putchar('\n');
		if (num % 100 == 0)
			printf("\n:::%d:::\n",num);
		ok(num)?
		printf("%04d ",num):
		printf("---- ");
	}
	putchar('\n');
	return 0;
}
