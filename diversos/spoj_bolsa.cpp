#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int ler()
{
  int a, b;
  scanf(" %d.%d", &a, &b);
  return 100*a+b;
}

int main()
{
  int n;
  while(scanf(" %d", &n) && n){
    priority_queue<int> C;
    priority_queue<int, vector<int>, greater<int> > V;
    int resp = 0;

    while(n--){
      char c;
      scanf(" %c", &c);
      int x = ler();
      if(c == 'C'){
	if(V.empty() || V.top() > x)
	  C.push(x);
	else{
	  resp += x - V.top();
	  V.pop();
	}
      }else{
	if(C.empty() || C.top() < x)
	  V.push(x);
	else{
	  resp += C.top() - x;
	  C.pop();
	}
      }
    }
    
    printf("%d.%02d\n", resp/100, resp%100);
  }
}
