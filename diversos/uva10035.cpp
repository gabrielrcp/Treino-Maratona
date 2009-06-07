#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
  long long x, y;
  string a, b;
  stringstream ss;

  while(1){
    cin >> a >> b;
    if(a == b && b == "0")
      break;

    ss.clear();
    sscanf(a.c_str(), "%lld", &x);
    ss >> x;
    ss << a;

    ss.clear();
    sscanf(b.c_str(), "%lld", &x);
    ss >> x;
    ss << b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while(a.size() < b.size())
      a += "0";
    while(a.size() > b.size())
      b += "0";
    int n = a.size();

    int conta = 0;
    int r = 0, i;
    for(i = 0; i < n; i++){
      r += a[i] - '0' + b[i] - '0';
      if(r >= 10)
	conta++;
      r /= 10;
    }

    if(conta == 0)
      printf("No carry operation.\n");
    else if(conta == 1)
      printf("%d carry operation.\n", conta);
    else
      printf("%d carry operations.\n", conta);
  }
  return 0;
}
