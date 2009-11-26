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

class MixedUpPrimes
{ 
public: 
   vector <int> findPrimes(vector <int> values);
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findPrimes(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findPrimes(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 719 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findPrimes(Arg0)); }
	void test_case_3() { int Arr0[] = {2,3,5,7,11,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 15017 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findPrimes(Arg0)); }
	void test_case_4() { int Arr0[] = {2,2,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 17 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findPrimes(Arg0)); }
	void test_case_5() { int Arr0[] = {8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, findPrimes(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
   MixedUpPrimes ___test; 
   ___test.run_test(-1); 
} 
// END CUT HERE 
set<int> pode [64];

void vai(int m)
{
  for(int x = ((m-1) & m); x != 0; x = ((x-1)&m)){
    int y = (m^x);
    set<int>::iterator i, j;
    for(i = pode[x].begin(); i != pode[x].end(); i++){
      for(j = pode[y].begin(); j != pode[y].end(); j++){
	pode[m].insert(*i + *j);
	pode[m].insert(*i - *j);
	pode[m].insert(*i * *j);
	if(*j) pode[m].insert(*i / *j);
      }
    }
  }
}

bool primo(int p)
{
  if(p < 2) return false;
  for(int i = 2; i*i <= p; i++)
    if(p % i == 0)
      return false;
  return true;
}

vector <int> MixedUpPrimes::findPrimes(vector <int> val)
{
  int n = val.size();

  for(int e = 1; e < (1<<n); e++)
    pode[e].clear();
  for(int i = 0; i < n; i++)
    pode[1<<i].insert(val[i]);

  for(int e = 2; e < (1<<n); e++){
    if(e & (e-1))
      vai(e);
  }

  set<int>::iterator it;
  int e = ((1<<n)-1);
  vector<int> resp (2, -1);
  for(it = pode[e].begin(); it != pode[e].end(); it++){
    if(primo(*it)){
      if(resp[0] == -1)
	resp[0] = *it;
      resp[1] = *it;
    }
  }
  if(resp[0] == -1) return vector<int> ();

  return resp;
}
