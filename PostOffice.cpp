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

// Classe e Testes - PostOffice {{{
class PostOffice
{
public: 
int matchAddress(string address1, string address2); 
#ifndef TEST

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "145 West 44th Street"; string Arg1 = "145 west 44 th street"; int Arg2 = -1; verify_case(0, Arg2, matchAddress(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = " wall street "; string Arg1 = "WallStreet"; int Arg2 = -1; verify_case(1, Arg2, matchAddress(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = " Wall Street"; string Arg1 = "  Waal Street"; int Arg2 = 2; verify_case(2, Arg2, matchAddress(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "                                                 A"; string Arg1 = "a                                                 "; int Arg2 = -1; verify_case(3, Arg2, matchAddress(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "Wall"; string Arg1 = "WallStreet"; int Arg2 = 4; verify_case(4, Arg2, matchAddress(Arg0, Arg1)); }

// END CUT HERE

#endif 
}; 
// }}}

int PostOffice::matchAddress(string address1, string address2) 
{
	
}

// Fun‹o main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	PostOffice ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
