// Includes {{{
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <stdio.h>
using namespace std;
// }}}

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf (x))
#define WATCH(x) TRACE(cout << #x << ": " << x << endl)
//#define DEBUG

// Classe e Testes - Touchdown {{{
class Touchdown
{
public: 
int howMany(int yardsToGo, vector <int> plays); 
#ifndef TEST


#endif 
}; 
// }}}

const int INF            = (1 << 30);
const int MAX_TEMPO      = 110;
const int MAX_TENTATIVAS = 5;

#define BIT(x) (1 << x) 
#define ON(x,y) ((x & BIT(y)) != 0)

vector <int> v;
int Y, N, 
    memo[(1 << 16)];

int andou (int usados) {
   int ret = 0, i;

   for (i = 0; i < N; i++)
      if (ON (usados, i) != 0)
         ret += v[i];

   return ret;
}

bool ok (int P) {
   return (Y <= P && P <= Y + 10);
}

int f (int usados) {

   int P = andou (usados), j1, j2, j3, j4;

   if (ok (P))
      return memo[usados] = 0;
   
   if (P > Y + 10)
      return memo[usados] = INF;

   int i, ret = INF, S;

   if (memo[usados] != -1)
      return memo[usados];

   for (j1 = 0; j1 < N; j1++) {
      if (ON (usados, j1)) continue;

      S = v[j1];
      if (S >= 10 || ok (S + P))
         ret = min (ret, 1 + f (usados | BIT (j1)));

      for (j2 = j1 + 1; j2 < N; j2++) {
         if (ON (usados, j2)) continue;

         S = v[j1] + v[j2];
         if (S >= 10 || ok (S + P))
            ret = min (ret, 2 + f (usados | BIT (j1) | BIT (j2)));

         for (j3 = j2 + 1; j3 < N; j3++) {
            if (ON (usados, j3)) continue;

            S = v[j1] + v[j2] + v[j3];
            if (S >= 10 || ok (S + P))
               ret = min (ret, 3 + f (usados | BIT (j1) | BIT (j2) | BIT (j3)));

            for (j4 = j3 + 1; j4 < N; j4++) {
               if (ON (usados, j4)) continue;

               S = v[j1] + v[j2] + v[j3] + v[j4];
               if (S >= 10 || ok (S + P))
                  ret = min (ret, 4 + f (usados | BIT (j1) | BIT (j2) | BIT (j3) | BIT (j4)));
            }
         }
      }
   }
   
   return memo[usados] = ret;
}

int Touchdown::howMany(int yardsToGo, vector <int> plays) 
{
   Y = yardsToGo;
   v = plays;
   N = plays.size ();

   memset (memo, -1, sizeof (memo));

   int ret = f (0);

   return ret == INF ? -1 : ret;
}

// Função main {{{
// }}}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
