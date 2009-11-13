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

class Answer
{ 
public: 
  int chooseOne(vector <string> words) ;
        
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"CAT", "DOG", "ANT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, chooseOne(Arg0)); }
  void test_case_1() { string Arr0[] = {"A", "D", "E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, chooseOne(Arg0)); }
  void test_case_2() { string Arr0[] = {"DOG", "CAT", "ANT", "DON", "ANN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, chooseOne(Arg0)); }
  void test_case_3() { string Arr0[] = {"FXFE", "SPOH", "ICFK", "JGHT", "TAMY", "OBBX", "IPIR", "YTBJ", "WXCZ", "WQSN", "CHEI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, chooseOne(Arg0)); }

  // END CUT HERE
 
}; 

// BEGIN CUT HERE
int main()
{
  Answer ___test; 
  ___test.run_test(-1); 
} 
// END CUT HERE

int n;
vector<int> separa[26];

bool diferentes(string &s1, string &s2, char c)
{
  for(int i = 0; i < s1.size(); i++)
    if(s1[i] != s2[i])
      if(s1[i] == c || s2[i] == c)
	return true;
  return false;
}


int memo[1<<18];


int resolve(int e)
{
  int &r = memo[e];
  if(r != -1) return r;

  r = (1 << 30);
  for(int k = 0; k < 26; k++){
    int t = 0;
    int j;
    for(j = 0; j < separa[k].size(); j++){
      int msk = (e & separa[k][j]);
      if(e == msk) break;
      t = max(t, resolve(msk)+1);
    }
    if(j == separa[k].size())
      r = min(r, t);
  }
  return r;
}

int Answer::chooseOne(vector <string> words)
{
  n = words.size();

  for(int k = 0; k < 26; k++){
    separa[k].clear();
    vector<int> indice;

    for(int i = 0; i < n; i++){
      int j;
      for(j = 0; j < separa[k].size(); j++){
	if(!diferentes(words[i], words[indice[j]], k+'A')){
	  separa[k][j] |= (1 << i);
	  break;
	}
      }
      if(j == separa[k].size()){
	separa[k].push_back(1 << i);
	indice.push_back(i);
      }
    }
  }


  memset(memo, -1, sizeof(memo));
  memo[0] = 0;
  for(int i = 0; i < n; i++)
    memo[1<<i] = 0;

  return resolve((1<<n)-1);
}
