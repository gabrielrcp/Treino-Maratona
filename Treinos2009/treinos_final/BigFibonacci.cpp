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

class BigFibonacci
{ 
public: 
        int fibNumber(string index, int M) ;
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "7"; int Arg1 = 10; int Arg2 = 3; verify_case(0, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "5"; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0"; int Arg1 = 23; int Arg2 = 0; verify_case(2, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "17"; int Arg1 = 2; int Arg2 = 1; verify_case(3, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "54"; int Arg1 = 341890; int Arg2 = 177022; verify_case(4, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "300"; int Arg1 = 77531; int Arg2 = 0; verify_case(5, Arg2, fibNumber(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE
int main()
{
   BigFibonacci ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE


typedef long long ll;

ll P[60][4][4];


int BigFibonacci::fibNumber(string index, int M_)
{
  P[0][0][1] = P[0][1][1] = P[0][1][0] = 1;
  ll p, M = M_;
  sscanf(index.c_str(), " %lld", &p);

  for(int x = 1; (1LL << x) <= p; x++){
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++){
	P[x][i][j] = 0;
	for(int k = 0; k < 2; k++){
	  P[x][i][j] += P[x-1][i][k] * P[x-1][k][j];
	  P[x][i][j] %= M;
	}
      }
  }

  ll mat[2][2] = {{1, 0}, {0, 1}};
  ll nova[2][2] = {{1, 0}, {0, 1}};

  for(int x = 0; (1LL << x) <= p; x++){
    if(!((1LL << x) & p)) continue;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++){
	nova[i][j] = 0;
	for(int k = 0; k < 2; k++){
	  nova[i][j] += mat[i][k] * P[x][k][j];
	  nova[i][j] %= M;
	}
      }
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
	mat[i][j] = nova[i][j];
  }

  return mat[0][1];

}
