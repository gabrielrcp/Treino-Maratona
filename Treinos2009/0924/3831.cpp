#include <set>
#include <cstdio>

using namespace std;


int main()
{
  
  int c;
  set< pair<int, int> > clientes;
  set< pair<int, int> >::iterator it;
  while(1){
    scanf(" %d", &c);
    if(c == 0) break;
    switch(c){
    case 1:
      int k, p;
      scanf(" %d %d", &k, &p);
      clientes.insert(make_pair(p, k));
      break;
    case 2:
      if(!clientes.empty()){
	it = clientes.end(); it--;
	printf("%d\n", it->second);
	clientes.erase(it);
      }
      else
	printf("0\n");
      break;
    case 3:
      if(!clientes.empty()){
	it = clientes.begin();
	printf("%d\n", it->second);
	clientes.erase(it);
      }
      else
	printf("0\n");
      break;
    }
  }
  return 0;
}
