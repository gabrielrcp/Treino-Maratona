#define TEST

#include "AutoLoan.cpp"
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



class AutoLoanTest {

	public: static bool passed;
	
	    static int cmp (double a, double b = 0.0, double tol = 1e-9) {
       if (a <= b + tol) {
          if (a + tol < b) return -1;
          return 0;
       }
       return 1;
    }

    static void assertEquals(int testCase, const double& expected, const double& actual) {
        if (cmp (expected * (1 + 1e-9), actual) >= 0 && cmp (expected * (1 - 1e-9), actual) <= 0) {
        	passed = true;
            cout << "Test case " << testCase << " PASSED!";
        } else {
        	passed = false;
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>';
        }
    }


    AutoLoan solution;
    
    

void testCase0 () {
double var0 = 6800.0;

double var1 = 100.0;

int var2 = 68;

double ret = 1.3322616182218813E-13;

assertEquals(0, ret, solution.interestRate(var0, var1, var2));
}

void testCase1 () {
double var0 = 2000.0;

double var1 = 510.0;

int var2 = 4;

double ret = 9.56205462458368;

assertEquals(1, ret, solution.interestRate(var0, var1, var2));
}

void testCase2 () {
double var0 = 15000.0;

double var1 = 364.0;

int var2 = 48;

double ret = 7.687856394581649;

assertEquals(2, ret, solution.interestRate(var0, var1, var2));
}

void testCase3 () {
double var0 = 10000.0;

double var1 = 385.0;

int var2 = 30;

double ret = 11.473054204549669;

assertEquals(3, ret, solution.interestRate(var0, var1, var2));
}

void testCase4 () {
double var0 = 200.0;

double var1 = 15.0;

int var2 = 600;

double ret = 89.99999999999982;

assertEquals(4, ret, solution.interestRate(var0, var1, var2));
}

void testCase5 () {
double var0 = 1000000.0;

double var1 = 1667.0;

int var2 = 600;

double ret = 7.986158248041164E-4;

assertEquals(5, ret, solution.interestRate(var0, var1, var2));
}

void testCase6 () {
double var0 = 724556.0;

double var1 = 50505.0;

int var2 = 575;

double ret = 83.64570854426711;

assertEquals(6, ret, solution.interestRate(var0, var1, var2));
}

void testCase7 () {
double var0 = 332696.0;

double var1 = 10951.0;

int var2 = 136;

double ret = 38.98851536883803;

assertEquals(7, ret, solution.interestRate(var0, var1, var2));
}

void testCase8 () {
double var0 = 23002.0;

double var1 = 4709.0;

int var2 = 6;

double ret = 74.54805516148613;

assertEquals(8, ret, solution.interestRate(var0, var1, var2));
}

void testCase9 () {
double var0 = 492214.0;

double var1 = 2049.0;

int var2 = 471;

double ret = 3.9204806010895594;

assertEquals(9, ret, solution.interestRate(var0, var1, var2));
}

void testCase10 () {
double var0 = 740192.0;

double var1 = 7185.0;

int var2 = 588;

double ret = 11.607783057395558;

assertEquals(10, ret, solution.interestRate(var0, var1, var2));
}

void testCase11 () {
double var0 = 570542.0;

double var1 = 24374.0;

int var2 = 65;

double ret = 47.05796362542851;

assertEquals(11, ret, solution.interestRate(var0, var1, var2));
}

void testCase12 () {
double var0 = 407050.0;

double var1 = 35078.0;

int var2 = 17;

double ret = 55.397079816319696;

assertEquals(12, ret, solution.interestRate(var0, var1, var2));
}

void testCase13 () {
double var0 = 140192.0;

double var1 = 1491.0;

int var2 = 454;

double ret = 12.653412761497272;

assertEquals(13, ret, solution.interestRate(var0, var1, var2));
}

void testCase14 () {
double var0 = 219252.0;

double var1 = 8934.0;

int var2 = 337;

double ret = 48.897089628821746;

assertEquals(14, ret, solution.interestRate(var0, var1, var2));
}

void testCase15 () {
double var0 = 506973.0;

double var1 = 11900.0;

int var2 = 50;

double ret = 7.7628540286105885;

assertEquals(15, ret, solution.interestRate(var0, var1, var2));
}

void testCase16 () {
double var0 = 281335.0;

double var1 = 16982.0;

int var2 = 54;

double ret = 68.87780115037442;

assertEquals(16, ret, solution.interestRate(var0, var1, var2));
}

void testCase17 () {
double var0 = 286417.0;

double var1 = 9239.0;

int var2 = 145;

double ret = 38.30192971448798;

assertEquals(17, ret, solution.interestRate(var0, var1, var2));
}

void testCase18 () {
double var0 = 140642.0;

double var1 = 1293.0;

int var2 = 561;

double ret = 10.965203755132924;

assertEquals(18, ret, solution.interestRate(var0, var1, var2));
}

void testCase19 () {
double var0 = 389951.0;

double var1 = 12413.0;

int var2 = 163;

double ret = 37.9601927752288;

assertEquals(19, ret, solution.interestRate(var0, var1, var2));
}

void testCase20 () {
double var0 = 973110.0;

double var1 = 337873.0;

int var2 = 3;

double ret = 24.80783488352443;

assertEquals(20, ret, solution.interestRate(var0, var1, var2));
}

void testCase21 () {
double var0 = 230977.0;

double var1 = 67123.0;

int var2 = 4;

double ret = 75.65099005216278;

assertEquals(21, ret, solution.interestRate(var0, var1, var2));
}

void testCase22 () {
double var0 = 61703.0;

double var1 = 16197.0;

int var2 = 4;

double ret = 23.76581938256987;

assertEquals(22, ret, solution.interestRate(var0, var1, var2));
}

void testCase23 () {
double var0 = 44755.0;

double var1 = 8959.0;

int var2 = 5;

double ret = 0.3574309895975514;

assertEquals(23, ret, solution.interestRate(var0, var1, var2));
}

void testCase24 () {
double var0 = 297007.0;

double var1 = 56775.0;

int var2 = 6;

double ret = 48.76330124289328;

assertEquals(24, ret, solution.interestRate(var0, var1, var2));
}

void testCase25 () {
double var0 = 584755.0;

double var1 = 1613.0;

int var2 = 475;

double ret = 1.4303822503235695;

assertEquals(25, ret, solution.interestRate(var0, var1, var2));
}

void testCase26 () {
double var0 = 5628.0;

double var1 = 2197.0;

int var2 = 3;

double ret = 100.00000000000003;

assertEquals(26, ret, solution.interestRate(var0, var1, var2));
}

void testCase27 () {
double var0 = 6800.0;

double var1 = 100.0;

int var2 = 68;

double ret = 1.3322616182218813E-13;

assertEquals(27, ret, solution.interestRate(var0, var1, var2));
}

void testCase28 () {
double var0 = 15000.0;

double var1 = 364.0;

int var2 = 48;

double ret = 7.687856394581649;

assertEquals(28, ret, solution.interestRate(var0, var1, var2));
}

void testCase29 () {
double var0 = 2000.0;

double var1 = 510.0;

int var2 = 4;

double ret = 9.56205462458368;

assertEquals(29, ret, solution.interestRate(var0, var1, var2));
}

void testCase30 () {
double var0 = 60000.0;

double var1 = 4999.0;

int var2 = 600;

double ret = 99.9799999999999;

assertEquals(30, ret, solution.interestRate(var0, var1, var2));
}

void testCase31 () {
double var0 = 100001.0;

double var1 = 989.0;

int var2 = 599;

double ret = 11.834664337677792;

assertEquals(31, ret, solution.interestRate(var0, var1, var2));
}

void testCase32 () {
double var0 = 1000.0;

double var1 = 500.0;

int var2 = 2;

double ret = 1.3322616182218813E-13;

assertEquals(32, ret, solution.interestRate(var0, var1, var2));
}

void testCase33 () {
double var0 = 12.0;

double var1 = 1.0;

int var2 = 500;

double ret = 99.99999999999977;

assertEquals(33, ret, solution.interestRate(var0, var1, var2));
}

void testCase34 () {
double var0 = 1000000.0;

double var1 = 2500.0;

int var2 = 600;

double ret = 1.7463073077668143;

assertEquals(34, ret, solution.interestRate(var0, var1, var2));
}

void testCase35 () {
double var0 = 1.0;

double var1 = 0.142857142857143;

int var2 = 7;

double ret = 3.9968010105369827E-13;

assertEquals(35, ret, solution.interestRate(var0, var1, var2));
}

void testCase36 () {
double var0 = 1000000.0;

double var1 = 79865.0;

int var2 = 599;

double ret = 95.83799999999995;

assertEquals(36, ret, solution.interestRate(var0, var1, var2));
}

void testCase37 () {
double var0 = 999999.0;

double var1 = 3000.0;

int var2 = 599;

double ret = 2.6299652255705737;

assertEquals(37, ret, solution.interestRate(var0, var1, var2));
}

void testCase38 () {
double var0 = 15000.0;

double var1 = 364.0;

int var2 = 600;

double ret = 29.11998354222205;

assertEquals(38, ret, solution.interestRate(var0, var1, var2));
}

void testCase39 () {
double var0 = 9.999999991;

double var1 = 2.5;

int var2 = 4;

double ret = 4.320001689699897E-7;

assertEquals(39, ret, solution.interestRate(var0, var1, var2));
}

void testCase40 () {
double var0 = 200.0;

double var1 = 100.0;

int var2 = 2;

double ret = 1.3322616182218813E-13;

assertEquals(40, ret, solution.interestRate(var0, var1, var2));
}

void testCase41 () {
double var0 = 1000.0;

double var1 = 40.0;

int var2 = 34;

double ret = 22.418392731637795;

assertEquals(41, ret, solution.interestRate(var0, var1, var2));
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
		case(29): testCase29(); break;
		case(30): testCase30(); break;
		case(31): testCase31(); break;
		case(32): testCase32(); break;
		case(33): testCase33(); break;
		case(34): testCase34(); break;
		case(35): testCase35(); break;
		case(36): testCase36(); break;
		case(37): testCase37(); break;
		case(38): testCase38(); break;
		case(39): testCase39(); break;
		case(40): testCase40(); break;
		case(41): testCase41(); break;
			default: cerr << "No such test case: " << testCase << endl; exit (1);
		}
		End = clock();
		tempo = (double) (End - Begin) / CLOCKS_PER_SEC;
		
		printf (" in %.4lfs\n", tempo);
	}

};

bool AutoLoanTest::passed;

int main(int argc, char *argv[]) {
	int cnt = 0, cntAc = 0, caso = -1;
	bool passedAll = true;
	
	if (argc > 1) {
		caso = atoi (argv[1]);
		if (caso == 42)
			return 100;
	}
	
    for (int i = 0; i < 42; i++) {
    	if (caso != -1 && caso != i) continue;
    	
		cnt++;
		AutoLoanTest *test = new AutoLoanTest ();
		test->runTest(i);
		passedAll &= AutoLoanTest::passed;
		if (AutoLoanTest::passed) cntAc++;
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
