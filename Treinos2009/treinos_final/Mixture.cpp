#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

class Mixture
{ 
public: 
   double mix(vector <int> mixture, vector <string> availableMixtures);
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 0 0 1","0 1 0 2","0 0 1 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 14.0; verify_case(0, Arg2, mix(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 0 0 1","0 1 0 2","0 0 1 3","2 2 2 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 10.0; verify_case(1, Arg2, mix(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10 9 9 9 9 9 9 9 9 10 0",
 "0 10 9 9 9 9 9 9 9 0 0",
 "0 0 10 9 9 9 9 9 9 0 0",
 "0 0 0 10 9 9 9 9 9 0 0",
 "0 0 0 0 10 9 9 9 9 0 0",
 "0 0 0 0 0 10 9 9 9 0 0",
 "0 0 0 0 0 0 10 9 9 0 0",
 "0 0 0 0 0 0 0 10 9 0 0",
 "0 0 0 0 0 0 0 0 10 1 0",
 "0 0 0 0 0 0 0 0 0 10 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(2, Arg2, mix(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7,7,8,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"9 0 4 8 4",
 "8 8 9 0 1",
 "0 10 3 10 7",
 "10 2 2 0 1",
 "8 9 10 2 6",
 "1 2 5 8 8",
 "4 7 8 9 6",
 "2 10 6 8 10",
 "6 3 9 7 1",
 "3 6 9 9 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.5855425945563804; verify_case(3, Arg2, mix(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
   Mixture ___test; 
   ___test.run_test(-1); 
} 
// END CUT HERE 

double Mixture::mix(vector <int> mixture, vector <string> availableMixtures)
{

}
