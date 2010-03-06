#include <cstdio>
#include <cstring>
#include <string>


using namespace std;

char buf[200];

bool ehvogal(char c)
{
  switch(c){
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return true;
  default:
    return false;
  }
}

string ler()
{
  scanf("%[^\n]\n", buf);
  for(int i = 0; buf[i]; i++){
    if('A' <= buf[i] && buf[i] <= 'Z')
      buf[i] -= 'A' - 'a';
  }

  int i = 0;
  for(int j = strlen(buf)-1; j >= 0; j--){
    if(ehvogal(buf[j])){
      i = j;
      break;
    } else if(buf[j] == ' '){
      i = j+1;
      break;
    }
  }
  return buf+i;
}

string rima[4];

string vai()
{
  if(rima[0] == rima[1] && rima[1] == rima[2] && rima[2] == rima[3])
    return "perfect";
  if(rima[0] == rima[1] && rima[2] == rima[3])
    return "even";
  if(rima[0] == rima[2] && rima[1] == rima[3])
    return "cross";
  if(rima[0] == rima[3] && rima[1] == rima[2])
    return "shell";
  return "free";
}

int main()
{
  int n;
  scanf("%d\n", &n);

  while(n--){
    for(int i = 0; i < 4; i++){
      rima[i] = ler();
      //printf("--%s--\n", rima[i].c_str());
    }

    printf("%s\n", vai().c_str());
  }
  return 0;
}
