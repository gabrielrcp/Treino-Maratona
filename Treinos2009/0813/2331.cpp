#include <cstdio>
#include <queue>
#include <set>

using namespace std;

#define INF (1<<20)
typedef pair<int, int> pii;

struct estado{
  int num[4];
  int x;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int x1, y1, x2, y2;
int comp[4];
int num_ini[4];


int passos(estado ini, estado fim)
{
  int r = 0;
  for(int i = 0; i < 4; i++)
    r += ini.num[i] - fim.num[i];
  return r;
}

int vai(estado inicial, int objt)
{

  if(inicial.x == objt)
    return 0;

  int r = INF;

  int k1 = 1;
  for(int k2 = -1; k2 <= 1; k2 += 2){
    if(k2 == 1 && inicial.num[1] == 0)
      break;
    for(int k3 = -1; k3 <= 1; k3 += 2){
      if(k3 == 1 && inicial.num[2] == 0)
	break;
      for(int k4 = -1; k4 <= 1; k4 += 2){
	if(k4 == 1 && inicial.num[3] == 0)
	  break;

	queue<estado> Q;
	set< pair<pii, pii> > S;
	Q.push(inicial);
	while(!Q.empty()){
	  estado novo = Q.front(); Q.pop();
	  pair<pii, pii> p = make_pair(make_pair(novo.num[0], novo.num[1]),
				       make_pair(novo.num[2], novo.num[3]));
	  if(S.find(p) != S.end())
	    continue;
	  S.insert(p);

	  if(novo.num[0] > 0){
	    novo.x += k1*comp[0];
	    novo.num[0]--;
	    if(novo.x == objt || novo.x == -objt){
	      r = min(r, passos(inicial, novo));
	      break;
	    }
	    Q.push(novo);
	    novo.num[0]++;
	    novo.x -= k1*comp[0];
	  }

	  if(novo.num[1] > 0){
	    novo.x += k2*comp[1];
	    novo.num[1]--;
	    if(novo.x == objt || novo.x == -objt){
	      r = min(r, passos(inicial, novo));
	      break;
	    }
	    Q.push(novo);
	    novo.num[1]++;
	    novo.x -= k2*comp[1];
	  }
	  
	  if(novo.num[2] > 0){
	    novo.x += k3*comp[2];
	    novo.num[2]--;
	    if(novo.x == objt || novo.x == -objt){
	      r = min(r, passos(inicial, novo));
	      break;
	    }
	    Q.push(novo);
	    novo.num[2]++;
	    novo.x -= k3*comp[2];
	  }
	  
	  if(novo.num[3] > 0){
	    novo.x += k4*comp[3];
	    novo.num[3]--;
	    if(novo.x == objt || novo.x == -objt){
	      r = min(r, passos(inicial, novo));
	      break;
	    }
	    Q.push(novo);
	    novo.num[3]++;
	    novo.x -= k4*comp[3];
	  }
	}
      }
    }
  }
  return r;
}


int resolve()
{
  int r = INF;
 
  for(int n1 = 0; n1 <= num_ini[0]; n1++)
    for(int n2 = 0; n2 <= num_ini[1]; n2++)
      for(int n3 = 0; n3 <= num_ini[2]; n3++)
	for(int n4 = 0; n4 <= num_ini[3]; n4++){
  
	  estado e;
	  int d;
	  e.x = 0;
	  e.num[0] = n1;
	  e.num[1] = n2;
	  e.num[2] = n3;
	  e.num[3] = n4;
	  d = vai(e, x2-x1);
	  if(d == INF) continue;

	  e.x = 0;
	  e.num[0] = num_ini[0] - n1;
	  e.num[1] = num_ini[1] - n2;
	  e.num[2] = num_ini[2] - n3;
	  e.num[3] = num_ini[3] - n4;
	  d += vai(e, y2-y1);

	  r = min(r, d);
	}

  if(r >= INF)
    return -1;
  return r;
}

int main()
{
  int k;
  scanf(" %d %d %d %d %d", &x1, &y1, &x2, &y2, &k);

  for(int i = 0; i < 4; i++)
    comp[i] = num_ini[i] = 0;
  
  for(int i = 0; i < k; i++)
    scanf(" %d", comp+i);
  for(int i = 0; i < k; i++)
    scanf(" %d", num_ini+i);
  
  printf("%d\n", resolve());
  return 0;
}
