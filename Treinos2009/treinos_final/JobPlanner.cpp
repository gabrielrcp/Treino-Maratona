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

class JobPlanner
{ 
public: 
  int minimalCost(vector <string> can, vector <int> cost) ;
        
  // BEGIN CUT HERE
public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
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
  void verify_case(int Case, const int &Expected, const int &Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received) cerr << "PASSED" << endl;
    else { cerr << "FAILED" << endl;
      cerr << "\tExpected: \"" << Expected << '\"' << endl;
      cerr << "\tReceived: \"" << Received << '\"' << endl;
    }
  }
	
  void test_case_0() {
    string Arr0[] = {"YY","YY"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {1,2};
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 3;
    verify_case(0, Arg2, minimalCost(Arg0, Arg1));
  }
  void test_case_1() { 
    string Arr0[] = {"YY","YY"};
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {1,5};
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 4;
    verify_case(1, Arg2, minimalCost(Arg0, Arg1));
  }
  void test_case_2() {
    string Arr0[] = {"YN", "YY"};
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {1, 5};
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 6; verify_case(2, Arg2, minimalCost(Arg0, Arg1));
  }
  void test_case_3() {
    string Arr0[] = {"YN", "YN"};
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {1, 1};
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = -1;
    verify_case(3, Arg2, minimalCost(Arg0, Arg1)); 
  }

  void test_case_4() {
    string Arr0[] =
      {"YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYYYYYYNNNYYYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYNNNNNNNNNNNNYYYYY",
       "YYNNNYYNNNYYYYNYYYYNNNNNNNNNNNNNNNNNNNNNNNNNYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYNNNNNNNNNNNNYYYYYYY",
       "YYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYYYYYYYYYYNYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYY",
       "YYNNNYYYYYYYYYYYYYNYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYYYYYYYYYYYYYNNNNNNNYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYYYYYYNNNNNNYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYY",
       "YYNNNYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYYYYYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYYYYYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYYYYYYNNNYYYYYYYYYYYNYYYYYYYYYYYYYNYYYYYYYYYYYYY",
       "YYYYYYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYYYYYYNNNYYYYYYYYNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYYYYYYNNNYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYNNYYYYY",
       "YYYYYYYNNNYYYYYYYYYYYYYYYYNNNNNNNYYYYYYYYYYYYYYYY",
       "NYYYYYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYYYYYYNNNYYYYYYNYYYYYYYYYYYYYYYYNYYYYYYNNNYYYYYY",
       "YYYYYYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYNYYYYYYNYYYYNYYYYYYYYYYYYYYNYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYNYYYYYYYNYYYYYYNYYYNYYYYYYY",
       "YYNNNYYNNNYYYYYYYNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYNYYYYYYNYYYYYYYNNYYYYYYY",
       "YYNNNYYNNNYYYYYNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYY",
       "NYYNNNYYNNNYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYNYYYNYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYY",
       "NNNYYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYNNYYYYYYYYYYYYYYYYYYYYYYYN",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYNNYYNYYYYYYYYNNYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYNNNNNYYYYYYYYYYYYYY",
       "YYNNNYYNNNYYYYYYYYYYYYYYYYYYYYYYYYYNNNYYYYYYYYYYY"};

    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));

    int Arr1[] = {500000, 2, 4, 5, 6, 25012, 32143, 5, 6,
		  25012, 32143, 31234, 5422, 34223, 4000, 5000, 7000, 8000,
		  9000, 10002, 4003, 40003, 400000, 55555, 66666, 77777,
		  88888, 99999, 202020, 2000, 4000, 5000, 7000, 8000, 9000,
		  10002, 4003, 40003, 400000, 55555, 66666, 77777, 88888,
		  99999, 202020, 55555, 66666, 88888, 99999, 202020};
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 1648;
    verify_case(4, Arg2, minimalCost(Arg0, Arg1)); 
  }

  void test_case_5() {
    string Arr0[] = {
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY"};    

    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		  1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 50;
    verify_case(5, Arg2, minimalCost(Arg0, Arg1)); 
  }

  // END CUT HERE
 
}; 

// BEGIN CUT HERE
int main()
{
  JobPlanner ___test; 
  ___test.run_test(-1); 
} 
// END CUT HERE

#define MAXV 110
#define MAXE 50000


int grafo[MAXV];
int vertice[MAXE];
int cap[MAXE];
int fluxo[MAXE];
int custo[MAXE];
int prox[MAXE];
int bufe;

int nw, nt, n;

void add_edge(int i, int j, int cp, int cs)
{
  int e1 = bufe++;
  int e2 = bufe++;

  prox[e1] = grafo[i];
  grafo[i] = e1;
  vertice[e1] = j;
  cap[e1] = cp;
  fluxo[e1] = 0;
  custo[e1] = cs;

  prox[e2] = grafo[j];
  grafo[j] = e2;
  vertice[e2] = i;
  cap[e2] = 0;
  fluxo[e2] = 0;
  custo[e2] = -cs;
}

int ant[MAXV];
int dist[MAXV];

bool encontra_caminho()
{
  queue<int> Q;
  Q.push(0);
  memset(dist, 0x3f, n * sizeof(int));
  dist[0] = 0;
  ant[0] = -1;

  while(!Q.empty()){
    int i = Q.front(); Q.pop();
    for(int e = grafo[i]; e != -1; e = prox[e]){
      if(fluxo[e] == cap[e]) continue;
      int j = vertice[e];
      if(dist[j] > dist[i] + custo[e]){
	dist[j] = dist[i] + custo[e];
	ant[j] = e;
	Q.push(j);
      }
    }
  }
  return (dist[1] < 0x3f3f3f3f);
}


int aumenta_fluxo(int j, int v)
{
  int e = ant[j];
  if(e == -1) return (1 << 30);

  v = min(v, cap[e] - fluxo[e]);
  v = min(v, aumenta_fluxo(vertice[e^1], v));

  fluxo[e] += v;
  fluxo[e^1] -= v;

  return v;  
}


int maxflowmincost()
{
  int max_flow = 0;
  while(encontra_caminho())
    max_flow += aumenta_fluxo(1, 1<<30);

  if(max_flow < nt) return -1;

  int resp = 0;
  for(int i = 0; i < n; i++){
    for(int e = grafo[i]; e != -1; e = prox[e]){
      if(fluxo[e] > 0)
	resp += custo[e] * fluxo[e];
    }
  }
  return resp;
}


int JobPlanner::minimalCost(vector <string> can, vector <int> cost)
{
  nw = can.size();
  nt = can[0].size();
  n = nw+nt+2;

  bufe = 0;
  memset(grafo, -1, sizeof(grafo));


  for(int i = 0; i < nt; i++)
    add_edge(nw+2+i, 1, 1, 0);
  

  for(int i = 0; i < nw; i++){
    int t = 0;
    for(int j = 0; j < nt; j++)
      if(can[i][j] == 'Y'){
	t++;
	add_edge(0, 2+i, 1, cost[i] * (2*t-1));
      }

    for(int j = 0; j < nt; j++){
      if(can[i][j] == 'Y')
	add_edge(2+i, 2+nw+j, 1, 0);
    }
  }
  return maxflowmincost();
}
