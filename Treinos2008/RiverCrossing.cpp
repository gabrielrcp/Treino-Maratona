// Includes {{{
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <stdio.h>
using namespace std;
// }}}

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf (x))
#define WATCH(x) TRACE(cout << #x << ": " << x << endl)
//#define DEBUG

// Classe e Testes - RiverCrossing {{{
class RiverCrossing
{
public: 
  int minimalWait(vector <string> cargo, int units, int T); 
#ifndef TEST

  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"5 1 right"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; int Arg3 = 22; verify_case(0, Arg3, minimalWait(Arg0, Arg1, Arg2)); }
  void test_case_1() { string Arr0[] = {"5 5 right"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; int Arg3 = 12; verify_case(1, Arg3, minimalWait(Arg0, Arg1, Arg2)); }
  void test_case_2() { string Arr0[] = {"1 1 left", "1 1 right", "2 4 left"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 4; verify_case(2, Arg3, minimalWait(Arg0, Arg1, Arg2)); }
  void test_case_3() { string Arr0[] = {"20 1 left", "20 2 left", "20 3 left", "20 4 left", "20 5 left", 
					"20 6 left", "20 7 left", "20 8 left", "20 9 left", "20 10 left"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 100; int Arg3 = 3979100; verify_case(3, Arg3, minimalWait(Arg0, Arg1, Arg2)); }
  void test_case_4() { string Arr0[] = {"20 1 right", "20 2 left", "20 3 right", "20 4 left", "20 5 right",
 "20 6 left", "20 7 right", "20 8 left", "20 9 right", "20 10 left"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 100; int Arg3 = 1989300; verify_case(4, Arg3, minimalWait(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"4 15 left", "10 24 left",  "3 35 left", "10 47 right",
 "4 51 right", "10 56 right", "9 65 left"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 34; int Arg3 = 1660; verify_case(5, Arg3, minimalWait(Arg0, Arg1, Arg2)); }

// END CUT HERE

#endif 
}; 
// }}}

#define INF 1000000

struct carga{
  int t;
  int num[2];
};

vector<carga> v;
int n;
int demora;
int cap;
int chegam[55][2];
int prox[55];

int vai(int i, int n0, int n1, int l)
{
  int r = INF, t, s;
  int qtde[2] = {n0, n1};
  s = 0;
  for(int j = i; j < n; j++){
    qtde[0] += v[j].num[0];
    qtde[1] += v[j].num[1];
    
  }
}


int RiverCrossing::minimalWait(vector <string> cargo, int units, int T) 
{

  cap = units;
  demora = T;

  n = -1;
  int ult = -1;
  for(int i = 0; i < cargo.size(); i++){
    int t, q, l;
    char buf[10];
    sscanf(cargo[i].c_str(), "%d %d %s", &q, &t, buf);
    if(strcmp(buf, "left") == 0)
      l = 0;
    else
      l = 1;
    if(t != ult){
      carga c;
      c.t = t;
      c.num[0] = c.num[1] = 0;
      ult = t;
      v.push_back(c)
      n++;
    }
    v[n].t = t;
    v[n].num[l] += q;
  }
  n = v.size();

  for(int i = 0; i < n; i++){
    chegam[i][0] = chegam[i][1] = 0;
    prox[i] = i+1;
    for(int j = i+1; j < n; j++)
      if(v[j].t < v[i].t + demora){
	prox[i] = j + 1;
	chegam[i][0] += v[j].num[0];
	chegam[i][1] += v[j].num[1];
      }
  }

  return vai(0, 0, 0, 0);
}

// Fun‹o main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	RiverCrossing ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
