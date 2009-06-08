#define TEST

#include "Mortgage.cpp"
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



class MortgageTest {

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


    Mortgage solution;
    
    

void testCase0 () {
int var0 = 1000;

int var1 = 50;

int var2 = 1;

int ret = 86;

assertEquals(0, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase1 () {
int var0 = 2000000000;

int var1 = 6000;

int var2 = 1;

int ret = 671844808;

assertEquals(1, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase2 () {
int var0 = 1000000;

int var1 = 1000000;

int var2 = 1000;

int ret = 988143;

assertEquals(2, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase3 () {
int var0 = 1000000;

int var1 = 129;

int var2 = 30;

int ret = 10868;

assertEquals(3, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase4 () {
int var0 = 100;

int var1 = 1;

int var2 = 1000;

int ret = 2;

assertEquals(4, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase5 () {
int var0 = 618083873;

int var1 = 932377;

int var2 = 462;

int ret = 610230012;

assertEquals(5, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase6 () {
int var0 = 37007334;

int var1 = 497647;

int var2 = 389;

int ret = 36135971;

assertEquals(6, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase7 () {
int var0 = 910806859;

int var1 = 106489;

int var2 = 245;

int ret = 818564691;

assertEquals(7, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase8 () {
int var0 = 620972289;

int var1 = 447604;

int var2 = 815;

int ret = 604759055;

assertEquals(8, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase9 () {
int var0 = 1964106774;

int var1 = 57176;

int var2 = 469;

int ret = 1623392057;

assertEquals(9, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase10 () {
int var0 = 396495408;

int var1 = 965433;

int var2 = 303;

int ret = 391627612;

assertEquals(10, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase11 () {
int var0 = 1303970803;

int var1 = 751105;

int var2 = 470;

int ret = 1283465566;

assertEquals(11, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase12 () {
int var0 = 560290889;

int var1 = 94158;

int var2 = 606;

int ret = 496956137;

assertEquals(12, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase13 () {
int var0 = 1193263809;

int var1 = 406909;

int var2 = 59;

int ret = 1159081766;

assertEquals(13, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase14 () {
int var0 = 790990757;

int var1 = 569741;

int var2 = 255;

int ret = 774674409;

assertEquals(14, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase15 () {
int var0 = 1878848491;

int var1 = 765597;

int var2 = 345;

int ret = 1849853804;

assertEquals(15, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase16 () {
int var0 = 1767005838;

int var1 = 159220;

int var2 = 890;

int ret = 1643164757;

assertEquals(16, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase17 () {
int var0 = 160606687;

int var1 = 352973;

int var2 = 961;

int ret = 155326077;

assertEquals(17, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase18 () {
int var0 = 468903894;

int var1 = 557830;

int var2 = 713;

int ret = 459029289;

assertEquals(18, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase19 () {
int var0 = 622058302;

int var1 = 712197;

int var2 = 633;

int ret = 611750749;

assertEquals(19, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase20 () {
int var0 = 804652054;

int var1 = 4523;

int var2 = 437;

int ret = 220265161;

assertEquals(20, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase21 () {
int var0 = 317486105;

int var1 = 626173;

int var2 = 530;

int ret = 311516199;

assertEquals(21, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase22 () {
int var0 = 1266328720;

int var1 = 680421;

int var2 = 78;

int ret = 1244382615;

assertEquals(22, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase23 () {
int var0 = 133678780;

int var1 = 660664;

int var2 = 497;

int ret = 131294016;

assertEquals(23, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase24 () {
int var0 = 180769391;

int var1 = 462677;

int var2 = 325;

int ret = 176199478;

assertEquals(24, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase25 () {
int var0 = 645338021;

int var1 = 625478;

int var2 = 616;

int ret = 633190063;

assertEquals(25, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase26 () {
int var0 = 534515614;

int var1 = 800188;

int var2 = 584;

int ret = 526618197;

assertEquals(26, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase27 () {
int var0 = 705069909;

int var1 = 347802;

int var2 = 229;

int ret = 681554646;

assertEquals(27, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase28 () {
int var0 = 614051902;

int var1 = 656351;

int var2 = 585;

int ret = 603026823;

assertEquals(28, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase29 () {
int var0 = 721647343;

int var1 = 325968;

int var2 = 970;

int ret = 696024302;

assertEquals(29, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase30 () {
int var0 = 1214770213;

int var1 = 843509;

int var2 = 161;

int ret = 1197730951;

assertEquals(30, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase31 () {
int var0 = 925650314;

int var1 = 407094;

int var2 = 289;

int ret = 899145989;

assertEquals(31, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase32 () {
int var0 = 1992772528;

int var1 = 53725;

int var2 = 966;

int ret = 1628934258;

assertEquals(32, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase33 () {
int var0 = 327822429;

int var1 = 896518;

int var2 = 882;

int ret = 323492445;

assertEquals(33, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase34 () {
int var0 = 1280563618;

int var1 = 750707;

int var2 = 121;

int ret = 1260415956;

assertEquals(34, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase35 () {
int var0 = 1114588932;

int var1 = 332313;

int var2 = 22;

int ret = 1075743268;

assertEquals(35, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase36 () {
int var0 = 61085060;

int var1 = 497791;

int var2 = 148;

int ret = 59647176;

assertEquals(36, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase37 () {
int var0 = 239835955;

int var1 = 918655;

int var2 = 492;

int ret = 236743476;

assertEquals(37, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase38 () {
int var0 = 252618379;

int var1 = 388703;

int var2 = 450;

int ret = 245053124;

assertEquals(38, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase39 () {
int var0 = 1157290063;

int var1 = 733456;

int var2 = 947;

int ret = 1138660553;

assertEquals(39, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase40 () {
int var0 = 259665595;

int var1 = 69925;

int var2 = 161;

int ret = 221630965;

assertEquals(40, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase41 () {
int var0 = 929938417;

int var1 = 686154;

int var2 = 508;

int ret = 913954464;

assertEquals(41, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase42 () {
int var0 = 175138409;

int var1 = 695122;

int var2 = 926;

int ret = 172166276;

assertEquals(42, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase43 () {
int var0 = 1495989673;

int var1 = 426673;

int var2 = 394;

int ret = 1455066535;

assertEquals(43, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase44 () {
int var0 = 1041972280;

int var1 = 681297;

int var2 = 337;

int ret = 1023937200;

assertEquals(44, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase45 () {
int var0 = 1382590995;

int var1 = 11132;

int var2 = 41;

int ret = 665355481;

assertEquals(45, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase46 () {
int var0 = 265538953;

int var1 = 562037;

int var2 = 137;

int ret = 259987974;

assertEquals(46, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase47 () {
int var0 = 1981832936;

int var1 = 758911;

int var2 = 487;

int ret = 1950983727;

assertEquals(47, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase48 () {
int var0 = 512042040;

int var1 = 323687;

int var2 = 861;

int ret = 493737774;

assertEquals(48, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase49 () {
int var0 = 163543995;

int var1 = 973173;

int var2 = 738;

int ret = 161551931;

assertEquals(49, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase50 () {
int var0 = 1511988723;

int var1 = 580548;

int var2 = 752;

int ret = 1481368648;

assertEquals(50, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase51 () {
int var0 = 1490110002;

int var1 = 305117;

int var2 = 39;

int ret = 1433722865;

assertEquals(51, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase52 () {
int var0 = 1463035902;

int var1 = 147540;

int var2 = 281;

int ret = 1352991833;

assertEquals(52, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase53 () {
int var0 = 1378407427;

int var1 = 121376;

int var2 = 802;

int ret = 1254390445;

assertEquals(53, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase54 () {
int var0 = 1939524178;

int var1 = 2486;

int var2 = 309;

int ret = 332849450;

assertEquals(54, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase55 () {
int var0 = 182518;

int var1 = 88;

int var2 = 197;

int ret = 1330;

assertEquals(55, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase56 () {
int var0 = 87128;

int var1 = 96;

int var2 = 279;

int ret = 693;

assertEquals(56, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase57 () {
int var0 = 184597;

int var1 = 40;

int var2 = 497;

int ret = 615;

assertEquals(57, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase58 () {
int var0 = 72135;

int var1 = 69;

int var2 = 268;

int ret = 414;

assertEquals(58, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase59 () {
int var0 = 179135;

int var1 = 74;

int var2 = 12;

int ret = 1870;

assertEquals(59, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase60 () {
int var0 = 48826;

int var1 = 32;

int var2 = 424;

int ret = 131;

assertEquals(60, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase61 () {
int var0 = 41875;

int var1 = 84;

int var2 = 677;

int ret = 293;

assertEquals(61, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase62 () {
int var0 = 177616;

int var1 = 57;

int var2 = 625;

int ret = 841;

assertEquals(62, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase63 () {
int var0 = 77336;

int var1 = 83;

int var2 = 661;

int ret = 533;

assertEquals(63, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase64 () {
int var0 = 13115;

int var1 = 25;

int var2 = 82;

int ret = 32;

assertEquals(64, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase65 () {
int var0 = 187890;

int var1 = 49;

int var2 = 103;

int ret = 770;

assertEquals(65, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase66 () {
int var0 = 164227;

int var1 = 44;

int var2 = 706;

int ret = 601;

assertEquals(66, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase67 () {
int var0 = 138709;

int var1 = 23;

int var2 = 280;

int ret = 267;

assertEquals(67, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase68 () {
int var0 = 9303;

int var1 = 82;

int var2 = 1000;

int ret = 65;

assertEquals(68, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase69 () {
int var0 = 14512;

int var1 = 15;

int var2 = 310;

int ret = 20;

assertEquals(69, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase70 () {
int var0 = 151273;

int var1 = 73;

int var2 = 895;

int ret = 916;

assertEquals(70, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase71 () {
int var0 = 127121;

int var1 = 6;

int var2 = 846;

int ret = 65;

assertEquals(71, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase72 () {
int var0 = 143038;

int var1 = 65;

int var2 = 879;

int ret = 772;

assertEquals(72, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase73 () {
int var0 = 126061;

int var1 = 53;

int var2 = 955;

int ret = 556;

assertEquals(73, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase74 () {
int var0 = 113753;

int var1 = 76;

int var2 = 387;

int ret = 717;

assertEquals(74, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase75 () {
int var0 = 1999999999;

int var1 = 1000000;

int var2 = 1;

int ret = 1976284585;

assertEquals(75, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase76 () {
int var0 = 2000000000;

int var1 = 6000;

int var2 = 1;

int ret = 671844808;

assertEquals(76, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase77 () {
int var0 = 20000000;

int var1 = 46;

int var2 = 999;

int ret = 76375;

assertEquals(77, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase78 () {
int var0 = 1000000;

int var1 = 1000000;

int var2 = 1000;

int ret = 988143;

assertEquals(78, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase79 () {
int var0 = 1999999999;

int var1 = 1000000;

int var2 = 1;

int ret = 1976284585;

assertEquals(79, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase80 () {
int var0 = 1999999997;

int var1 = 100000;

int var2 = 1;

int ret = 1785714284;

assertEquals(80, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase81 () {
int var0 = 1000;

int var1 = 50;

int var2 = 1;

int ret = 86;

assertEquals(81, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase82 () {
int var0 = 3948234;

int var1 = 984;

int var2 = 73;

int ret = 299221;

assertEquals(82, ret, solution.monthlyPayment(var0, var1, var2));
}

void testCase83 () {
int var0 = 2000000000;

int var1 = 1;

int var2 = 1000;

int ret = 263648;

assertEquals(83, ret, solution.monthlyPayment(var0, var1, var2));
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
		case(48): testCase48(); break;
		case(49): testCase49(); break;
		case(50): testCase50(); break;
		case(51): testCase51(); break;
		case(52): testCase52(); break;
		case(53): testCase53(); break;
		case(54): testCase54(); break;
		case(55): testCase55(); break;
		case(56): testCase56(); break;
		case(57): testCase57(); break;
		case(58): testCase58(); break;
		case(59): testCase59(); break;
		case(60): testCase60(); break;
		case(61): testCase61(); break;
		case(62): testCase62(); break;
		case(63): testCase63(); break;
		case(64): testCase64(); break;
		case(65): testCase65(); break;
		case(66): testCase66(); break;
		case(67): testCase67(); break;
		case(68): testCase68(); break;
		case(69): testCase69(); break;
		case(70): testCase70(); break;
		case(71): testCase71(); break;
		case(72): testCase72(); break;
		case(73): testCase73(); break;
		case(74): testCase74(); break;
		case(75): testCase75(); break;
		case(76): testCase76(); break;
		case(77): testCase77(); break;
		case(78): testCase78(); break;
		case(79): testCase79(); break;
		case(80): testCase80(); break;
		case(81): testCase81(); break;
		case(82): testCase82(); break;
		case(83): testCase83(); break;
			default: cerr << "No such test case: " << testCase << endl; exit (1);
		}
		End = clock();
		tempo = (double) (End - Begin) / CLOCKS_PER_SEC;
		
		printf (" in %.4lfs\n", tempo);
	}

};

bool MortgageTest::passed;

int main(int argc, char *argv[]) {
	int cnt = 0, cntAc = 0, caso = -1;
	bool passedAll = true;
	
	if (argc > 1) {
		caso = atoi (argv[1]);
		if (caso == 84)
			return 100;
	}
	
    for (int i = 0; i < 84; i++) {
    	if (caso != -1 && caso != i) continue;
    	
		cnt++;
		MortgageTest *test = new MortgageTest ();
		test->runTest(i);
		passedAll &= MortgageTest::passed;
		if (MortgageTest::passed) cntAc++;
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
