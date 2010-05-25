#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
 
using namespace std;
 
class SumRectangle
{ 
 public:
    int getCorner(vector <int> leftColumn, vector <int> topRow);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {88,18,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {88,57,33,10,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(0, Arg2, getCorner(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getCorner(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, getCorner(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SumRectangle ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 

typedef long long ll;
ll mat[15][15];
int n, m;

int SumRectangle::getCorner(vector <int> leftColumn, vector <int> topRow)
{
  n = leftColumn.size();
  m = topRow.size();
  for(int i = 0; i < n; i++)
    mat[i][0] = leftColumn[i];
  for(int j = 0; j < m; j++)
    mat[0][j] = topRow[j];
  for(int i = 1; i < n; i++)
    for(int j = 1; j < m; j++)
      mat[i][j] = mat[i-1][j-1] - mat[i][j-1] - mat[i-1][j];
  return mat[n-1][m-1];
}
