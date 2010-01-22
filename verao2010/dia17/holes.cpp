#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 1010;

struct Point { int x,y; };

int h, c;
Point hole[MAX], cover[MAX];
int limX, limY;

void ler_e_normaliza(Point *v, int n) {
	int minx, maxx, miny, maxy;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &v[i].x, &v[i].y);
		if (i==0) {
			minx=maxx=v[i].x;
			miny=maxy=v[i].y;
		} else {
			minx = min(minx,v[i].x);
			maxx = max(maxx,v[i].x);
			miny = min(miny,v[i].y);
			maxy = max(maxy,v[i].y);
		}
	}
	for (int i = 0; i < n; ++i) {
		v[i].x -= minx;
		v[i].y -= miny;
	}
}

void comprime() {
	map<int,int> X,Y;



	for (int i = 0; i < h; ++i) {
		X[hole[i].x] = 0;
		Y[hole[i].y] = 0;
		for (int j= 0; j < c; ++j) {
			X[hole[i].x+cover[j].x] = 0;
			Y[hole[i].y+cover[j].y] = 0;
		}
	}
	for (int i = 0; i < c; ++i) {
		X[cover[i].x] = 0;
		Y[cover[i].y] = 0;
		for (int j= 0; j < h; ++j) {
			X[hole[j].x+cover[i].x] = 0;
			Y[hole[j].y+cover[i].y] = 0;
		}

	}



	int idx = 1;
	for (map<int,int>::iterator it = X.begin(); it != X.end(); ++it) {
		it->second = idx++;
	}
	limX = idx + 2;

	idx = 1;
	for (map<int,int>::iterator it = Y.begin(); it != Y.end(); ++it) {
		it->second = idx++;
	}
	limY = idx + 2;



	for (int i = 0; i < h; ++i) {
		hole[i].x = X[hole[i].x];
		hole[i].y = Y[hole[i].y];
	}
	for (int i = 0; i < c; ++i) {
		cover[i].x = X[cover[i].x];
		cover[i].y = Y[cover[i].y];
	}
}

char grid[MAX][MAX];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
void flood(int i, int j) {
	if (i<0 || i>limX || j<0 || j>limY || grid[i][j]==1 || grid[i][j]==-1) return;
	grid[i][j] = 1;
	for (int d = 0; d < 4; ++d) {
		flood(i+dx[d], j+dy[d]);
	}

}

int procura(int offx, int offy) {
	for (int i = 0; i < h; ++i) {
		int ii = (i+1)%h;
		int x = hole[i].x, y = hole[i].y;
		int xx = hole[ii].x - hole[i].x;
		if (xx<0) xx = -1;
		if (xx>0) xx = 1;
		int yy = hole[ii].y - hole[i].y;
		if (yy<0) yy = -1;
		if (yy>0) yy = 1;
		do {
			int X = x+offx;
			int Y = y+offy;

			if (X<0 || Y<0 || X>limX || Y>limY || grid[X][Y]==1) {
				return 0;
			}

			x += xx;
			y += yy;
		} while (x!=hole[ii].x || y!=hole[ii].y);
	}

	return 1;
}

int main() {
	freopen("holes.in","r",stdin);
	freopen("holes.out","w",stdout);

	int test = 0;

	while (scanf("%d %d", &h, &c) == 2 && (h+c)) {
		ler_e_normaliza(hole,h);
		ler_e_normaliza(cover,c);

		comprime();

		memset(grid,0,sizeof grid);
		for (int i = 0; i < c; ++i) {
			int ii = (i+1)%c;
			int x = cover[i].x, y = cover[i].y;
			int xx = cover[ii].x - cover[i].x;
			if (xx<0) xx = -1;
			if (xx>0) xx = 1;
			int yy = cover[ii].y - cover[i].y;
			if (yy<0) yy = -1;
			if (yy>0) yy = 1;
			do {
				grid[x][y] = -1;
				x += xx;
				y += yy;
			} while (x!=cover[ii].x || y!=cover[ii].y);
		}
		flood(0,0);


		bool ok = false;
		for (int i = -limX; i <= limX; ++i) {
			for (int j = -limY; j <= limY; ++j) {
				bool r = procura(i,j);
				if (r) {
					ok = true;
					i=j=MAX;
				}
			}
		}

		printf("Hole %d: %s\n", ++test, ok ? "Yes" : "No");
	}

	return 0;
}
