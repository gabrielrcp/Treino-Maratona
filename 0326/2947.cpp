#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 510

int A[MAX][MAX];
int b[MAX];
int m, n;
int sol[MAX];
                //0, 1, 2, 3, 4, 5, 6
int inverso[7] = {0, 1, 4, 5, 2, 3, 6};

map<string, int> diasemana;

int mod7(int x)
{
  while(x < 0) x += 7;
  while(x >= 7) x -= 7;
  return x;
}

void imprimematriz()
{
  printf("---------\n");
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++)
      printf("%d ", A[i][j]);
    printf(" = %d\n", b[i]);
  }
  printf("---------\n");
}


void imprimesol()
{
  for(int i = 0; i < n; i++)
    sol[i] = -1;

  for(int i = n-1; i >= 0; i--){
    int s = 0;
    int j;
    for(int l = 0; l < n; l++)
      if(sol[l] != -1)
	s = mod7(s + A[i][l]*sol[l]);
      else if(A[i][l] != 0)
	j = l;
    sol[j] = mod7(inverso[A[i][j]] * (b[i] - s));
  }

  for(int i = 0; i < n; i++)
    if(sol[i] < 3)
      sol[i] += 7;
  printf("%d", sol[0]);
  for(int i = 1; i < n; i++)
    printf(" %d", sol[i]);
  printf("\n");
}


void resolve()
{
  for(int i = 0; i < m; i++){
    int j = 0;
    while(j < n && A[i][j] == 0)
      j++;

    if(j == n){
      if(b[i] != 0){
	printf("Inconsistent data.\n");
	return;
      }
      for(j = 0; j < n; j++)
	A[i][j] = A[m-1][j];
      b[i] = b[m-1];
      m--; i--;
    }else{
      for(int k = i+1; k < m; k++){
	int a = A[k][j] * inverso[A[i][j]];
	for(int l = 0; l < n; l++)
	  A[k][l] = mod7(A[k][l] - a * A[i][l]);
	b[k] = mod7(b[k] - a * b[i]);
      }
    }
  }

  if(n == m)
    imprimesol();
  else
    printf("Multiple solutions.\n");

}


int main()
{

  diasemana["MON"] = 0;
  diasemana["TUE"] = 1;
  diasemana["WED"] = 2;
  diasemana["THU"] = 3;
  diasemana["FRI"] = 4;
  diasemana["SAT"] = 5;
  diasemana["SUN"] = 6;

  while(1){
    scanf(" %d %d", &n, &m);
    if(n == m && m == 0) break;

    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++)
	A[i][j] = 0;
      b[i] = 0;
    }

    for(int i = 0; i < m; i++){
      char buf1[10], buf2[10];
      int k;
      scanf(" %d %s %s", &k, buf1, buf2);
      b[i] = mod7(diasemana[buf2] - diasemana[buf1] + 1);
      while(k--){
	int j;
	scanf(" %d", &j);
	j--;
	A[i][j]++;
	if(A[i][j] == 7)
	  A[i][j] = 0;
      }
    }
    //imprimematriz();
    resolve();
    //imprimematriz();
  }  

  return 0;
}
