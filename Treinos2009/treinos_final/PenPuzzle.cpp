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

class PenPuzzle
{ 
public: 
   int solve(vector <string> puzzle);
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABC", "ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABC", "BCA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABA", "BCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"CBBC", "DCAB", "ADAD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
   PenPuzzle ___test; 
   ___test.run_test(-1); 
} 
// END CUT HERE 


int mapa[3][4];
int n, m;
int lx, ly;

typedef long long ll;

int a[4];

ll codifica()
{
  memset(a, 0, sizeof a);  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(mapa[i][j] != -1)
	a[mapa[i][j]] |= (1 << (i + j*n));
  
  sort(a, a+m);
 
  ll r = 0;
  for(int i = 0; i < m; i++)
    r |= (((ll)a[i]) << (n*m*i));
  return r;
  
}

void decodifica(ll e)
{
  memset(a, 0, sizeof a);  
  ll msk = ((1ll << (n*m)) - 1);
  for(int i = 0; i < m; i++){
    a[i] = (int) (msk & e);
    e >>= (n*m);
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      mapa[i][j] = -1;
      int k;
      for(k = 0; k < m; k++){
	if(a[k] & (1 << (i + j*n))){
	  mapa[i][j] = k;
	  break;
	}
      }
      if(k == m){
	lx = i; ly = j;
      }
    }
  }
}

void gira(int i, int d)
{
  if(d == 1){
    for(int j = 1; j < m; j++)
      swap(mapa[i][j-1], mapa[i][j]);
  } else{
    for(int j = m-1; j > 0; j--)
      swap(mapa[i][j-1], mapa[i][j]);
  }

  ly += d;
}

bool troca(int d)
{
  if(lx + d < 0 || lx + d >= n)
    return false;
  swap(mapa[lx][ly], mapa[lx+d][ly]);
  lx += d;
  return true;
}

bool resolvido(ll e)
{
  ll msk = ((1ll << (n*m)) - 1);
  for(int i = 0; i < m; i++){
    a[i] = (int) (msk & e);
    e >>= (n*m);
  }
  for(int i = 0; i < m; i++){
    if(a[i] >= (1 << (n*(i+1))))
      return false;
    int x = ((a[i] & (a[i]-1)) ^ a[i]);
    if(x < (1 << (n*i)))
      return false;
  }

  return true;
}

int resolve()
{
  queue<ll> Q;
  map<ll, int> M;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      int x = mapa[i][j];
      mapa[i][j] = -1;
      ll e = codifica();
      if(resolvido(e)) { return 0;}
      Q.push(e);
      M[e] = 0;
      mapa[i][j] = x;
    }

  while(!Q.empty()){
    ll e = Q.front(); Q.pop();
    decodifica(e);
    int dist = M[e];

    for(int i = 0; i < n; i++){
      for(int d = -1; d <= 1; d += 2){
	gira(i, d);
	ll nv = codifica();
	if(resolvido(nv)) { return dist+1;}
	if(M.find(nv) == M.end()){
	  Q.push(nv);
	  M[nv] = dist + 1;
	}
	gira(i, -d);
      }
    }

    for(int d = -1; d <= 1; d += 2){
      if(troca(d)){
	ll nv = codifica();
	if(resolvido(nv)){ return dist+1;}
	if(M.find(nv) == M.end()){
	  Q.push(nv);
	  M[nv] = dist + 1;
	}
	troca(-d);
      }
    }
  }

  return -1; //hein?!
}

int PenPuzzle::solve(vector <string> puzzle)
{
  n = puzzle.size();
  m = puzzle[0].size();
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      mapa[i][j] = puzzle[i][j] - 'A';

  return resolve();
}
