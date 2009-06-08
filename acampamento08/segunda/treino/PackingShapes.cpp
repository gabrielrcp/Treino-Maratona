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

//Classe e Testes - PackingShapes {{{
class           PackingShapes
{
	public:
		vector < string > tryToFit(int width, int height, vector < string > shapes);

		//BEGIN CUT HERE
	public:
		void            run_test(int Case) {
			if ((Case == -1) || (Case == 0))
				test_case_0();
			if ((Case == -1) || (Case == 1))
				test_case_1();
			if ((Case == -1) || (Case == 2))
				test_case_2();
			if ((Case == -1) || (Case == 3))
				test_case_3();
		}
	private:
		template < typename T > string print_array(const vector < T > &V) {
			ostringstream   os;
			os << "{ ";
			for (typename vector < T >::const_iterator iter = V.begin(); iter != V.end(); ++iter)
				os << '\"' << *iter << "\",";
			os << " }";
			return os.str();
		}
		void            verify_case(int Case, const vector < string > &Expected, const vector < string > &Received) {
			cerr << "Test Case #" << Case << "...";
			if (Expected == Received)
				cerr << "PASSED" << endl;
			else {
				cerr << "FAILED" << endl;
				cerr << "\tExpected: " << print_array(Expected) << endl;
				cerr << "\tReceived: " << print_array(Received) << endl;
			}
		}
		void            test_case_0() {
			int             Arg0 = 100;
			int             Arg1 = 100;
			string          Arr2[] = {"RECTANGLE 3 3",
				"RECTANGLE 3 230",
				"RECTANGLE 140 1"};
			vector < string > Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			string          Arr3[] = {"YES", "NO", "YES"};
			vector < string > Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(0, Arg3, tryToFit(Arg0, Arg1, Arg2));
		}
		void            test_case_1() {
			int             Arg0 = 100;
			int             Arg1 = 100;
			string          Arr2[] = {"RECTANGLE 100 100",
				"CIRCLE 50"};
			vector < string > Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			string          Arr3[] = {"YES", "YES"};
			vector < string > Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(1, Arg3, tryToFit(Arg0, Arg1, Arg2));
		}
		void            test_case_2() {
			int             Arg0 = 10;
			int             Arg1 = 100;
			string          Arr2[] = {"RECTANGLE 99 9",
				"CIRCLE 22"};
			vector < string > Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			string          Arr3[] = {"YES", "NO"};
			vector < string > Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(2, Arg3, tryToFit(Arg0, Arg1, Arg2));
		}
		void            test_case_3() {
			int             Arg0 = 170;
			int             Arg1 = 900;
			string          Arr2[] = {"RECTANGLE 200 700",
				"RECTANGLE 3 910",
				"RECTANGLE 1000 7",
				"CIRCLE 5",
				"CIRCLE 50",
				"CIRCLE 500",
				"RECTANGLE 1000 99"};
			vector < string > Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			string          Arr3[] = {"NO", "YES", "NO", "YES", "YES", "NO", "NO"};
			vector < string > Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(3, Arg3, tryToFit(Arg0, Arg1, Arg2));
		}

		//END CUT HERE

};
// }}}

vector < string > PackingShapes::tryToFit(int width, int height, vector < string > shapes)
{
}

//Fun ç ão main {{{
//BEGIN CUT HERE
int             main() {
	PackingShapes   ___test;
	___test.run_test(-1);
}
//END CUT HERE
//}}}
