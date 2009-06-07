#include <cstdio>
#include <set>

using namespace std;

char tab[25][25];
int dist[25][25][5][4];


struct Estado{
  int x, y;
  int cor;
  int dir;

  bool operator<(const Estado &a) const{
    if(*this == a)
      return false;
    
    if(dist[x][y][cor][dir] != dist[a.x][a.y][a.cor][a.dir])
      return (dist[x][y][cor][dir] > dist[a.x][a.y][a.cor][a.dir]);
    if(x != a.x)
      return (x < a.x);
    if(y != a.y)
      return (y < a.y);
    if(dir != a.dir)
      return (dir < a.dir);
    return (cor < a.cor);
  }

  bool operator==(const Estado &a) const{
    return(x == a.x && y == a.y && dir == a.dir && cor == a.cor);
  }

  bool igual(const Estado &a) const{
    return(x == a.x && y == a.y && cor == a.cor);
  }
};

int main()
{
  int h;
  int n, m;

  Estado ori, dest;

  for(h = 1; ; h++){
    scanf(" %d %d ", &n, &m);
    if(n == 0 && m == 0)
      break;

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
	do{
	  tab[i][j] = getchar();
	}while(tab[i][j] == '\n');
	if(tab[i][j] == 'S'){
	  ori.x = i; ori.y = j;
	}
	else if(tab[i][j] == 'T'){
	  dest.x = i; dest.y = j;
	}
	for(int k = 0; k < 5; k++)
	  for(int l = 0; l < 4; l++)
	    dist[i][j][k][l] = -1;
      }

    ori.dir = 0; ori.cor = 0;
    dest.cor = 0;


    set<Estado> Q;
    Q.insert(ori);
    dist[ori.x][ori.y][0][0] = 0;

    while(!Q.empty()){
      set<Estado>::iterator it = Q.begin();
      Estado at = *it;

      if(at.igual(dest))
	break;

      Q.erase(it);

      int x = at.x;
      int y = at.y;
      int cor = at.cor;
      int dir = at.dir;
      int d = dist[x][y][cor][dir];

      Estado novo;
      int dn;

      // Mudar a direcao
      for(int i = 0; i < 4; i++){
	dn = dist[x][y][cor][i];
	int t = i - dir;
	if(t < 0) t = -t;
	if(t == 3) t = 1;
	if(dn == -1 || dn > d + t){
	  novo.x = x; novo.y = y; novo.cor = cor; novo.dir = i;
	  if(dn != -1) Q.erase(novo);
	  Q.insert(novo);
	  dist[x][y][cor][i] = d + t;
	}
      }

      // Ir para frente
      int dx, dy;
      switch(dir){
      case 0:
	dx = -1; dy = 0;
	break;
      case 1:
	dx = 0; dy = 1;
	break;
      case 2:
	dx = 1; dy = 0;
	break;
      default:
	dx = 0; dy = -1;
	break;
      }

      if(x + dx < 0 || x + dx >= n ||
	 y + dy < 0 || y + dy >= m ||
	 tab[x+dx][y+dy] == '#')
	continue;
      dn = dist[x+dx][y+dy][(cor+1)%5][dir];
      if(dn == -1 || dn > d + 1){
	novo.x = x + dx; novo.y = y + dy;
	novo.cor = (cor+1)%5;
	novo.dir = dir;
	if(dn != -1) Q.erase(novo);
	Q.insert(novo);
	dist[x+dx][y+dy][(cor+1)%5][dir] = d + 1;
      }
    }


    if(h != 1)
      putchar('\n');
    printf("Case #%d\n", h);

    if(Q.empty())
      printf("destination not reachable\n");
    else{
      dest = *(Q.begin());
      printf("minimum time = %d sec\n",
	     dist[dest.x][dest.y][dest.cor][dest.dir]);
	
    }
  }

  return 0;
}
