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

// Classe e Testes - FibonacciSequence {{{
class FibonacciSequence
{
public: 
int numFibs(int a, int b); 
#ifndef TEST

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 3; verify_case(0, Arg2, numFibs(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 13; int Arg2 = 1; verify_case(1, Arg2, numFibs(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = 13; int Arg2 = 1; verify_case(2, Arg2, numFibs(Arg0, Arg1)); }

// END CUT HERE

#endif 
}; 
// }}}

int FibonacciSequence::numFibs(int a, int b) 
{
	
}

// Fun‹o main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	FibonacciSequence ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
