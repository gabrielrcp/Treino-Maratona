#include <cstdio>

#define P1  10LL
#define P2  100LL
#define P3  1000LL
#define P4  10000LL
#define P5  100000LL
#define P6  1000000LL
#define P7  10000000LL
#define P8  100000000LL
#define P9  1000000000LL
#define P10 10000000000LL
#define P11 100000000000LL

long long vaip(long long x)
{
  if(x == 1LL)
    return 5;
  if(x == 2LL)
    return 15;
  x -= 3LL;
  long long pot = 10LL;
  while(x >= pot){
    x -= pot;
    pot *= 10LL;
  }
  return x + 5LL*pot;
}


long long vaio(long long x)
{
  if(x == 1LL)
    return 8LL;
  if(x == 2LL)
    return 18LL;
  x -= 3LL;
  long long pot = 10LL;
  while(x >= pot){
    x -= pot;
    pot *= 10LL;
  }
  return x + 8LL*pot;
}


long long vaid(long long x)
{
  switch(x){
  case 1LL:
    return 2LL;
  case 2LL:
    return 9LL;
  case 3LL:
    return 10LL;
  case 4LL:
    return 12LL;
  case 5LL:
    return 19LL;
  default:
    break;
  }

  x -= 6LL;

  long long pot = 10LL;
  while(1){
    if(pot == P4 || pot == P7 || pot == P10){
      if(x < 3LL*pot)
	break;
      x -= 3LL*pot;
    }
    else{
      if(x < 2LL*pot)
	break;
      x -= 2LL*pot;
    }
    pot *= 10LL;
  }

  if(pot == P4 || pot == P7 || pot == P10){
    if(x < pot)
      return x + pot;
    else if(x < 2LL*pot)
      return x - pot + 2LL*pot;
    else
      return x - 2LL*pot + 9LL*pot;
  }
  if(x < pot)
    return x + 2LL*pot;
  return x - pot + 9LL*pot;
}

long long vait(long long x)
{
  switch(x){
  case 1LL:
    return 3LL;
  case 2LL:
    return 13LL;
  default:
    break;
  }

  x -= 3LL;

  long long pot = 10LL;
  while(1){
    if(pot == P3){
      if(x < 2LL*pot)
	break;
      x -= 2LL*pot;
    }
    else{
      if(x < pot)
	break;
      x -= pot;
    }
    pot *= 10LL;
  }

  if(pot == P3){
    if(x < pot)
      return x + pot;
    else
      return x-pot + 3LL*pot;
  }
  return x + 3LL*pot;
}

long long vais(long long x)
{
  switch(x){
  case 1LL:
    return 7LL;
  case 2LL:
    return 17LL;
  default:
    break;
  }

  x -= 3LL;

  long long pot = 10LL;
  while(1){
    if(pot == P2 || pot == P5 || pot == P8 || pot == P11){
      if(x < 2LL*pot)
	break;
      x -= 2LL*pot;
    }
    else{
      if(x < pot)
	break;
      x -= pot;
    }
    pot *= 10LL;
  }

  if(pot == P2 || pot == P5 || pot == P8 || pot == P11){
    if(x < pot)
      return x + pot;
    else
      return x-pot + 7LL*pot;
  }
  return x + 7LL*pot;
}


int main()
{
  char l;
  long long x;


  for(x = P3; x < P5; x++)
    printf("%lld ", vaid(x));
  printf("\n");


  //while(1){
    scanf(" %c", &l);
    //if(l == 'q' || l == 'Q')
    //return 0;
    scanf(" %lld", &x);
    switch(l){
    case 'J':
    case 'j':
      printf("%lld\n", (x-1)*10+1);
      break;
    case 'm':
    case 'M':
      if(x <= P6)
	printf("%lld\n", x+P6-1LL);
      else
	printf("%lld\n", x-P6+P9-1LL);
      break;
    case 'D':
    case 'd':
      printf("%lld\n", vaid(x));
      break;
    case 'O':
    case 'o':
      printf("%lld\n", vaio(x));
      break;
    case 'P':
    case 'p':
      printf("%lld\n", vaip(x));
      break;
    case 'S':
    case 's':
      printf("%lld\n", vais(x));
      break;
    case 'T':
    case 't':
      printf("%lld\n", vait(x));
      break;
    }
    //}
  return 0;
}
