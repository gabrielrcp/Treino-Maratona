#define TEST

#include "Flags.cpp"
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
#include <time.h>
using namespace std;



class FlagsTest {

	public: static bool passed;
	
	    
    static void assertEquals(int testCase, const long long& expected, const long long& actual) {
        if (expected == actual) {
        	passed = true;
            cout << "Test case " << testCase << " PASSED!";
        } else {
        	passed = false;
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>';
        }
    }


    Flags solution;
    
    

void testCase0 () {
string var0 = "10";

string _var1[] = {"0","1 2","1 2"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 3LL;

assertEquals(0, ret, solution.numStripes(var0, var1));
}

void testCase1 () {
string var0 = "100";

string _var1[] = {"0","1","2"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 6LL;

assertEquals(1, ret, solution.numStripes(var0, var1));
}

void testCase2 () {
string var0 = "93";

string _var1[] = {"0","1","2"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 5LL;

assertEquals(2, ret, solution.numStripes(var0, var1));
}

void testCase3 () {
string var0 = "94";

string _var1[] = {"0","1","2"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 6LL;

assertEquals(3, ret, solution.numStripes(var0, var1));
}

void testCase4 () {
string var0 = "100000000000000000";

string _var1[] = {"0","1"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 50000000000000000LL;

assertEquals(4, ret, solution.numStripes(var0, var1));
}

void testCase5 () {
string var0 = "100000000000000000";

string _var1[] = {"0","1 2","1 2"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 108LL;

assertEquals(5, ret, solution.numStripes(var0, var1));
}

void testCase6 () {
string var0 = "10000000000000000";

string _var1[] = {"0 1","0 1","2 3 4","2 3 4","2 3 4"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 40LL;

assertEquals(6, ret, solution.numStripes(var0, var1));
}

void testCase7 () {
string var0 = "10000000000000000";

string _var1[] = {"0 5 6 7 8 9","1","2","3","4","0 5","0 6","0 7","0 8","0 9"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 18LL;

assertEquals(7, ret, solution.numStripes(var0, var1));
}

void testCase8 () {
string var0 = "10000000000000000";

string _var1[] = {"0 1 2 3 4 5 6 7 8 9","0 1 3 4 5 6 7 8 9","0 2 3 4 5 6 7 8 9","0 1 2 3 4 5 6 7 8 9","0 1 2 3 4 5 6 7 8 9","0 1 2 3 4 5 6 7 8 9","0 1 2 3 4 5 6 7 8 9","0 1 2 3 4 5 6 7 8 9","0 1 2 3 4 5 6 7 8 9","0 1 2 3 4 5 6 7 8 9"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 4999999999999996LL;

assertEquals(8, ret, solution.numStripes(var0, var1));
}

void testCase9 () {
string var0 = "14";

string _var1[] = {"0","1 2","1 2"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 4LL;

assertEquals(9, ret, solution.numStripes(var0, var1));
}

void testCase10 () {
string var0 = "13";

string _var1[] = {"0","1 2","1 2"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 3LL;

assertEquals(10, ret, solution.numStripes(var0, var1));
}

void testCase11 () {
string var0 = "21";

string _var1[] = {"0","1 2","1 2"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 4LL;

assertEquals(11, ret, solution.numStripes(var0, var1));
}

void testCase12 () {
string var0 = "22";

string _var1[] = {"0","1 2","1 2"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 5LL;

assertEquals(12, ret, solution.numStripes(var0, var1));
}

void testCase13 () {
string var0 = "41";

string _var1[] = {"0","1 2","1 2","3"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 4LL;

assertEquals(13, ret, solution.numStripes(var0, var1));
}

void testCase14 () {
string var0 = "40";

string _var1[] = {"0","1 2","1 2","3"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 3LL;

assertEquals(14, ret, solution.numStripes(var0, var1));
}

void testCase15 () {
string var0 = "5";

string _var1[] = {"0","1","2","3","4","5"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 1LL;

assertEquals(15, ret, solution.numStripes(var0, var1));
}

void testCase16 () {
string var0 = "3";

string _var1[] = {"0","1","2"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 1LL;

assertEquals(16, ret, solution.numStripes(var0, var1));
}

void testCase17 () {
string var0 = "4";

string _var1[] = {"0","1","2"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 2LL;

assertEquals(17, ret, solution.numStripes(var0, var1));
}

void testCase18 () {
string var0 = "7";

string _var1[] = {"0","1","2","3","4","5"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 2LL;

assertEquals(18, ret, solution.numStripes(var0, var1));
}

void testCase19 () {
string var0 = "6";

string _var1[] = {"0","1","2","3","4","5"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 1LL;

assertEquals(19, ret, solution.numStripes(var0, var1));
}

void testCase20 () {
string var0 = "10";

string _var1[] = {"0 1","0 1 2","1 2 3","2 3 4","3 4 5","4 5 6","5 6 7","6 7 8","7 8 9","8 9"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 1LL;

assertEquals(20, ret, solution.numStripes(var0, var1));
}

void testCase21 () {
string var0 = "11";

string _var1[] = {"0 1","0 1 2","1 2 3","2 3 4","3 4 5","4 5 6","5 6 7","6 7 8","7 8 9","8 9"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 2LL;

assertEquals(21, ret, solution.numStripes(var0, var1));
}

void testCase22 () {
string var0 = "82";

string _var1[] = {"0 1","0 1 2","1 2 3","2 3 4","3 4 5","4 5 6","5 6 7","6 7 8","7 8 9","8 9"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 2LL;

assertEquals(22, ret, solution.numStripes(var0, var1));
}

void testCase23 () {
string var0 = "83";

string _var1[] = {"0 1","0 1 2","1 2 3","2 3 4","3 4 5","4 5 6","5 6 7","6 7 8","7 8 9","8 9"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 3LL;

assertEquals(23, ret, solution.numStripes(var0, var1));
}

void testCase24 () {
string var0 = "100000000000000000";

string _var1[] = {"0 1","0 1 2","1 2 3","2 3 4","3 4 5","4 5 6","5 6 7","6 7 8","7 8 9","8 9"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 20LL;

assertEquals(24, ret, solution.numStripes(var0, var1));
}

void testCase25 () {
string var0 = "32899482551498534";

string _var1[] = {"0 1","0 1 2","1 2 3","2 3 4","3 4 5","4 5 6","5 6 7","6 7 8","7 8 9","8 9"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 19LL;

assertEquals(25, ret, solution.numStripes(var0, var1));
}

void testCase26 () {
string var0 = "32899482551498535";

string _var1[] = {"0 1","0 1 2","1 2 3","2 3 4","3 4 5","4 5 6","5 6 7","6 7 8","7 8 9","8 9"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 20LL;

assertEquals(26, ret, solution.numStripes(var0, var1));
}

void testCase27 () {
string var0 = "10000000000000000";

string _var1[] = {"0 2 3","1 2 3","0 1 2","0 1 3"};
vector <string> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 2500000000000000LL;

assertEquals(27, ret, solution.numStripes(var0, var1));
}
	
    public: void runTest(int testCase) {
		double tempo;
		clock_t Begin, End;
		   
		Begin = clock();    
		switch (testCase) {
			
		case(0): testCase0(); break;
		case(1): testCase1(); break;
		case(2): testCase2(); break;
		case(3): testCase3(); break;
		case(4): testCase4(); break;
		case(5): testCase5(); break;
		case(6): testCase6(); break;
		case(7): testCase7(); break;
		case(8): testCase8(); break;
		case(9): testCase9(); break;
		case(10): testCase10(); break;
		case(11): testCase11(); break;
		case(12): testCase12(); break;
		case(13): testCase13(); break;
		case(14): testCase14(); break;
		case(15): testCase15(); break;
		case(16): testCase16(); break;
		case(17): testCase17(); break;
		case(18): testCase18(); break;
		case(19): testCase19(); break;
		case(20): testCase20(); break;
		case(21): testCase21(); break;
		case(22): testCase22(); break;
		case(23): testCase23(); break;
		case(24): testCase24(); break;
		case(25): testCase25(); break;
		case(26): testCase26(); break;
		case(27): testCase27(); break;
			default: cerr << "No such test case: " << testCase << endl; exit (1);
		}
		End = clock();
		tempo = (double) (End - Begin) / CLOCKS_PER_SEC;
		
		printf (" in %.4lfs\n", tempo);
	}

};

bool FlagsTest::passed;

int main(int argc, char *argv[]) {
	int cnt = 0, cntAc = 0, caso = -1;
	bool passedAll = true;
	
	if (argc > 1) {
		caso = atoi (argv[1]);
		if (caso == 28)
			return 100;
	}
	
    for (int i = 0; i < 28; i++) {
    	if (caso != -1 && caso != i) continue;
    	
		cnt++;
		FlagsTest *test = new FlagsTest ();
		test->runTest(i);
		passedAll &= FlagsTest::passed;
		if (FlagsTest::passed) cntAc++;
    }
    if (caso == -1) {
		if (passedAll) {
    		cout << "You've got AC! (" << cnt << "/" << cntAc << ")" << endl;
    	} else {
 	   		cout << "You've got WA! (" << cnt << "/" << cntAc << ")" << endl;
    	}
    }
    return 0;	
}
