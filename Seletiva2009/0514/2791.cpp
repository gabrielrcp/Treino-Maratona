#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define MAX 110
#define EPS 1.0e-12

struct chim{
  char letra;
  int x, y;
};

int n;
char obser[MAX];
chim chamines[MAX];

double pivo;

bool compara(const chim &c1, const chim &c2){
  double x1 = c1.x - pivo, y1 = c1.y;
  double x2 = c2.x - pivo, y2 = c2.y;

  return x1*y2 - x2*y1 < 0.0;
}

bool ok()
{
  for(int i = 0; i < n; i++)
    if(chamines[i].letra != obser[i])
      return false;
  return true;
}


int main()
{
  scanf(" %d", &n);
  scanf(" %s", obser);

  for(int i = 0; i < n; i++)
    scanf(" %c %d %d", &chamines[i].letra, &chamines[i].x, &chamines[i].y);

  vector<double> pontos;
  double minimo = 1.0e30;
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++){
      int xi, xj, yi, yj;
      double pt;
      xi = chamines[i].x;
      yi = chamines[i].y;
      xj = chamines[j].x;
      yj = chamines[j].y;

      if(yi == yj)
	continue;
      pt = xi - (double)yi * (xj - xi) / (yj - yi);
      minimo = min(pt, minimo);
      pontos.push_back(pt);
    }
  
  if(pontos.size() == 0){
    pivo = 0.0;
    sort(chamines, chamines+n, compara);
    if(ok())
      printf("1\n* *\n");
    else
      printf("0\n\n");
    return 0;
  }


  pontos.push_back(minimo - 100.0);
  sort(pontos.begin(), pontos.end());
  pontos.push_back(pontos[pontos.size()-1] + 100.0);
  
  
  vector<double> pt_temp = pontos;
  pontos.clear();
  pontos.push_back(pt_temp[0]);
  for(int i = 1; i < pt_temp.size(); i++)
    if(pt_temp[i] - pt_temp[i-1] > EPS)
      pontos.push_back(pt_temp[i]);
  

  vector<bool> pode;

  for(int i = 0; i+1 < pontos.size(); i++){
    pivo = 0.5 * (pontos[i] + pontos[i+1]);
    sort(chamines, chamines+n, compara);
    pode.push_back(ok());
  }

  int conta = 0;
  for(int i = 0; i < pode.size(); i++)
    if(pode[i])
      conta++;
  printf("%d\n", conta);

  for(int i = 0; i < pode.size(); i++){
    if(pode[i]){
      if(i == 0)
	printf("* %lf ", pontos[i+1]);
      else if(i+1 == pode.size())
	printf("%lf * ", pontos[i]);
      else
	printf("%lf %lf ", pontos[i], pontos[i+1]);
    }
  }
  printf("\n");

  return 0;
}
