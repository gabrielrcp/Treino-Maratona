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

// Classe e Testes - CarParking {{{
class CarParking
{
public: 
int closestShed(int now, int streets); 
#ifndef TEST

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 19; int Arg1 = 22; int Arg2 = 22; verify_case(0, Arg2, closestShed(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 19; int Arg1 = 21; int Arg2 = 11; verify_case(1, Arg2, closestShed(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1234567; int Arg1 = 12345678; int Arg2 = 1234321; verify_case(2, Arg2, closestShed(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 9999; int Arg1 = 99999999; int Arg2 = 9999; verify_case(3, Arg2, closestShed(Arg0, Arg1)); }

// END CUT HERE

#endif 
}; 
// }}}

int CarParking::closestShed(int now, int streets) 
{
	
}

// Fun‹o main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	CarParking ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
