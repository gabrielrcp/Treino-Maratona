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

class RepeatingFreeStrings
{ 
public: 
  string kthString(int n, int k);
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
  }
private:
  template <typename T> string print_array(const vector<T> &V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const string &Expected, const string &Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl; 
      cerr << "\tExpected: \"" << Expected << '\"' << endl;
      cerr << "\tReceived: \"" << Received << '\"' << endl;
    }
  }
  void test_case_0() { 
    int Arg0 = 2; int Arg1 = 0;
    string Arg2 = "01"; 
    verify_case(0, Arg2, kthString(Arg0, Arg1));
  }
  void test_case_1() {
    int Arg0 = 2;
    int Arg1 = 1;
    string Arg2 = "10";
    verify_case(1, Arg2, kthString(Arg0, Arg1));
  }
  void test_case_2() {
    int Arg0 = 3;
    int Arg1 = 2;
    string Arg2 = "100";
    verify_case(2, Arg2, kthString(Arg0, Arg1));
  }
  void test_case_3() {
    int Arg0 = 5;
    int Arg1 = 2; 
    string Arg2 = "00101";
    verify_case(3, Arg2, kthString(Arg0, Arg1));
  }
  void test_case_4() {
    int Arg0 = 50;
    int Arg1 = 2000000000;
    string Arg2 = "?????";
    verify_case(4, Arg2, kthString(Arg0, Arg1));
  }

  // END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
   RepeatingFreeStrings ___test; 
   ___test.run_test(-1); 
}
// END CUT HERE 

typedef long long ll;

ll conta(string ptr)
{
  int n = ptr.size();
  int m = n / 2;

  if(n == 0) return 1;
  if(n == 1) return (ptr[0] == ' ' ? 2 : 1);
  
  if(n & 1){
    string s = ptr.substr(0, m) + ptr.substr(m+1, m);
    ll mult = (ptr[m] == ' ' ? 2LL : 1LL);
    return mult * conta(s);
  }

  bool ok = false;
  string inter (m, ' ');
  for(int i = 0; i < m; i++){
    if(ptr[i] != ' ' && ptr[i+m] != ' '){
      if(ptr[i] != ptr[i+m])
	ok = true;
      inter[i] = ptr[i];
    } else if(ptr[i] == ' ' && ptr[i+m] != ' ')
      inter[i] = ptr[i+m];
    else
      inter[i] = ptr[i];
  }

  string esq = ptr.substr(0, m-1);
  string dir = ptr.substr(m, m);
  ll mult = (ptr[m-1] == ' ' ? 2 : 1);
   
  ll r = mult * conta(esq + dir);
  if (!ok) r -= conta(inter);
  return r;
}

string RepeatingFreeStrings::kthString(int n, int _k)
{
  ll k = _k;
  string s (n, ' ');
  if(conta(s) <= k) return "";
  
   for(int i = 0; i < n; i++){
    s[i] = '0';
    ll t = conta(s);
    if(t <= k){
      s[i] = '1';
      k -= t;
    }
   }

  return s;
}
