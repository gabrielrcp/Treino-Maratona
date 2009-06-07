#include <cstdio>
#include <vector>

using namespace std;

vector< pair<int, int> > resp;


void resolve(long long n)
{
  resp.clear();
  int s = 0;
  while(n > 0){
    while(!(n&1)){
      n = n >> 1;
      s++;
    }
    long long pot = 1;
    int i = 0;
    while(3LL*pot <= n){
      pot *= 3LL;
      i++;
    }
    n -= pot;
    resp.push_back(make_pair(s, i));
  }
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int n;
    scanf( "%d", &n);

    resolve(n);
    printf("%d %d", h, resp.size());
    for(int i = 0; i < resp.size(); i++)
      printf(" [%d,%d]", resp[i].first, resp[i].second);
    printf("\n");
  }
  return 0;
}
