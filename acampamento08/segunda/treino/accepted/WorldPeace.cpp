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

// Classe e Testes - WorldPeace {{{
class WorldPeace
{
public: 
long long numGroups(int k, vector <int> countries); 

// BEGIN CUT HERE
#ifndef TEST
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = { 4,4,4,4,4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 5LL; verify_case(0, Arg2, numGroups(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = { 1,2,3,4,5,6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3LL; verify_case(1, Arg2, numGroups(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = { 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3000000000LL; verify_case(2, Arg2, numGroups(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arr1[] = { 96, 17, 32, 138, 112, 50, 7, 19, 412, 23, 14, 50, 47, 343, 427, 22, 39 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 166LL; verify_case(3, Arg2, numGroups(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 10; int Arr1[] = { 638074479, 717901019, 910893151, 924124222, 991874870, 919392444, 729973192, 607898881, 
  838529741, 907090878, 632877562, 678638852, 749258866, 949661738, 784641190, 815740520, 
  689809286, 711327114, 658017649, 636727234, 871088534, 964608547, 867960437, 964911023, 
  642411618, 868318236, 793328473, 849540177, 960039699, 998262224, 775720601, 634685437, 
  743766982, 826321850, 846671921, 712570181, 676890302, 814283264, 958273130, 899003369, 
  909973864, 921987721, 978601888, 633027021, 896400011, 725078407, 662183572, 629843174, 
  617774786, 695823011 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3983180234LL; verify_case(4, Arg2, numGroups(Arg0, Arg1)); }
#endif
// END CUT HERE
 
}; 
// }}}


vector<int> v;
long long k;

bool tenta(long long n)
{
  long long r = 0;
  for(int i = 0; i < v.size(); i++)
    r += min((long long)v[i], n);
  //printf("%lld %lld %lld\n", r, n, k);
  return(r >= (n * k));
}

long long WorldPeace::numGroups(int _k, vector<int> countries) {
  v = countries;
  k = _k;
  long long e = 0, d = (1LL << 50);
  while(e < d){
    //printf("%lld %lld\n", e, d);
    long long  m = e + (d - e + 1LL)/2LL;
    if(tenta(m))
      e = m;
    else
      d = m - 1LL;
  }
  return e;
}


// Fun‹o main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	WorldPeace ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
