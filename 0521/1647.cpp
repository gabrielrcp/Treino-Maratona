#include <cstdio>
#include <string>

using namespace std;

bool proib[10][10];

pair<int, int> ler()
{
  char buf[10];
  scanf(" %s", buf);
  return make_pair(buf[0]-'a'+1, buf[1]-'1'+1);
}

pair<int, int> wk, bk;

inline bool ataca(pair<int, int> a, pair<int, int> b)
{


  if(a.first == b.first){
    int x = a.first;
    int y1 = min(a.second, b.second);
    int y2 = max(a.second, b.second);
    return (!(wk.first == x && y1 <= wk.second && wk.second <= y2));
  }

  if(a.second == b.second){
    int x = a.second;
    int y1 = min(a.first, b.first);
    int y2 = max(a.first, b.first);
    return (!(wk.second == x && y1 <= wk.first && wk.first <= y1));

  }

  if(a.first + a.second == b.first + b.second){
    int x = a.first + a.second;
    int y1 = min(a.first - a.second, b.first - b.second);
    int y2 = max(a.first - a.second, b.first - b.second);
    return (!(x == wk.first+wk.second && y1 <= wk.first-wk.second && wk.first-wk.second <= y2));
  }

  if(a.first - a.second == b.first - b.second){
    int x = a.first - a.second;
    int y1 = min(a.first + a.second, b.first + b.second);
    int y2 = max(a.first + a.second, b.first + b.second);
    return (!(x == wk.first-wk.second && y1 <= wk.first+wk.second && wk.first+wk.second <= y2));
  }

  return false;
}


bool confere(pair<int, int > wq)
{
  if(!ataca(wq, bk))
    return false;

  if(abs(wq.first - bk.first) <= 1 && abs(wq.second - bk.second) <= 1)
    if(!proib[wq.first][wq.second])
      return false;
  for(int i = bk.first-1; i <= bk.first+1; i++)
    for(int j = bk.second-1; j <= bk.second+1; j++){
      if(proib[i][j] == false && ataca(wq, make_pair(i, j)) == false)
	return false;
    }
  return true;
}

string resolve(pair<int, int > wq)
{
  char buf[10];
  pair<int, int> P;
  for(int i = 1; i <= 8; i++)
    for(int j = 1; j <= 8; j++){
      P = make_pair(i, j);
      if(ataca(wq, P) && confere(P)){
	sprintf(buf, "%c%c", i-1+'a', j-1+'1');
	return buf;
      }
    }

  return "no";
}

int main()
{
  pair<int, int> wq;

  wk = ler();
  wq = ler();
  bk = ler();

  for(int i = 1; i <= 8; i++)
    for(int j = 1; j <= 8; j++)
      proib[i][j] = false;

  for(int i = 0; i < 10; i++)
    proib[i][0] = proib[i][9] = proib[0][i] = proib[9][i] = true;

  for(int i = wk.first - 1; i <= wk.first+1; i++)
    for(int j = wk.second-1; j <= wk.second+1; j++)
      proib[i][j] = true;


  string r = resolve(wq);
  printf("%s\n", r.c_str());

  return 0;
}
