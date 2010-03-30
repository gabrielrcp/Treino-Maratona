#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

char buf[1010];
string pal[100010];
int ordem[256];
int n;

bool compara(const string &a, const string &b)
{
  int l = min(a.size(), b.size());
  for(int i = 0; i < l; i++)
    if(a[i] != b[i])
      return ordem[a[i]] < ordem[b[i]];
  return (a.size() < b.size());
}

int main()
{
  int casos;
  scanf(" %d\n", &casos);
  while(casos--){
    scanf(" %s %d", buf, &n);
    for(int i = 0; buf[i]; i++)
      ordem[buf[i]] = i;
    for(int i = 0; i < n; i++){
      scanf(" %s", buf);
      pal[i] = buf;
    }

    sort(pal, pal+n, compara);
    for(int i = 0; i < n; i++)
      printf("%s\n", pal[i].c_str());
    puts("");
      
  }
  return 0;
}


