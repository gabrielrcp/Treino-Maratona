#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N;
string nomes[25];
int dinheiro[15][15][25];
char mapa[15][15];
char cidcomp[15][15];
int faltapais[25];

int falta;

int tcomp[25];

#define INF (1<<30)

char buf[55];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int recebe[15][15][25];

void trabalha(int t)
{
  memset(recebe, 0, sizeof recebe);

  for(int i = 1; i <= 10; i++)
    for(int j = 1; j <= 10; j++)
      for(int k = 0; k < N; k++){
	int da = dinheiro[i][j][k] / 1000;
	for(int d = 0; d < 4; d++){
	  if(mapa[i+dx[d]][j+dy[d]] != -1){
	    recebe[i+dx[d]][j+dy[d]][k] += da;
	    recebe[i][j][k] -= da;
	  }
	}
      }

  for(int i = 1; i <= 10; i++)
    for(int j = 1; j <= 10; j++){
      int tipos = 0;
      for(int k = 0; k < N; k++){
	dinheiro[i][j][k] += recebe[i][j][k];
	if(dinheiro[i][j][k] > 0)
	  tipos++;
      }
      if(tipos == N  && (!cidcomp[i][j])){
	cidcomp[i][j] = 1;
	faltapais[mapa[i][j]]--;
	if(faltapais[mapa[i][j]] == 0){
	  falta--;
	  tcomp[mapa[i][j]] = t;
	}
      }
    }
}

int main()
{
  freopen("euro.in", "r", stdin);
  freopen("euro.out", "w", stdout);

  for(int h = 1; scanf(" %d", &N) && N > 0; h++){

    memset(mapa, -1, sizeof mapa);
    memset(dinheiro, 0, sizeof dinheiro);
    memset(cidcomp, 0, sizeof cidcomp);
    memset(faltapais, 0, sizeof faltapais);
    tcomp[0] = 0;

    for(int i = 0; i < N; i++){
      int x1, y1, x2, y2;
      scanf(" %s %d %d %d %d", buf, &x1, &y1, &x2, &y2);
      nomes[i] = buf;
      for(int x = x1; x <= x2; x++)
	for(int y = y1; y <= y2; y++){
	  mapa[x][y] = i;
	  faltapais[i]++;
	}
    }

    for(int i = 1; i <= 10; i++)
      for(int j = 1; j <= 10; j++){
	if(mapa[i][j] != -1)
	  dinheiro[i][j][mapa[i][j]] = 1000000;
      }

    falta = (N == 1 ? 0 : N);
    int t = 0;
    while(falta > 0){
      t++;
      trabalha(t);
    }
    
    vector< pair<int, string> > v;
    for(int i = 0; i < N; i++)
      v.push_back(make_pair(tcomp[i], nomes[i]));
    sort(v.begin(), v.end());
    printf("Case Number %d\n", h);
    for(int i = 0; i < N; i++){
      printf("   %s   %d\n", v[i].second.c_str(),  v[i].first);
    }
  }

  return 0;
}
