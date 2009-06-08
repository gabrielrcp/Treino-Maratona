#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define MAX 200


int main()
{

  int N;

  scanf(" %d", &N);

  set<int> S;
  for (int i = 0; i < N; i++){
    int x;
    scanf(" %d", &x);
    S.insert(x);
  }
  
  vector<int> v = vector<int> (S.begin(), S.end());
  N = v.size();
  vector<int> w;

  for (int i = 0; i < N; i++)
    {
      int j;
      for (j = i + 1; j < N; j++)
	{
	  if (v[j] % v[i] == 0)
	    break;
	}
      if (j == N)
	w.push_back(v[i]);
    }

  printf("%d\n%d", w.size(), w[0]);
  for (int i = 1; i < (int)w.size(); i++)
    printf(" %d", w[i]);
  printf("\n");
    
  return 0;
}
