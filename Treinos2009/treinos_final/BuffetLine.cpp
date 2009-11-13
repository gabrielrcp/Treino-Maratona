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

class BuffetLine
{ 
public: 
  vector <int> order(string food, vector <string> cravings) ;
        
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
  void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { 
    cerr << "Test Case #" << Case << "..."; 
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: " << print_array(Expected) << endl;
      cerr << "\tReceived: " << print_array(Received) << endl;
    }
  }
  void test_case_0() {
    string Arg0 = "applesauce beans carrots dates eggplant";
    string Arr1[] = { "beans", "applesauce",  "dates" };
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {2, 0, 1 };
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(0, Arg2, order(Arg0, Arg1));
  }
  void test_case_1() {
    string Arg0 = "applesauce beans carrots dates eggplant";
    string Arr1[] = { "beans", "applesauce", "beans", "dates" };
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {0, 1, 3, 2 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(1, Arg2, order(Arg0, Arg1));
 }
  void test_case_2() {
    string Arg0 = "bread water"; string Arr1[] = { "" }; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {0 };
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(2, Arg2, order(Arg0, Arg1));
  }
  void test_case_3() {
    string Arg0 = "A B C D E F";
    string Arr1[] = { "A C E D",
		      "A B D E F",
		      "B C A D",
		      "B C F D E",
		      "B D C F" };
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {3, 1, 0, 4, 2 };
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(3, Arg2, order(Arg0, Arg1));
  }
  void test_case_4() {
    string Arg0 = "A B C"; 
    string Arr1[] = { "A", "A", "A", "A",
		      "B", "B", "B", "B",
		      "C", "C", "C", "C" };
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {8, 4, 0, 9, 5, 1, 10, 6, 2, 11, 7, 3 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(4, Arg2, order(Arg0, Arg1));
  }
  void test_case_5() {
    string Arg0 = "A G E F D B H C";
    string Arr1[] = { "D C A H",
		      "H B F G A",
		      "B F G D",
		      "F C E B A G",
		      "D H B C",
		      "B A D F G",
		      "E B C F D",
		      "A D H E B G",
		      "A H B G E C",
		      "F D A B C",
		      "B D A G C",
		      "A G E C F" };
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {0, 4, 1, 10, 9, 6, 2, 3, 11, 8, 7, 5 };
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(5, Arg2, order(Arg0, Arg1));
  }

// END CUT HERE
 
}; 

// BEGIN CUT HERE
int main()
{
   BuffetLine ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE



map<string, int> comida;
vector<int> desejos;
int n, nc;

int memo[1<<12][1<<8];
pair<int, int> proximo[1<<12][1<<8];


int novas_paradas(int paradas, int i)
{
  int np = desejos[i];
  int conta = 0;
  for(int j = 0; j + 1 < nc; j++){

    if(((1 << j) & np)){
      if(!(((1 << (j+1)) & paradas)))
	 conta++;
    }else{
      if((1 << (j+1)) & paradas){
	if(conta == 0)
	  np |= (1 << j);
	else
	  conta--;
      }
    }
  }
  return np;
}


int vai(int faltam, int paradas)
{
  int &r = memo[faltam][paradas];
  if(r != -1) return r;

  pair<int, int> &prox = proximo[faltam][paradas];

  r = 0;
  if(faltam == 0){
    for(int i = 0; i < nc; i++)
      if((1<<i) & paradas)
	r++;
    return r;
  }

  if(paradas & 1){
    r++;
    paradas ^= 1;
  }

  int melhor = (1<<30);
  for(int i = 0; i < n; i++){
    if(!((1<<i)&faltam)) continue;
    int np = novas_paradas(paradas, i);
    int t = vai(faltam ^ (1<<i), np);
    if(t < melhor){
      melhor = t;
      prox = make_pair(i, np);
    }
  }
  r += melhor;
  return r;
}


vector <int> BuffetLine::order(string food, vector <string> cravings)
{
  istringstream iss (food);
  string s;
  comida.clear();
  nc = 0;
  while(iss >> s)
    comida[s] = nc++;

  n = cravings.size();
  desejos = vector<int> (n, 0);
  for(int i = 0; i < n; i++){
    istringstream iss2 (cravings[i]);
    while(iss2 >> s)
      desejos[i] |= (1 << comida[s]);
  }

  memset(memo, -1, sizeof(memo));

  vai((1<<n)-1, 0);

  vector<int> resp;
  int falta = (1<<n) - 1;
  pair<int, int> at = make_pair(n+1, 0);
  for(int i = 0; i < n; i++){
    at = proximo[falta][at.second];
    falta ^= (1 << at.first);
    resp.push_back(at.first);
  }

  return resp;
}
