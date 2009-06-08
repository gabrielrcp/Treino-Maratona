#define TEST

#include "SortEstimate.cpp"
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



class SortEstimateTest {

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


    SortEstimate solution;
    
    

void testCase0 () {
int var0 = 1;

int var1 = 8;

double ret = 4.0;

assertEquals(0, ret, solution.howMany(var0, var1));
}

void testCase1 () {
int var0 = 1;

int var1 = 1073741824;

double ret = 4.237868701779632E7;

assertEquals(1, ret, solution.howMany(var0, var1));
}

void testCase2 () {
int var0 = 1;

int var1 = 20971520;

double ret = 1048576.0;

assertEquals(2, ret, solution.howMany(var0, var1));
}

void testCase3 () {
int var0 = 1;

int var1 = 1744830463;

double ret = 6.7108863963560425E7;

assertEquals(3, ret, solution.howMany(var0, var1));
}

void testCase4 () {
int var0 = 2;

int var1 = 16;

double ret = 4.0;

assertEquals(4, ret, solution.howMany(var0, var1));
}

void testCase5 () {
int var0 = 37;

int var1 = 12392342;

double ret = 23104.999312341137;

assertEquals(5, ret, solution.howMany(var0, var1));
}

void testCase6 () {
int var0 = 1;

int var1 = 2000000000;

double ret = 7.637495090348122E7;

assertEquals(6, ret, solution.howMany(var0, var1));
}

void testCase7 () {
int var0 = 15;

int var1 = 183518033;

double ret = 634711.5366691528;

assertEquals(7, ret, solution.howMany(var0, var1));
}

void testCase8 () {
int var0 = 94;

int var1 = 528002855;

double ret = 308072.16281298193;

assertEquals(8, ret, solution.howMany(var0, var1));
}

void testCase9 () {
int var0 = 22;

int var1 = 1891962415;

double ret = 3926030.802208677;

assertEquals(9, ret, solution.howMany(var0, var1));
}

void testCase10 () {
int var0 = 19;

int var1 = 21449736;

double ret = 70129.92471231497;

assertEquals(10, ret, solution.howMany(var0, var1));
}

void testCase11 () {
int var0 = 41;

int var1 = 251000508;

double ret = 333658.1565933969;

assertEquals(11, ret, solution.howMany(var0, var1));
}

void testCase12 () {
int var0 = 41;

int var1 = 682091086;

double ret = 844976.7106648742;

assertEquals(12, ret, solution.howMany(var0, var1));
}

void testCase13 () {
int var0 = 15;

int var1 = 324891869;

double ret = 1080626.000222133;

assertEquals(13, ret, solution.howMany(var0, var1));
}

void testCase14 () {
int var0 = 100;

int var1 = 269939035;

double ret = 156438.87972686428;

assertEquals(14, ret, solution.howMany(var0, var1));
}

void testCase15 () {
int var0 = 65;

int var1 = 150597632;

double ret = 135872.67212630875;

assertEquals(15, ret, solution.howMany(var0, var1));
}

void testCase16 () {
int var0 = 82;

int var1 = 1668460444;

double ret = 1019427.0794480281;

assertEquals(16, ret, solution.howMany(var0, var1));
}

void testCase17 () {
int var0 = 94;

int var1 = 698125302;

double ret = 399152.58894443273;

assertEquals(17, ret, solution.howMany(var0, var1));
}

void testCase18 () {
int var0 = 73;

int var1 = 537393400;

double ret = 395894.080674982;

assertEquals(18, ret, solution.howMany(var0, var1));
}

void testCase19 () {
int var0 = 61;

int var1 = 952343733;

double ret = 796412.1957200351;

assertEquals(19, ret, solution.howMany(var0, var1));
}

void testCase20 () {
int var0 = 62;

int var1 = 1668728800;

double ret = 1323517.520513234;

assertEquals(20, ret, solution.howMany(var0, var1));
}

void testCase21 () {
int var0 = 67;

int var1 = 1422724322;

double ret = 1060844.4313069163;

assertEquals(21, ret, solution.howMany(var0, var1));
}

void testCase22 () {
int var0 = 50;

int var1 = 1302510048;

double ret = 1283769.883887477;

assertEquals(22, ret, solution.howMany(var0, var1));
}

void testCase23 () {
int var0 = 72;

int var1 = 1240983207;

double ret = 873315.4015855292;

assertEquals(23, ret, solution.howMany(var0, var1));
}

void testCase24 () {
int var0 = 61;

int var1 = 1668868721;

double ret = 1343872.2486778102;

assertEquals(24, ret, solution.howMany(var0, var1));
}

void testCase25 () {
int var0 = 70;

int var1 = 672611577;

double ret = 507012.8623876511;

assertEquals(25, ret, solution.howMany(var0, var1));
}

void testCase26 () {
int var0 = 41;

int var1 = 844981191;

double ret = 1031674.1952518377;

assertEquals(26, ret, solution.howMany(var0, var1));
}

void testCase27 () {
int var0 = 69;

int var1 = 346799919;

double ret = 277924.8297328659;

assertEquals(27, ret, solution.howMany(var0, var1));
}

void testCase28 () {
int var0 = 96;

int var1 = 1650394599;

double ret = 871225.0564874781;

assertEquals(28, ret, solution.howMany(var0, var1));
}

void testCase29 () {
int var0 = 41;

int var1 = 800275356;

double ret = 980681.0457517206;

assertEquals(29, ret, solution.howMany(var0, var1));
}

void testCase30 () {
int var0 = 47;

int var1 = 1751439252;

double ret = 1793764.4273233637;

assertEquals(30, ret, solution.howMany(var0, var1));
}

void testCase31 () {
int var0 = 72;

int var1 = 1034087829;

double ret = 736868.1134626163;

assertEquals(31, ret, solution.howMany(var0, var1));
}

void testCase32 () {
int var0 = 65;

int var1 = 1405206580;

double ret = 1078722.5591509202;

assertEquals(32, ret, solution.howMany(var0, var1));
}

void testCase33 () {
int var0 = 97;

int var1 = 698397013;

double ret = 387824.0070168886;

assertEquals(33, ret, solution.howMany(var0, var1));
}

void testCase34 () {
int var0 = 45;

int var1 = 1345840599;

double ret = 1460472.8429022175;

assertEquals(34, ret, solution.howMany(var0, var1));
}

void testCase35 () {
int var0 = 92;

int var1 = 1248825953;

double ret = 699151.35947252;

assertEquals(35, ret, solution.howMany(var0, var1));
}

void testCase36 () {
int var0 = 22;

int var1 = 1200654528;

double ret = 2563460.5078692725;

assertEquals(36, ret, solution.howMany(var0, var1));
}

void testCase37 () {
int var0 = 1;

int var1 = 1999999999;

double ret = 7.637495086728776E7;

assertEquals(37, ret, solution.howMany(var0, var1));
}

void testCase38 () {
int var0 = 1;

int var1 = 2000000000;

double ret = 7.637495090348122E7;

assertEquals(38, ret, solution.howMany(var0, var1));
}

void testCase39 () {
int var0 = 2;

int var1 = 1999999997;

double ret = 3.962007767021034E7;

assertEquals(39, ret, solution.howMany(var0, var1));
}

void testCase40 () {
int var0 = 1;

int var1 = 1;

double ret = 1.5596104694623691;

assertEquals(40, ret, solution.howMany(var0, var1));
}

void testCase41 () {
int var0 = 43;

int var1 = 2000000000;

double ret = 2207091.972283502;

assertEquals(41, ret, solution.howMany(var0, var1));
}

void testCase42 () {
int var0 = 100;

int var1 = 1;

double ret = 1.0069076686081029;

assertEquals(42, ret, solution.howMany(var0, var1));
}

void testCase43 () {
int var0 = 1;

int var1 = 3;

double ret = 2.3884234844993384;

assertEquals(43, ret, solution.howMany(var0, var1));
}

void testCase44 () {
int var0 = 100;

int var1 = 2523526;

double ret = 2264.2982128022004;

assertEquals(44, ret, solution.howMany(var0, var1));
}

void testCase45 () {
int var0 = 5;

int var1 = 100;

double ret = 7.081840920218569;

assertEquals(45, ret, solution.howMany(var0, var1));
}

void testCase46 () {
int var0 = 1;

int var1 = 2;

double ret = 2.0;

assertEquals(46, ret, solution.howMany(var0, var1));
}

void testCase47 () {
int var0 = 2;

int var1 = 2000000000;

double ret = 3.962007772642713E7;

assertEquals(47, ret, solution.howMany(var0, var1));
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
		case(42): testCase42(); break;
		case(43): testCase43(); break;
		case(44): testCase44(); break;
		case(45): testCase45(); break;
		case(46): testCase46(); break;
		case(47): testCase47(); break;
			default: cerr << "No such test case: " << testCase << endl; exit (1);
		}
		End = clock();
		tempo = (double) (End - Begin) / CLOCKS_PER_SEC;
		
		printf (" in %.4lfs\n", tempo);
	}

};

bool SortEstimateTest::passed;

int main(int argc, char *argv[]) {
	int cnt = 0, cntAc = 0, caso = -1;
	bool passedAll = true;
	
	if (argc > 1) {
		caso = atoi (argv[1]);
		if (caso == 48)
			return 100;
	}
	
    for (int i = 0; i < 48; i++) {
    	if (caso != -1 && caso != i) continue;
    	
		cnt++;
		SortEstimateTest *test = new SortEstimateTest ();
		test->runTest(i);
		passedAll &= SortEstimateTest::passed;
		if (SortEstimateTest::passed) cntAc++;
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
