#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define EPS 1.0e-9

#define MAX 15

double r[MAX];
double cx[MAX], cy[MAX];
double w;

pair<double, double> interseccao2(double x1, double y1, double r1,
				  double x2, double y2, double r2)
{
  double dx = x2 - x1;
  double dy = y2 - y1;
  double D = sqrt(dx*dx + dy*dy);
  double E = (r1*r1 - r2*r2 + D*D)/(2.0*D);
  double F = sqrt(r1*r1 - E*E);

  return make_pair(x1 + (E*dx - F*dy)/D, y1 + (F*dx + E*dy)/D);
}

inline pair<double, double> interseccao(double x1, double y1, double r1,
					double x2, double y2, double r2)
{

  pair<double, double> p1, p2;

  p1 = interseccao2(x1, y1, r1, x2, y2, r2);
  p2 = interseccao2(x2, y2, r2, x1, y1, r1);

  if(p1.second > p2.second)
    return p1;
  return p2;
}


double distancia(double x1, double y1, double x2, double y2)
{
  double dx = x1 - x2;
  double dy = y1 - y2;
  return sqrt(dx*dx+dy*dy);
}

double distancia(int i, int j)
{
  return distancia(cx[i], cy[i], cx[j], cy[j]);
}

bool pode(double px, double py, double pr, int j, int k, int n)
{

  if(px - pr < 0.0 || px + pr > w || py - pr < 0.0)
    return false;
  for(int i = 0; i < n; i++){
    if(i == j || i == k) continue;
    double dx = px - cx[i];
    double dy = py - cy[i];
    if(r[i] + pr >= sqrt(dx*dx+dy*dy))
      return false;
  }
  
  for(int i = 0; i < n; i++){
    //if(i == j || i == k) continue;
    if(cy[i] > py && cx[i] - r[i] <= px && px <= cx[i] + r[i])
      return false;
  }
  

  return true;
}

int main()
{
  int n;
  while(1){
    scanf(" %lf", &w);
    if(w < 0.5) break;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %lf", r+i);
      r[i] *= 0.5;
    }

    cx[0] = r[0];
    cy[0] = r[0];
    double resp = 2.0 * r[0];
    for(int i = 1; i < n; i++){

      double x = 1.0e10;
      double y = 1.0e10;
      pair<double, double>  p;
      double xat, yat;


      // colocar no chao
      for(int j = 0; j < i; j++){
	xat = cx[j] + 2 * sqrt(r[i] * r[j]);
	yat = r[i];
	if(pode(xat, yat, r[i], j, -1, i) && y > yat){
	  x = xat;
	  y = yat;
	}
      }
	  
      // colocar emcima de 2 bolas
      for(int j = 0; j < i; j++){
	for(int k = j + 1; k < i; k++){
	  if(2.0 * r[i] + r[j] + r[k] >= distancia(j, k)){
	    p = interseccao(cx[k], cy[k], r[i]+r[k],
			    cx[j], cy[j], r[i]+r[j]);
	    
	    if(pode(p.first, p.second, r[i], j, k, i) &&
	       p.second < y){
	      x = p.first;
	      y = p.second;
	    }
	  }
	}
      }

      for(int j = 0; j < i; j++){

	// entre a bola j e a parede direita
	if(cx[j] + r[j] + 2.0 * r[i] > w){
	  xat = w - r[i];
	  double dx = xat - cx[j];
	  yat = cy[j] + sqrt((r[i]+r[j])*(r[i]+r[j]) - dx*dx);
	  if(pode(xat, yat, r[i], j, -1, i) && yat < y){
	    x = xat;
	    y = yat;
	  }
	}

	// entre a bola j e a parede esquerda
	if(cx[j] - r[j] - 2.0 * r[i] < 0.0){
	  xat = r[i];
	  double dx = xat - cx[j];
	  yat = cy[j] + sqrt((r[i]+r[j])*(r[i]+r[j]) - dx*dx);
	  if(pode(xat, yat, r[i], j, -1, i) && yat < y){
	    x = xat;
	    y = yat;
	  }
	}
      }

      cx[i] = x;
      cy[i] = y;
      resp = max(y + r[i], resp);
    }
    /*
    printf("\n");
    for(int i = 0; i < n; i++)
      printf("%lf %lf %lf\n", cx[i], cy[i], r[i]);
    */
    printf("%.2lf\n", resp);
  }
  return 0;
}
