#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 15010
#define MAXM 1510

int n, m;
int v[MAXM];
int ord[MAXM];

char ler()
{
  char c;
  do{
    c = getchar();
  }while(c != '0' && c != '1');
  return c - '0';
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d ", &n, &m);

    memset(ord, 0, m * sizeof(ord[0]));
    memset(v, 0, m * sizeof(v[0]));

    int resp = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
	char c = ler();
	if(c)
	  v[j]++;
	else
	  v[j] = 0;
	ord[j] = v[j];
      }
      sort(ord, ord+m);
      for(int j = m-1; j >= 0; j--)
	resp = max(resp, (m - j)*ord[j]);
    }
    printf("%d\n", resp);
  }
  return 0;
}
