#include "WaterBot.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class WaterBotTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    WaterBot solution;

    void testCase0() {
        string garden_[] = {"5....", ".....", ".....", ".....", "...RW"};
        vector<string> garden(garden_, garden_ + (sizeof(garden_) / sizeof(garden_[0])));
		int carryLimit = 5;
		int expected_ = 16;
        assertEquals(0, expected_, solution.minTime(garden, carryLimit));
    }

    void testCase1() {
        string garden_[] = {"3.2..", ".....", ".....", "....R", "....W"};
        vector<string> garden(garden_, garden_ + (sizeof(garden_) / sizeof(garden_[0])));
		int carryLimit = 5;
		int expected_ = 16;
        assertEquals(1, expected_, solution.minTime(garden, carryLimit));
    }

    void testCase2() {
        string garden_[] = {".5555", ".....", ".....", "....R", "....W"};
        vector<string> garden(garden_, garden_ + (sizeof(garden_) / sizeof(garden_[0])));
		int carryLimit = 3;
		int expected_ = 85;
        assertEquals(2, expected_, solution.minTime(garden, carryLimit));
    }

    void testCase3() {
        string garden_[] = {"R.....55", "......55", "........", "........", "........", ".......W"};
        vector<string> garden(garden_, garden_ + (sizeof(garden_) / sizeof(garden_[0])));
		int carryLimit = 2;
		int expected_ = -1;
        assertEquals(3, expected_, solution.minTime(garden, carryLimit));
    }

    void testCase4() {
        string garden_[] = {"R.......", "........", "....5...", "...5W5..", "....5...", "........"};
        vector<string> garden(garden_, garden_ + (sizeof(garden_) / sizeof(garden_[0])));
		int carryLimit = 4;
		int expected_ = -1;
        assertEquals(4, expected_, solution.minTime(garden, carryLimit));
    }

    void testCase5() {
        string garden_[] = {".1", ".2", ".3", ".4", "R.", "W."};
        vector<string> garden(garden_, garden_ + (sizeof(garden_) / sizeof(garden_[0])));
		int carryLimit = 5;
		int expected_ = 28;
        assertEquals(5, expected_, solution.minTime(garden, carryLimit));
    }

    void testCase6() {
        string garden_[] = {"R....", ".....", ".....", ".....", "....W"};
        vector<string> garden(garden_, garden_ + (sizeof(garden_) / sizeof(garden_[0])));
		int carryLimit = 5;
		int expected_ = 0;
        assertEquals(6, expected_, solution.minTime(garden, carryLimit));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            case (6): testCase6(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 7; i++) {
        WaterBotTest test;
        test.runTest(i);
    }
}
