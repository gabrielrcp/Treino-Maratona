#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 1010

struct Time{
  int cod;
  int numprob;
  int tempo;
  int tentativas[20];
  bool operator <(const Time &outro) const{
    if(numprob == outro.numprob){
      if(tempo == outro.tempo)
	return cod < outro.cod;
      return tempo < outro.tempo;
    }
    return numprob > outro.numprob;
  }
};

struct submis{
  int cod, ti, p, t, r;
  bool operator <(const submis &outro) const{
    if(t == outro.t)
      return cod < outro.cod;
    return t < outro.t;
  }
};

int c, n;
Time equip[MAX];
submis submissoes[MAX];

int main()
{
  scanf("%d %d", &c, &n);
  for(int i = 0; i < c; i++){
    equip[i].cod = i;
    equip[i].numprob = 0;
    equip[i].tempo = 0;
    for(int j = 0; j < 20; j++)
      equip[i].tentativas[j] = 0;
  }

  for(int k = 0; k < n; k++){
    submissoes[k].cod = k;
    scanf("%d %d %d %d", &submissoes[k].ti, &submissoes[k].p,
	  &submissoes[k].t, &submissoes[k].r);
  }

  sort(submissoes, submissoes+n);
  /*
  for(int i = 0; i < n; i++){
    int ti, p, t, r;
    ti = submissoes[i].ti;
    p  = submissoes[i].p;
    t  = submissoes[i].t;
    r  = submissoes[i].r;
    ti--; p--;

    printf("%d %d %d %d\n", ti, p, t, r);
  }
  */
  for(int i = 0; i < n; i++){
    int ti, p, t, r;
    ti = submissoes[i].ti;
    p  = submissoes[i].p;
    t  = submissoes[i].t;
    r  = submissoes[i].r;
    ti--; p--;

    if(equip[ti].tentativas[p] == -1) continue;
    if(r == 1){
      equip[ti].numprob++;
      equip[ti].tempo += equip[ti].tentativas[p] + t;
      equip[ti].tentativas[p] = -1;
    }
    else
      equip[ti].tentativas[p] += 1200;
  }
  /*
  for(int i = 0; i < c; i++)
    printf("%d %d\n", equip[i].numprob, equip[i].tempo);
  */
  sort(equip, equip+c);
  
  printf("%d", equip[0].cod+1);
  for(int i = 1; i < c; i++)
    printf(" %d", equip[i].cod+1);
  printf("\n");

}
