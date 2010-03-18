#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <sstream>

using namespace std;

char buf[500];
char buf2[500];

map<string, string> dic;

int main()
{
  gets(buf);
  int casos;
  sscanf(buf, " %d", &casos);
  while(casos--){
    int m, n;
    gets(buf);
    sscanf(buf, " %d %d", &m, &n);
    
    dic.clear();

    while(m--){
      gets(buf);
      gets(buf2);
      dic[buf] = buf2;
    }

    while(n--){
      gets(buf);
      istringstream iss(buf);
      string s;
      bool pri = true;
      while(iss >> s){
	if(!pri) printf(" ");
	pri = false;
	if(dic.find(s) == dic.end())
	  printf("%s",s.c_str());
	else
	  printf("%s",dic[s].c_str());
      }
      puts("");
    }
    puts("");
  }
  return 0;
}

