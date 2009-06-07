#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<string> nomes;
int n, k;

int main()
{
  char buf[25];
  for(int h = 1; ; h++){
    scanf(" %d %d", &n, &k);
    if(n == k && k == 0)
      break;
    

    nomes.clear();
    for(int i = 0; i < n; i++){
      scanf(" %s", buf);
      nomes.push_back(buf);
    }

    for(int j = 0; j < n && k > 0; j++){
      int min = j;
      for(int i = j + 1; i <= j + k && i < n; i++)
	if(nomes[i] < nomes[min])
	  min = i;
      for(int i = min; i > j; i--){
	/*
	string t = nomes[i];
	nomes[i] = nomes[i-1];
	nomes[i-1] = t;
	*/
	swap(nomes[i], nomes[i-1]);
	k--;
      }
    }

    printf("Instancia %d\n", h);
    //printf("%s", nomes[0].c_str());
    for(int i = 0; i < n; i++)
      printf("%s ", nomes[i].c_str());
    printf("\n\n");

  }

  
  return 0;
}
