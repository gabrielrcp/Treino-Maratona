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

// Classe e Testes - Mortgage {{{
class Mortgage
{
public: 
int monthlyPayment(int loan, int interest, int term); 

// BEGIN CUT HERE
#ifndef TEST
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1000; int Arg1 = 50; int Arg2 = 1; int Arg3 = 86; verify_case(0, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2000000000; int Arg1 = 6000; int Arg2 = 1; int Arg3 = 671844808; verify_case(1, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 1000000; int Arg2 = 1000; int Arg3 = 988143; verify_case(2, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 129; int Arg2 = 30; int Arg3 = 10868; verify_case(3, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1999999999; int Arg1 = 1000000; int Arg2 = 1; int Arg3 = 1976284585; verify_case(4, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
#endif
// END CUT HERE
 
}; 
// }}}

int Mortgage::monthlyPayment(int loan, int interest, int term) 
{
}

// Fun‹o main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	Mortgage ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
