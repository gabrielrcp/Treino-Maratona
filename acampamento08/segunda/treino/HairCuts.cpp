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

// Classe e Testes - HairCuts {{{
class HairCuts
{
public: 
double maxCut(vector <string> enter, string lastExit); 

// BEGIN CUT HERE
#ifndef TEST
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"04:22","09:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "05:52"; double Arg2 = 90.0; verify_case(0, Arg2, maxCut(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"09:00","09:22","09:22"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "10:11"; double Arg2 = 23.666666666666863; verify_case(1, Arg2, maxCut(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"09:00","04:00","04:02"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "04:09"; double Arg2 = -1.0; verify_case(2, Arg2, maxCut(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {  "04:40", "10:54", "12:30", "03:46", "04:48", "01:57", "04:47", "10:29", "10:39"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "05:21"; double Arg2 = 13.6666666666669; verify_case(3, Arg2, maxCut(Arg0, Arg1)); }
#endif
// END CUT HERE
 
}; 
// }}}

double HairCuts::maxCut(vector <string> enter, string lastExit) 
{
}

// Função main {{{
// BEGIN CUT HERE 
#ifdef TEST
int main()
{
	HairCuts ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
