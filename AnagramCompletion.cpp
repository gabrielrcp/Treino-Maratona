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

// Classe e Testes - AnagramCompletion {{{
class AnagramCompletion
{
public: 
vector <string> complete(string word1, string word2); 
#ifndef TEST

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "AB.AC."; string Arg1 = "ABD..E"; string Arr2[] = {"ABDACE", "ABDACE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, complete(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABC..."; string Arg1 = "DEF..."; string Arr2[] = {"ABCDEF", "DEFABC" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, complete(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "......"; string Arg1 = "......"; string Arr2[] = {"AAAAAA", "AAAAAA" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, complete(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "TOPCODER"; string Arg1 = "D.E..TR."; string Arr2[] = {"TOPCODER", "DCEOOTRP" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, complete(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ABC."; string Arg1 = "DEF."; string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, complete(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "TEFAT..PVSKKJT.QBJEB..NPN..NBL"; string Arg1 = "...B...E.ND.LNE...HW.ANTB.TKBD"; string Arr2[] = {"TEFATAAPVSKKJTAQBJEBDDNPNHWNBL", "AAABFJJEKNDPLNEPQSHWTANTBVTKBD" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, complete(Arg0, Arg1)); }

// END CUT HERE

#endif 
}; 
// }}}

vector <string> AnagramCompletion::complete(string word1, string word2) 
{
	
}

// Função main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	AnagramCompletion ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
