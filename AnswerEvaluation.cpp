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

// Classe e Testes - AnswerEvaluation {{{
class AnswerEvaluation
{
public: 
int getScore(vector <string> keywords, vector <int> scores, string answer); 
#ifndef TEST

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"red", "fox", "lazy", "dogs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25, 25, 25, 25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "the quick brown fox jumped over the lazy dog"; int Arg3 = 50; verify_case(0, Arg3, getScore(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"red", "fox", "lazy", "dogs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25, 25, 25, 25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "highschool matches are nice"; int Arg3 = 0; verify_case(1, Arg3, getScore(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"red", "fox", "lazy", "dogs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "lazy lazy lazy lazy"; int Arg3 = 3; verify_case(2, Arg3, getScore(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
 "n", "o", "p", "q", "r", "s", "t", "u", "v", "x", "y", "z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a b c d e f g h i j k l m n o p q r s t u v x y z"; int Arg3 = 25000; verify_case(3, Arg3, getScore(Arg0, Arg1, Arg2)); }

// END CUT HERE

#endif 
}; 
// }}}

int AnswerEvaluation::getScore(vector <string> keywords, vector <int> scores, string answer) 
{
	
}

// Função main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	AnswerEvaluation ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
