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

class Clue
{ 
public: 
  vector <string> whodunit(vector <string> cards, vector <string> guesses) ;
        
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { string Arr0[] = {"S1","S2","S4","S3","S5","W5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1 1 1 0 N0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "L1",  "S6",  "W1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, whodunit(Arg0, Arg1)); }
  void test_case_1() { string Arr0[] = {"L3","S2","S4","S3","S5","W5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 1 1 1 0 N0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "L1",  "L2",  "L4",  "L5",  "L6",  "L7",  "L8",  "L9",  "S1",  "S6",  "W1",  "W2",  "W3",  "W4",  "W6" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, whodunit(Arg0, Arg1)); }
  void test_case_2() { string Arr0[] = {"W4","W1","L5","L9","S3","L2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 3 8 4 1 W4",
																			      "1 3 8 3 3 W3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "L8",  "S1",  "S2",  "S4",  "S5",  "S6",  "W2",  "W5",  "W6" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, whodunit(Arg0, Arg1)); }
  void test_case_3() { string Arr0[] = {"W4","W1","L5","L9","S3","L2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 3 5 4 0 N0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "L1",  "L3",  "L4",  "L6",  "L7",  "L8",  "S1",  "S2",  "S4",  "S5",  "S6",  "W2",  "W3",  "W5",  "W6" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, whodunit(Arg0, Arg1)); }
  void test_case_4() { string Arr0[] = {"W4","W1","L5","L9","S3","L2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "L1",  "L3",  "L4",  "L6",  "L7",  "L8",  "S1",  "S2",  "S4",  "S5",  "S6",  "W2",  "W3",  "W5",  "W6" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, whodunit(Arg0, Arg1)); }
  void test_case_5() { string Arr0[] = {"L5","L7","L8","S5","W5","W6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 6 1 6 3 N0", "3 6 5 4 1 L5", "1 6 1 3 2 W3","2 3 5 1 3 N0", "3 5 7 1 1 S5", "1 6 1 1 3 L1", "2 1 2 5 3 N0", "3 4 6 5 1 W5", "1 3 3 4 2 W4", "2 6 4 1 3 N0", "3 4 3 6 1 W6", "1 4 6 1 2 S4", "2 2 5 6 3 N0", "3 6 7 4 1 L7", "1 6 4 1 3 L4", "2 6 5 1 1 L5", "3 4 3 1 2 N0", "1 6 2 1 3 L2", "2 6 3 1 0 N0", "3 6 3 1 0 N0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "L3",  "S6",  "W1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, whodunit(Arg0, Arg1)); }

  // END CUT HERE
}; 

// BEGIN CUT HERE
int main()
{
  Clue ___test; 
  ___test.run_test(-1); 
} 
// END CUT HERE


int id_carta(string s)
{
  switch(s[0]){
  case 'S': return s[1] - '1';
  case 'W': return s[1] - '1' + 6;
  case 'L': return s[1] - '1' + 12;
  }
}

string nome_carta(int id)
{
  string s = "12";
  if(id < 6){
    s[0] = 'S';
    s[1] = id+'1';
  } else if(id >= 12){
    s[0] = 'L';
    s[1] = id-12+'1';
  }
  else{
    s[0] = 'W';
    s[1] = id-6+'1';
  }
  return s;
}

struct pal{
  int a, b;
  int mask;
  int show;
};

int mao[3];
int suspeita;
int total;
int usadas;

vector<pal> v;
int n;


bool verifica()
{
  for(int i = 0; i < n; i++){
    if(v[i].b == -1){
      for(int j = 0; j < 3; j++){
	if(j == v[i].a) continue;
	if((v[i].mask & mao[j]) != 0)
	  return false;
      }
    }
    else{
      if((mao[v[i].b] & v[i].mask) == 0)
	return false;
      int j = (v[i].a + 1)%3;
      if(v[i].b != j){
	if((mao[j] & v[i].mask) != 0)
	  return false;
      }
      if(v[i].show != -1){
	if ((mao[v[i].b] & v[i].show) == 0)
	  return false;
      }
    }
  }
  return true;
}

bool para;

void gera(int k, int at)
{
  if(k == 6){
    mao[2] = (((1<<21)-1) & (~usadas));
    if(verifica()){
      total |= suspeita;
      para = true;
    }   
    return;
  }
  if(at == 21) return;

  gera(k, at+1);
  if(para) return;
  if((1 << at) & usadas)
    return;

  usadas |= (1 << at);
  mao[1] |= (1 << at);
  gera(k+1, at+1);
  usadas ^= (1 << at);
  mao[1] ^= (1 << at);

}


vector <string> Clue::whodunit(vector <string> cards, vector <string> guesses)
{
  for(int i = 0; i < 3; i++)
    mao[i] = 0;

  for(int i = 0; i < cards.size(); i++)
    mao[0] |= (1<< id_carta(cards[i]));

  n = guesses.size();
  v = vector<pal> (n);

  for(int i = 0; i < n; i++){
    int s, l, w;
    char st[10];
    sscanf(guesses[i].c_str(), "%d %d %d %d %d %s",
	   &v[i].a, &s, &l, &w, &v[i].b, st);
    v[i].a--; v[i].b--;
    s--; l--; w--;
    l += 12; w += 6;
    v[i].mask = ( (1 << s) | (1 << l) | (1 << w));
    v[i].show = ((st[0] == 'N') ? -1 : (1 << id_carta(st)));
  }

  total = 0;
  for(int i = 0; i < 6; i++)
    for(int j = 6; j < 12; j++)
      for(int k = 12; k < 21; k++){
	suspeita = ((1 << i) | (1 << j) | (1 << k));
	if((suspeita & mao[0]) != 0) continue;
	usadas = (suspeita | mao[0]);
	para = false;
	gera(0, 0);
      }
  vector<string> resp;
  for(int i = 0; i < 21; i++)
    if((1 << i) & total)
      resp.push_back(nome_carta(i));
  sort(resp.begin(), resp.end());
  return resp;
}
