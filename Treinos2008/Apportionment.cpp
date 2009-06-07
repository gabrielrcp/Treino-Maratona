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

// Classe e Testes - Apportionment {{{
class Apportionment
{
public: 
long long numberOfSquares(int N, int M); 
#ifndef TEST

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 1LL; verify_case(0, Arg2, numberOfSquares(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; long long Arg2 = 5LL; verify_case(1, Arg2, numberOfSquares(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; long long Arg2 = 1LL; verify_case(2, Arg2, numberOfSquares(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 4; long long Arg2 = 13LL; verify_case(3, Arg2, numberOfSquares(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 76711; int Arg1 = 54969; long long Arg2 = 1LL; verify_case(4, Arg2, numberOfSquares(Arg0, Arg1)); }

// END CUT HERE

#endif 
}; 
// }}}

long long Apportionment::numberOfSquares(int N, int M) 
{
	
}

// Fun‹o main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	Apportionment ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
