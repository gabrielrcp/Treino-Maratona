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
 
class WhatsThisChord
{ 
 public:
    string classify(vector <int> chord);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, 3, 2, 0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C Major"; verify_case(0, Arg1, classify(Arg0)); }
	void test_case_1() { int Arr0[] = {3,2,0,0,0,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "G Major"; verify_case(1, Arg1, classify(Arg0)); }
	void test_case_2() { int Arr0[] = {-1,0,2,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A Minor"; verify_case(2, Arg1, classify(Arg0)); }
	void test_case_3() { int Arr0[] = {-1,4,3,1,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C# Major"; verify_case(3, Arg1, classify(Arg0)); }
	void test_case_4() { int Arr0[] = {8,10,10,9,8,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C Major"; verify_case(4, Arg1, classify(Arg0)); }
	void test_case_5() { int Arr0[] = {0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(5, Arg1, classify(Arg0)); }
	void test_case_6() { int Arr0[] = {-1,-1,4,-1,-1,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(6, Arg1, classify(Arg0)); }
	void test_case_7() { int Arr0[] = {-1, -1, 2, 0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C Major"; verify_case(7, Arg1, classify(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WhatsThisChord ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 

//0  1   2  3   4  5  6   7  8   9  10 11

//E, A, D, G, B, E

int inicial[6] = {4, 9, 2, 7, 11, 4};
string nomes[12] = {"C", "C#", "D", "D#", "E", "F",
		    "F#", "G", "G#", "A", "A#", "B"};
struct corda{
  set<int> S;
  bool operator == (const corda &outra) const{
    if(S.size() != outra.S.size())
      return false;
    set<int>::iterator it = S.begin(), jt= outra.S.begin();
    while(it != S.end()){
      if(*it != *jt)
	return false;
      it++; jt++;
    }
    return true;
  }
};

string WhatsThisChord::classify(vector <int> chord)
{
  corda atual;
  for(int i = 0; i < 6; i++){
    if(chord[i] == -1) continue;
    atual.S.insert((chord[i] + inicial[i]) % 12);
  }
  if(atual.S.size() != 3) return "";

  corda at;
  at.S.insert(0);
  at.S.insert(4);
  at.S.insert(7);
  for(int i = 0; i < 12; i++){
    if(at == atual)
      return nomes[i] + " Major";
    corda nova;
    for(set<int>::iterator it = at.S.begin(); it != at.S.end(); it++){
      nova.S.insert(((*it)+1)%12);
    }
    at = nova;
  }

  at.S.clear();
  at.S.insert(0);
  at.S.insert(3);
  at.S.insert(7);
  for(int i = 0; i < 12; i++){
    if(at == atual)
      return nomes[i] + " Minor";
    corda nova;
    for(set<int>::iterator it = at.S.begin(); it != at.S.end(); it++){
      nova.S.insert(((*it)+1)%12);
    }
    at = nova;
  }

  return "";  
}
