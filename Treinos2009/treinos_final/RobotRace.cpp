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

class RobotRace
{ 
public: 
   vector <string> getPrizes(vector <string> board, vector <string> tokenValues);
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"b C"
,"a D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a:CD", "b:DC"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a 100", "b 100" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getPrizes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"b Cx"
,"a D "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a:CD", "b:DC", "x:C"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a 99", "b 20", "x 100" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getPrizes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"b C x"
,"a D  "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a:CD", "b:DC", "x:C"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a 99", "b 99", "x 20" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getPrizes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"w     x"
,"  A*B  "
," H   C "
," * Q * "
," G   D "
,"  F*E  "
,"y     z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"z:Q", "y:Q", "x:Q", "w:Q"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"w 20", "x 20", "y 20", "z 20" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getPrizes(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"a*  "
," X b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a:X","b:X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a 20", "b 100" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getPrizes(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"  bY a"
,"X c  Z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a:XYZ"
,"b:XYZ"
,"c:YXZ"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a 98", "b 99", "c 99" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, getPrizes(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
   RobotRace ___test; 
   ___test.run_test(-1); 
} 
// END CUT HERE 


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int dist[55][55][4];

bool obstaculo(char c)
{
  return (('A' <= c && c <= 'Z') || c == '*');
}

vector<int> distancias(vector<string> &board, int sx, int sy)
{
  int n = board.size();
  int m = board[0].size();

  vector<bool> cheguei (30, false);
  vector< pair<int, int> > resp;

  queue< pair< pair<int, int> , int> > Q;
  memset(dist, -1, sizeof dist);
  for(int k = 0; k < 4; k++){
    dist[sx][sy][k] = 0;
    Q.push(make_pair(make_pair(sx, sy), k));
  }

  while(!Q.empty()){
    int i = Q.front().first.first;
    int j = Q.front().first.second;
    int k = Q.front().second;
    int d = dist[i][j][k];
    Q.pop();

    int x = i + dx[k], y = j + dy[k];
    if(0 <= x && x < n && 0 <= y && y < m && dist[x][y][k] == -1 && (!obstaculo(board[x][y]))){
      if('a' <= board[x][y] && board[x][y] <= 'z' && (!cheguei[board[x][y] - 'a'])){
	cheguei[board[x][y]-'a'] = true;
	resp.push_back(make_pair(d+1, board[x][y]-'a'));
      }
      dist[x][y][k] = d+1;
      Q.push(make_pair(make_pair(x,y),k));
    }

    for(int l = -1; l <= 1; l += 2){
      int kk = k + l;
      if(kk == 4) kk = 0;
      if(kk == -1) kk = 3;

      if(dist[i][j][kk] == -1){
	dist[i][j][kk] = d+1;
	Q.push(make_pair(make_pair(i,j), kk));
      }
    }
  }

  vector<int> r (27, resp.size()+1);
  sort(resp.begin(), resp.end());

  for(int i = 0; i < resp.size(); i++)
    r[resp[i].second] = i;
  r[26] = resp.size();
  return r;
}

vector<int> prefHomens[30];
int atH[30];
vector<int> ordemMulheres[30];
int casouM[30];

char buf[100];

vector <string> RobotRace::getPrizes(vector <string> board, vector <string> tokenValues)
{
  for(int i = 0; i < 30; i++){
    prefHomens[i].clear();
    ordemMulheres[i].clear();
  }

  for(int i = 0; i < tokenValues.size(); i++){
    char c;
    sscanf(tokenValues[i].c_str(), "%c:%s", &c, buf);
    for(int j = 0; buf[j]; j++)
      prefHomens[c-'a'].push_back(buf[j] - 'A');
  }

  vector<bool> existe (26, false);
  for(int i = 0; i < board.size(); i++)
    for(int j = 0; j < board[i].size(); j++)
      if('A' <= board[i][j] && board[i][j] <= 'Z')
	ordemMulheres[board[i][j] - 'A'] = distancias(board, i, j);
      else if('a' <= board[i][j] && board[i][j] <= 'z')
	existe[board[i][j] - 'a'] = true;

  
  memset(atH, 0, sizeof(atH));
  for(int i = 0; i < 26; i++)
    casouM[i] = 26;

  for(int i = 0; i < 26; i++)
    if(prefHomens[i].size() > 0){
      int j = prefHomens[i][0];
      if(ordemMulheres[j][casouM[j]] > ordemMulheres[j][i])
	casouM[j] = i;
    }

  bool fail = true;
  while(fail){
    fail = false;
    for(int i = 0; i < 26; i++){
      if(atH[i] == prefHomens[i].size()) continue;
      int j = prefHomens[i][atH[i]];
      if(casouM[j] == i) continue;

      fail = true;
      while(1){
	atH[i]++;
	if(atH[i] == prefHomens[i].size()) break;
	j = prefHomens[i][atH[i]];
	if(ordemMulheres[j][casouM[j]] > ordemMulheres[j][i]){
	  casouM[j] = i;
	  break;
	}
      }
    }
  }
  
  vector<string> resp;
  for(int i = 0; i < 26; i++){
    if(existe[i]){
      int v = ((prefHomens[i].size() == atH[i]) ? 20 : 100-atH[i]);
      sprintf(buf, "%c %d", i+'a', v);
      resp.push_back(buf);
    }
  }
  return resp;
  
}
