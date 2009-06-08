#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
#define MAX_K 5000

typedef struct node
{
	int val;
	struct node *ant, *suc;
}No;

class FloatingMedian {

	int prox;
	int numeros[MAX_K];

	No *lista;

	inline int geraproximo()
	{
		return (int) (( ((long)prox * mul + add) ) % 65536);
	}

	int achamediana()
	{

	}

	void insere()
	{
	}

	public: long long sumOfMedians(int _seed, int _mul, int _add, int _N, int _K) {
			long long soma = 0;

			K = _K;
			numeros[0] = prox = seed;

			for(int i=1; i<K; i++)
				numeros[i] = geraproximo();

			for(i=0; i<K; i++)
				insere(numeros(i));

			for(atual=0; atual<N-K; atual++)//laco principal:para cada intervalo
			{

			}

			
			
			return soma;
	}

};
