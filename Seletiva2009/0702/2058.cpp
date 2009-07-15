#include <cstdio>
#include <cctype>
#include <cstring>

#define M1 26
#define M2 676
#define M3 17576

char buf[50];
bool p1[M1], p2[M2], p3[M3];

int memo[M1][M1][30];

void ler(int m)
{
  for(int i = 0; i < M1; i++)
    p1[i] = false;
  for(int i = 0; i < M2; i++)
    p2[i] = false;
  for(int i = 0; i < M3; i++)
    p3[i] = false;

  while(m--){
    scanf(" %s", buf);
    int n = strlen(buf);
    int x;
    switch(n){
    case 1:
      p1[buf[0] - 'a'] = true;
      break;
    case 2:
      x = (int)buf[0]-'a' + (int)M1*(buf[1]-'a');
      p2[x] = true;
      break;
    case 3:
      x = (int)buf[0]-'a' + (int)M1*(buf[1]-'a') + (int)M2*(buf[2]-'a');
      p3[x] = true;
      break;      
      
    }
  }
}

bool proibe(char a, char b, char c)
{
  int x;
  if(p1[c-'a']) 
    return true;

  x = (int)b-'a' + (int)M1*(c-'a');
  if(b && p2[x])
    return true;

  x = M1*x + (int)a-'a';
  if(a && b && p3[x])
    return true;

  return false;
}



long long conta(char a, char b, int l)
{
  if(l == 0)
    return 1;

  if(a && b && memo[a-'a'][b-'a'][l] != -1LL)
    return memo[a-'a'][b-'a'][l];

  long long r = 0;
  for(char c = 'a'; c <= 'z'; c++){
    if(!proibe(a, b, c))
      r += conta(b, c, l-1);
  }

  if(a && b)
    memo[a-'a'][b-'a'][l] = r;
  return r;
}

void imprime_pal(long long num)
{
  int l = 1;
  while(1){
    long long t = conta(0, 0, l);
    if(t > num)
      break;
    num -= t;
    l++;
  }

  char a = 0, b = 0, c;
  for(int i = 1; i <= l; i++){
    for(c = 'a'; c <= 'z'; c++){
      if(proibe(a, b, c)) continue;
      long long t = conta(b, c, l-i);
      if(t <= num)
	num -= t;
      else{
	putchar(c);
	a = b; b = c;
	break;
      }
    }
  }
  putchar('\n');
}

void imprime_num(char *srt)
{
  int r = 0;
  int n = strlen(srt);

  char a = 0, b = 0, c;

  for(int i = 0; srt[i] != '\0'; i++){
    if(i != 0)
      r += conta(0, 0, i);

    for(c = 'a'; c < srt[i]; c++)
      if(!proibe(a, b, c))
	r += conta(b, c, n-i-1);
    a = b; b = srt[i];
  }
  printf("%d\n", r+1);
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){

    int p, m;
    scanf(" %d %d", &p, &m);
    ler(p);

    for(int k = 0; k < 30; k++){
      for(int i = 0; i < M1; i++)
	for(int j = 0; j < M1; j++)
	  memo[i][j][k] = -1;
    }

    while(m--){
      scanf(" %s", buf);
      if(isdigit(buf[0])){
	int x;
	sscanf(buf, " %d", &x);
	imprime_pal(x-1);
      }else
	imprime_num(buf);
    }
  }
  return 0;
}
