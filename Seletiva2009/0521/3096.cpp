#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

char pal[100];
int n;

bool separado(int k)
{
  set< pair<char, char> > S;
  for(int i = 0; i+k < n; i++){
    pair<char, char> P = make_pair(pal[i], pal[i+k]);
    if(S.find(P) != S.end())
      return false;
    S.insert(P);
  }
  return true;
}


bool surpresa()
{
  for(int k = 1; k < n; k++)
    if(!separado(k))
      return false;
  return true;
}

int main()
{
  while(1){
    if(feof(stdin)) break;
    if(scanf(" %s", pal) != 1)
      break;
    if(pal[0] == '*')
      break;
    n = strlen(pal);

    printf("%s", pal);
    if(surpresa())
      printf(" is surprising.\n");
    else
      printf(" is NOT surprising.\n");
  }
  return 0;
}
