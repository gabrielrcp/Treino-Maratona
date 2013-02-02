#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int casos;
  scanf(" %d", &casos);

  while(casos--){
    int n;
    scanf(" %d", &n);
    vector<string> v (n);
    string resp = "";
    for(int i = 0; i < n; i++)
      cin >> v[i];
    sort(v.begin(), v.end());
    do{
      string s = "";
      for(int i = 0; i < n; i++)
	s += v[i];
      if(resp == "" || resp > s)
	resp = s;
    } while(next_permutation(v.begin(), v.end()));
    cout << resp << endl;
  }
  return 0;
}
