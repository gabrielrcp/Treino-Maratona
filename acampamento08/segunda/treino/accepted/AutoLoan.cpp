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

// Classe e Testes - AutoLoan {{{
class AutoLoan
{
public: 
double interestRate(double price, double monthlyPayment, int loanTerm); 

// BEGIN CUT HERE
#ifndef TEST
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arg0 = 6800; double Arg1 = 100; int Arg2 = 68; double Arg3 = 1.3322616182218813E-13; verify_case(0, Arg3, interestRate(Arg0, Arg1, Arg2)); }
	void test_case_1() { double Arg0 = 2000; double Arg1 = 510; int Arg2 = 4; double Arg3 = 9.56205462458368; verify_case(1, Arg3, interestRate(Arg0, Arg1, Arg2)); }
	void test_case_2() { double Arg0 = 15000; double Arg1 = 364; int Arg2 = 48; double Arg3 = 7.687856394581649; verify_case(2, Arg3, interestRate(Arg0, Arg1, Arg2)); }
#endif
// END CUT HERE
}; 
// }}}

double vai(double preco, double taxa, int meses, double pagamento)
{
	for(int i = 0; i< meses; i++)
	{
	    preco = preco - pagamento + preco * taxa;
	}
	return preco;
}


double AutoLoan::interestRate(double price, double monthlyPayment, int loanTerm) 
{

	double esq = 0.0, dir = 1.0;

	for(int i = 0; i<100; i++)
	{
		double taxa = (esq+dir) * 0.5;
		double divida = vai(price, taxa, loanTerm, monthlyPayment);
		if(divida <= 0.0)
			esq = taxa;
		else
			dir = taxa;
	}

	return esq * 1200.0;

}

// Fun‹o main {{{
// BEGIN CUT HERE 
#ifndef TEST
int main()
{
	AutoLoan ___test; 
	___test.run_test(-1); 
} 
#endif
// END CUT HERE
// }}}
