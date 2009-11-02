#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 65000

pair<int, int> v[MAX];
int n;
int s[MAX];

int main()
{
  while(scanf(" %d", &n) && n > 0){
    for(int i = 0; i < n; i++){
      int h, m, s;
      char c;
      scanf(" %d:%d:%d %c", &h, &m, &s, &c);
      v[i].first = s + 60*m + 60*60*h;
      v[i].second = 0;
      if(c != '?')
	v[i].second = ((c == 'E') ? 1 : -1);
    }
    sort(v, v+n);

    s[n] = 0;
    for(int i = n-1; i >= 0; i--)
      s[i] = s[i+1] + (v[i].second == 1 ? -1 : 1);
    
    int resp = 0, at = 0;
    for(int i = 0; i < n; i++){
      switch(v[i].second){
      case 1:
	at++;
	resp = max(resp, at);
	break;
      case -1:
	at--;
	break;
      default:
	if(s[i+1] > at){
	  at++;
	  resp = max(resp, at);
	}
	else{
	  at--;
	}
      }
    }

    printf("%d\n", resp);
  }
  return 0;
}
