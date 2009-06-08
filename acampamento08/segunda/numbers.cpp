#include<cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int paraDec(string s, int r){
  int n = s.size();
  reverse(s.begin(), s.end());
  int ret = 0;
  int p = 1;
  for(int i = 0; i < n; i++){
    ret += (int)(s[i] - '0') * p;
    p *= -r;
  }
  return ret;
}

inline int mod(int n, int r){
  if(n >= 0)
    return n%r;
  n = (-n) % r;
  n = (r - n) % r;
  return n;
}


void paraR(int n, int r){
  if(n >= 0 && n < r){
    printf("%d", n);
    return;
  }
  int d = mod(n, r);
  paraR(- (n - d) / r, r);
  printf("%d", d);
}

int main()
{
  char buf[20];
  int r, n;
  
  while(1){
    scanf(" %s", buf);
    if(buf[0] == 'e')
      break;
    if(buf[0] == 'f'){
      sscanf(buf, "from-%d", &r);
      scanf(" %s", buf);
      printf("%d\n", paraDec(buf, r));
    }
    else{
      sscanf(buf, "to-%d", &r);
      scanf(" %d", &n);
      paraR(n, r);
      printf("\n");
    }
  }
  
  return 0;
}
