#include <cstdio>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int N;
string dic[10010];

pair<int, int> v[10010];
int pontos[10010];

string L;

void calcula(int a, int b, int l, int at)
{

  if(b == a+1){
    pontos[v[a].second] = at;
    return;
  }

  char c = L[l];
  for(int i = a; i < b; i++){
    int k = v[i].second;
    int msk = 0;
    for(int j = 0; j < (int)dic[k].size(); j++){
      if(dic[k][j] == c)
	msk |= (1 << j);
    }
    v[i].first = msk;
  }

  sort(v+a, v+b);
  if(v[a].first == v[b-1].first){
    calcula(a, b, l+1, at);
  } else{
    int i = a;
    while(i < b){
      int j = i + 1;
      while(j < b && v[j].first == v[i].first) j++;
      int p = ((v[i].first == 0) ? 1 : 0);
      calcula(i, j, l+1, at+p);
      i = j;
    }
  }
}

string vai()
{

  for(int i = 0; i < N; i++)
    v[i] = make_pair(dic[i].size(), i);

  sort(v, v+N);

  int i = 0;
  while(i < N){
    int j = i + 1;
    while(j < N && v[j].first == v[i].first) j++;
    calcula(i, j, 0, 0);
    i = j;
  }

  int r = 0;
  for(i = 1; i < N; i++){
    if(pontos[i] > pontos[r]){
      r = i;
    }
  }
  return dic[r];   
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int m;
    scanf(" %d %d", &N, &m);
    for(int i = 0; i < N; i++)
      cin >> dic[i];

    printf("Case #%d:", h);
    while(m--){
      cin >> L;
      cout << " " << vai();
    }
    cout << endl;
  }
  return 0;
}
