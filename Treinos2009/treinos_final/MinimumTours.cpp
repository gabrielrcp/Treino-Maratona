#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

class MinimumTours
{ 
public: 
  int getMinimumTours(vector <string> islandMap) ;
        
  // BEGIN CUT HERE
public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
    if ((Case == -1) || (Case == 6)) test_case_6();
  }
private:
  template <typename T> string print_array(const vector<T> &V) {
    ostringstream os; 
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const int &Expected, const int &Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: \"" << Expected << '\"' << endl;
      cerr << "\tReceived: \"" << Received << '\"' << endl; 
    }
  }
  void test_case_0() {
    string Arr0[] = {
      "..x..x..x..",
      "..x..x..x..",
      "..x..x..x..",
      "..x..x..x.."
    };
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 1;
    verify_case(0, Arg1, getMinimumTours(Arg0));
  }
  void test_case_1() { 
    string Arr0[] = {
      "x....x....x",
      ".....x.....",
      ".....x.....",
      ".....x.....",
      "xxxxxxxxxxx",
      ".....x.....",
      ".....x.....",
      ".....x.....",
      "x....x....x"
    };
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 3;
    verify_case(1, Arg1, getMinimumTours(Arg0));
  }
  void test_case_2() {
    string Arr0[] = {
      "x....x....x",
      ".....x.....",
      ".....x.....",
      "....x.x....",
      "xxxx...xxxx",
      "....x.x....",
      ".....x.....",
      ".....x.....",
      "x....x....x"};
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 1;
    verify_case(2, Arg1, getMinimumTours(Arg0));
  }
  void test_case_3() {
    string Arr0[] = {
      "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
      "x............................x",
      "x..xxxxxxxxxx....xxxxxxxxxx..x",
      "x..x........x....x........x..x",
      "x..x..xxxx..x....x.xxxxxx.x..x",
      "x..x........x....x.x....x.x..x",
      "x..xxxxxxxxxx....x.x.x..x.x..x",
      "x................x.x....x.x..x",
      "x................x.xxxxxx.x..x",
      "x..xxxxxxxxxx....x........x..x",
      "x..x........x....x........x..x",
      "x..x..xxxx..x....x.xxxxxx.x..x",
      "x..x........x....x........x..x",
      "x..xxxxxxxxxx....xxxxxxxxxx..x",
      "x............................x",
      "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    };
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 2; 
    verify_case(3, Arg1, getMinimumTours(Arg0));
  }
  void test_case_4() {
    string Arr0[] = {
      "xxxxxxxxxxxxx....xxxxxxxxxxxxxxxxxxxxxx",
      "x...........x....x.....................",
      "x.xxxxxxxxx.x....x.xxxxxxxxxxxxxxxxxxx.",
      "x.x.......x.x....x.x.................x.",
      "x.x.xxxxx.x.x....x.x.xxxxxxxxxxx.....x.",
      "x.x...x...x.x....x.x.x..........x....x.",
      "x.x...x...x.x....x.x.x.xxx..xxx...x..x.",
      "x.x.......x.x....x.x.x.x....x..x..x..x.",
      "x.xxxxxxxxx.x....x.x.x.xxx..x..x..x..x.",
      "x...........x....x.x.x.x....x..x..x..x.",
      "xxxxxxxxxxxxx....x.x.x.xxx..xxx...x..x.",
      "x................x.x.x......xx....x..x.",
      "x................x.x.x......x.x...x..x.",
      "x................x.x.x......x..x..x..x.",
      "x................x.x.x...........x...x.",
      "x................x.x.xxxxxxxxxxxx....x.",
      "x................x.x.................x.",
      "x................x.xxxxxxxxxxxxxxxxxxx.",
      "x................x.....................",
      "x................xxxxxxxxxxxxxxxxxxxxxx"
    };
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 1;
    verify_case(4, Arg1, getMinimumTours(Arg0));
  }
  void test_case_5() {
    string Arr0[] = {
      "x.........x.........x", 
      "..........x..........",
      "xxxxxxxxxxxxxxxxxxxxx",
      "..........x..........",
      "..........x.xxxxxxx..",
      "..........x.x.....x..", 
      "..........x.x.x.x.x..",
      "..........x.x.....x..",
      "..........x.xxxxxxx..", 
      "x.........x.........x",
      "..........x.xxxxxxx..",
      "..........x.x.....x..",
      "..........x.x.x.x.x..",
      "..........x.x.....x..",
      "..........x.xxxxxxx..",
      "..........x.........x"};


    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 3;
    verify_case(5, Arg1, getMinimumTours(Arg0));
  }

  void test_case_6() {
    string Arr0[] = {
      "..........x..........",
      "xxxxxxxxxxxxxxxxxxxxx",
      "..........x..........",
      "..........x.xxxxxxx..", 
      "..........x.x.....x..",
      "..........x.x.x.x.x..", 
      "..........x.x.....x..",
      "..........x.xxxxxxx..", 
      "..........x..........", 
      "..........x.xxxxxxx..",
      "..........x.x.....x..",
      "..........x.x.x.x.x..",
      "..........x.x.....x..",
      "..........x.xxxxxxx..",
      "..........x.........."};

    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 1;
    verify_case(6, Arg1, getMinimumTours(Arg0));
  }

  // END CUT HERE
 
}; 

