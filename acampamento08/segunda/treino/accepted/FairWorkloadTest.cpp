#define TEST

#include "FairWorkload.cpp"
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



class FairWorkloadTest {

	public: static bool passed;
	
	    
    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
        	passed = true;
            cout << "Test case " << testCase << " PASSED!";
        } else {
        	passed = false;
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>';
        }
    }


    FairWorkload solution;
    
    

void testCase0 () {
int _var0[] = {10,20,30,40,50,60,70,80,90};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 3;

int ret = 170;

assertEquals(0, ret, solution.getMostWork(var0, var1));
}

void testCase1 () {
int _var0[] = {10,20,30,40,50,60,70,80,90};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 5;

int ret = 110;

assertEquals(1, ret, solution.getMostWork(var0, var1));
}

void testCase2 () {
int _var0[] = {568,712,412,231,241,393,865,287,128,457,238,98,980,23,782};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 4;

int ret = 1785;

assertEquals(2, ret, solution.getMostWork(var0, var1));
}

void testCase3 () {
int _var0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1000};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 2;

int ret = 1000;

assertEquals(3, ret, solution.getMostWork(var0, var1));
}

void testCase4 () {
int _var0[] = {50,50,50,50,50,50,50};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 2;

int ret = 200;

assertEquals(4, ret, solution.getMostWork(var0, var1));
}

void testCase5 () {
int _var0[] = {1,1,1,1,100};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 5;

int ret = 100;

assertEquals(5, ret, solution.getMostWork(var0, var1));
}

void testCase6 () {
int _var0[] = {950,650,250,250,350,100,650,150,150,700};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 6;

int ret = 950;

assertEquals(6, ret, solution.getMostWork(var0, var1));
}

void testCase7 () {
int _var0[] = {689,516,776,244,991,797};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 5;

int ret = 1020;

assertEquals(7, ret, solution.getMostWork(var0, var1));
}

void testCase8 () {
int _var0[] = {444,976,369};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 1;

int ret = 1789;

assertEquals(8, ret, solution.getMostWork(var0, var1));
}

void testCase9 () {
int _var0[] = {845,335,950,324,345,558};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 2;

int ret = 2130;

assertEquals(9, ret, solution.getMostWork(var0, var1));
}

void testCase10 () {
int _var0[] = {208,916,724,185,33,292,792,23,720};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 1;

int ret = 3893;

assertEquals(10, ret, solution.getMostWork(var0, var1));
}

void testCase11 () {
int _var0[] = {961,37,126,508,247,572,286};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 3;

int ret = 961;

assertEquals(11, ret, solution.getMostWork(var0, var1));
}

void testCase12 () {
int _var0[] = {496,477,832,670,367,231,36,741,648,259,773,557,784};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 5;

int ret = 1680;

assertEquals(12, ret, solution.getMostWork(var0, var1));
}

void testCase13 () {
int _var0[] = {962,400,598,497,873,671,465,372,922,965,645};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 5;

int ret = 1759;

assertEquals(13, ret, solution.getMostWork(var0, var1));
}

void testCase14 () {
int _var0[] = {646,321,347,684,273,718,429,842,559,893,717,971};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 2;

int ret = 3982;

assertEquals(14, ret, solution.getMostWork(var0, var1));
}

void testCase15 () {
int _var0[] = {101,653,661,310,977};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 5;

int ret = 977;

assertEquals(15, ret, solution.getMostWork(var0, var1));
}

void testCase16 () {
int _var0[] = {669,331};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 1;

int ret = 1000;

assertEquals(16, ret, solution.getMostWork(var0, var1));
}

void testCase17 () {
int _var0[] = {64,498,364,970,901,352,289,76,67,805,471,787,983,649};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 8;

int ret = 1253;

assertEquals(17, ret, solution.getMostWork(var0, var1));
}

void testCase18 () {
int _var0[] = {613,723,680,518,727,60,495,322,707,94,582,755,410,340};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 7;

int ret = 1336;

assertEquals(18, ret, solution.getMostWork(var0, var1));
}

void testCase19 () {
int _var0[] = {759,746,460,92,283,739,502,501,980,86,212,276,306,571,940};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 8;

int ret = 1206;

assertEquals(19, ret, solution.getMostWork(var0, var1));
}

void testCase20 () {
int _var0[] = {30,142,706,67,303,474,930,959,325,14,995,103,113,433,564};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 8;

int ret = 995;

assertEquals(20, ret, solution.getMostWork(var0, var1));
}

void testCase21 () {
int _var0[] = {320,543,187,87,710,653,333,135,674,54,739,528,930,807,503};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 8;

int ret = 1267;

assertEquals(21, ret, solution.getMostWork(var0, var1));
}

void testCase22 () {
int _var0[] = {261,575,597,217,623,620,11,946,912,575,8,728,244,248,802};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 7;

int ret = 1311;

assertEquals(22, ret, solution.getMostWork(var0, var1));
}

void testCase23 () {
int _var0[] = {722,235,642,251,105,860,532,980,483,256,226,256,799,761,200};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 9;

int ret = 980;

assertEquals(23, ret, solution.getMostWork(var0, var1));
}

void testCase24 () {
int _var0[] = {10,20,30,40,50,60,70,80,90};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 3;

int ret = 170;

assertEquals(24, ret, solution.getMostWork(var0, var1));
}

void testCase25 () {
int _var0[] = {1000,1,1,1,1,1,1,1,1,1};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 4;

int ret = 1000;

assertEquals(25, ret, solution.getMostWork(var0, var1));
}

void testCase26 () {
int _var0[] = {100,1,1,1,1};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 5;

int ret = 100;

assertEquals(26, ret, solution.getMostWork(var0, var1));
}

void testCase27 () {
int _var0[] = {1,1,1,1,1,1,1,1000};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 3;

int ret = 1000;

assertEquals(27, ret, solution.getMostWork(var0, var1));
}

void testCase28 () {
int _var0[] = {950,650,250,250,350,100,650,150,150,700,200,170,320,100};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int var1 = 7;

int ret = 950;

assertEquals(28, ret, solution.getMostWork(var0, var1));
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
		case(28): testCase28(); break;
			default: cerr << "No such test case: " << testCase << endl; exit (1);
		}
		End = clock();
		tempo = (double) (End - Begin) / CLOCKS_PER_SEC;
		
		printf (" in %.4lfs\n", tempo);
	}

};

bool FairWorkloadTest::passed;

int main(int argc, char *argv[]) {
	int cnt = 0, cntAc = 0, caso = -1;
	bool passedAll = true;
	
	if (argc > 1) {
		caso = atoi (argv[1]);
		if (caso == 29)
			return 100;
	}
	
    for (int i = 0; i < 29; i++) {
    	if (caso != -1 && caso != i) continue;
    	
		cnt++;
		FairWorkloadTest *test = new FairWorkloadTest ();
		test->runTest(i);
		passedAll &= FairWorkloadTest::passed;
		if (FairWorkloadTest::passed) cntAc++;
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
