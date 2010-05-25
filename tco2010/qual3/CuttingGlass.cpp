#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
 
using namespace std;
 
class CuttingGlass
{ 
 public:
    int pieces(int W, int H, int startx, int starty, vector <string> program);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 50; int Arg3 = 50; string Arr4[] = {"ULDR"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(0, Arg5, pieces(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 3; int Arg3 = 4; string Arr4[] = {"UDUDUDUDUDU"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1; verify_case(1, Arg5, pieces(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 0; int Arg3 = 0; string Arr4[] = {"RDDDUUU","RDDDUUU","R","DLLLRRR","DLLL"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 9; verify_case(2, Arg5, pieces(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 5; int Arg3 = 3; string Arr4[] = {"LULLULLU"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(3, Arg5, pieces(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CuttingGlass ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 

#define MAX 1010

char vert[MAX][MAX];
char horiz[MAX][MAX];
char vis[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dir(char c)
{
  switch(c){
  case 'L': return 0;
  case 'R': return 1;
  case 'U': return 2;
  case 'D': return 3;
  }
}

void preenche(int x, int y, vector<string> &prog)
{
  for(int a = 0; a < (int)prog.size(); a++){
    for(int b = 0; b < (int)prog[a].size(); b++){
      int d = dir(prog[a][b]);
      int i = min(x + dx[d], x);
      int j = min(y + dy[d], y);

      if(d <= 1)
	horiz[i][j] = 1;
      else
	vert[i][j] = 1;
      x += dx[d];
      y += dy[d];
    }
  }  
}

void vai(int x, int y)
{
  queue< pair<int, int> > Q;
  Q.push(make_pair(x, y));
  vis[x][y] = 1;

  while(!Q.empty()){
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();

    if(!vert[x+1][y] && !vis[x+1][y]){
      vis[x+1][y] = 1;
      Q.push(make_pair(x+1, y));
    }

    if(!horiz[x][y+1] && !vis[x][y+1]){
      vis[x][y+1] = 1;
      Q.push(make_pair(x, y+1));
    }

    if(!vert[x][y] && !vis[x-1][y]){
      vis[x-1][y] = 1;
      Q.push(make_pair(x-1,y));
    }

    if(!horiz[x][y] && !vis[x][y-1]){
      vis[x][y-1] = 1;
      Q.push(make_pair(x, y-1));
    }
  }
}

int CuttingGlass::pieces(int W, int H, int startx, int starty, vector <string> program)
{
  memset(vert, 0, sizeof vert);
  memset(horiz, 0, sizeof horiz);
  preenche(startx, starty, program);
 
  for(int i = 0; i <= W; i++){
    horiz[i][0] = 1;
    horiz[i][H] = 1;
  }
  for(int j = 0; j <= H; j++){
    vert[0][j] = 1;
    vert[W][j] = 1;
  }

  int resp = 0;
  memset(vis, 0, sizeof vis);
  for(int i = 0; i < W; i++)
    for(int j = 0; j < H; j++)
      if(!vis[i][j]){
	resp++;
	vai(i, j);
      }

  return resp;
}
