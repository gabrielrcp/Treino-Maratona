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

class Books
{ 
public: 
        int sortMoves(vector <string> titles) ;
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Algorithms", "Purely Functional Data Structures",
"Intro to C", "Automata and Computability"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, sortMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"the fellowship of the ring",
"the return of the king",
"The two towers"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, sortMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"Basic Engineering Circuit Analysis", "A Course in Combinatorics",
"Artificial Intelligence", "Asimovs Guide to Shakespeare",
"The Nature of Space and Time", "A Time for Trumpets",
"Essentials of Artificial Intelligence", "Life by the Numbers",
"Cognitive Psychology", "ColdFusion"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, sortMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"A", "B", "A", "A", "B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, sortMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"This Book Has No Title", " This Book Does Have A Title"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, sortMoves(Arg0)); }
	void test_case_5() { string Arr0[] = {"What Is The", "What Is The ", "What Is The Title Of This Book"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, sortMoves(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE
int main()
{
   Books ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE

int w[50];
int l;

int busca(int x)
{
  if(w[l-1] <= x) return l;
  int e = 0, d = l-1, r = l-1;
  while(e <= d){
    int m = (e+d)/2;
    if(w[m] > x){
      r = m;
      d = m - 1;
    }
    else
      e = m + 1;
  }
  return r;
}

int lis(vector<int> &v)
{
  l = 1;
  w[0] = v[0];
  for(int i = 1; i < v.size(); i++){
    int j = busca(v[i]);
    if(j == l) l++;
    w[j] = v[i];
  }
  return l;
}

int Books::sortMoves(vector <string> titles)
{
  vector< pair<string, int> > v;
  for(int i = 0; i < titles.size(); i++)
    v.push_back(make_pair(titles[i], i));
  sort(v.begin(), v.end());

  vector<int> w;
  for(int i = 0; i < v.size(); i++)
    w.push_back(v[i].second);

  return titles.size() - lis(w);
}
