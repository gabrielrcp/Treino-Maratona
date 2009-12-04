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

class ShortPaths
{ 
public: 
  long long getPath(vector <string> graph, long long k, int start, int finish);
  
  // BEGIN CUT HERE
public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0(); 
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
    if ((Case == -1) || (Case == 6)) test_case_6();
    if ((Case == -1) || (Case == 7)) test_case_7();
  }

private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	
  void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() {
    string Arr0[] = {
      "0100",
      "0020",
      "0003",
      "4000"};
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    long long Arg1 = 1LL;
    int Arg2 = 0;
    int Arg3 = 2;
    long long Arg4 = 3LL;
    verify_case(0, Arg4, getPath(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_1() { string Arr0[] = {
      "0100",
      "0020",
      "0003",
      "4000"};
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    long long Arg1 = 2LL;
    int Arg2 = 0;
    int Arg3 = 2;
    long long Arg4 = 13LL; verify_case(1, Arg4, getPath(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_2() {
    string Arr0[] = {
      "011",
      "000",
      "000"};
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    long long Arg1 = 1LL;
    int Arg2 = 1;
    int Arg3 = 2;
    long long Arg4 = -1LL;
    verify_case(2, Arg4, getPath(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_3() {
    string Arr0[] = {
      "010000",
      "001010",
      "000101",
      "000000",
      "010000",
      "001000"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    long long Arg1 = 3LL; 
    int Arg2 = 0;
    int Arg3 = 3;
    long long Arg4 = 5LL; 
    verify_case(3, Arg4, getPath(Arg0, Arg1, Arg2, Arg3)); 
  }
  void test_case_4() {
    string Arr0[] = {
      "010000",
      "001010",
      "000103",
      "000000",
      "010000",
      "002000"};
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    long long Arg1 = 11LL;
    int Arg2 = 0; 
    int Arg3 = 3;
    long long Arg4 = 14LL; 
    verify_case(4, Arg4, getPath(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_5() {
    string Arr0[] = {
      "010000000",
      "001002000",
      "000100000",
      "000010900",
      "000000006",
      "030000000",
      "007000000",
      "000040000",
      "000000070"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    long long Arg1 = 5621LL;
    int Arg2 = 0;
    int Arg3 = 7;
    long long Arg4 = 363LL; 
    verify_case(5, Arg4, getPath(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_6() {
    string Arr0[] = {
      "09000000000000000000000002000000000000000000000000",
      "00900000000000000000000000000000000000000000000000",
      "00090000000000000000000000000000000000000000000000",
      "00009000000000000000000000000000000000000000000000",
      "00000900000000000000000000000000000000000000000000",
      "00000090000000000000000000000000000000000000000000",
      "00000009000000000000000000000000000000000000000000",
      "00000000900000000000000000000000000000000000000000",
      "00000000090000000000000000000000000000000000000000",
      "00000000009000000000000000000000000000000000000000",
      "00000000000900000000000000000000000000000000000000",
      "00000000000090000000000000000000000000000000000000",
      "00000000000009000000000000000000000000000000000000",
      "00000000000000900000000000000000000000000000000000",
      "00000000000000090000000000000000000000000000000000",
      "00000000000000009000000000000000000000000000000000",
      "00000000000000000900000000000000000000000000000000",
      "00000000000000000090000000000000000000000000000000",
      "00000000000000000009000000000000000000000000000000",
      "00000000000000000000900000000000000000000000000000",
      "00000000000000000000090000000000000000000000000000",
      "00000000000000000000009000000000000000000000000000",
      "00000000000000000000000900000000000000000000000000",
      "00000000000000000000000090000000000000000000000000",
      "40000000000000000000000000000000000000000000000000",
      "00000000000000000000000000900000000000000000000000",
      "00000000000000000000000000090000000000000000000000",
      "00000000000000000000000000009000000000000000000000",
      "00000000000000000000000000000900000000000000000000",
      "00000000000000000000000000000090000000000000000000",
      "00000000000000000000000000000009000000000000000000",
      "00000000000000000000000000000000900000000000000000",
      "00000000000000000000000000000000090000000000000000",
      "00000000000000000000000000000000009000000000000000",
      "00000000000000000000000000000000000900000000000000",
      "00000000000000000000000000000000000090000000000000",
      "00000000000000000000000000000000000009000000000000",
      "00000000000000000000000000000000000000900000000000",
      "00000000000000000000000000000000000000090000000000",
      "00000000000000000000000000000000000000009000000000",
      "00000000000000000000000000000000000000000900000000",
      "00000000000000000000000000000000000000000090000000",
      "00000000000000000000000000000000000000000009000000",
      "00000000000000000000000000000000000000000000900000",
      "00000000000000000000000000000000000000000000090000",
      "00000000000000000000000000000000000000000000009000",
      "00000000000000000000000000000000000000000000000900",
      "00000000000000000000000000000000000000000000000090",
      "00000000000000000000000000000000000000000000000009",
      "00000000000000000000000004000000000000000000000000"};
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    long long Arg1 = 10000000000LL;
    int Arg2 = 0;
    int Arg3 = 49;
    long long Arg4 = 31112618LL;
    verify_case(6, Arg4, getPath(Arg0, Arg1, Arg2, Arg3));
  }

  void test_case_7() {

    string Arr0[] = {
      "09000000000000000000010",
      "00900000000000000000000",
      "00090000000000000000000",
      "00009000000000000000000",
      "00000900000000000000000",
      "00000090000000000000000",
      "00000009000000000000000",
      "00000000900000000000000",
      "00000000090000000000000",
      "00000000009000000000000",
      "00000000000900000000000",
      "00000000000090000000000",
      "00000000000009000000000",
      "00000000000000900000000",
      "00000000000000090000000",
      "00000000000000009000000",
      "00000000000000000900000",
      "00000000000000000090000",
      "00000000000000000009000",
      "00000000000000000000900",
      "60000000000000000000000",
      "00000000000000000000005",
      "00000000000000000000010"};

    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    long long Arg1 = 1000000000000LL;
    int Arg2 = 0;
    int Arg3 = 22;
    long long Arg4 = 47243958LL; 
    verify_case(7, Arg4, getPath(Arg0, Arg1, Arg2, Arg3));
  }


// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
   ShortPaths ___test; 
   ___test.run_test(-1); 
} 
// END CUT HERE 

typedef long long ll;

int n;
vector< vector<int> > G;

int lbl[55], low[55], pai[55], tempo;
int ponta[55];

void dfs(int i)
{
  if(lbl[i] != -1) return;
  lbl[i] = tempo++;
  low[i] = lbl[i];
  for(int j = 0; j < n; j++){
    if(G[i][j] == 0) continue;
    if(lbl[j] == -1){
      pai[j] = i;
      dfs(j);
      low[i] = min(low[i], low[j]);
    } else{
      low[i] = min(low[i], lbl[j]);
      ponta[j] = i;
    }
  }
}

int ciclo(int i)
{
  int j = ponta[i];
  if(j == -1) return 0;
  int r = G[j][i];
  while(j != i){
    r += G[pai[j]][j];
    j = pai[j];
  }
  return r;
}


vector<int> conta;

#define LIM 510

ll memo[LIM][51];

bool predicado(ll a, ll b, ll H, ll k)
{
  ll r = 0;
  for(int i = 0; a*i <= H; i++){
    r += (H - i*a) / b + 1;
    if(r >= k) return true;
  }
  return false;
}

int resolve2(int a, int b, ll k)
{
  int esq = 1, dir = 1000000000;
  int r = dir;
  while(esq <= dir){
    int m = (esq+dir)/2;
    if(predicado(a, b, m, k)){
      r = m;
      dir = m - 1;
    } else
      esq = m + 1;
  }
  return r;
}


ll resolve(ll k)
{
  if(conta.size() == 1)
    return (k-1) * conta[0];
  if(k == 1) return 0;

  
  if(conta.size() == 2)
    return resolve2(conta[1], conta[0], k);
  
  memset(memo, 0, sizeof memo);

  for(int h = 0; h < LIM; h++)
    memo[h][conta.size()] = 0;
 
  for(int i = 0; i < conta.size(); i++)
    memo[0][i] = 1;
  k--;

  for(int H = 1; ; H++){
    int h = (H % LIM);

    for(int i = conta.size()-1; i >= 0; i--)
      if(conta[i] <= H)
	memo[h][i] = memo[(h-conta[i]+LIM)%LIM][i] + memo[h][i+1];
    k -= memo[h][0];
    if(k <= 0)
      return H;
  }
}

ll ShortPaths::getPath(vector <string> graph, ll k, int s, int t)
{
  n = graph.size();
  G = vector< vector<int> > (n, vector<int> (n, 0));
 
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      G[i][j] = graph[i][j] - '0';
    }

  memset(lbl, -1, sizeof lbl);
  memset(pai, -1, sizeof pai);
  memset(ponta, -1, sizeof ponta);
  tempo = 0;
  dfs(s);

  if(pai[t] == -1) return -1;

  conta.clear();
  ll base = 0;
  for(int i = t; i != s; i = pai[i]){
    base += G[pai[i]][i];
    if(low[i] == lbl[i]){
      int x = ciclo(i);
      if(x != 0)
	conta.push_back(x);
    }
  }
  int x = ciclo(s);
  if(x != 0)
    conta.push_back(x);

  if(conta.size() == 0 && k > 1) return -1;
  sort(conta.begin(), conta.end());

  return base + resolve(k);
}
