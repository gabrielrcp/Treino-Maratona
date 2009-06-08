#define TEST

#include "PackingShapes.cpp"
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



class PackingShapesTest {

	public: static bool passed;
	
	    static void writeTo(std::ostream& out, const vector<string>& v) {
        out << '{';
        for (unsigned int i = 0; i < v.size(); i++) {
            out << '"' << v[i] << '"';
            if (i + 1 != v.size()) out << ", ";
        }
        out << '}';
    }

    static void assertEquals(int testCase, const vector<string>& expected, const vector<string>& actual) {
        if (expected == actual) {
        	passed = true;
            cout << "Test case " << testCase << " PASSED!";
        } else {
        	passed = false;
            cout << "Test case " << testCase << " FAILED! Expected: <";
            writeTo(cout, expected);
            cout << "> but was: <";
            writeTo(cout, actual);
            cout << '>';
        }
    }


    PackingShapes solution;
    
    

void testCase0 () {
int var0 = 100;

int var1 = 100;

string _var2[] = {"RECTANGLE 3 3","RECTANGLE 3 230","RECTANGLE 140 1"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "NO", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(0, ret, solution.tryToFit(var0, var1, var2));
}

void testCase1 () {
int var0 = 100;

int var1 = 100;

string _var2[] = {"RECTANGLE 100 100","CIRCLE 50"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(1, ret, solution.tryToFit(var0, var1, var2));
}

void testCase2 () {
int var0 = 10;

int var1 = 100;

string _var2[] = {"RECTANGLE 99 9","CIRCLE 22"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(2, ret, solution.tryToFit(var0, var1, var2));
}

void testCase3 () {
int var0 = 170;

int var1 = 900;

string _var2[] = {"RECTANGLE 200 700","RECTANGLE 3 910","RECTANGLE 1000 7","CIRCLE 5","CIRCLE 50","CIRCLE 500","RECTANGLE 1000 99"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "YES", "NO", "YES", "YES", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(3, ret, solution.tryToFit(var0, var1, var2));
}

void testCase4 () {
int var0 = 1;

int var1 = 1;

string _var2[] = {"RECTANGLE 1 1","RECTANGLE 2 1","RECTANGLE 1 2","RECTANGLE 2 2","RECTANGLE 1 3","RECTANGLE 2 3","RECTANGLE 3 3","CIRCLE 1","CIRCLE 2","CIRCLE 3","RECTANGLE 1000 1000","CIRCLE 1000"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(4, ret, solution.tryToFit(var0, var1, var2));
}

void testCase5 () {
int var0 = 2;

int var1 = 2;

string _var2[] = {"CIRCLE 1","CIRCLE 2","CIRCLE 3","CIRCLE 4","CIRCLE 5","RECTANGLE 1 1","RECTANGLE 2 1","RECTANGLE 1 2","RECTANGLE 2 2","RECTANGLE 1 3","RECTANGLE 2 3","RECTANGLE 3 3","RECTANGLE 10 10"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "YES", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(5, ret, solution.tryToFit(var0, var1, var2));
}

void testCase6 () {
int var0 = 1000;

int var1 = 1000;

string _var2[] = {"CIRCLE 1","CIRCLE 490","CIRCLE 500","CIRCLE 501","RECTANGLE 2 5","RECTANGLE 999 997"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "YES", "NO", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(6, ret, solution.tryToFit(var0, var1, var2));
}

void testCase7 () {
int var0 = 10;

int var1 = 10;

string _var2[] = {"RECTANGLE 11 11","RECTANGLE 11 10","RECTANGLE 11 12","RECTANGLE 10 11","RECTANGLE 11 10","RECTANGLE 11 12","RECTANGLE 11 12","RECTANGLE 11 12","RECTANGLE 10 10","RECTANGLE 11 11","RECTANGLE 12 12","RECTANGLE 10 10","RECTANGLE 12 12","RECTANGLE 11 12","RECTANGLE 11 11","RECTANGLE 10 12","RECTANGLE 10 10","RECTANGLE 10 12","RECTANGLE 11 11","RECTANGLE 11 11","RECTANGLE 10 10","RECTANGLE 12 10","RECTANGLE 11 12","RECTANGLE 12 12","RECTANGLE 10 12","RECTANGLE 11 12","RECTANGLE 12 11","RECTANGLE 10 12","RECTANGLE 12 12","RECTANGLE 11 11","RECTANGLE 10 10","RECTANGLE 10 12","RECTANGLE 12 12","RECTANGLE 10 11","RECTANGLE 12 11","RECTANGLE 10 10","RECTANGLE 10 10","RECTANGLE 10 12","RECTANGLE 12 12","RECTANGLE 12 10","RECTANGLE 10 11","RECTANGLE 12 10","RECTANGLE 10 12","RECTANGLE 12 10","RECTANGLE 11 12","RECTANGLE 10 10","RECTANGLE 10 12","RECTANGLE 11 11","RECTANGLE 10 11","RECTANGLE 12 10"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(7, ret, solution.tryToFit(var0, var1, var2));
}

void testCase8 () {
int var0 = 100;

int var1 = 100;

string _var2[] = {"RECTANGLE 97 108","RECTANGLE 97 107","RECTANGLE 102 98","RECTANGLE 110 104","RECTANGLE 90 93","RECTANGLE 98 103","RECTANGLE 92 94","RECTANGLE 103 110","RECTANGLE 110 90","RECTANGLE 98 103","RECTANGLE 93 109","RECTANGLE 94 93","RECTANGLE 101 93","RECTANGLE 95 93","RECTANGLE 109 105","RECTANGLE 100 108","RECTANGLE 102 95","RECTANGLE 104 105","RECTANGLE 98 91","RECTANGLE 95 101","RECTANGLE 93 97","RECTANGLE 101 101","RECTANGLE 101 93","RECTANGLE 93 93","RECTANGLE 107 100","RECTANGLE 99 100","RECTANGLE 101 108","RECTANGLE 109 101","RECTANGLE 102 110","RECTANGLE 104 94","RECTANGLE 91 101","RECTANGLE 104 92","RECTANGLE 107 103","RECTANGLE 103 97","RECTANGLE 106 95","RECTANGLE 100 108","RECTANGLE 98 107","RECTANGLE 90 90","RECTANGLE 91 107","RECTANGLE 97 93","RECTANGLE 101 106","RECTANGLE 103 104","RECTANGLE 92 92","RECTANGLE 91 102","RECTANGLE 106 104","RECTANGLE 94 104","RECTANGLE 106 105","RECTANGLE 95 107","RECTANGLE 93 102","RECTANGLE 105 108"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "YES", "NO", "YES", "NO", "NO", "NO", "NO", "YES", "NO", "YES", "NO", "NO", "NO", "NO", "YES", "NO", "YES", "NO", "NO", "YES", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "YES", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(8, ret, solution.tryToFit(var0, var1, var2));
}

void testCase9 () {
int var0 = 100;

int var1 = 100;

string _var2[] = {"RECTANGLE 101 102","RECTANGLE 101 101","RECTANGLE 102 102","RECTANGLE 101 102","RECTANGLE 101 101","RECTANGLE 100 100","RECTANGLE 100 100","RECTANGLE 100 102","RECTANGLE 100 102","RECTANGLE 102 100","RECTANGLE 102 102","RECTANGLE 102 101","RECTANGLE 100 101","RECTANGLE 102 102","RECTANGLE 101 102","RECTANGLE 102 100","RECTANGLE 102 100","RECTANGLE 100 101","RECTANGLE 101 100","RECTANGLE 102 102","RECTANGLE 100 102","RECTANGLE 100 102","RECTANGLE 102 101","RECTANGLE 101 101","RECTANGLE 101 102","RECTANGLE 101 100","RECTANGLE 100 101","RECTANGLE 102 101","RECTANGLE 102 100","RECTANGLE 100 101","RECTANGLE 102 100","RECTANGLE 101 102","RECTANGLE 102 100","RECTANGLE 100 102","RECTANGLE 102 100","RECTANGLE 100 100","RECTANGLE 102 102","RECTANGLE 101 100","RECTANGLE 102 102","RECTANGLE 102 100","RECTANGLE 101 100","RECTANGLE 102 101","RECTANGLE 100 101","RECTANGLE 102 101","RECTANGLE 101 102","RECTANGLE 100 100","RECTANGLE 100 101","RECTANGLE 101 102","RECTANGLE 102 102","RECTANGLE 100 102"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(9, ret, solution.tryToFit(var0, var1, var2));
}

void testCase10 () {
int var0 = 1000;

int var1 = 1000;

string _var2[] = {"RECTANGLE 1000 1000","RECTANGLE 994 1000","RECTANGLE 100 1000","RECTANGLE 1000 1000","RECTANGLE 995 1000","RECTANGLE 1000 1000","RECTANGLE 1000 997","RECTANGLE 992 997","RECTANGLE 994 1000","RECTANGLE 990 996"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(10, ret, solution.tryToFit(var0, var1, var2));
}

void testCase11 () {
int var0 = 90;

int var1 = 90;

string _var2[] = {"RECTANGLE 101 100","RECTANGLE 100 101","RECTANGLE 100 100","RECTANGLE 100 100","RECTANGLE 102 101","RECTANGLE 101 100","RECTANGLE 102 101","RECTANGLE 100 100","RECTANGLE 100 101","RECTANGLE 100 102","RECTANGLE 100 102","RECTANGLE 102 100","RECTANGLE 101 102","RECTANGLE 101 101","RECTANGLE 102 100","RECTANGLE 101 102","RECTANGLE 10 100","RECTANGLE 11 102","RECTANGLE 12 101","RECTANGLE 10 100","RECTANGLE 10 101","RECTANGLE 10 102","RECTANGLE 12 100","RECTANGLE 11 102","RECTANGLE 102 12","RECTANGLE 102 11","RECTANGLE 100 12","RECTANGLE 101 11","RECTANGLE 102 12","RECTANGLE 100 10","RECTANGLE 102 12","RECTANGLE 100 12","RECTANGLE 102 11","RECTANGLE 102 12","RECTANGLE 102 11","RECTANGLE 100 10","RECTANGLE 102 10","RECTANGLE 100 11","RECTANGLE 101 12","RECTANGLE 101 12","RECTANGLE 11 100","RECTANGLE 12 101","RECTANGLE 10 102","RECTANGLE 11 102","RECTANGLE 12 100","RECTANGLE 10 102","RECTANGLE 11 100","RECTANGLE 12 100","RECTANGLE 10 100","RECTANGLE 12 102"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(11, ret, solution.tryToFit(var0, var1, var2));
}

void testCase12 () {
int var0 = 900;

int var1 = 900;

string _var2[] = {"RECTANGLE 999 999","RECTANGLE 995 994","RECTANGLE 1000 1000","RECTANGLE 94 990","RECTANGLE 103 992","RECTANGLE 105 996","RECTANGLE 106 1000","RECTANGLE 103 1000","RECTANGLE 103 1000","RECTANGLE 91 993","RECTANGLE 110 1000","RECTANGLE 990 99","RECTANGLE 997 95","RECTANGLE 992 93","RECTANGLE 1000 92","RECTANGLE 999 92","RECTANGLE 994 96","RECTANGLE 1000 103","RECTANGLE 1000 109","RECTANGLE 990 92","RECTANGLE 997 93","RECTANGLE 1000 103","RECTANGLE 994 90","RECTANGLE 1000 101","RECTANGLE 1000 107","RECTANGLE 998 109","RECTANGLE 995 101","RECTANGLE 106 996","RECTANGLE 99 1000","RECTANGLE 103 1000","RECTANGLE 108 996","RECTANGLE 103 990","RECTANGLE 103 992","RECTANGLE 90 1000","RECTANGLE 101 993","RECTANGLE 97 1000","RECTANGLE 99 1000"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(12, ret, solution.tryToFit(var0, var1, var2));
}

void testCase13 () {
int var0 = 14;

int var1 = 10;

string _var2[] = {"RECTANGLE 11 21","RECTANGLE 11 21","RECTANGLE 11 22","RECTANGLE 11 21","RECTANGLE 11 21","RECTANGLE 11 20","RECTANGLE 12 20","RECTANGLE 11 22","RECTANGLE 20 12","RECTANGLE 22 12","RECTANGLE 22 11","RECTANGLE 21 11","RECTANGLE 21 10","RECTANGLE 22 12","RECTANGLE 22 10","RECTANGLE 22 12","RECTANGLE 16 11","RECTANGLE 16 11","RECTANGLE 15 10","RECTANGLE 16 12","RECTANGLE 16 12","RECTANGLE 15 10","RECTANGLE 15 10","RECTANGLE 15 11","RECTANGLE 11 15","RECTANGLE 10 17","RECTANGLE 10 15","RECTANGLE 11 17","RECTANGLE 11 15","RECTANGLE 10 15","RECTANGLE 11 17","RECTANGLE 11 17","RECTANGLE 22 15","RECTANGLE 20 15","RECTANGLE 20 17","RECTANGLE 22 17","RECTANGLE 20 16","RECTANGLE 20 17","RECTANGLE 21 16","RECTANGLE 22 15","RECTANGLE 16 20","RECTANGLE 16 22","RECTANGLE 17 22","RECTANGLE 17 20","RECTANGLE 16 21","RECTANGLE 15 20","RECTANGLE 15 22","RECTANGLE 15 22","RECTANGLE 17 22","RECTANGLE 17 20"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(13, ret, solution.tryToFit(var0, var1, var2));
}

void testCase14 () {
int var0 = 140;

int var1 = 100;

string _var2[] = {"RECTANGLE 102 204","RECTANGLE 95 201","RECTANGLE 110 208","RECTANGLE 92 201","RECTANGLE 93 191","RECTANGLE 104 191","RECTANGLE 107 191","RECTANGLE 100 205","RECTANGLE 208 110","RECTANGLE 202 106","RECTANGLE 207 107","RECTANGLE 204 103","RECTANGLE 205 102","RECTANGLE 196 92","RECTANGLE 193 93","RECTANGLE 205 106","RECTANGLE 144 105","RECTANGLE 150 110","RECTANGLE 148 93","RECTANGLE 145 102","RECTANGLE 154 102","RECTANGLE 151 109","RECTANGLE 151 100","RECTANGLE 149 109","RECTANGLE 105 146","RECTANGLE 93 159","RECTANGLE 101 151","RECTANGLE 90 155","RECTANGLE 108 143","RECTANGLE 94 145","RECTANGLE 90 159","RECTANGLE 104 160","RECTANGLE 207 144","RECTANGLE 197 143","RECTANGLE 204 143","RECTANGLE 203 150","RECTANGLE 198 145","RECTANGLE 205 143","RECTANGLE 192 159","RECTANGLE 193 141","RECTANGLE 160 205","RECTANGLE 143 196","RECTANGLE 159 199","RECTANGLE 152 194","RECTANGLE 149 204","RECTANGLE 153 207","RECTANGLE 154 197","RECTANGLE 149 196","RECTANGLE 147 198","RECTANGLE 151 206"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(14, ret, solution.tryToFit(var0, var1, var2));
}

void testCase15 () {
int var0 = 15;

int var1 = 10;

string _var2[] = {"RECTANGLE 10 21","RECTANGLE 10 20","RECTANGLE 12 20","RECTANGLE 10 20","RECTANGLE 12 21","RECTANGLE 11 20","RECTANGLE 11 22","RECTANGLE 12 21","RECTANGLE 20 12","RECTANGLE 22 10","RECTANGLE 20 11","RECTANGLE 20 10","RECTANGLE 21 10","RECTANGLE 20 10","RECTANGLE 22 10","RECTANGLE 22 10","RECTANGLE 17 10","RECTANGLE 15 12","RECTANGLE 16 11","RECTANGLE 15 11","RECTANGLE 16 10","RECTANGLE 15 12","RECTANGLE 16 12","RECTANGLE 17 10","RECTANGLE 11 15","RECTANGLE 11 17","RECTANGLE 12 16","RECTANGLE 12 17","RECTANGLE 10 16","RECTANGLE 11 15","RECTANGLE 11 17","RECTANGLE 10 15","RECTANGLE 20 15","RECTANGLE 22 17","RECTANGLE 20 16","RECTANGLE 22 17","RECTANGLE 22 17","RECTANGLE 22 15","RECTANGLE 20 16","RECTANGLE 21 16","RECTANGLE 15 21","RECTANGLE 16 20","RECTANGLE 15 20","RECTANGLE 16 21","RECTANGLE 17 21","RECTANGLE 16 20","RECTANGLE 16 20","RECTANGLE 16 20","RECTANGLE 17 21","RECTANGLE 15 21"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(15, ret, solution.tryToFit(var0, var1, var2));
}

void testCase16 () {
int var0 = 150;

int var1 = 100;

string _var2[] = {"RECTANGLE 101 199","RECTANGLE 108 208","RECTANGLE 91 203","RECTANGLE 93 208","RECTANGLE 91 197","RECTANGLE 97 198","RECTANGLE 90 205","RECTANGLE 106 199","RECTANGLE 206 103","RECTANGLE 205 102","RECTANGLE 197 102","RECTANGLE 205 98","RECTANGLE 202 101","RECTANGLE 204 92","RECTANGLE 209 98","RECTANGLE 205 90","RECTANGLE 156 99","RECTANGLE 160 103","RECTANGLE 150 107","RECTANGLE 142 93","RECTANGLE 151 99","RECTANGLE 141 99","RECTANGLE 158 99","RECTANGLE 140 108","RECTANGLE 97 151","RECTANGLE 90 155","RECTANGLE 90 154","RECTANGLE 92 155","RECTANGLE 106 152","RECTANGLE 108 154","RECTANGLE 105 152","RECTANGLE 109 153","RECTANGLE 195 150","RECTANGLE 195 158","RECTANGLE 209 155","RECTANGLE 191 147","RECTANGLE 206 148","RECTANGLE 207 143","RECTANGLE 190 151","RECTANGLE 210 155","RECTANGLE 150 197","RECTANGLE 159 210","RECTANGLE 154 198","RECTANGLE 140 209","RECTANGLE 153 197","RECTANGLE 159 208","RECTANGLE 148 195","RECTANGLE 153 207","RECTANGLE 153 203","RECTANGLE 145 208"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(16, ret, solution.tryToFit(var0, var1, var2));
}

void testCase17 () {
int var0 = 30;

int var1 = 84;

string _var2[] = {"RECTANGLE 16 80","RECTANGLE 16 79","RECTANGLE 17 78","RECTANGLE 15 80","RECTANGLE 17 80","RECTANGLE 16 80","RECTANGLE 16 79","RECTANGLE 16 78","RECTANGLE 80 17","RECTANGLE 78 17","RECTANGLE 80 15","RECTANGLE 78 15","RECTANGLE 78 15","RECTANGLE 79 17","RECTANGLE 80 16","RECTANGLE 80 17","RECTANGLE 38 17","RECTANGLE 39 15","RECTANGLE 39 15","RECTANGLE 39 16","RECTANGLE 37 15","RECTANGLE 38 16","RECTANGLE 38 17","RECTANGLE 39 17","RECTANGLE 17 38","RECTANGLE 17 39","RECTANGLE 15 37","RECTANGLE 15 37","RECTANGLE 17 38","RECTANGLE 15 39","RECTANGLE 16 37","RECTANGLE 17 39","RECTANGLE 79 39","RECTANGLE 80 39","RECTANGLE 78 38","RECTANGLE 79 39","RECTANGLE 78 39","RECTANGLE 80 37","RECTANGLE 78 39","RECTANGLE 79 38","RECTANGLE 38 78","RECTANGLE 37 79","RECTANGLE 39 80","RECTANGLE 38 79","RECTANGLE 37 80","RECTANGLE 37 79","RECTANGLE 39 80","RECTANGLE 39 80","RECTANGLE 39 78","RECTANGLE 38 80"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(17, ret, solution.tryToFit(var0, var1, var2));
}

void testCase18 () {
int var0 = 300;

int var1 = 840;

string _var2[] = {"RECTANGLE 154 774","RECTANGLE 143 774","RECTANGLE 144 771","RECTANGLE 147 773","RECTANGLE 144 784","RECTANGLE 158 788","RECTANGLE 148 775","RECTANGLE 147 783","RECTANGLE 775 160","RECTANGLE 774 140","RECTANGLE 787 150","RECTANGLE 782 150","RECTANGLE 780 145","RECTANGLE 775 152","RECTANGLE 779 153","RECTANGLE 787 159","RECTANGLE 362 143","RECTANGLE 364 158","RECTANGLE 360 144","RECTANGLE 377 149","RECTANGLE 367 142","RECTANGLE 368 154","RECTANGLE 365 155","RECTANGLE 374 153","RECTANGLE 154 368","RECTANGLE 158 376","RECTANGLE 145 368","RECTANGLE 153 367","RECTANGLE 160 373","RECTANGLE 146 376","RECTANGLE 152 368","RECTANGLE 149 360","RECTANGLE 787 375","RECTANGLE 787 371","RECTANGLE 770 375","RECTANGLE 788 373","RECTANGLE 775 367","RECTANGLE 790 363","RECTANGLE 786 370","RECTANGLE 786 374","RECTANGLE 369 777","RECTANGLE 375 784","RECTANGLE 379 783","RECTANGLE 365 775","RECTANGLE 379 786","RECTANGLE 364 781","RECTANGLE 370 781","RECTANGLE 363 781","RECTANGLE 362 776","RECTANGLE 360 790"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(18, ret, solution.tryToFit(var0, var1, var2));
}

void testCase19 () {
int var0 = 21;

int var1 = 55;

string _var2[] = {"RECTANGLE 20 72","RECTANGLE 20 70","RECTANGLE 19 70","RECTANGLE 21 70","RECTANGLE 19 70","RECTANGLE 20 70","RECTANGLE 19 71","RECTANGLE 19 70","RECTANGLE 70 21","RECTANGLE 71 21","RECTANGLE 70 21","RECTANGLE 72 21","RECTANGLE 70 20","RECTANGLE 72 21","RECTANGLE 72 21","RECTANGLE 72 21","RECTANGLE 76 19","RECTANGLE 76 20","RECTANGLE 76 21","RECTANGLE 75 19","RECTANGLE 77 19","RECTANGLE 77 19","RECTANGLE 75 21","RECTANGLE 77 21","RECTANGLE 20 75","RECTANGLE 19 76","RECTANGLE 20 77","RECTANGLE 20 75","RECTANGLE 21 76","RECTANGLE 20 75","RECTANGLE 20 77","RECTANGLE 19 75","RECTANGLE 71 77","RECTANGLE 72 77","RECTANGLE 70 76","RECTANGLE 72 76","RECTANGLE 71 77","RECTANGLE 70 76","RECTANGLE 70 76","RECTANGLE 72 77","RECTANGLE 76 72","RECTANGLE 77 71","RECTANGLE 76 71","RECTANGLE 77 70","RECTANGLE 76 72","RECTANGLE 77 72","RECTANGLE 75 70","RECTANGLE 75 72","RECTANGLE 77 70","RECTANGLE 76 72"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(19, ret, solution.tryToFit(var0, var1, var2));
}

void testCase20 () {
int var0 = 210;

int var1 = 550;

string _var2[] = {"RECTANGLE 195 705","RECTANGLE 188 703","RECTANGLE 200 691","RECTANGLE 192 698","RECTANGLE 183 704","RECTANGLE 194 694","RECTANGLE 194 709","RECTANGLE 200 706","RECTANGLE 705 183","RECTANGLE 708 183","RECTANGLE 698 197","RECTANGLE 695 185","RECTANGLE 692 189","RECTANGLE 705 200","RECTANGLE 707 197","RECTANGLE 701 191","RECTANGLE 743 190","RECTANGLE 751 200","RECTANGLE 745 182","RECTANGLE 754 181","RECTANGLE 745 188","RECTANGLE 745 188","RECTANGLE 741 199","RECTANGLE 760 182","RECTANGLE 183 756","RECTANGLE 190 758","RECTANGLE 180 749","RECTANGLE 199 755","RECTANGLE 192 742","RECTANGLE 198 753","RECTANGLE 184 749","RECTANGLE 199 748","RECTANGLE 695 747","RECTANGLE 698 747","RECTANGLE 696 751","RECTANGLE 707 741","RECTANGLE 697 751","RECTANGLE 697 760","RECTANGLE 692 749","RECTANGLE 692 747","RECTANGLE 742 695","RECTANGLE 755 703","RECTANGLE 745 692","RECTANGLE 743 703","RECTANGLE 745 706","RECTANGLE 744 690","RECTANGLE 748 697","RECTANGLE 755 690","RECTANGLE 745 702","RECTANGLE 742 692"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(20, ret, solution.tryToFit(var0, var1, var2));
}

void testCase21 () {
int var0 = 33;

int var1 = 80;

string _var2[] = {"RECTANGLE 90 42","RECTANGLE 91 44","RECTANGLE 91 43","RECTANGLE 90 43","RECTANGLE 89 43","RECTANGLE 90 43","RECTANGLE 89 44","RECTANGLE 91 43","RECTANGLE 42 90","RECTANGLE 44 91","RECTANGLE 44 90","RECTANGLE 44 90","RECTANGLE 43 89","RECTANGLE 42 91","RECTANGLE 44 89","RECTANGLE 42 89","RECTANGLE 89 91","RECTANGLE 87 89","RECTANGLE 89 91","RECTANGLE 88 91","RECTANGLE 87 91","RECTANGLE 89 89","RECTANGLE 89 91","RECTANGLE 87 90","RECTANGLE 91 88","RECTANGLE 91 87","RECTANGLE 90 88","RECTANGLE 91 88","RECTANGLE 91 89","RECTANGLE 89 87","RECTANGLE 90 89","RECTANGLE 90 89","RECTANGLE 42 89","RECTANGLE 43 88","RECTANGLE 42 89","RECTANGLE 44 87","RECTANGLE 43 89","RECTANGLE 44 88","RECTANGLE 42 87","RECTANGLE 43 87","RECTANGLE 87 44","RECTANGLE 89 43","RECTANGLE 87 43","RECTANGLE 88 44","RECTANGLE 87 42","RECTANGLE 89 44","RECTANGLE 88 43","RECTANGLE 87 43","RECTANGLE 87 43","RECTANGLE 88 42"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(21, ret, solution.tryToFit(var0, var1, var2));
}

void testCase22 () {
int var0 = 330;

int var1 = 800;

string _var2[] = {"RECTANGLE 886 417","RECTANGLE 896 410","RECTANGLE 891 414","RECTANGLE 900 425","RECTANGLE 892 410","RECTANGLE 885 430","RECTANGLE 892 422","RECTANGLE 900 412","RECTANGLE 430 893","RECTANGLE 423 881","RECTANGLE 417 891","RECTANGLE 420 900","RECTANGLE 416 883","RECTANGLE 418 892","RECTANGLE 413 886","RECTANGLE 421 899","RECTANGLE 879 887","RECTANGLE 869 886","RECTANGLE 860 888","RECTANGLE 868 888","RECTANGLE 865 890","RECTANGLE 880 891","RECTANGLE 872 896","RECTANGLE 868 899","RECTANGLE 898 871","RECTANGLE 900 880","RECTANGLE 899 865","RECTANGLE 886 869","RECTANGLE 899 864","RECTANGLE 888 872","RECTANGLE 890 861","RECTANGLE 886 878","RECTANGLE 413 867","RECTANGLE 425 875","RECTANGLE 411 862","RECTANGLE 420 860","RECTANGLE 419 866","RECTANGLE 411 870","RECTANGLE 418 860","RECTANGLE 421 868","RECTANGLE 867 414","RECTANGLE 867 418","RECTANGLE 876 413","RECTANGLE 865 421","RECTANGLE 862 424","RECTANGLE 874 423","RECTANGLE 870 423","RECTANGLE 878 430","RECTANGLE 875 422","RECTANGLE 872 420"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(22, ret, solution.tryToFit(var0, var1, var2));
}

void testCase23 () {
int var0 = 24;

int var1 = 51;

string _var2[] = {"RECTANGLE 93 35","RECTANGLE 94 35","RECTANGLE 94 36","RECTANGLE 92 35","RECTANGLE 93 34","RECTANGLE 94 34","RECTANGLE 92 34","RECTANGLE 92 34","RECTANGLE 36 93","RECTANGLE 35 94","RECTANGLE 35 94","RECTANGLE 35 92","RECTANGLE 34 92","RECTANGLE 35 93","RECTANGLE 36 92","RECTANGLE 35 94","RECTANGLE 34 93","RECTANGLE 36 92","RECTANGLE 36 93","RECTANGLE 36 92","RECTANGLE 34 93","RECTANGLE 35 93","RECTANGLE 35 93","RECTANGLE 34 93","RECTANGLE 92 35","RECTANGLE 93 36","RECTANGLE 94 36","RECTANGLE 92 34","RECTANGLE 93 36","RECTANGLE 92 36","RECTANGLE 93 36","RECTANGLE 93 36","RECTANGLE 35 36","RECTANGLE 34 35","RECTANGLE 35 34","RECTANGLE 34 36","RECTANGLE 35 34","RECTANGLE 35 35","RECTANGLE 35 34","RECTANGLE 35 34","RECTANGLE 36 36","RECTANGLE 36 34","RECTANGLE 35 36","RECTANGLE 34 36","RECTANGLE 36 34","RECTANGLE 36 34","RECTANGLE 34 35","RECTANGLE 35 36","RECTANGLE 34 35","RECTANGLE 36 36"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(23, ret, solution.tryToFit(var0, var1, var2));
}

void testCase24 () {
int var0 = 240;

int var1 = 510;

string _var2[] = {"RECTANGLE 922 336","RECTANGLE 919 348","RECTANGLE 912 343","RECTANGLE 912 350","RECTANGLE 918 346","RECTANGLE 910 343","RECTANGLE 912 344","RECTANGLE 924 336","RECTANGLE 339 928","RECTANGLE 331 928","RECTANGLE 346 929","RECTANGLE 344 914","RECTANGLE 337 923","RECTANGLE 336 925","RECTANGLE 339 918","RECTANGLE 344 929","RECTANGLE 344 929","RECTANGLE 341 910","RECTANGLE 350 924","RECTANGLE 339 921","RECTANGLE 334 918","RECTANGLE 331 920","RECTANGLE 344 914","RECTANGLE 332 923","RECTANGLE 920 332","RECTANGLE 910 331","RECTANGLE 915 336","RECTANGLE 927 343","RECTANGLE 917 343","RECTANGLE 929 331","RECTANGLE 928 344","RECTANGLE 922 340","RECTANGLE 340 341","RECTANGLE 335 331","RECTANGLE 342 339","RECTANGLE 345 342","RECTANGLE 331 344","RECTANGLE 349 345","RECTANGLE 337 343","RECTANGLE 344 349","RECTANGLE 350 346","RECTANGLE 350 342","RECTANGLE 334 332","RECTANGLE 343 344","RECTANGLE 345 342","RECTANGLE 333 339","RECTANGLE 349 340","RECTANGLE 350 344","RECTANGLE 343 336","RECTANGLE 344 332"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(24, ret, solution.tryToFit(var0, var1, var2));
}

void testCase25 () {
int var0 = 51;

int var1 = 62;

string _var2[] = {"RECTANGLE 87 21","RECTANGLE 87 21","RECTANGLE 87 21","RECTANGLE 85 20","RECTANGLE 87 21","RECTANGLE 85 21","RECTANGLE 85 21","RECTANGLE 87 21","RECTANGLE 20 86","RECTANGLE 21 86","RECTANGLE 20 85","RECTANGLE 21 86","RECTANGLE 19 86","RECTANGLE 20 86","RECTANGLE 19 87","RECTANGLE 20 86","RECTANGLE 64 85","RECTANGLE 63 86","RECTANGLE 65 86","RECTANGLE 63 85","RECTANGLE 63 87","RECTANGLE 65 86","RECTANGLE 63 86","RECTANGLE 65 87","RECTANGLE 85 63","RECTANGLE 86 63","RECTANGLE 86 65","RECTANGLE 85 63","RECTANGLE 85 65","RECTANGLE 86 63","RECTANGLE 86 64","RECTANGLE 86 65","RECTANGLE 20 63","RECTANGLE 19 65","RECTANGLE 19 64","RECTANGLE 20 63","RECTANGLE 21 64","RECTANGLE 21 63","RECTANGLE 19 63","RECTANGLE 20 65","RECTANGLE 65 19","RECTANGLE 64 21","RECTANGLE 64 20","RECTANGLE 63 20","RECTANGLE 65 20","RECTANGLE 65 21","RECTANGLE 65 21","RECTANGLE 63 21","RECTANGLE 64 20","RECTANGLE 63 19"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(25, ret, solution.tryToFit(var0, var1, var2));
}

void testCase26 () {
int var0 = 510;

int var1 = 620;

string _var2[] = {"RECTANGLE 850 191","RECTANGLE 849 200","RECTANGLE 850 184","RECTANGLE 841 185","RECTANGLE 854 181","RECTANGLE 855 193","RECTANGLE 849 197","RECTANGLE 844 199","RECTANGLE 198 842","RECTANGLE 190 853","RECTANGLE 193 846","RECTANGLE 183 850","RECTANGLE 187 856","RECTANGLE 189 843","RECTANGLE 197 846","RECTANGLE 198 852","RECTANGLE 630 844","RECTANGLE 628 846","RECTANGLE 630 860","RECTANGLE 620 847","RECTANGLE 638 843","RECTANGLE 640 855","RECTANGLE 633 847","RECTANGLE 627 843","RECTANGLE 855 631","RECTANGLE 855 638","RECTANGLE 845 625","RECTANGLE 840 636","RECTANGLE 857 632","RECTANGLE 856 627","RECTANGLE 857 633","RECTANGLE 857 633","RECTANGLE 198 626","RECTANGLE 185 622","RECTANGLE 188 627","RECTANGLE 190 626","RECTANGLE 199 625","RECTANGLE 190 627","RECTANGLE 189 632","RECTANGLE 180 638","RECTANGLE 633 183","RECTANGLE 628 193","RECTANGLE 628 198","RECTANGLE 629 186","RECTANGLE 631 184","RECTANGLE 636 184","RECTANGLE 636 187","RECTANGLE 634 190","RECTANGLE 631 193","RECTANGLE 640 199"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(26, ret, solution.tryToFit(var0, var1, var2));
}

void testCase27 () {
int var0 = 82;

int var1 = 81;

string _var2[] = {"RECTANGLE 75 25","RECTANGLE 75 24","RECTANGLE 75 24","RECTANGLE 75 24","RECTANGLE 75 23","RECTANGLE 73 25","RECTANGLE 73 24","RECTANGLE 74 23","RECTANGLE 24 73","RECTANGLE 24 75","RECTANGLE 24 73","RECTANGLE 25 73","RECTANGLE 25 75","RECTANGLE 24 75","RECTANGLE 23 74","RECTANGLE 23 73","RECTANGLE 90 73","RECTANGLE 90 75","RECTANGLE 89 75","RECTANGLE 88 74","RECTANGLE 88 74","RECTANGLE 90 74","RECTANGLE 90 74","RECTANGLE 89 73","RECTANGLE 73 90","RECTANGLE 75 88","RECTANGLE 74 90","RECTANGLE 74 90","RECTANGLE 74 89","RECTANGLE 75 88","RECTANGLE 74 88","RECTANGLE 74 88","RECTANGLE 25 89","RECTANGLE 24 88","RECTANGLE 24 90","RECTANGLE 24 89","RECTANGLE 23 90","RECTANGLE 23 89","RECTANGLE 25 88","RECTANGLE 23 90","RECTANGLE 90 23","RECTANGLE 90 25","RECTANGLE 88 24","RECTANGLE 90 24","RECTANGLE 89 25","RECTANGLE 90 25","RECTANGLE 90 24","RECTANGLE 90 23","RECTANGLE 88 23","RECTANGLE 88 24"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(27, ret, solution.tryToFit(var0, var1, var2));
}

void testCase28 () {
int var0 = 820;

int var1 = 810;

string _var2[] = {"RECTANGLE 738 231","RECTANGLE 724 227","RECTANGLE 728 227","RECTANGLE 728 221","RECTANGLE 727 226","RECTANGLE 723 234","RECTANGLE 725 237","RECTANGLE 735 238","RECTANGLE 227 732","RECTANGLE 238 736","RECTANGLE 224 739","RECTANGLE 237 738","RECTANGLE 239 727","RECTANGLE 240 731","RECTANGLE 226 737","RECTANGLE 226 734","RECTANGLE 889 723","RECTANGLE 878 730","RECTANGLE 880 727","RECTANGLE 881 736","RECTANGLE 877 737","RECTANGLE 883 734","RECTANGLE 881 731","RECTANGLE 872 726","RECTANGLE 740 888","RECTANGLE 736 890","RECTANGLE 738 873","RECTANGLE 730 880","RECTANGLE 720 884","RECTANGLE 728 877","RECTANGLE 739 874","RECTANGLE 726 884","RECTANGLE 222 888","RECTANGLE 222 884","RECTANGLE 228 882","RECTANGLE 226 883","RECTANGLE 226 883","RECTANGLE 223 890","RECTANGLE 223 885","RECTANGLE 230 876","RECTANGLE 873 222","RECTANGLE 875 226","RECTANGLE 884 239","RECTANGLE 882 234","RECTANGLE 870 235","RECTANGLE 889 239","RECTANGLE 882 238","RECTANGLE 885 224","RECTANGLE 887 232","RECTANGLE 873 237"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(28, ret, solution.tryToFit(var0, var1, var2));
}

void testCase29 () {
int var0 = 50;

int var1 = 62;

string _var2[] = {"RECTANGLE 85 20","RECTANGLE 85 19","RECTANGLE 86 19","RECTANGLE 86 19","RECTANGLE 87 20","RECTANGLE 86 20","RECTANGLE 85 20","RECTANGLE 86 19","RECTANGLE 18 85","RECTANGLE 19 87","RECTANGLE 18 87","RECTANGLE 18 87","RECTANGLE 20 87","RECTANGLE 20 85","RECTANGLE 18 87","RECTANGLE 19 86","RECTANGLE 63 85","RECTANGLE 65 87","RECTANGLE 63 87","RECTANGLE 64 85","RECTANGLE 63 87","RECTANGLE 63 87","RECTANGLE 64 87","RECTANGLE 65 87","RECTANGLE 86 63","RECTANGLE 85 63","RECTANGLE 85 63","RECTANGLE 87 63","RECTANGLE 85 63","RECTANGLE 85 65","RECTANGLE 86 63","RECTANGLE 86 64","RECTANGLE 19 64","RECTANGLE 18 63","RECTANGLE 19 65","RECTANGLE 18 65","RECTANGLE 20 65","RECTANGLE 19 64","RECTANGLE 18 64","RECTANGLE 19 64","RECTANGLE 65 19","RECTANGLE 64 19","RECTANGLE 64 18","RECTANGLE 64 19","RECTANGLE 65 20","RECTANGLE 63 20","RECTANGLE 64 18","RECTANGLE 63 19","RECTANGLE 65 18","RECTANGLE 63 19"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(29, ret, solution.tryToFit(var0, var1, var2));
}

void testCase30 () {
int var0 = 500;

int var1 = 620;

string _var2[] = {"RECTANGLE 856 179","RECTANGLE 857 189","RECTANGLE 842 183","RECTANGLE 848 181","RECTANGLE 846 178","RECTANGLE 847 171","RECTANGLE 858 179","RECTANGLE 841 183","RECTANGLE 175 857","RECTANGLE 183 849","RECTANGLE 187 854","RECTANGLE 186 853","RECTANGLE 182 842","RECTANGLE 175 851","RECTANGLE 179 860","RECTANGLE 176 858","RECTANGLE 636 842","RECTANGLE 636 843","RECTANGLE 632 856","RECTANGLE 623 841","RECTANGLE 623 858","RECTANGLE 624 849","RECTANGLE 621 859","RECTANGLE 636 843","RECTANGLE 853 624","RECTANGLE 859 626","RECTANGLE 858 627","RECTANGLE 849 634","RECTANGLE 844 629","RECTANGLE 847 633","RECTANGLE 850 631","RECTANGLE 854 633","RECTANGLE 184 624","RECTANGLE 188 627","RECTANGLE 176 625","RECTANGLE 171 640","RECTANGLE 178 629","RECTANGLE 176 625","RECTANGLE 179 629","RECTANGLE 183 621","RECTANGLE 625 190","RECTANGLE 626 181","RECTANGLE 622 172","RECTANGLE 630 184","RECTANGLE 626 174","RECTANGLE 636 187","RECTANGLE 627 184","RECTANGLE 636 177","RECTANGLE 632 171","RECTANGLE 624 184"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "YES", "NO", "YES", "NO", "NO", "YES", "NO", "YES", "NO", "NO", "NO", "YES", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(30, ret, solution.tryToFit(var0, var1, var2));
}

void testCase31 () {
int var0 = 13;

int var1 = 45;

string _var2[] = {"RECTANGLE 94 58","RECTANGLE 95 60","RECTANGLE 95 58","RECTANGLE 93 60","RECTANGLE 94 58","RECTANGLE 95 60","RECTANGLE 95 58","RECTANGLE 93 58","RECTANGLE 60 95","RECTANGLE 59 95","RECTANGLE 60 93","RECTANGLE 58 93","RECTANGLE 59 93","RECTANGLE 60 95","RECTANGLE 59 95","RECTANGLE 60 94","RECTANGLE 74 93","RECTANGLE 74 94","RECTANGLE 75 93","RECTANGLE 75 94","RECTANGLE 75 95","RECTANGLE 74 94","RECTANGLE 76 94","RECTANGLE 75 94","RECTANGLE 94 75","RECTANGLE 95 76","RECTANGLE 93 74","RECTANGLE 94 74","RECTANGLE 95 76","RECTANGLE 94 75","RECTANGLE 93 75","RECTANGLE 95 76","RECTANGLE 58 75","RECTANGLE 58 74","RECTANGLE 60 74","RECTANGLE 60 75","RECTANGLE 58 75","RECTANGLE 58 74","RECTANGLE 60 76","RECTANGLE 59 76","RECTANGLE 76 59","RECTANGLE 75 59","RECTANGLE 75 58","RECTANGLE 74 59","RECTANGLE 76 60","RECTANGLE 75 60","RECTANGLE 75 58","RECTANGLE 75 58","RECTANGLE 74 60","RECTANGLE 76 60"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(31, ret, solution.tryToFit(var0, var1, var2));
}

void testCase32 () {
int var0 = 130;

int var1 = 450;

string _var2[] = {"RECTANGLE 924 586","RECTANGLE 935 570","RECTANGLE 936 572","RECTANGLE 934 589","RECTANGLE 933 575","RECTANGLE 932 582","RECTANGLE 932 585","RECTANGLE 930 587","RECTANGLE 589 927","RECTANGLE 570 934","RECTANGLE 578 929","RECTANGLE 580 930","RECTANGLE 575 938","RECTANGLE 573 938","RECTANGLE 585 932","RECTANGLE 575 924","RECTANGLE 734 939","RECTANGLE 749 920","RECTANGLE 747 938","RECTANGLE 732 932","RECTANGLE 731 929","RECTANGLE 731 935","RECTANGLE 739 933","RECTANGLE 749 930","RECTANGLE 921 737","RECTANGLE 934 747","RECTANGLE 925 739","RECTANGLE 924 731","RECTANGLE 939 740","RECTANGLE 940 735","RECTANGLE 929 743","RECTANGLE 929 733","RECTANGLE 573 741","RECTANGLE 579 737","RECTANGLE 587 750","RECTANGLE 576 741","RECTANGLE 573 749","RECTANGLE 579 737","RECTANGLE 587 740","RECTANGLE 585 737","RECTANGLE 734 586","RECTANGLE 734 576","RECTANGLE 737 577","RECTANGLE 745 576","RECTANGLE 742 576","RECTANGLE 749 584","RECTANGLE 745 589","RECTANGLE 740 578","RECTANGLE 743 588","RECTANGLE 745 589"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(32, ret, solution.tryToFit(var0, var1, var2));
}

void testCase33 () {
int var0 = 49;

int var1 = 49;

string _var2[] = {"RECTANGLE 20 51","RECTANGLE 19 51","RECTANGLE 19 50","RECTANGLE 20 50","RECTANGLE 19 50","RECTANGLE 21 52","RECTANGLE 19 52","RECTANGLE 19 51","RECTANGLE 50 21","RECTANGLE 52 19","RECTANGLE 50 20","RECTANGLE 52 20","RECTANGLE 50 20","RECTANGLE 52 19","RECTANGLE 52 19","RECTANGLE 51 20","RECTANGLE 62 20","RECTANGLE 61 20","RECTANGLE 62 19","RECTANGLE 62 19","RECTANGLE 60 19","RECTANGLE 62 21","RECTANGLE 61 20","RECTANGLE 60 21","RECTANGLE 19 61","RECTANGLE 19 60","RECTANGLE 20 61","RECTANGLE 19 60","RECTANGLE 20 62","RECTANGLE 21 62","RECTANGLE 20 61","RECTANGLE 19 61","RECTANGLE 50 61","RECTANGLE 52 61","RECTANGLE 52 60","RECTANGLE 51 61","RECTANGLE 50 60","RECTANGLE 52 60","RECTANGLE 51 62","RECTANGLE 51 62","RECTANGLE 62 52","RECTANGLE 60 52","RECTANGLE 60 50","RECTANGLE 60 51","RECTANGLE 62 51","RECTANGLE 62 50","RECTANGLE 62 50","RECTANGLE 62 50","RECTANGLE 61 52","RECTANGLE 61 52"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "YES", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(33, ret, solution.tryToFit(var0, var1, var2));
}

void testCase34 () {
int var0 = 490;

int var1 = 490;

string _var2[] = {"RECTANGLE 195 507","RECTANGLE 186 498","RECTANGLE 197 498","RECTANGLE 191 504","RECTANGLE 182 494","RECTANGLE 196 496","RECTANGLE 185 494","RECTANGLE 182 492","RECTANGLE 506 195","RECTANGLE 510 193","RECTANGLE 510 198","RECTANGLE 496 191","RECTANGLE 505 198","RECTANGLE 496 198","RECTANGLE 499 200","RECTANGLE 506 199","RECTANGLE 596 183","RECTANGLE 599 181","RECTANGLE 603 181","RECTANGLE 595 200","RECTANGLE 596 195","RECTANGLE 607 180","RECTANGLE 591 189","RECTANGLE 594 200","RECTANGLE 190 607","RECTANGLE 194 591","RECTANGLE 192 597","RECTANGLE 184 608","RECTANGLE 193 596","RECTANGLE 184 601","RECTANGLE 189 591","RECTANGLE 183 608","RECTANGLE 510 606","RECTANGLE 505 602","RECTANGLE 502 602","RECTANGLE 495 610","RECTANGLE 509 606","RECTANGLE 492 591","RECTANGLE 509 610","RECTANGLE 506 594","RECTANGLE 595 498","RECTANGLE 606 497","RECTANGLE 592 506","RECTANGLE 610 508","RECTANGLE 598 506","RECTANGLE 607 493","RECTANGLE 591 506","RECTANGLE 601 508","RECTANGLE 600 509","RECTANGLE 598 495"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "YES", "NO", "NO", "YES", "YES", "YES", "YES", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(34, ret, solution.tryToFit(var0, var1, var2));
}

void testCase35 () {
int var0 = 86;

int var1 = 78;

string _var2[] = {"RECTANGLE 102 44","RECTANGLE 101 43","RECTANGLE 100 42","RECTANGLE 100 43","RECTANGLE 100 43","RECTANGLE 102 44","RECTANGLE 100 42","RECTANGLE 101 43","RECTANGLE 43 101","RECTANGLE 44 101","RECTANGLE 43 101","RECTANGLE 42 102","RECTANGLE 42 100","RECTANGLE 43 100","RECTANGLE 42 102","RECTANGLE 44 101","RECTANGLE 58 102","RECTANGLE 59 101","RECTANGLE 60 100","RECTANGLE 58 101","RECTANGLE 60 102","RECTANGLE 58 102","RECTANGLE 58 100","RECTANGLE 59 102","RECTANGLE 100 59","RECTANGLE 100 58","RECTANGLE 100 58","RECTANGLE 100 58","RECTANGLE 100 59","RECTANGLE 101 58","RECTANGLE 102 58","RECTANGLE 101 58","RECTANGLE 44 60","RECTANGLE 42 60","RECTANGLE 43 59","RECTANGLE 44 58","RECTANGLE 44 58","RECTANGLE 43 58","RECTANGLE 44 58","RECTANGLE 43 60","RECTANGLE 59 42","RECTANGLE 59 42","RECTANGLE 58 44","RECTANGLE 58 43","RECTANGLE 60 44","RECTANGLE 58 43","RECTANGLE 60 43","RECTANGLE 59 43","RECTANGLE 58 43","RECTANGLE 58 44"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(35, ret, solution.tryToFit(var0, var1, var2));
}

void testCase36 () {
int var0 = 860;

int var1 = 780;

string _var2[] = {"RECTANGLE 996 428","RECTANGLE 996 415","RECTANGLE 998 430","RECTANGLE 990 430","RECTANGLE 1000 425","RECTANGLE 993 414","RECTANGLE 992 425","RECTANGLE 1000 415","RECTANGLE 411 1000","RECTANGLE 416 990","RECTANGLE 418 997","RECTANGLE 412 1000","RECTANGLE 424 995","RECTANGLE 423 991","RECTANGLE 425 1000","RECTANGLE 419 994","RECTANGLE 580 990","RECTANGLE 588 1000","RECTANGLE 583 1000","RECTANGLE 580 1000","RECTANGLE 570 1000","RECTANGLE 574 1000","RECTANGLE 586 992","RECTANGLE 580 1000","RECTANGLE 1000 586","RECTANGLE 992 586","RECTANGLE 996 590","RECTANGLE 994 574","RECTANGLE 994 588","RECTANGLE 999 587","RECTANGLE 1000 589","RECTANGLE 1000 587","RECTANGLE 420 577","RECTANGLE 412 587","RECTANGLE 423 570","RECTANGLE 421 581","RECTANGLE 430 583","RECTANGLE 423 585","RECTANGLE 419 584","RECTANGLE 419 573","RECTANGLE 587 412","RECTANGLE 570 421","RECTANGLE 583 412","RECTANGLE 588 414","RECTANGLE 590 427","RECTANGLE 586 415","RECTANGLE 571 429","RECTANGLE 575 423","RECTANGLE 577 419","RECTANGLE 579 415"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(36, ret, solution.tryToFit(var0, var1, var2));
}

void testCase37 () {
int var0 = 51;

int var1 = 62;

string _var2[] = {"RECTANGLE 87 18","RECTANGLE 87 20","RECTANGLE 86 20","RECTANGLE 86 19","RECTANGLE 87 19","RECTANGLE 86 19","RECTANGLE 86 20","RECTANGLE 85 20","RECTANGLE 19 87","RECTANGLE 18 85","RECTANGLE 20 86","RECTANGLE 18 87","RECTANGLE 18 86","RECTANGLE 20 87","RECTANGLE 20 87","RECTANGLE 18 85","RECTANGLE 63 87","RECTANGLE 64 87","RECTANGLE 64 86","RECTANGLE 63 85","RECTANGLE 64 86","RECTANGLE 64 85","RECTANGLE 65 87","RECTANGLE 65 86","RECTANGLE 86 64","RECTANGLE 87 63","RECTANGLE 87 65","RECTANGLE 86 65","RECTANGLE 87 63","RECTANGLE 86 64","RECTANGLE 86 65","RECTANGLE 87 64","RECTANGLE 19 64","RECTANGLE 19 64","RECTANGLE 19 63","RECTANGLE 19 65","RECTANGLE 20 65","RECTANGLE 20 65","RECTANGLE 19 63","RECTANGLE 19 65","RECTANGLE 63 19","RECTANGLE 63 20","RECTANGLE 65 18","RECTANGLE 65 19","RECTANGLE 65 20","RECTANGLE 65 18","RECTANGLE 64 19","RECTANGLE 64 20","RECTANGLE 63 20","RECTANGLE 63 18"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(37, ret, solution.tryToFit(var0, var1, var2));
}

void testCase38 () {
int var0 = 510;

int var1 = 620;

string _var2[] = {"RECTANGLE 851 186","RECTANGLE 840 184","RECTANGLE 857 188","RECTANGLE 846 188","RECTANGLE 843 171","RECTANGLE 858 187","RECTANGLE 853 180","RECTANGLE 842 179","RECTANGLE 178 850","RECTANGLE 177 853","RECTANGLE 174 843","RECTANGLE 175 852","RECTANGLE 190 855","RECTANGLE 184 849","RECTANGLE 183 842","RECTANGLE 186 844","RECTANGLE 638 844","RECTANGLE 640 856","RECTANGLE 631 852","RECTANGLE 631 845","RECTANGLE 640 854","RECTANGLE 624 848","RECTANGLE 635 853","RECTANGLE 620 844","RECTANGLE 855 621","RECTANGLE 844 627","RECTANGLE 857 639","RECTANGLE 853 629","RECTANGLE 857 634","RECTANGLE 856 624","RECTANGLE 848 629","RECTANGLE 851 631","RECTANGLE 174 623","RECTANGLE 184 630","RECTANGLE 183 633","RECTANGLE 174 622","RECTANGLE 181 633","RECTANGLE 173 626","RECTANGLE 180 623","RECTANGLE 174 623","RECTANGLE 628 174","RECTANGLE 620 178","RECTANGLE 636 174","RECTANGLE 638 181","RECTANGLE 634 180","RECTANGLE 637 181","RECTANGLE 640 190","RECTANGLE 621 178","RECTANGLE 636 171","RECTANGLE 632 185"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "YES", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "NO", "NO", "NO", "NO", "YES", "YES", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(38, ret, solution.tryToFit(var0, var1, var2));
}

void testCase39 () {
int var0 = 78;

int var1 = 68;

string _var2[] = {"RECTANGLE 81 17","RECTANGLE 79 17","RECTANGLE 81 18","RECTANGLE 79 17","RECTANGLE 80 17","RECTANGLE 80 17","RECTANGLE 81 17","RECTANGLE 81 17","RECTANGLE 18 79","RECTANGLE 17 79","RECTANGLE 16 80","RECTANGLE 16 80","RECTANGLE 16 81","RECTANGLE 17 81","RECTANGLE 18 79","RECTANGLE 18 80","RECTANGLE 39 79","RECTANGLE 39 79","RECTANGLE 40 81","RECTANGLE 41 79","RECTANGLE 39 81","RECTANGLE 39 79","RECTANGLE 41 81","RECTANGLE 39 79","RECTANGLE 80 40","RECTANGLE 79 41","RECTANGLE 79 40","RECTANGLE 80 41","RECTANGLE 80 41","RECTANGLE 81 41","RECTANGLE 80 40","RECTANGLE 81 41","RECTANGLE 18 40","RECTANGLE 18 41","RECTANGLE 17 39","RECTANGLE 16 40","RECTANGLE 17 40","RECTANGLE 16 40","RECTANGLE 18 39","RECTANGLE 16 39","RECTANGLE 41 16","RECTANGLE 40 16","RECTANGLE 41 18","RECTANGLE 41 16","RECTANGLE 39 17","RECTANGLE 39 18","RECTANGLE 40 17","RECTANGLE 39 18","RECTANGLE 41 17","RECTANGLE 40 18"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(39, ret, solution.tryToFit(var0, var1, var2));
}

void testCase40 () {
int var0 = 780;

int var1 = 680;

string _var2[] = {"RECTANGLE 787 159","RECTANGLE 796 164","RECTANGLE 798 158","RECTANGLE 799 155","RECTANGLE 792 164","RECTANGLE 786 151","RECTANGLE 788 168","RECTANGLE 783 161","RECTANGLE 170 797","RECTANGLE 166 786","RECTANGLE 162 780","RECTANGLE 151 796","RECTANGLE 166 781","RECTANGLE 165 795","RECTANGLE 150 783","RECTANGLE 161 788","RECTANGLE 382 788","RECTANGLE 396 786","RECTANGLE 390 798","RECTANGLE 392 792","RECTANGLE 393 781","RECTANGLE 400 796","RECTANGLE 387 781","RECTANGLE 396 780","RECTANGLE 786 384","RECTANGLE 785 391","RECTANGLE 784 398","RECTANGLE 798 384","RECTANGLE 799 400","RECTANGLE 780 392","RECTANGLE 798 400","RECTANGLE 787 391","RECTANGLE 166 400","RECTANGLE 168 380","RECTANGLE 163 385","RECTANGLE 156 387","RECTANGLE 152 383","RECTANGLE 152 383","RECTANGLE 153 387","RECTANGLE 162 396","RECTANGLE 386 158","RECTANGLE 385 167","RECTANGLE 380 160","RECTANGLE 387 152","RECTANGLE 392 170","RECTANGLE 397 158","RECTANGLE 399 160","RECTANGLE 387 151","RECTANGLE 381 164","RECTANGLE 397 154"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(40, ret, solution.tryToFit(var0, var1, var2));
}

void testCase41 () {
int var0 = 60;

int var1 = 49;

string _var2[] = {"RECTANGLE 50 50","RECTANGLE 51 51","RECTANGLE 51 51","RECTANGLE 52 51","RECTANGLE 50 50","RECTANGLE 52 52","RECTANGLE 51 51","RECTANGLE 51 51","RECTANGLE 52 50","RECTANGLE 50 52","RECTANGLE 51 50","RECTANGLE 51 52","RECTANGLE 50 51","RECTANGLE 51 51","RECTANGLE 50 52","RECTANGLE 50 51","RECTANGLE 52 51","RECTANGLE 52 52","RECTANGLE 51 51","RECTANGLE 51 52","RECTANGLE 50 51","RECTANGLE 51 50","RECTANGLE 50 52","RECTANGLE 52 52","RECTANGLE 51 50","RECTANGLE 50 52","RECTANGLE 52 51","RECTANGLE 52 50","RECTANGLE 51 52","RECTANGLE 50 51","RECTANGLE 52 51","RECTANGLE 50 51","RECTANGLE 51 52","RECTANGLE 52 50","RECTANGLE 50 52","RECTANGLE 52 50","RECTANGLE 52 50","RECTANGLE 50 50","RECTANGLE 52 50","RECTANGLE 51 50","RECTANGLE 52 50","RECTANGLE 52 52","RECTANGLE 52 50","RECTANGLE 50 51","RECTANGLE 50 51","RECTANGLE 51 50","RECTANGLE 51 50","RECTANGLE 51 51","RECTANGLE 50 52","RECTANGLE 50 50"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(41, ret, solution.tryToFit(var0, var1, var2));
}

void testCase42 () {
int var0 = 600;

int var1 = 490;

string _var2[] = {"RECTANGLE 500 496","RECTANGLE 491 507","RECTANGLE 490 500","RECTANGLE 501 494","RECTANGLE 507 501","RECTANGLE 505 502","RECTANGLE 509 490","RECTANGLE 499 502","RECTANGLE 504 500","RECTANGLE 502 508","RECTANGLE 492 499","RECTANGLE 510 495","RECTANGLE 499 502","RECTANGLE 494 499","RECTANGLE 491 493","RECTANGLE 497 504","RECTANGLE 500 499","RECTANGLE 508 496","RECTANGLE 499 498","RECTANGLE 509 496","RECTANGLE 507 493","RECTANGLE 493 501","RECTANGLE 490 505","RECTANGLE 494 500","RECTANGLE 498 505","RECTANGLE 491 504","RECTANGLE 509 500","RECTANGLE 510 490","RECTANGLE 497 496","RECTANGLE 497 491","RECTANGLE 505 498","RECTANGLE 506 503","RECTANGLE 509 492","RECTANGLE 500 501","RECTANGLE 507 495","RECTANGLE 497 496","RECTANGLE 508 503","RECTANGLE 497 500","RECTANGLE 490 508","RECTANGLE 500 502","RECTANGLE 493 496","RECTANGLE 504 502","RECTANGLE 502 492","RECTANGLE 498 501","RECTANGLE 503 510","RECTANGLE 495 505","RECTANGLE 497 495","RECTANGLE 498 509","RECTANGLE 499 494","RECTANGLE 497 506"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "YES", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(42, ret, solution.tryToFit(var0, var1, var2));
}

void testCase43 () {
int var0 = 62;

int var1 = 51;

string _var2[] = {"RECTANGLE 66 85","RECTANGLE 66 87","RECTANGLE 66 85","RECTANGLE 65 86","RECTANGLE 66 85","RECTANGLE 64 85","RECTANGLE 65 87","RECTANGLE 66 85","RECTANGLE 87 65","RECTANGLE 86 65","RECTANGLE 87 65","RECTANGLE 86 66","RECTANGLE 85 65","RECTANGLE 87 64","RECTANGLE 87 66","RECTANGLE 85 66","RECTANGLE 19 65","RECTANGLE 19 66","RECTANGLE 19 64","RECTANGLE 18 64","RECTANGLE 19 64","RECTANGLE 19 65","RECTANGLE 19 66","RECTANGLE 19 64","RECTANGLE 66 20","RECTANGLE 64 18","RECTANGLE 64 20","RECTANGLE 65 19","RECTANGLE 66 19","RECTANGLE 64 20","RECTANGLE 65 20","RECTANGLE 65 18","RECTANGLE 86 18","RECTANGLE 86 19","RECTANGLE 87 20","RECTANGLE 86 20","RECTANGLE 87 18","RECTANGLE 85 20","RECTANGLE 87 18","RECTANGLE 85 19","RECTANGLE 20 87","RECTANGLE 20 86","RECTANGLE 18 87","RECTANGLE 19 87","RECTANGLE 19 86","RECTANGLE 18 87","RECTANGLE 19 85","RECTANGLE 18 87","RECTANGLE 18 87","RECTANGLE 19 87"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(43, ret, solution.tryToFit(var0, var1, var2));
}

void testCase44 () {
int var0 = 620;

int var1 = 510;

string _var2[] = {"RECTANGLE 642 842","RECTANGLE 645 860","RECTANGLE 638 845","RECTANGLE 636 858","RECTANGLE 642 855","RECTANGLE 632 844","RECTANGLE 647 860","RECTANGLE 633 846","RECTANGLE 851 633","RECTANGLE 859 635","RECTANGLE 854 631","RECTANGLE 853 635","RECTANGLE 851 636","RECTANGLE 851 640","RECTANGLE 860 645","RECTANGLE 858 650","RECTANGLE 187 641","RECTANGLE 186 640","RECTANGLE 176 633","RECTANGLE 188 631","RECTANGLE 175 648","RECTANGLE 185 648","RECTANGLE 171 650","RECTANGLE 173 646","RECTANGLE 630 182","RECTANGLE 643 190","RECTANGLE 635 183","RECTANGLE 649 173","RECTANGLE 644 186","RECTANGLE 640 178","RECTANGLE 635 183","RECTANGLE 633 175","RECTANGLE 856 190","RECTANGLE 842 187","RECTANGLE 858 171","RECTANGLE 857 190","RECTANGLE 856 173","RECTANGLE 840 181","RECTANGLE 845 187","RECTANGLE 847 173","RECTANGLE 173 843","RECTANGLE 186 858","RECTANGLE 171 846","RECTANGLE 171 855","RECTANGLE 170 853","RECTANGLE 173 849","RECTANGLE 183 845","RECTANGLE 174 844","RECTANGLE 170 846","RECTANGLE 175 847"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(44, ret, solution.tryToFit(var0, var1, var2));
}

void testCase45 () {
int var0 = 63;

int var1 = 51;

string _var2[] = {"RECTANGLE 65 85","RECTANGLE 65 86","RECTANGLE 65 87","RECTANGLE 66 87","RECTANGLE 64 85","RECTANGLE 66 85","RECTANGLE 64 86","RECTANGLE 65 85","RECTANGLE 85 66","RECTANGLE 85 66","RECTANGLE 86 64","RECTANGLE 85 64","RECTANGLE 86 64","RECTANGLE 85 66","RECTANGLE 86 65","RECTANGLE 85 66","RECTANGLE 19 66","RECTANGLE 18 65","RECTANGLE 19 64","RECTANGLE 20 66","RECTANGLE 18 66","RECTANGLE 18 65","RECTANGLE 19 65","RECTANGLE 19 66","RECTANGLE 66 18","RECTANGLE 65 19","RECTANGLE 64 19","RECTANGLE 65 20","RECTANGLE 66 19","RECTANGLE 65 19","RECTANGLE 65 18","RECTANGLE 66 19","RECTANGLE 85 18","RECTANGLE 87 20","RECTANGLE 87 20","RECTANGLE 86 19","RECTANGLE 85 18","RECTANGLE 87 20","RECTANGLE 86 20","RECTANGLE 87 19","RECTANGLE 18 87","RECTANGLE 18 87","RECTANGLE 19 85","RECTANGLE 18 87","RECTANGLE 19 86","RECTANGLE 19 87","RECTANGLE 18 86","RECTANGLE 20 86","RECTANGLE 20 86","RECTANGLE 18 86"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(45, ret, solution.tryToFit(var0, var1, var2));
}

void testCase46 () {
int var0 = 630;

int var1 = 510;

string _var2[] = {"RECTANGLE 633 850","RECTANGLE 642 845","RECTANGLE 645 853","RECTANGLE 637 849","RECTANGLE 631 844","RECTANGLE 646 847","RECTANGLE 630 857","RECTANGLE 643 848","RECTANGLE 842 644","RECTANGLE 840 635","RECTANGLE 853 640","RECTANGLE 848 647","RECTANGLE 847 638","RECTANGLE 843 636","RECTANGLE 848 639","RECTANGLE 857 638","RECTANGLE 181 642","RECTANGLE 172 636","RECTANGLE 185 635","RECTANGLE 178 639","RECTANGLE 187 644","RECTANGLE 179 633","RECTANGLE 179 645","RECTANGLE 179 631","RECTANGLE 636 181","RECTANGLE 631 177","RECTANGLE 634 189","RECTANGLE 636 177","RECTANGLE 643 179","RECTANGLE 648 177","RECTANGLE 645 171","RECTANGLE 641 182","RECTANGLE 859 174","RECTANGLE 849 183","RECTANGLE 842 181","RECTANGLE 843 185","RECTANGLE 859 187","RECTANGLE 851 182","RECTANGLE 853 175","RECTANGLE 857 188","RECTANGLE 175 857","RECTANGLE 185 858","RECTANGLE 174 847","RECTANGLE 186 859","RECTANGLE 175 858","RECTANGLE 187 851","RECTANGLE 170 859","RECTANGLE 172 847","RECTANGLE 190 857","RECTANGLE 178 849"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "NO", "YES", "NO", "YES", "YES", "YES", "NO", "YES", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(46, ret, solution.tryToFit(var0, var1, var2));
}

void testCase47 () {
int var0 = 64;

int var1 = 70;

string _var2[] = {"RECTANGLE 82 17","RECTANGLE 81 15","RECTANGLE 80 16","RECTANGLE 80 17","RECTANGLE 82 16","RECTANGLE 81 17","RECTANGLE 80 17","RECTANGLE 80 16","RECTANGLE 15 82","RECTANGLE 15 82","RECTANGLE 16 80","RECTANGLE 16 80","RECTANGLE 16 80","RECTANGLE 17 81","RECTANGLE 15 81","RECTANGLE 16 82","RECTANGLE 83 82","RECTANGLE 82 80","RECTANGLE 83 80","RECTANGLE 83 81","RECTANGLE 82 80","RECTANGLE 83 80","RECTANGLE 83 81","RECTANGLE 82 81","RECTANGLE 80 83","RECTANGLE 80 83","RECTANGLE 82 81","RECTANGLE 81 83","RECTANGLE 82 82","RECTANGLE 80 81","RECTANGLE 81 81","RECTANGLE 80 83","RECTANGLE 17 82","RECTANGLE 17 82","RECTANGLE 17 81","RECTANGLE 15 82","RECTANGLE 17 82","RECTANGLE 16 81","RECTANGLE 16 82","RECTANGLE 17 81","RECTANGLE 81 15","RECTANGLE 82 17","RECTANGLE 83 15","RECTANGLE 83 17","RECTANGLE 83 16","RECTANGLE 83 17","RECTANGLE 82 16","RECTANGLE 81 17","RECTANGLE 81 16","RECTANGLE 83 15"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(47, ret, solution.tryToFit(var0, var1, var2));
}

void testCase48 () {
int var0 = 640;

int var1 = 700;

string _var2[] = {"RECTANGLE 797 144","RECTANGLE 810 146","RECTANGLE 794 150","RECTANGLE 805 153","RECTANGLE 795 146","RECTANGLE 809 152","RECTANGLE 796 146","RECTANGLE 796 157","RECTANGLE 153 804","RECTANGLE 151 810","RECTANGLE 159 807","RECTANGLE 143 791","RECTANGLE 153 802","RECTANGLE 146 806","RECTANGLE 159 797","RECTANGLE 151 801","RECTANGLE 816 796","RECTANGLE 814 799","RECTANGLE 801 810","RECTANGLE 803 796","RECTANGLE 818 794","RECTANGLE 810 792","RECTANGLE 817 793","RECTANGLE 818 807","RECTANGLE 806 810","RECTANGLE 796 806","RECTANGLE 797 813","RECTANGLE 792 807","RECTANGLE 793 820","RECTANGLE 795 806","RECTANGLE 808 801","RECTANGLE 795 814","RECTANGLE 142 813","RECTANGLE 150 820","RECTANGLE 145 802","RECTANGLE 146 811","RECTANGLE 151 803","RECTANGLE 146 817","RECTANGLE 151 808","RECTANGLE 156 801","RECTANGLE 807 146","RECTANGLE 817 141","RECTANGLE 808 155","RECTANGLE 812 158","RECTANGLE 803 149","RECTANGLE 811 155","RECTANGLE 809 159","RECTANGLE 811 154","RECTANGLE 813 149","RECTANGLE 809 159"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "NO", "YES", "NO", "YES", "NO", "YES", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(48, ret, solution.tryToFit(var0, var1, var2));
}

void testCase49 () {
int var0 = 65;

int var1 = 70;

string _var2[] = {"RECTANGLE 82 17","RECTANGLE 82 17","RECTANGLE 81 16","RECTANGLE 81 15","RECTANGLE 80 16","RECTANGLE 82 17","RECTANGLE 80 16","RECTANGLE 82 17","RECTANGLE 15 81","RECTANGLE 16 81","RECTANGLE 16 80","RECTANGLE 17 81","RECTANGLE 16 82","RECTANGLE 16 82","RECTANGLE 17 80","RECTANGLE 17 82","RECTANGLE 82 81","RECTANGLE 81 82","RECTANGLE 82 80","RECTANGLE 82 82","RECTANGLE 82 81","RECTANGLE 83 81","RECTANGLE 82 80","RECTANGLE 83 80","RECTANGLE 81 82","RECTANGLE 81 82","RECTANGLE 80 81","RECTANGLE 81 82","RECTANGLE 81 83","RECTANGLE 82 83","RECTANGLE 81 82","RECTANGLE 82 81","RECTANGLE 17 82","RECTANGLE 16 81","RECTANGLE 17 81","RECTANGLE 16 81","RECTANGLE 16 83","RECTANGLE 17 83","RECTANGLE 17 83","RECTANGLE 16 83","RECTANGLE 81 16","RECTANGLE 82 17","RECTANGLE 83 16","RECTANGLE 81 17","RECTANGLE 83 16","RECTANGLE 83 16","RECTANGLE 82 17","RECTANGLE 81 17","RECTANGLE 83 16","RECTANGLE 83 17"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(49, ret, solution.tryToFit(var0, var1, var2));
}

void testCase50 () {
int var0 = 650;

int var1 = 700;

string _var2[] = {"RECTANGLE 792 151","RECTANGLE 810 147","RECTANGLE 803 141","RECTANGLE 797 157","RECTANGLE 797 156","RECTANGLE 798 154","RECTANGLE 808 144","RECTANGLE 802 154","RECTANGLE 145 804","RECTANGLE 146 794","RECTANGLE 154 793","RECTANGLE 157 807","RECTANGLE 153 793","RECTANGLE 152 793","RECTANGLE 154 809","RECTANGLE 147 798","RECTANGLE 813 805","RECTANGLE 816 796","RECTANGLE 802 794","RECTANGLE 820 793","RECTANGLE 815 797","RECTANGLE 810 796","RECTANGLE 818 802","RECTANGLE 805 810","RECTANGLE 793 800","RECTANGLE 793 809","RECTANGLE 795 816","RECTANGLE 807 818","RECTANGLE 790 816","RECTANGLE 803 808","RECTANGLE 804 813","RECTANGLE 797 820","RECTANGLE 146 807","RECTANGLE 151 800","RECTANGLE 141 806","RECTANGLE 152 808","RECTANGLE 154 817","RECTANGLE 146 801","RECTANGLE 140 809","RECTANGLE 150 810","RECTANGLE 819 141","RECTANGLE 817 153","RECTANGLE 809 142","RECTANGLE 816 154","RECTANGLE 801 147","RECTANGLE 820 148","RECTANGLE 808 156","RECTANGLE 800 144","RECTANGLE 805 152","RECTANGLE 816 149"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "NO", "YES", "YES", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "NO", "YES", "NO", "YES", "NO", "NO", "YES", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(50, ret, solution.tryToFit(var0, var1, var2));
}

void testCase51 () {
int var0 = 65;

int var1 = 70;

string _var2[] = {"RECTANGLE 81 15","RECTANGLE 83 16","RECTANGLE 81 16","RECTANGLE 82 15","RECTANGLE 83 16","RECTANGLE 81 17","RECTANGLE 83 15","RECTANGLE 83 15","RECTANGLE 15 83","RECTANGLE 16 83","RECTANGLE 16 83","RECTANGLE 16 82","RECTANGLE 15 82","RECTANGLE 16 83","RECTANGLE 15 83","RECTANGLE 15 82","RECTANGLE 83 81","RECTANGLE 82 81","RECTANGLE 82 82","RECTANGLE 83 81","RECTANGLE 81 81","RECTANGLE 83 81","RECTANGLE 82 83","RECTANGLE 83 83","RECTANGLE 82 82","RECTANGLE 82 83","RECTANGLE 82 81","RECTANGLE 83 81","RECTANGLE 83 82","RECTANGLE 82 83","RECTANGLE 81 83","RECTANGLE 82 83","RECTANGLE 15 81","RECTANGLE 16 83","RECTANGLE 15 83","RECTANGLE 15 82","RECTANGLE 16 82","RECTANGLE 16 83","RECTANGLE 17 81","RECTANGLE 17 83","RECTANGLE 82 15","RECTANGLE 82 16","RECTANGLE 83 17","RECTANGLE 81 17","RECTANGLE 82 16","RECTANGLE 83 17","RECTANGLE 82 16","RECTANGLE 82 15","RECTANGLE 81 15","RECTANGLE 83 16"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(51, ret, solution.tryToFit(var0, var1, var2));
}

void testCase52 () {
int var0 = 650;

int var1 = 700;

string _var2[] = {"RECTANGLE 815 156","RECTANGLE 805 154","RECTANGLE 803 151","RECTANGLE 818 140","RECTANGLE 805 148","RECTANGLE 815 143","RECTANGLE 801 147","RECTANGLE 818 143","RECTANGLE 157 816","RECTANGLE 153 805","RECTANGLE 147 807","RECTANGLE 148 803","RECTANGLE 150 804","RECTANGLE 159 810","RECTANGLE 155 807","RECTANGLE 142 819","RECTANGLE 810 809","RECTANGLE 800 805","RECTANGLE 806 811","RECTANGLE 819 818","RECTANGLE 819 809","RECTANGLE 815 812","RECTANGLE 813 818","RECTANGLE 814 812","RECTANGLE 815 807","RECTANGLE 814 806","RECTANGLE 807 800","RECTANGLE 804 820","RECTANGLE 809 817","RECTANGLE 801 800","RECTANGLE 817 804","RECTANGLE 811 804","RECTANGLE 149 804","RECTANGLE 156 811","RECTANGLE 146 813","RECTANGLE 140 812","RECTANGLE 143 804","RECTANGLE 140 815","RECTANGLE 144 814","RECTANGLE 140 814","RECTANGLE 820 160","RECTANGLE 820 152","RECTANGLE 811 146","RECTANGLE 800 141","RECTANGLE 820 140","RECTANGLE 802 141","RECTANGLE 803 154","RECTANGLE 818 153","RECTANGLE 802 151","RECTANGLE 801 153"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "YES", "NO", "YES", "NO", "YES", "NO", "NO", "NO", "YES", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "YES", "YES", "YES", "NO", "YES", "NO", "NO", "NO", "YES", "NO", "YES", "NO", "NO", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(52, ret, solution.tryToFit(var0, var1, var2));
}

void testCase53 () {
int var0 = 65;

int var1 = 70;

string _var2[] = {"RECTANGLE 83 15","RECTANGLE 81 16","RECTANGLE 83 15","RECTANGLE 81 15","RECTANGLE 83 17","RECTANGLE 82 16","RECTANGLE 83 17","RECTANGLE 81 16","RECTANGLE 15 83","RECTANGLE 17 81","RECTANGLE 17 81","RECTANGLE 17 83","RECTANGLE 17 81","RECTANGLE 17 83","RECTANGLE 17 83","RECTANGLE 17 82","RECTANGLE 81 82","RECTANGLE 82 83","RECTANGLE 80 81","RECTANGLE 82 81","RECTANGLE 82 81","RECTANGLE 82 82","RECTANGLE 80 83","RECTANGLE 81 83","RECTANGLE 81 80","RECTANGLE 81 82","RECTANGLE 83 80","RECTANGLE 82 80","RECTANGLE 81 82","RECTANGLE 82 81","RECTANGLE 83 82","RECTANGLE 82 82","RECTANGLE 17 80","RECTANGLE 17 80","RECTANGLE 16 80","RECTANGLE 15 82","RECTANGLE 17 81","RECTANGLE 16 80","RECTANGLE 15 82","RECTANGLE 16 80","RECTANGLE 82 17","RECTANGLE 82 17","RECTANGLE 80 15","RECTANGLE 82 16","RECTANGLE 82 16","RECTANGLE 81 16","RECTANGLE 80 17","RECTANGLE 80 17","RECTANGLE 80 17","RECTANGLE 80 15"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(53, ret, solution.tryToFit(var0, var1, var2));
}

void testCase54 () {
int var0 = 650;

int var1 = 700;

string _var2[] = {"RECTANGLE 811 151","RECTANGLE 813 153","RECTANGLE 802 142","RECTANGLE 805 158","RECTANGLE 807 143","RECTANGLE 820 144","RECTANGLE 812 156","RECTANGLE 804 153","RECTANGLE 145 809","RECTANGLE 151 801","RECTANGLE 155 811","RECTANGLE 148 812","RECTANGLE 143 801","RECTANGLE 144 809","RECTANGLE 143 805","RECTANGLE 156 817","RECTANGLE 797 812","RECTANGLE 805 807","RECTANGLE 794 809","RECTANGLE 802 818","RECTANGLE 791 809","RECTANGLE 795 810","RECTANGLE 792 813","RECTANGLE 790 807","RECTANGLE 806 796","RECTANGLE 815 801","RECTANGLE 803 790","RECTANGLE 820 792","RECTANGLE 809 796","RECTANGLE 811 794","RECTANGLE 819 800","RECTANGLE 802 795","RECTANGLE 150 793","RECTANGLE 150 805","RECTANGLE 152 802","RECTANGLE 141 791","RECTANGLE 149 803","RECTANGLE 143 794","RECTANGLE 151 802","RECTANGLE 156 793","RECTANGLE 805 158","RECTANGLE 806 148","RECTANGLE 799 158","RECTANGLE 791 156","RECTANGLE 808 158","RECTANGLE 798 151","RECTANGLE 804 154","RECTANGLE 807 148","RECTANGLE 792 141","RECTANGLE 803 146"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "YES", "NO", "YES", "NO", "NO", "NO", "YES", "YES", "NO", "NO", "YES", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "NO", "YES", "NO", "YES", "NO", "YES", "NO", "YES", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(54, ret, solution.tryToFit(var0, var1, var2));
}

void testCase55 () {
int var0 = 85;

int var1 = 60;

string _var2[] = {"RECTANGLE 102 87","RECTANGLE 101 85","RECTANGLE 101 85","RECTANGLE 101 86","RECTANGLE 102 86","RECTANGLE 101 85","RECTANGLE 102 85","RECTANGLE 101 87","RECTANGLE 86 102","RECTANGLE 86 102","RECTANGLE 87 101","RECTANGLE 86 100","RECTANGLE 87 102","RECTANGLE 85 100","RECTANGLE 85 102","RECTANGLE 86 102","RECTANGLE 62 100","RECTANGLE 61 100","RECTANGLE 61 101","RECTANGLE 60 102","RECTANGLE 62 100","RECTANGLE 60 102","RECTANGLE 62 101","RECTANGLE 62 102","RECTANGLE 102 61","RECTANGLE 100 60","RECTANGLE 100 62","RECTANGLE 102 62","RECTANGLE 102 60","RECTANGLE 102 62","RECTANGLE 102 61","RECTANGLE 102 61","RECTANGLE 86 62","RECTANGLE 86 60","RECTANGLE 87 60","RECTANGLE 87 62","RECTANGLE 86 62","RECTANGLE 86 60","RECTANGLE 85 60","RECTANGLE 87 60","RECTANGLE 60 87","RECTANGLE 62 85","RECTANGLE 60 86","RECTANGLE 62 86","RECTANGLE 61 87","RECTANGLE 61 87","RECTANGLE 60 86","RECTANGLE 60 85","RECTANGLE 60 87","RECTANGLE 60 87"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(55, ret, solution.tryToFit(var0, var1, var2));
}

void testCase56 () {
int var0 = 850;

int var1 = 600;

string _var2[] = {"RECTANGLE 604 859","RECTANGLE 606 857","RECTANGLE 603 860","RECTANGLE 592 848","RECTANGLE 594 840","RECTANGLE 604 841","RECTANGLE 607 843","RECTANGLE 596 853","RECTANGLE 605 847"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "YES", "YES", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(56, ret, solution.tryToFit(var0, var1, var2));
}

void testCase57 () {
int var0 = 65;

int var1 = 70;

string _var2[] = {"RECTANGLE 82 17","RECTANGLE 83 18","RECTANGLE 82 16","RECTANGLE 83 16","RECTANGLE 81 16","RECTANGLE 81 16","RECTANGLE 81 18","RECTANGLE 82 16","RECTANGLE 18 82","RECTANGLE 16 81","RECTANGLE 17 83","RECTANGLE 16 81","RECTANGLE 16 81","RECTANGLE 16 82","RECTANGLE 18 83","RECTANGLE 16 81","RECTANGLE 82 81","RECTANGLE 81 83","RECTANGLE 80 81","RECTANGLE 81 82","RECTANGLE 82 82","RECTANGLE 80 83","RECTANGLE 80 83","RECTANGLE 81 81","RECTANGLE 81 80","RECTANGLE 82 82","RECTANGLE 83 82","RECTANGLE 81 81","RECTANGLE 81 81","RECTANGLE 81 80","RECTANGLE 81 82","RECTANGLE 81 81","RECTANGLE 18 81","RECTANGLE 18 81","RECTANGLE 18 80","RECTANGLE 17 81","RECTANGLE 17 82","RECTANGLE 17 80","RECTANGLE 16 82","RECTANGLE 18 82","RECTANGLE 80 17","RECTANGLE 80 16","RECTANGLE 80 18","RECTANGLE 81 17","RECTANGLE 82 16","RECTANGLE 81 18","RECTANGLE 81 16","RECTANGLE 82 17","RECTANGLE 80 16","RECTANGLE 80 18"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(57, ret, solution.tryToFit(var0, var1, var2));
}

void testCase58 () {
int var0 = 650;

int var1 = 700;

string _var2[] = {"RECTANGLE 807 159","RECTANGLE 812 170","RECTANGLE 812 167","RECTANGLE 805 158","RECTANGLE 820 168","RECTANGLE 814 157","RECTANGLE 809 152","RECTANGLE 812 153","RECTANGLE 170 803","RECTANGLE 163 805","RECTANGLE 161 807","RECTANGLE 152 814","RECTANGLE 170 801","RECTANGLE 157 811","RECTANGLE 151 803","RECTANGLE 162 814","RECTANGLE 801 806","RECTANGLE 792 804","RECTANGLE 800 803","RECTANGLE 809 805","RECTANGLE 802 807","RECTANGLE 800 813","RECTANGLE 804 819","RECTANGLE 810 820","RECTANGLE 804 803","RECTANGLE 818 801","RECTANGLE 804 803","RECTANGLE 814 790","RECTANGLE 809 791","RECTANGLE 804 809","RECTANGLE 810 800","RECTANGLE 816 805","RECTANGLE 167 791","RECTANGLE 152 806","RECTANGLE 150 796","RECTANGLE 163 809","RECTANGLE 159 800","RECTANGLE 157 790","RECTANGLE 168 793","RECTANGLE 164 796","RECTANGLE 805 152","RECTANGLE 805 162","RECTANGLE 800 170","RECTANGLE 809 157","RECTANGLE 795 169","RECTANGLE 796 153","RECTANGLE 806 166","RECTANGLE 805 170","RECTANGLE 803 162","RECTANGLE 806 165"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(58, ret, solution.tryToFit(var0, var1, var2));
}

void testCase59 () {
int var0 = 15;

int var1 = 16;

string _var2[] = {"RECTANGLE 16 18","RECTANGLE 16 16","RECTANGLE 16 18","RECTANGLE 17 18","RECTANGLE 16 18","RECTANGLE 16 18","RECTANGLE 17 17","RECTANGLE 16 16","RECTANGLE 17 16","RECTANGLE 16 15","RECTANGLE 17 16","RECTANGLE 18 15","RECTANGLE 16 15","RECTANGLE 16 15","RECTANGLE 16 16","RECTANGLE 16 17","RECTANGLE 68 17","RECTANGLE 68 17","RECTANGLE 67 16","RECTANGLE 67 17","RECTANGLE 67 15","RECTANGLE 68 15","RECTANGLE 67 17","RECTANGLE 66 16","RECTANGLE 16 68","RECTANGLE 17 68","RECTANGLE 17 66","RECTANGLE 15 68","RECTANGLE 15 67","RECTANGLE 17 67","RECTANGLE 15 67","RECTANGLE 16 66","RECTANGLE 16 67","RECTANGLE 16 66","RECTANGLE 16 68","RECTANGLE 16 67","RECTANGLE 16 68","RECTANGLE 17 66","RECTANGLE 17 67","RECTANGLE 18 68","RECTANGLE 67 17","RECTANGLE 68 17","RECTANGLE 67 18","RECTANGLE 66 16","RECTANGLE 67 17","RECTANGLE 66 18","RECTANGLE 66 16","RECTANGLE 67 18","RECTANGLE 66 17","RECTANGLE 67 18"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(59, ret, solution.tryToFit(var0, var1, var2));
}

void testCase60 () {
int var0 = 150;

int var1 = 160;

string _var2[] = {"RECTANGLE 142 159","RECTANGLE 155 164","RECTANGLE 157 158","RECTANGLE 141 160","RECTANGLE 145 160","RECTANGLE 155 157","RECTANGLE 152 165","RECTANGLE 154 162","RECTANGLE 163 157","RECTANGLE 165 155","RECTANGLE 159 143","RECTANGLE 153 153","RECTANGLE 163 147","RECTANGLE 159 154","RECTANGLE 155 154","RECTANGLE 150 151","RECTANGLE 654 147","RECTANGLE 663 156","RECTANGLE 653 159","RECTANGLE 656 154","RECTANGLE 651 146","RECTANGLE 651 141","RECTANGLE 661 153","RECTANGLE 659 153","RECTANGLE 148 653","RECTANGLE 144 652","RECTANGLE 153 665","RECTANGLE 160 656","RECTANGLE 160 653","RECTANGLE 157 656","RECTANGLE 157 652","RECTANGLE 147 666","RECTANGLE 161 650","RECTANGLE 169 668","RECTANGLE 160 662","RECTANGLE 169 653","RECTANGLE 152 659","RECTANGLE 170 668","RECTANGLE 158 663","RECTANGLE 164 659","RECTANGLE 659 164","RECTANGLE 656 168","RECTANGLE 653 170","RECTANGLE 653 156","RECTANGLE 662 151","RECTANGLE 651 170","RECTANGLE 663 159","RECTANGLE 657 157","RECTANGLE 654 151","RECTANGLE 664 154"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "NO", "NO", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(60, ret, solution.tryToFit(var0, var1, var2));
}

void testCase61 () {
int var0 = 21;

int var1 = 22;

string _var2[] = {"RECTANGLE 23 21","RECTANGLE 22 22","RECTANGLE 23 21","RECTANGLE 23 21","RECTANGLE 23 22","RECTANGLE 23 22","RECTANGLE 24 22","RECTANGLE 22 22","RECTANGLE 22 22","RECTANGLE 23 22","RECTANGLE 22 22","RECTANGLE 22 23","RECTANGLE 23 22","RECTANGLE 23 24","RECTANGLE 21 24","RECTANGLE 23 24","RECTANGLE 86 24","RECTANGLE 88 22","RECTANGLE 87 24","RECTANGLE 86 23","RECTANGLE 88 24","RECTANGLE 86 23","RECTANGLE 87 22","RECTANGLE 87 23","RECTANGLE 22 86","RECTANGLE 22 86","RECTANGLE 24 88","RECTANGLE 24 87","RECTANGLE 24 88","RECTANGLE 24 88","RECTANGLE 23 86","RECTANGLE 22 88","RECTANGLE 21 87","RECTANGLE 22 88","RECTANGLE 23 87","RECTANGLE 21 86","RECTANGLE 22 88","RECTANGLE 23 87","RECTANGLE 22 86","RECTANGLE 22 86","RECTANGLE 87 22","RECTANGLE 87 22","RECTANGLE 87 22","RECTANGLE 87 22","RECTANGLE 87 21","RECTANGLE 86 21","RECTANGLE 88 23","RECTANGLE 88 21","RECTANGLE 87 22","RECTANGLE 88 21"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(61, ret, solution.tryToFit(var0, var1, var2));
}

void testCase62 () {
int var0 = 210;

int var1 = 220;

string _var2[] = {"RECTANGLE 228 203","RECTANGLE 216 203","RECTANGLE 226 218","RECTANGLE 210 209","RECTANGLE 228 211","RECTANGLE 214 202","RECTANGLE 226 200","RECTANGLE 220 209","RECTANGLE 214 219","RECTANGLE 209 230","RECTANGLE 206 211","RECTANGLE 215 226","RECTANGLE 203 210","RECTANGLE 213 228","RECTANGLE 205 218","RECTANGLE 209 223","RECTANGLE 864 210","RECTANGLE 866 225","RECTANGLE 853 219","RECTANGLE 869 227","RECTANGLE 869 230","RECTANGLE 870 210","RECTANGLE 860 222","RECTANGLE 850 217","RECTANGLE 214 851","RECTANGLE 212 857","RECTANGLE 211 860","RECTANGLE 220 865","RECTANGLE 221 854","RECTANGLE 222 851","RECTANGLE 222 866","RECTANGLE 226 869","RECTANGLE 213 855","RECTANGLE 212 862","RECTANGLE 206 865","RECTANGLE 212 858","RECTANGLE 209 852","RECTANGLE 213 859","RECTANGLE 216 867","RECTANGLE 216 861","RECTANGLE 869 220","RECTANGLE 857 216","RECTANGLE 858 220","RECTANGLE 851 215","RECTANGLE 866 219","RECTANGLE 864 211","RECTANGLE 859 207","RECTANGLE 860 208","RECTANGLE 868 220","RECTANGLE 864 202"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "YES", "NO", "YES", "NO", "YES", "NO", "YES", "NO", "NO", "YES", "NO", "YES", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(62, ret, solution.tryToFit(var0, var1, var2));
}

void testCase63 () {
int var0 = 29;

int var1 = 29;

string _var2[] = {"RECTANGLE 86 32","RECTANGLE 86 33","RECTANGLE 85 33","RECTANGLE 86 33","RECTANGLE 87 32","RECTANGLE 86 33","RECTANGLE 86 32","RECTANGLE 86 33","RECTANGLE 32 86","RECTANGLE 33 87","RECTANGLE 32 87","RECTANGLE 33 85","RECTANGLE 31 87","RECTANGLE 32 85","RECTANGLE 31 85","RECTANGLE 33 87","RECTANGLE 24 87","RECTANGLE 23 85","RECTANGLE 22 85","RECTANGLE 24 86","RECTANGLE 23 85","RECTANGLE 24 87","RECTANGLE 24 85","RECTANGLE 23 85","RECTANGLE 85 22","RECTANGLE 86 22","RECTANGLE 85 24","RECTANGLE 86 22","RECTANGLE 86 22","RECTANGLE 86 22","RECTANGLE 87 24","RECTANGLE 86 22","RECTANGLE 33 24","RECTANGLE 31 22","RECTANGLE 32 24","RECTANGLE 31 24","RECTANGLE 32 22","RECTANGLE 32 24","RECTANGLE 31 23","RECTANGLE 32 24","RECTANGLE 24 31","RECTANGLE 24 31","RECTANGLE 22 32","RECTANGLE 24 31","RECTANGLE 23 31","RECTANGLE 24 33","RECTANGLE 22 32","RECTANGLE 22 32","RECTANGLE 24 33","RECTANGLE 24 31"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(63, ret, solution.tryToFit(var0, var1, var2));
}

void testCase64 () {
int var0 = 290;

int var1 = 290;

string _var2[] = {"RECTANGLE 840 310","RECTANGLE 857 311","RECTANGLE 851 311","RECTANGLE 859 303","RECTANGLE 858 308","RECTANGLE 858 309","RECTANGLE 841 309","RECTANGLE 859 311","RECTANGLE 300 857","RECTANGLE 311 848","RECTANGLE 301 842","RECTANGLE 301 859","RECTANGLE 300 857","RECTANGLE 302 853","RECTANGLE 314 840","RECTANGLE 308 850","RECTANGLE 230 852","RECTANGLE 210 842","RECTANGLE 213 850","RECTANGLE 227 859","RECTANGLE 216 840","RECTANGLE 217 852","RECTANGLE 213 845","RECTANGLE 211 846","RECTANGLE 852 211","RECTANGLE 841 223","RECTANGLE 849 221","RECTANGLE 847 212","RECTANGLE 853 218","RECTANGLE 846 219","RECTANGLE 860 214","RECTANGLE 857 224","RECTANGLE 314 227","RECTANGLE 304 227","RECTANGLE 314 227","RECTANGLE 315 229","RECTANGLE 311 230","RECTANGLE 304 211","RECTANGLE 305 222","RECTANGLE 313 213","RECTANGLE 226 315","RECTANGLE 215 315","RECTANGLE 227 303","RECTANGLE 219 313","RECTANGLE 230 308","RECTANGLE 222 315","RECTANGLE 218 317","RECTANGLE 223 308","RECTANGLE 215 320","RECTANGLE 224 318"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(64, ret, solution.tryToFit(var0, var1, var2));
}

void testCase65 () {
int var0 = 70;

int var1 = 65;

string _var2[] = {"RECTANGLE 17 83","RECTANGLE 17 81","RECTANGLE 18 81","RECTANGLE 16 81","RECTANGLE 16 83","RECTANGLE 18 81","RECTANGLE 17 81","RECTANGLE 17 81","RECTANGLE 83 17","RECTANGLE 81 17","RECTANGLE 82 17","RECTANGLE 82 17","RECTANGLE 81 17","RECTANGLE 81 16","RECTANGLE 82 16","RECTANGLE 83 16","RECTANGLE 79 16","RECTANGLE 80 17","RECTANGLE 80 18","RECTANGLE 81 16","RECTANGLE 80 16","RECTANGLE 80 18","RECTANGLE 79 18","RECTANGLE 79 18","RECTANGLE 17 81","RECTANGLE 16 80","RECTANGLE 18 79","RECTANGLE 17 81","RECTANGLE 16 79","RECTANGLE 17 81","RECTANGLE 18 81","RECTANGLE 18 79","RECTANGLE 83 79","RECTANGLE 83 81","RECTANGLE 81 80","RECTANGLE 83 81","RECTANGLE 83 80","RECTANGLE 82 79","RECTANGLE 81 81","RECTANGLE 83 80","RECTANGLE 79 82","RECTANGLE 80 83","RECTANGLE 79 81","RECTANGLE 80 81","RECTANGLE 79 82","RECTANGLE 79 83","RECTANGLE 79 81","RECTANGLE 79 82","RECTANGLE 80 81","RECTANGLE 79 82"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(65, ret, solution.tryToFit(var0, var1, var2));
}

void testCase66 () {
int var0 = 700;

int var1 = 650;

string _var2[] = {"RECTANGLE 153 810","RECTANGLE 156 817","RECTANGLE 154 812","RECTANGLE 158 807","RECTANGLE 156 810","RECTANGLE 168 807","RECTANGLE 157 808","RECTANGLE 158 820","RECTANGLE 801 152","RECTANGLE 800 159","RECTANGLE 815 154","RECTANGLE 802 170","RECTANGLE 818 158","RECTANGLE 805 162","RECTANGLE 801 163","RECTANGLE 800 165","RECTANGLE 792 152","RECTANGLE 794 154","RECTANGLE 789 166","RECTANGLE 783 170","RECTANGLE 784 163","RECTANGLE 780 150","RECTANGLE 799 162","RECTANGLE 794 159","RECTANGLE 166 800","RECTANGLE 151 793","RECTANGLE 162 791","RECTANGLE 169 781","RECTANGLE 162 787","RECTANGLE 168 781","RECTANGLE 167 793","RECTANGLE 166 798","RECTANGLE 801 786","RECTANGLE 820 787","RECTANGLE 807 788","RECTANGLE 800 782","RECTANGLE 801 791","RECTANGLE 800 781","RECTANGLE 808 798","RECTANGLE 815 793","RECTANGLE 785 803","RECTANGLE 794 816","RECTANGLE 796 815","RECTANGLE 781 810","RECTANGLE 790 807","RECTANGLE 798 819","RECTANGLE 794 804","RECTANGLE 790 813","RECTANGLE 799 813","RECTANGLE 780 809"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "NO", "YES", "NO", "YES", "YES", "YES", "YES", "YES", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(66, ret, solution.tryToFit(var0, var1, var2));
}

void testCase67 () {
int var0 = 535;

int var1 = 552;

string _var2[] = {"RECTANGLE 577 192","RECTANGLE 577 191"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(67, ret, solution.tryToFit(var0, var1, var2));
}

void testCase68 () {
int var0 = 502;

int var1 = 520;

string _var2[] = {"RECTANGLE 570 153","RECTANGLE 569 153","RECTANGLE 570 152","RECTANGLE 569 153","RECTANGLE 570 152","RECTANGLE 569 153","RECTANGLE 570 152","RECTANGLE 569 153","RECTANGLE 570 153","RECTANGLE 570 152"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "NO", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(68, ret, solution.tryToFit(var0, var1, var2));
}

void testCase69 () {
int var0 = 206;

int var1 = 215;

string _var2[] = {"RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79","RECTANGLE 219 79"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(69, ret, solution.tryToFit(var0, var1, var2));
}

void testCase70 () {
int var0 = 107;

int var1 = 235;

string _var2[] = {"RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29","RECTANGLE 239 29"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(70, ret, solution.tryToFit(var0, var1, var2));
}

void testCase71 () {
int var0 = 139;

int var1 = 141;

string _var2[] = {"RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29","RECTANGLE 169 29"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(71, ret, solution.tryToFit(var0, var1, var2));
}

void testCase72 () {
int var0 = 602;

int var1 = 660;

string _var2[] = {"RECTANGLE 676 220","RECTANGLE 676 221","RECTANGLE 677 220","RECTANGLE 220 676","RECTANGLE 676 220","RECTANGLE 676 221","RECTANGLE 677 220","RECTANGLE 220 676","RECTANGLE 676 220","RECTANGLE 676 221","RECTANGLE 677 220","RECTANGLE 220 676","RECTANGLE 676 220","RECTANGLE 676 221","RECTANGLE 677 220","RECTANGLE 220 676","RECTANGLE 676 220","RECTANGLE 676 221","RECTANGLE 677 220","RECTANGLE 220 676","RECTANGLE 676 220","RECTANGLE 676 221","RECTANGLE 677 220","RECTANGLE 220 676","RECTANGLE 676 220","RECTANGLE 676 221","RECTANGLE 677 220","RECTANGLE 220 676","RECTANGLE 676 220","RECTANGLE 676 221","RECTANGLE 677 220","RECTANGLE 220 676","RECTANGLE 676 220","RECTANGLE 676 221","RECTANGLE 677 220","RECTANGLE 220 676","RECTANGLE 676 220","RECTANGLE 676 221","RECTANGLE 677 220","RECTANGLE 220 676","RECTANGLE 676 220","RECTANGLE 676 221","RECTANGLE 677 220","RECTANGLE 220 676","RECTANGLE 676 220","RECTANGLE 676 221","RECTANGLE 677 220","RECTANGLE 220 676"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "NO", "NO", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(72, ret, solution.tryToFit(var0, var1, var2));
}

void testCase73 () {
int var0 = 998;

int var1 = 47;

string _var2[] = {"RECTANGLE 1000 1","RECTANGLE 50 50","CIRCLE 44","CIRCLE 45","CIRCLE 46","RECTANGLE 999 1","CIRCLE 23","CIRCLE 22","RECTANGLE 46 46","RECTANGLE 998 1","RECTANGLE 997 1","RECTANGLE 999 1","CIRCLE 24"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "YES", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(73, ret, solution.tryToFit(var0, var1, var2));
}

void testCase74 () {
int var0 = 83;

int var1 = 64;

string _var2[] = {"CIRCLE 31","CIRCLE 32","CIRCLE 33","RECTANGLE 5 100","RECTANGLE 100 5","RECTANGLE 101 5","RECTANGLE 5 101","RECTANGLE 100 6","RECTANGLE 6 100","RECTANGLE 99 5","RECTANGLE 5 99","RECTANGLE 100 4","RECTANGLE 4 100","RECTANGLE 104 1","RECTANGLE 1 104","RECTANGLE 103 1","RECTANGLE 1 103","RECTANGLE 64 83","RECTANGLE 83 64","RECTANGLE 63 83","RECTANGLE 83 63","RECTANGLE 65 83","RECTANGLE 83 65"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "NO", "YES", "YES", "NO", "NO", "NO", "NO", "YES", "YES", "YES", "YES", "NO", "NO", "YES", "YES", "YES", "YES", "YES", "YES", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(74, ret, solution.tryToFit(var0, var1, var2));
}

void testCase75 () {
int var0 = 10;

int var1 = 10;

string _var2[] = {"CIRCLE 9"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(75, ret, solution.tryToFit(var0, var1, var2));
}

void testCase76 () {
int var0 = 143;

int var1 = 250;

string _var2[] = {"RECTANGLE 143 250","RECTANGLE 57 100","RECTANGLE 250 143","RECTANGLE 250 142","RECTANGLE 251 1","RECTANGLE 251 50","RECTANGLE 251 130","RECTANGLE 300 100","RECTANGLE 1000 1000","RECTANGLE 1 1","RECTANGLE 144 251","RECTANGLE 300 1","CIRCLE 143"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "YES", "YES", "YES", "NO", "NO", "NO", "NO", "YES", "NO", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(76, ret, solution.tryToFit(var0, var1, var2));
}

void testCase77 () {
int var0 = 10;

int var1 = 10;

string _var2[] = {"CIRCLE 10"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(77, ret, solution.tryToFit(var0, var1, var2));
}

void testCase78 () {
int var0 = 10;

int var1 = 100;

string _var2[] = {"RECTANGLE 99 9","CIRCLE 22","CIRCLE 6"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "NO", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(78, ret, solution.tryToFit(var0, var1, var2));
}

void testCase79 () {
int var0 = 100;

int var1 = 10;

string _var2[] = {"RECTANGLE 99 9","CIRCLE 22","CIRCLE 5","CIRCLE 6"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "NO", "YES", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(79, ret, solution.tryToFit(var0, var1, var2));
}

void testCase80 () {
int var0 = 800;

int var1 = 950;

string _var2[] = {"RECTANGLE 250 1000","RECTANGLE 1000 250","RECTANGLE 251 1000","RECTANGLE 249 1000","RECTANGLE 251 999","RECTANGLE 251 990","RECTANGLE 251 980","RECTANGLE 990 251","RECTANGLE 400 960","RECTANGLE 300 970","RECTANGLE 500 500","RECTANGLE 1 1000","RECTANGLE 960 500","RECTANGLE 234 987","RECTANGLE 1 1","RECTANGLE 999 999","RECTANGLE 1000 1","RECTANGLE 123 321","RECTANGLE 576 729","RECTANGLE 953 240","CIRCLE 1000","CIRCLE 399","CIRCLE 401","CIRCLE 400","CIRCLE 1"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "YES", "NO", "YES", "YES", "YES", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "YES", "YES", "NO", "YES", "YES", "YES", "YES", "NO", "YES", "NO", "YES", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(80, ret, solution.tryToFit(var0, var1, var2));
}

void testCase81 () {
int var0 = 10;

int var1 = 100;

string _var2[] = {"RECTANGLE 99 9","CIRCLE 22"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(81, ret, solution.tryToFit(var0, var1, var2));
}

void testCase82 () {
int var0 = 50;

int var1 = 50;

string _var2[] = {"CIRCLE 50"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(82, ret, solution.tryToFit(var0, var1, var2));
}

void testCase83 () {
int var0 = 10;

int var1 = 10;

string _var2[] = {"CIRCLE 8"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(83, ret, solution.tryToFit(var0, var1, var2));
}

void testCase84 () {
int var0 = 100;

int var1 = 100;

string _var2[] = {"RECTANGLE 100 100","CIRCLE 51"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(84, ret, solution.tryToFit(var0, var1, var2));
}

void testCase85 () {
int var0 = 100;

int var1 = 80;

string _var2[] = {"RECTANGLE 128 1","RECTANGLE 127 1","RECTANGLE 126 1","RECTANGLE 126 2","RECTANGLE 126 3","RECTANGLE 125 4","RECTANGLE 120 5","CIRCLE 40","CIRCLE 41","RECTANGLE 122 7","RECTANGLE 111 2","RECTANGLE 100 100"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "YES", "YES", "YES", "NO", "NO", "YES", "YES", "NO", "NO", "YES", "NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(85, ret, solution.tryToFit(var0, var1, var2));
}

void testCase86 () {
int var0 = 100;

int var1 = 100;

string _var2[] = {"CIRCLE 90"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(86, ret, solution.tryToFit(var0, var1, var2));
}

void testCase87 () {
int var0 = 100;

int var1 = 100;

string _var2[] = {"CIRCLE 99"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(87, ret, solution.tryToFit(var0, var1, var2));
}

void testCase88 () {
int var0 = 19;

int var1 = 23;

string _var2[] = {"RECTANGLE 5 25"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(88, ret, solution.tryToFit(var0, var1, var2));
}

void testCase89 () {
int var0 = 100;

int var1 = 100;

string _var2[] = {"CIRCLE 51","CIRCLE 99","CIRCLE 100","CIRCLE 50"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO", "NO", "NO", "YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(89, ret, solution.tryToFit(var0, var1, var2));
}

void testCase90 () {
int var0 = 222;

int var1 = 146;

string _var2[] = {"RECTANGLE 240 30"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(90, ret, solution.tryToFit(var0, var1, var2));
}

void testCase91 () {
int var0 = 1;

int var1 = 1;

string _var2[] = {"CIRCLE 1"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"NO"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(91, ret, solution.tryToFit(var0, var1, var2));
}

void testCase92 () {
int var0 = 34;

int var1 = 43;

string _var2[] = {"RECTANGLE 50 5"};
vector <string> var2 (_var2, _var2 + (sizeof(_var2) / sizeof(_var2[0])));

string _ret[] = {"YES"};
vector <string> ret (_ret, _ret + (sizeof(_ret) / sizeof(_ret[0])));

assertEquals(92, ret, solution.tryToFit(var0, var1, var2));
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
		case(84): testCase84(); break;
		case(85): testCase85(); break;
		case(86): testCase86(); break;
		case(87): testCase87(); break;
		case(88): testCase88(); break;
		case(89): testCase89(); break;
		case(90): testCase90(); break;
		case(91): testCase91(); break;
		case(92): testCase92(); break;
			default: cerr << "No such test case: " << testCase << endl; exit (1);
		}
		End = clock();
		tempo = (double) (End - Begin) / CLOCKS_PER_SEC;
		
		printf (" in %.4lfs\n", tempo);
	}

};

bool PackingShapesTest::passed;

int main(int argc, char *argv[]) {
	int cnt = 0, cntAc = 0, caso = -1;
	bool passedAll = true;
	
	if (argc > 1) {
		caso = atoi (argv[1]);
		if (caso == 93)
			return 100;
	}
	
    for (int i = 0; i < 93; i++) {
    	if (caso != -1 && caso != i) continue;
    	
		cnt++;
		PackingShapesTest *test = new PackingShapesTest ();
		test->runTest(i);
		passedAll &= PackingShapesTest::passed;
		if (PackingShapesTest::passed) cntAc++;
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
