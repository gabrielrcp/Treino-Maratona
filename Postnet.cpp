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

// Classe e Testes - Postnet {{{
class Postnet
{
public: 
string barcode(string zipCode); 
#ifndef TEST

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "12345"; string Arg1 = "HLLLHHLLHLHLLHHLLHLLHLHLHLLHLHLH"; verify_case(0, Arg1, barcode(Arg0)); }
	void test_case_1() { string Arg0 = "94070"; string Arg1 = "HHLHLLLHLLHHHLLLHLLLHHHLLLHHLLLH"; verify_case(1, Arg1, barcode(Arg0)); }
	void test_case_2() { string Arg0 = "11111"; string Arg1 = "HLLLHHLLLHHLLLHHLLLHHLLLHHLHLHLH"; verify_case(2, Arg1, barcode(Arg0)); }
	void test_case_3() { string Arg0 = "12348"; string Arg1 = "HLLLHHLLHLHLLHHLLHLLHHLLHLLLHLHH"; verify_case(3, Arg1, barcode(Arg0)); }

// END CUT HERE

#endif 
}; 
// }}}

string Postnet::barcode(string zipCode) 
{
	
}

// Fun‹o main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	Postnet ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
