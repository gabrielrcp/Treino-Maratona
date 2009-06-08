#define TEST

#include "RemoteRover.cpp"
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



class RemoteRoverTest {

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


    RemoteRover solution;
    
    

void testCase0 () {
int _var0[] = {100,300,200};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {100,50,75};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 1000;

double ret = 17.042083785318038;

assertEquals(0, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase1 () {
int _var0[] = {1155,6184,2783,7540,8156};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {570,810,875,172,642};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 0;

double ret = 69.38271426584203;

assertEquals(1, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase2 () {
int _var0[] = {5000};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {50};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 10000;

double ret = 223.60679774997894;

assertEquals(2, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase3 () {
int _var0[] = {9033,8232,8842,6518,2358,1115,941,928,220,8460};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {50,50,50,50,50,50,50,50,50,50};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 10000;

double ret = 954.1368054948935;

assertEquals(3, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase4 () {
int _var0[] = {9236,7065,2283,506,6432,9812,3133,1397,7052,3729,2556,9954,1367,6440,5141,3091,2879,1346,7080,1036,7503,7775,433,7579,6520,2287,1971,3879,1725,8200,1830,2774,3850,7509,8531,7493,1511,9399,9679,2124,791,3432};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {956,799,481,194,993,444,571,986,815,910,98,847,650,487,419,434,410,812,374,751,307,134,134,955,758,73,932,360,135,588,218,936,674,494,157,556,881,292,851,890,886,912};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 9756;

double ret = 501.6129192127166;

assertEquals(4, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase5 () {
int _var0[] = {1704,244,5035,7818,2769,307,371,4421,3419,8092,4870,957,4142,8349,7158,7,2727,9943,6076,9862,3087,5156,3081,4300,9483,3744,3914,6425,4027,8040,6743,1166,723,9903,6020,8184,3891,707,2762,4347,315,2194,1099,6493,2076};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {24,746,178,224,690,112,730,811,81,906,481,191,491,591,416,980,165,330,629,588,317,461,990,504,998,408,62,369,363,8,897,322,595,423,546,889,472,316,92,449,832,615,593,730,344};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 9970;

double ret = 1601.6600284822227;

assertEquals(5, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase6 () {
int _var0[] = {6131,9321,8209,9136,6194,3479,5829,4158,5494,4798,5996,8811,9507,5039,5252,7757,5491,7565,2225,5003,672,4491,7724,4800,6621,3980,8530,9004,6263,1803,8879,7405,3977,4548,9521,4431,4484,4439,2432,6297,7522,2237,7226,4383,6690};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {924,339,314,401,242,310,434,712,842,714,811,525,702,904,75,213,490,853,501,877,995,856,328,590,863,526,565,960,616,916,895,138,963,921,133,604,327,680,819,684,993,914,551,442,904};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 7760;

double ret = 646.4357091147734;

assertEquals(6, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase7 () {
int _var0[] = {8176,9361,9756,6950,1264,4969};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {495,682,496,531,491,700};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 253;

double ret = 72.67514264727286;

assertEquals(7, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase8 () {
int _var0[] = {2278,7901,3988,7443,2519,6973,8460,638,3860,6667,9346,46,5148,9005,8586,452,1331,9289,561,6135,8736,7733,4965,5762,4152,9391,874,7034,6427,8740};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {132,641,177,507,545,173,180,779,344,851,129,978,511,841,405,859,560,22,288,723,187,651,304,294,637,251,805,487,547,729};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 9498;

double ret = 906.9986841995154;

assertEquals(8, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase9 () {
int _var0[] = {8118,6867,8983,9166,6643,5949,4869,4276,5972,7336,9763,7307,7649,4396,5048,1991,4330,1042,8219,7742,4843,9005,8673,3845,9703,6120,1749,1258,185,8017,5821,2396,7069,8369,3157,7415,8772,6943,8925,6711,48,6744,7437};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {804,375,1,789,400,1,1,1,989,1,1,1,541,1,1,1,34,530,107,505,1,745,719,151,1,1,1,596,709,1,488,1,1,1,332,1,659,1,108,521,972,376,1};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 9067;

double ret = 130478.13610265777;

assertEquals(9, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase10 () {
int _var0[] = {9635,2963,8836,6105,8237,6880,9072,1740,880,4483,9051,9658};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {401,996,787,349,259,290,848,138,570,330,359,555};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 5889;

double ret = 192.74753875165402;

assertEquals(10, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase11 () {
int _var0[] = {8728,4251,1595,5973,8100,5281,5063,932,3950,2554,7273,5460,3822,9587,3639,6661,8218,7818,3344,4067,3542,7378,4630,6875,2668,5373,4907,3039,8505,4367,4331};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {345,260,524,254,16,355,907,195,270,394,318,337,460,143,684,100,88,56,75,928,976,420,491,632,129,43,835,656,689,562,175};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 2659;

double ret = 1331.6947851504485;

assertEquals(11, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase12 () {
int _var0[] = {6304,8314,2841,8424,5018,4185,8467,1779,666,8287,5643,4343,9975,293,6960};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {1,1,1,1,1,433,1,205,576,1,1,475,1,1,1};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 2826;

double ret = 70555.47822116842;

assertEquals(12, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase13 () {
int _var0[] = {7541,2015,288,2947,10,9794,8909,1894,1927,3866,6976,4188};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {837,600,364,987,870,257,137,691,198,930,715,481};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 3044;

double ret = 154.56239076022194;

assertEquals(13, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase14 () {
int _var0[] = {2767,905,2897,1930,2980,5621,3232,2935,2594,6787,9071,6720,5885,2221,6376,2681,5987,4080,560,2485,339,8082,9241,87,5069,471,3321,55,2723,4964,2471,3934,4103,9888,3465,3604,4526,8418,7211,1791,4222,660,6049,5345,9542,3182,8509,8937,2173,5951};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {522,701,579,415,997,134,889,11,996,506,198,356,630,599,504,156,963,910,12,168,133,469,143,94,611,687,899,259,682,76,190,171,931,380,260,157,470,66,70,469,405,231,858,678,301,672,243,102,627,391};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 7796;

double ret = 1247.9511575421454;

assertEquals(14, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase15 () {
int _var0[] = {755,5215,6047,7462,3631,3384,275};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {778,945,987,853,301,853,184};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 6959;

double ret = 39.9736616725716;

assertEquals(15, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase16 () {
int _var0[] = {8460,1380,4066,2108,6081,7908,1793,7083,2692,8560,5446,503,7403,5274,8635,1116,470,8353,2943,8186,7323,4104,9124,6170,7619,5319,7774,8818,6171,2488,3285,743,3491,7478,1190,9831,7175,3865,9099,656,7600,1380,4074,7379,8503,4087,3995,3121,9165};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {43,898,49,636,314,794,989,625,138,699,122,545,854,517,510,879,316,358,743,25,838,792,149,550,777,406,590,806,826,684,467,804,28,509,600,731,652,824,20,194,830,729,79,281,158,598,286,802,575};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 8263;

double ret = 1762.5377393852918;

assertEquals(16, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase17 () {
int _var0[] = {1873,1217,1985,1340,8635,6349,8711,7401,7441,4997,8578,9469,1971,633,4202,4388,9942,8185,7296,6295,2738,1427,2072,970,4373,6679,1362,8700,8873,1879,7155,8958,6336,6594,1662,3859,7094,7940,1808,1421};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {627,27,284,257,415,195,762,532,308,213,475,999,360,687,951,41,728,599,405,349,870,223,465,661,332,305,630,168,433,419,291,563,11,419,729,803,929,939,506,988};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 8786;

double ret = 1185.6088910907129;

assertEquals(17, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase18 () {
int _var0[] = {9134,8742,5889,8117,8215,9453,7254,7953,5788,2905,770,8708,2977,8077,8216,2031,9318,8286,6006,9783,5255,1662,6690,1780,6907,9900};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {593,390,862,723,231,73,241,887,130,968,456,526,281,379,924,951,111,742,70,959,734,291,890,875,576,855};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 683;

double ret = 605.8085687345417;

assertEquals(18, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase19 () {
int _var0[] = {3282,6794,2681,8498,1569,1561,2212,949};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {237,535,481,196,671,393,129,501};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 2827;

double ret = 101.23604445798776;

assertEquals(19, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase20 () {
int _var0[] = {3980,2876,7139,671,3565,7886};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {248,659,947,337,690,269};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 7672;

double ret = 66.38330030595517;

assertEquals(20, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase21 () {
int _var0[] = {6177,5647,2764,7841};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {448,929,786,941};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 4120;

double ret = 32.19408148863989;

assertEquals(21, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase22 () {
int _var0[] = {9461,1772,5754,2964,4160,1611,9462,2977,8874,3010,8709,1994,6108,9578,8127,9007,8505,9606,2986,4033,7816,2955,3213};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {424,158,324,851,437,151,260,293,685,281,598,812,529,367,62,822,337,646,675,443,602,139,576};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 9305;

double ret = 436.0290305479315;

assertEquals(22, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase23 () {
int _var0[] = {6755,1340,558,698,393,9180,7073,9937,9149,5841,8492,2553,9496,482,1864,3728,2628,1925,5469,1872,35,3604,673,1283,2155,584,396,1060,4074,2438,6814,7033,1640,6885,2186,6553,7369,3141,9971,130,9561,4970,2408,6586,3181};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {284,197,161,669,236,390,568,766,68,583,470,996,406,633,834,848,901,388,266,973,74,509,389,920,231,309,165,786,745,750,206,49,543,746,993,732,477,416,890,844,128,458,271,543,615};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 3486;

double ret = 692.596186446376;

assertEquals(23, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase24 () {
int _var0[] = {8285,544,8786,1651,7520,92,903,6590,9420,8051,7549,1538,3296,2997,6068,1325,625,2044,4788,3428,6581,7980,5830,8243,2322,9708,4420,555,3851,2564,8262,9926,577,7021,5,169,1737,2351,7184,9449,9051,221,7511,1824,2307,2305};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {653,680,346,1,560,381,282,1,13,1,654,215,1,1,1,1,180,1,16,470,912,737,1,194,1,480,730,1,371,1,646,1,710,1,394,1,1,173,1,571,995,1,1,705,40,884};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 1305;

double ret = 78384.00500164002;

assertEquals(24, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase25 () {
int _var0[] = {1745,4408,2379,1708,148,6616,3839,5254,30,4788,239,8192,636,1917,7614};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {1,1,1,1,1,793,1,1,1,240,1,1,1,768,1};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 5040;

double ret = 36224.31589129784;

assertEquals(25, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase26 () {
int _var0[] = {6645,4994,5380,9555,8267,2447,6076,7485,3080,9306,5543,6693,5092,3971,8823,3343,5489,4932,5093,3281,1226,7719,9085,509,6604,7239,8219,5726,1313,3392,2382,1818,8754,8949};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {765,501,296,698,182,584,559,330,685,336,897,56,232,544,242,510,53,301,132,905,30,415,151,687,298,851,65,387,856,598,640,852,86,586};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 5050;

double ret = 948.5697381114564;

assertEquals(26, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase27 () {
int _var0[] = {988,6828,4669,4158,875,8683,777,9337,2303,7986,1225,8117,4192,1562,5588};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {593,37,609,573,914,134,345,771,174,347,118,397,346,706,772};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 5972;

double ret = 370.50625617117413;

assertEquals(27, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase28 () {
int _var0[] = {5559,978,2860,5339,2942,414,5202,4994,6556,4291,8102,574,5122,2104,7841,4925,9589,7710,5404,600,4216,513,3916,4909,1355,4763,7700};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {536,936,959,536,24,381,35,102,391,691,876,291,1,821,780,31,786,995,430,45,937,698,153,163,547,110,93};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 9831;

double ret = 5909.52316678749;

assertEquals(28, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase29 () {
int _var0[] = {1817,7332,858,600,7403,6890,9540,3701,7552,5516,5058,6315,2406,5542,236,3060,9364,7991,5833,9893,2860,2938,9996,2253,5383,3065,4948,2634,3047,3817,1645,2289,8904};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {243,246,313,895,388,225,459,265,978,781,693,216,431,80,520,43,359,315,852,292,116,495,881,494,917,40,513,673,803,218,955,730,775};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 8616;

double ret = 595.7875396125969;

assertEquals(29, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase30 () {
int _var0[] = {1870,2213,4734,7972,3449,7765,7050,5061,7549,7605,236,5311,4670,8693,1071,7913,5850,3652,2436,1481,5933,8876,1084,7084,6006,2604,6431,4900,5388,2308,254,83,8761,3419,2423,456,1946,1083,5838,2287,7175,6079,2643,2831,1336,8778,6858,7941,2807,9967};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {971,737,1,154,324,1,1,223,228,1,391,1,743,675,724,855,717,283,1,363,348,786,1,1,382,225,1,285,1,532,1,309,1,1,51,39,724,328,154,621,746,482,490,457,1,1,307,865,930,83};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 39;

double ret = 77987.45099512913;

assertEquals(30, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase31 () {
int _var0[] = {3605,2633,88,3868,484,3019,6488,6304,7902,2027,1827,4898,2974,1286,6756,804,8924,9777,719,2045,6682,6073,9718,6651,9431,9337,4436,9620,6015,1669,186,1513};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {648,633,451,1,146,431,157,874,828,671,545,327,673,434,683,15,151,365,33,315,885,820,534,520,72,110,717,271,68,176,559,713};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 5369;

double ret = 4556.826316446121;

assertEquals(31, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase32 () {
int _var0[] = {9042,7439,8447,1970,45,2161,8849,9961,7298,4588,4589,6351,707,9090,9266,352,7136,9443,528,2852,3456,8272,1803,8554,7649,6596,6333};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {1,1,60,1,1,1,862,1,1,675,1,266,609,1,1,427,1,1,1,1,1,1,1,232,430,384,739};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 2997;

double ret = 94615.28502419492;

assertEquals(32, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase33 () {
int _var0[] = {2125,8423,2458,6131,4918,878,7467,6000,4376,8586,1043,754,7571,7306,8353,8008,8942,6114,2087,422,9950,4325,5929,4931,6765,4402,2482,3376,6160,7431,9051,8587,2587,5522,4377};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {962,282,683,58,560,170,375,277,415,818,368,203,90,595,660,263,139,639,616,904,712,165,955,913,888,909,221,523,382,669,346,139,316,913,710};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 8504;

double ret = 659.6499947489211;

assertEquals(33, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase34 () {
int _var0[] = {5066,8988,1475,1320,6002,9828,3547,9974,8718,2824,9996,9673,2728,8223,3486,4336,3114,3714,749,1526,2115,3939,214,7865,9979,8700,3521,1124,6233};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {232,833,862,748,9,821,114,625,290,582,277,862,437,419,997,681,517,454,493,711,108,552,990,520,164,533,703,959,672};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 4385;

double ret = 1032.6679333828695;

assertEquals(34, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase35 () {
int _var0[] = {9015,1813,7365,1977,2402,9985,9411,9388,8963,3202,2237,7596,9515,6279,8388,5043,5947,1560,4486,9602,6925,7434,806,9531,9425,9513,5190,6266,6842,9644,2996,8433,9371,3486,7483,3981,9766,1479,5277,1118};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {583,815,909,900,810,52,233,405,848,272,142,974,258,778,679,882,336,513,424,927,136,374,985,277,190,462,271,880,768,918,876,703,113,859,745,680,112,952,631,552};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 3849;

double ret = 876.5370053520969;

assertEquals(35, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase36 () {
int _var0[] = {9501,8511,1322,3468,7652,906,3127,1610,6374,1086,4860,1947,614,4287};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {1,437,255,917,1,611,511,805,660,770,52,201,828,446};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 5908;

double ret = 17316.532437558133;

assertEquals(36, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase37 () {
int _var0[] = {7491};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {894};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 7158;

double ret = 11.589578519316133;

assertEquals(37, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase38 () {
int _var0[] = {3823,4503,1945,6065,7606,6313,5717,9674,6359,8659,7387,5034,2677,8867,2999,8134,829,3474,1135,6017,5421,3545,6057,1838,699,9364,6291,7777,7185,8382,2200,5096,6541,3878,8437,935,9837,8532,4499};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {497,576,933,383,744,845,416,727,37,408,694,352,360,139,501,637,172,57,422,570,353,734,296,663,576,614,77,223,52,317,317,970,152,534,735,316,630,46,366};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 7683;

double ret = 1096.9001851377095;

assertEquals(38, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase39 () {
int _var0[] = {9008,4362,7322,4608,236,7970,4783,3406,9199,4863,904,7195,1175,4741,2262,1999,2884,4822,7016,6897,2434,7500,2818,7606,5143,3821,2039,7485,8181};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {1,1,52,1,1,516,205,1,913,25,551,771,1,1,581,1,1,1,1,1,1,419,1,695,292,84,1,494,1};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 16;

double ret = 67132.14326884235;

assertEquals(39, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase40 () {
int _var0[] = {7397,7148,4316,3787,3669,8315,3877,3850,8963,3739,2624,2908,554,2489,2582,9828,16,3901,5218,8283,6523,4310,540,702,9938,6742,7162,9900,7674,1664,8990,4767,867,1184,4481,2444,4382,2916};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {1,1,1,947,1,1,194,1,1,842,963,1,1,1,1,1,896,1,1,1,951,1,982,1,854,1,287,1,1,61,1,935,229,1,1,356,973,1};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 2083;

double ret = 126442.75744362312;

assertEquals(40, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase41 () {
int _var0[] = {5457,2871,4321,2380,3922,8418,729,2377,424,2439,2290};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {827,290,439,295,561,382,813,316,278,267,535};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 7936;

double ret = 88.64675007146676;

assertEquals(41, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase42 () {
int _var0[] = {2186,3417,4153,7711,1437,5551,4706,1349,9229,9814,914,2367,2913,9563,4674,8772,9375,8515,7750,9171,9819,3859,3431,4706,353,1633,6723,4150,3043,5055,2206};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {975,536,400,270,142,336,51,485,998,167,490,615,499,685,139,215,65,865,225,950,959,606,714,4,82,771,725,693,247,847,781};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 1356;

double ret = 1776.1006165127742;

assertEquals(42, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase43 () {
int _var0[] = {1633,3578,2707,2489};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {220,24,436,764};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 4977;

double ret = 168.9514754823039;

assertEquals(43, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase44 () {
int _var0[] = {2928,2523,328,6475,4625,8488,978,4675,8837,4671,279,6643};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {158,967,449,230,918,499,108,656,364,453,306,103};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 9505;

double ret = 190.23788076796723;

assertEquals(44, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase45 () {
int _var0[] = {7853,1281,2567,112,7360,222,397,2085,3208};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {150,390,550,22,528,742,426,881,177};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 1784;

double ret = 101.2208892145542;

assertEquals(45, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase46 () {
int _var0[] = {4046,4600,8319,9219,5258,4670,4922,2294,2820,7808,9079,8356,1550,2192,8841,4034,9767};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {625,729,588,105,483,203,168,762,275,781,278,676,648,761,384,89,766};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 9078;

double ret = 333.45216024443437;

assertEquals(46, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase47 () {
int _var0[] = {3927,1645,9375};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {11,152,33};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 8233;

double ret = 689.0218038519076;

assertEquals(47, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase48 () {
int _var0[] = {1457,4810,3478,7889,585,2068,1914,5177,5440,7582,2279,2339,745,8447,2555,4635,3039,9745,8620,9080,3567,8548,8311,5255,5518,3736,3217,7596};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {825,567,552,250,759,211,136,852,583,401,240,87,248,98,638,441,410,825,962,189,823,997,42,45,773,382,830,563};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 4167;

double ret = 685.3659723970964;

assertEquals(48, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase49 () {
int _var0[] = {7270,5001,6735,4768,3295,7839,9554,2872,4214,612,1056,2268,9149,701,7533,4880,5512,437,7209,997,6001,2890,5753,3719,5368,225,7762,8850,7842,7665,3697,5731,6052,7565,915,9481};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {520,816,1,1,1,538,1,1,1,431,1,498,689,119,125,1,998,1,1,17,1,1,277,367,1,1,163,1,10,1,1,255,747,227,1,1};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 3761;

double ret = 91223.06605478864;

assertEquals(49, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase50 () {
int _var0[] = {9236,7065,2283,506,6432,9812,3133,1397,7052,3729,2556,9954,1367,6440,5141,3091,2879,1346,7080,1036,7503,7775,433,7579,6520,2287,1971,3879,1725,8200,1830,2774,3850,7509,8531,7493,1511,9399,9679,2124,791,3432};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {956,799,481,194,993,444,571,986,815,910,98,847,650,487,419,434,410,812,374,751,307,134,134,955,758,73,932,360,135,588,218,936,674,494,157,556,881,292,851,890,886,912};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 9756;

double ret = 501.6129192127166;

assertEquals(50, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase51 () {
int _var0[] = {3,54,654};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {34,5,46};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 3432;

double ret = 86.75018655555829;

assertEquals(51, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase52 () {
int _var0[] = {304,219,123,304,219,123,304,219,123,304,219,123,304,219,123,304,219,123,304,219,123,304,219,123,304,219,123,304,219,123,305,219,123,304,219,122,14,199};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {281,943,281,943,281,943,287,943,281,943,281,941,281,943,281,943,281,943,281,943,281,943,281,943,281,943,281,943,281,943,781,943,281,943,281,943,199,111};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 7182;

double ret = 23.04520935704459;

assertEquals(52, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase53 () {
int _var0[] = {31,213,123,512,11,1,1234,31,213,123,512,11,1,1234,31,213,123,512,11,1,1234,31,213,123,512,11,1,1234,1,12,53,23,64,23,77,1,5,5,5,1,5,12,3,4,51,23,4,1,2,34};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {2,4,35,31,213,123,512,11,1,31,213,123,512,11,1,31,213,123,512,11,1,32,2,34,5,3,123,42,86,456,34,2,1,5,3,4,1,2,4,5,2,12,17,34,2,3,434,45,34,717};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 9989;

double ret = 2115.4800249869286;

assertEquals(53, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase54 () {
int _var0[] = {4241,2766,4395,7991,4005,6839,3104,2672,3164,7427,1976,2763,705,6054,7020,6306,8958,7210,8396,3219,2838,5454,4548,2046,6859,8199,6422,4791,5151,7005,6941,1569,7782,9360,6699,9869,2691,2390,5418,1599,6249,9701,154,4751,7082,2687,5445,5531,7133,7973};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {525,85,373,213,496,949,592,722,737,617,992,31,137,468,666,155,172,208,957,120,519,168,588,804,863,52,70,992,546,528,265,61,997,561,593,765,108,124,397,168,758,746,413,164,763,396,99,917,376,347};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 3665;

double ret = 1083.9961173400802;

assertEquals(54, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase55 () {
int _var0[] = {10000,1};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {1,1000};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 10000;

double ret = 10009.994999966919;

assertEquals(55, ret, solution.optimalTravel(var0, var1, var2));
}

void testCase56 () {
int _var0[] = {1,10000};
vector <int> var0 (_var0, _var0 + (sizeof(_var0) / sizeof(_var0[0])));

int _var1[] = {1000,1};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

int var2 = 1000;

double ret = 10000.9950005038;

assertEquals(56, ret, solution.optimalTravel(var0, var1, var2));
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
			default: cerr << "No such test case: " << testCase << endl; exit (1);
		}
		End = clock();
		tempo = (double) (End - Begin) / CLOCKS_PER_SEC;
		
		printf (" in %.4lfs\n", tempo);
	}

};

bool RemoteRoverTest::passed;

int main(int argc, char *argv[]) {
	int cnt = 0, cntAc = 0, caso = -1;
	bool passedAll = true;
	
	if (argc > 1) {
		caso = atoi (argv[1]);
		if (caso == 57)
			return 100;
	}
	
    for (int i = 0; i < 57; i++) {
    	if (caso != -1 && caso != i) continue;
    	
		cnt++;
		RemoteRoverTest *test = new RemoteRoverTest ();
		test->runTest(i);
		passedAll &= RemoteRoverTest::passed;
		if (RemoteRoverTest::passed) cntAc++;
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
