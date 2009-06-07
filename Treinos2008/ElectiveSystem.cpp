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

// Classe e Testes - ElectiveSystem {{{
class ElectiveSystem
{
public: 
int maximalGoodness(vector <string> values, int D, int K); 
#ifndef TEST

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"acacca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; int Arg3 = 10; verify_case(0, Arg3, maximalGoodness(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"cab","cca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 10; verify_case(1, Arg3, maximalGoodness(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"abcdefghijkl"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 100; int Arg3 = 78; verify_case(2, Arg3, maximalGoodness(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"yptcsevnuzlsrfjxurpslztlinhddelpitmvaezowjcfjjfgmf","q"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 18; int Arg3 = 598; verify_case(3, Arg3, maximalGoodness(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"zzhhhhhh","zz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 2; int Arg3 = 152; verify_case(4, Arg3, maximalGoodness(Arg0, Arg1, Arg2)); }

// END CUT HERE

#endif 
}; 
// }}}

int ElectiveSystem::maximalGoodness(vector <string> values, int D, int K) 
{
	
}

// Função main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	ElectiveSystem ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
