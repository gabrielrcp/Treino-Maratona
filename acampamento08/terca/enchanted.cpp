
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 101
/*
int main()
{
  char str[4][MAX];
  int v[2][MAX];
  int n;
  int i;
  int res;

  while(scanf(" %s %s %s %s", str[0], str[1], str[2], str[3]) == 4)
    {
      n = strlen(str[0]);
      for (i = 0; i < n; i++)
	{
   
	  str[0][i] -= 'A';
	  str[1][i] -= 'A';
	  str[2][i] -= 'A';
	  str[3][i] -= 'A';
	  v[0][i] = 100*(int)str[0][i] + (int)str[1][n - 1 - i];
	  v[1][i] = 100*(int)str[2][i] + (int)str[3][n - 1 - i];
	}
      sort(v[0], v[0] + n);
      sort(v[1], v[1] + n);

      res = 1;
      for (i = 0; i < n; i++)
	if (v[0][i] != v[1][i])
	  {
	    res = 0;
	    break;
  }
      if (res == 1)
	printf("Yes\n");
      else
	printf("No\n");
    }
}

*/

int main()
{
  char str[4][MAX];
  vector< pair<char, char> > v, w;
  int n;
  int i;
 
  while(scanf(" %s %s %s %s", str[0], str[1], str[2], str[3]) == 4)
    {
      n = strlen(str[0]);
      v.clear();
      w.clear();

      for (i = 0; i < n; i++){
	v.push_back(make_pair(str[0][i], str[1][n - 1 - i]));
	w.push_back(make_pair(str[2][i], str[3][n - 1 - i]));
      }
      
      sort(v.begin(), v.end());
      sort(w.begin(), w.end());

      int res = 1;
      for (i = 0; i < n; i++){
	if (v[i] != w[i])
	  {
	    res = 0;
	    break;
	  }
      }
      if (res == 1)
	printf("Yes\n");
      else
	printf("No\n");
    }
}
