#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

const int MAX = 10000;

struct bignum {
  int d[MAX], nd;
  bignum() { memset(d, 0, sizeof d); nd = 1; }
  bignum(int n) {
    memset(d,0,sizeof d);
    for (nd = 0; n;) { d[nd++] = n % 10; n /= 10; }
    if (nd == 0) nd = 1;
  }
  bignum operator+(const int& n) {
    bignum ret;
    ret.nd = nd;
    ret.d[0] += n;
    for (int i = 0; i < nd; ++i) {
      ret.d[i] += d[i];
      ret.d[i+1] += ret.d[i] / 10;
      ret.d[i] %= 10;
    }
    while (ret.d[ret.nd]>0) {
      ret.d[ret.nd+1] += ret.d[ret.nd] / 10;
      ret.d[ret.nd] %= 10;
      ret.nd++;
    }
    return ret;
  }
  bignum operator+(const bignum& n) {
    bignum ret;
    ret.nd = max(nd, n.nd);
    for (int i = 0; i < ret.nd; ++i) {
      ret.d[i] += d[i] + n.d[i];
      ret.d[i+1] += ret.d[i] / 10;
      ret.d[i] %= 10;
    }
    while (ret.d[ret.nd]>0) {
      ret.d[ret.nd+1] += ret.d[ret.nd] / 10;
      ret.d[ret.nd] %= 10;
      ret.nd++;
    }
    return ret;
  }
  bignum operator*(const int n) {
    bignum ret;
    ret.nd = nd;
    for (int i = 0; i < nd; ++i)
      ret.d[i] = d[i] * n;
    for(int i = 0; i < nd; i++){
      ret.d[i+1] += ret.d[i] / 10;
      ret.d[i] %= 10;
    }
    while (ret.d[ret.nd] > 0) {
      ret.d[ret.nd+1] += ret.d[ret.nd] / 10;
      ret.d[ret.nd] %= 10;
      ret.nd++;
    }
    return ret;
  }
  void print() {
    for (int i = nd-1; i >= 0; --i) {
      printf("%d", d[i]);
    }
    puts("");
  }
};

int val[300];
char buffer[MAX];

int le(char *s) {
  int n = 0;
  while(1){
    char c = getchar();
    if(c == EOF || c == '\n'){
      s[n] = '\0';
      if(c == '\n')
	return n;
      return (n == 0 ? -1 : n);
    }
    if(!isspace(c))
      s[n++] = c;
  }
}


int main()
{

  bool primeiro = true;
  while(1){
    int base_maior = le(buffer);
    if(base_maior == -1) break;
    if(base_maior == 0) continue;
    for(int i = 0; i < base_maior; i++)
      val[buffer[i]] = i;
    if(!primeiro) printf("\n");
    primeiro = false;

    while(1){
      int n = le(buffer);

      if(n <= 0) break;
      int b = 1;
      for(int i = 0; i < n; i++) 
	b = max(b, val[buffer[i]]);
      b++;

      bignum resp;
      for(; b <= base_maior; b++){
	bignum at;
	for(int i = 0; i < n; i++){
	  at = at*b;
	  at = at + val[buffer[i]];
	}
	resp = resp + at;
      }
      resp.print();
    }
  }
  return 0;
}
