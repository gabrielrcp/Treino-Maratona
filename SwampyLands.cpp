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

// Classe e Testes - SwampyLands {{{
class SwampyLands
{
public: 
int surroundedArea(vector <string> swampy); 
#ifndef TEST

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 4 3 9", "1 2 9 4", "7 4 9 9", "3 9 9 11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(0, Arg1, surroundedArea(Arg0)); }
	void test_case_1() { string Arr0[] = {"5 12 16 14", "4 5 7 13", "2 3 22 7",
 "3 9 22 10", "11 4 13 17", "16 2 20 14"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(1, Arg1, surroundedArea(Arg0)); }
	void test_case_2() { string Arr0[] = {"8 7 11 14", "7 12 10 19", "2 14 9 17", "9 18 21 21",
 "6 11 18 13", "18 6 20 18", "9 4 21 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 67; verify_case(2, Arg1, surroundedArea(Arg0)); }
	void test_case_3() { string Arr0[] = {"1 4 3 9", "1 2 9 4", "7 4 9 9", "4 9 9 11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, surroundedArea(Arg0)); }
	void test_case_4() { string Arr0[] = {"2 1 3 2", "1 2 2 3", "2 3 3 4", "3 2 4 3",
 "5 2 6 3", "6 1 7 2", "6 3 7 4", "7 2 8 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, surroundedArea(Arg0)); }

// END CUT HERE

#endif 
}; 
// }}}

int SwampyLands::surroundedArea(vector <string> swampy) 
{
	
}

// Função main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	SwampyLands ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
