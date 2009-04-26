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

// Classe e Testes - FixedPoint {{{
class FixedPoint
{
public: 
vector <double> find(double scale, vector <double> translate, double rotate); 
#ifndef TEST

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { double Arg0 = 0.5; double Arr1[] = {1, 0}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.5707963267948966; double Arr3[] = {-0.39999999999999997, 0.8 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { double Arg0 = 0.5; double Arr1[] = {2, 0}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0; double Arr3[] = {4.0, 0.0 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { double Arg0 = 0.1; double Arr1[] = {0, 0}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2; double Arr3[] = {0.0, -0.0 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { double Arg0 = 0.5; double Arr1[] = {1, 2}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.785398163397; double Arr3[] = {-2.223469992542095, 2.065452845425795 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

#endif 
}; 
// }}}

vector <double> FixedPoint::find(double scale, vector <double> translate, double rotate) 
{
	
}

// Função main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	FixedPoint ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
