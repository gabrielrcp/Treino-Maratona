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

class NumJordanForms
{ 
public: 
   int howMany(vector <int> charPoly, vector <int> minPoly);
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,3,3,3,3,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 840; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4000,4000,4000,4000,4000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {500,1000,1500,2000,2500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 41788067; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
   NumJordanForms ___test; 
   ___test.run_test(-1); 
   ___test.howMany(vector<int> (1, 5), vector<int> (1, 1));
} 
// END CUT HERE 

typedef long long ll;

const ll mod = 179424673;

int memo[4010][4010];

int resolve(int s, int m)
{
  if(m == 1 || s == 1) return 1;

  int &r = memo[s][m];
  if(r != -1) return r;
  r = resolve(s, m-1);
  if(s > m)
    r += resolve(s-m, m);
  else if(s == m)
    r += 1;
  r %= mod;
  return r;
}

int NumJordanForms::howMany(vector <int> s, vector <int> m)
{
  memset(memo, -1, sizeof memo);
  int n = s.size();
  ll r = 1;
  for(int i = 0; i < n; i++){
    r *= (ll)resolve(s[i]-m[i], m[i]);
    r %= mod;
  }
  return (int) r;
}
