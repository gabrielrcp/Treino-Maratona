#include <cstdio>
#include <cstring>

char buf[500];
char tab[50];


bool confere(int n, int m)
{
  for(int i = 0; i < m; i++)
    if(tab[i] != 'B')
      return false;
  for(int i = 0; i < n; i++)
    if(tab[m+1+i] != 'G')
      return false;
  return true;
}

bool vai(int at, int pos, int n, int m)
{
  if(pos > n * m + n + m)
    return false;


  if(at - 2 >= 0 && tab[at-1] == 'B' && tab[at-2] == 'G'){
    buf[pos] = 'H';
    tab[at] = 'G';
    tab[at-2] = '-';
    if(vai(at-2, pos+1, n, m))
      return true;
    tab[at] = '-';
    tab[at-2] = 'G';
  }
  if(at + 2 <= n + m && tab[at+1] == 'G' && tab[at+2] == 'B'){
    buf[pos] = 'h';
    tab[at] = 'B';
    tab[at+2] = '-';
    if(vai(at+2, pos+1, n, m))
      return true;
    tab[at] = '-';
    tab[at+2] = 'B';   
  }
  if(at - 1 >= 0 && tab[at-1] == 'G'){
    buf[pos] = 'S';
    tab[at] = 'G';
    tab[at-1] = '-';
    if(vai(at-1, pos+1, n, m))
      return true;
    tab[at] = '-';
    tab[at-1] = 'G';
  }
  if(at + 1 <= n + m && tab[at+1] == 'B'){
    buf[pos] = 's';
    tab[at] = 'B';
    tab[at+1] = '-';
    if(vai(at+1, pos+1, n, m))
      return true;
    tab[at] = '-';
    tab[at+1] = 'B';
    
  }
  if(confere(n, m)){
    buf[pos] = '\0';
    return true;
  }
  return false;
}

int resolve(int n, int m)
{
  for(int i = 0; i < n; i++)
    tab[i] = 'G';
  for(int i = 0; i < m; i++)
    tab[n+1+i] = 'B';
  tab[n] = '-';

  vai(n, 0, n, m);
  int r = strlen(buf);
  //printf("%s\n", tab);
  return r;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int p, n, m;
    scanf(" %d %d %d", &p, &n, &m);
    int r = resolve(n, m);
    printf("%d %d", p, r);

    for(int i = 0; i < r; i++){
      if(i % 50 == 0) putchar('\n');
      putchar(buf[i]);
    }
    putchar('\n');
    putchar('\n');
  }
  return 0;
}