// BEGIN CUT HERE
int main()
{
  MinimumTours ___test; 
  ___test.run_test(-1); 
} 
// END CUT HERE

vector<string> mapa;
int n, m;
int ncp;

vector< vector<int> > comp;
vector<bool> ehilha;

vector< vector<bool> > foi;
vector< vector<bool> > liga;
vector< vector<int> > G;



int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void fill(int i, int j, int cp)
{
  if(comp[i][j] != -1) return;
  comp[i][j] = cp;
  for(int k = 0; k < 8; k++){
    int x = i+dx[k];
    int y = j+dy[k];
    if(x < 0 || x >= n) continue;
    if(y < 0 || y >= m) continue;
    if(mapa[x][y] == mapa[i][j])
      fill(x, y, cp);
  }
}

void monta(int i, int j)
{
  if(foi[i][j]) return;
  foi[i][j] = true;

  for(int k = 0; k < 8; k++){
    int x = i+dx[k];
    int y = j+dy[k];
    if(x < 0 || x >= n) continue;
    if(y < 0 || y >= m) continue;


    if(mapa[x][y] == mapa[i][j])
      monta(x, y);
    else{
      liga[comp[i][j]][comp[x][y]] = true;
      liga[comp[x][y]][comp[i][j]] = true;
    }
  }
}

typedef pair<int, int> pii;

pii dfsilha(int, int);
pii dfsmar(int, int);


pii dfsilha(int i, int pai)
{
  int resp = 0;
  int q0 = 0, q1 = 0;
  for(int k = 0; k < (int)G[i].size(); k++){
    int j = G[i][k];
    if(j == pai) continue;
    pii p = dfsmar(j, i);
    resp += p.second;
    switch(p.first){
    case 0: q0++; break;
    case 1: q1++; break;
    }
  }
  if(q0 == 0 && q1 == 0)
    return make_pair(0, resp + 1);
  if(q0 > 1)
    return make_pair(-1, resp - 1);
  if(q0 > 0)
    return make_pair(1, resp);
  return make_pair(-1, resp);
}

pii dfsmar(int i, int pai)
{
  int resp = 0;
  int q0 = 0, q1 = 0;
  for(int k = 0; k < (int)G[i].size(); k++){
    int j = G[i][k];
    if(j == pai) continue;
    pii p = dfsilha(j, i);
    resp += p.second;
    switch(p.first){
    case 0: q0++; break;
    case 1: q1++; break;
    }
  }


  if(q0 == 0 && q1 == 0)
    return make_pair(-1, resp);
  if(q1 == 0){
    resp -= q0 - 1;
    return make_pair(0, resp);
  }

  int t = q1/2;
  resp -= t;
  resp -= q0;
  q0 = 0;
  q1 -= 2*t;

  if(q1 == 1)
    return make_pair(0, resp);
  return make_pair(1, resp);
}


int MinimumTours::getMinimumTours(vector <string> islandMap)
{
  mapa = islandMap;
  n = mapa.size();
  m = mapa[0].size();
  ncp = 0;

  comp = vector< vector<int> > (n, vector<int> (m, -1));
  ehilha.clear();
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      if(comp[i][j] == -1){
	ehilha.push_back(mapa[i][j] == 'x');
	fill(i, j, ncp++);
      }
    }
  

  foi = vector< vector<bool> > (n, vector<bool> (m, false));
  liga = vector< vector<bool> > (ncp, vector<bool> (ncp, false));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      monta(i, j);

  G = vector< vector<int> > (ehilha.size(), vector<int> ());
  for(int i = 0; i < ncp; i++)
    for(int j = 0; j < ncp; j++)
      if(liga[i][j])
	G[i].push_back(j);

  int i = 0;
  while(!ehilha[i]) i++;

  return dfsilha(i, -1).second;

}
