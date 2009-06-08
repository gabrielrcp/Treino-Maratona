#include "FloatingMedian.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class FloatingMedianTest {

  static void assertEquals(int testCase, const long long& expected, const long long& actual) {
    if (expected == actual) {
      cout << "Test case " << testCase << " PASSED!" << endl;
    } else {
      cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
    }
  }

  FloatingMedian solution;

  void testCase0() {
    int seed = 3;
    int mul = 1;
    int add = 1;
    int N = 10;
    int K = 3;
    long long expected_ = 60LL;
    assertEquals(0, expected_, solution.sumOfMedians(seed, mul, add, N, K));
  }

  void testCase1() {
    int seed = 10;
    int mul = 0;
    int add = 13;
    int N = 5;
    int K = 2;
    long long expected_ = 49LL;
    assertEquals(1, expected_, solution.sumOfMedians(seed, mul, add, N, K));
  }

  void testCase2() {
    int seed = 4123;
    int mul = 2341;
    int add = 1231;
    int N = 7;
    int K = 3;
    long long expected_ = 102186LL;
    assertEquals(2, expected_, solution.sumOfMedians(seed, mul, add, N, K));
  }

  void testCase3() {
    int seed = 47;
    int mul = 5621;
    int add = 1;
    int N = 125000;
    int K = 1700;
    long long expected_ = 4040137193LL;
    assertEquals(3, expected_, solution.sumOfMedians(seed, mul, add, N, K));
  }

    void testCase4() {
		int seed = 32321;
		int mul = 46543;
		int add = 32552;
		int N = 17;
		int K = 17;
		long long expected_ = 25569LL;
        assertEquals(4, expected_, solution.sumOfMedians(seed, mul, add, N, K));
    }

public: void runTest(int testCase) {
  switch (testCase) {
  case (0): testCase0(); break;
  case (1): testCase1(); break;
  case (2): testCase2(); break;
  case (3): testCase3(); break;
  case (4): testCase4(); break;
  default: cerr << "No such test case: " << testCase << endl; break;
  }
}

};

int main() {
    for (int i = 0; i < 5; i++) {
        FloatingMedianTest test;
        test.runTest(i);
    }
}
