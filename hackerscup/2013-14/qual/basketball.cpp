#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <list>

using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define forit(it, S) for(typeof((S).begin()) it = (S).begin(); it != (S).end(); (it)++)

struct jogador{
  string nome;
  int shot_perc;
  int height;
  int play_time;
  bool operator<(const jogador &outro) const{
    if(play_time != outro.play_time)
      return (play_time < outro.play_time);
    if(shot_perc != outro.shot_perc)
      return (shot_perc > outro.shot_perc);
    if(height != outro.height)
      return (height > outro.height);
  }
};

int N, M, P;

void insert_sorted(jogador novo, list<jogador> &S)
{
  forit(it, S){
    if(novo < *it){
      S.insert(it, novo);
      return;
    }
  }
  S.push_back(novo);
}

void transfer_last(list<jogador> &orig, list<jogador> &dest)
{
  list<jogador>::iterator it = orig.end();
  it--;
  insert_sorted(*it, dest);
  orig.erase(it);
}

void transfer_first(list<jogador> &orig, list<jogador> &dest)
{
  list<jogador>::iterator it = orig.begin();
  insert_sorted(*it, dest);
  orig.erase(it);
}

void solve()
{
  scanf(" %d %d %d", &N, &M, &P);

  vector<jogador> todos (N);
  for(int i = 0; i < N; i++){
    cin >> todos[i].nome >> todos[i].shot_perc >> todos[i].height;
    todos[i].play_time = 0;
  }
  sort(todos.begin(), todos.end());

  list<jogador> j1, j2, b1, b2;
  for(int i = 0; i < 2*P; i += 2)
    j1.push_back(todos[i]);
  for(int i = 1; i < 2*P; i += 2)
    j2.push_back(todos[i]);
  for(int i = 2*P; i < N; i+= 2)
    b1.push_back(todos[i]);
  for(int i = 2*P+1; i < N; i+= 2)
    b2.push_back(todos[i]);


  for(int t = 1; t <= M; t++){
    forit(it, j1){
      (*it).play_time += 1;
    }
    forit(it, j2){
      (*it).play_time += 1;
    }

    transfer_last(j1, b1);
    transfer_last(j2, b2);

    transfer_first(b1, j1);
    transfer_first(b2, j2);
  }


  vector<string> final;
  forit(it, j1){
    final.push_back(it->nome);
  }
  forit(it, j2){
    final.push_back(it->nome);
  }
  sort(final.begin(), final.end());
  forit(it, final){
    cout << " " << *it;
  }
  cout << endl;
}

int main()
{
  int cases;
  scanf(" %d", &cases);
  for(int h = 1; h <= cases; h++){
    printf("Case #%d:", h);
    solve();
  }
  return 0;
}
