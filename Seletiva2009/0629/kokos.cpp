#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int n, k;
vector<string> palavras;
char buf[500];


vector< vector<int> > separa(vector<int> &at, int p)
{
  vector< vector<int> > resp;
  vector< vector<int> > letras (26);
  for(int i = 0; i < at.size(); i++)
    letras[palavras[at[i]][p]-'A'].push_back(at[i]);
  for(int i = 0; i < 26; i++)
    if(letras[i].size() != 0)
      resp.push_back(letras[i]);
  return resp;
}





int main()
{
  scanf(" %d %d", &n, &k);

  for(int i = 0; i < n; i++){
    scanf(" %s", buf);
    palavras.push_back(buf);
  }
  vector<int> ini;
  for(int i = 0; i < n; i++)
    ini.push_back(i);

  vector< vector<int> > grupos, temp, temp2
  grupos = separa(ini, 0);
  int r = grupos.size();
  for(int i = 1; i < k; i++){
    temp2.clear();
    for(int j = 0; j < grupos.size(); j++){
      temp = separa(grupos[j], i);
      for(int l = 0; l < temp.size(); l++)
	temp2.push_back(temp[l]);
    }
    grupos = temp2;
    r += grupos.size();
  }



  return 0;
}
