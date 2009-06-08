#include "WorldPeace.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class WorldPeaceTest {

    static void assertEquals(int testCase, const long long& expected, const long long& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    WorldPeace solution;

    void testCase0() {
		int k = 4;
        int countries_[] = {4, 4, 4, 4, 4};
        vector<int> countries(countries_, countries_ + (sizeof(countries_) / sizeof(countries_[0])));
		long long expected_ = 5LL;
        assertEquals(0, expected_, solution.numGroups(k, countries));
    }

    void testCase1() {
		int k = 5;
        int countries_[] = {1, 2, 3, 4, 5, 6};
        vector<int> countries(countries_, countries_ + (sizeof(countries_) / sizeof(countries_[0])));
		long long expected_ = 3LL;
        assertEquals(1, expected_, solution.numGroups(k, countries));
    }

    void testCase2() {
		int k = 2;
        int countries_[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
        vector<int> countries(countries_, countries_ + (sizeof(countries_) / sizeof(countries_[0])));
		long long expected_ = 3000000000LL;
        assertEquals(2, expected_, solution.numGroups(k, countries));
    }

    void testCase3() {
		int k = 7;
        int countries_[] = {96, 17, 32, 138, 112, 50, 7, 19, 412, 23, 14, 50, 47, 343, 427, 22, 39};
        vector<int> countries(countries_, countries_ + (sizeof(countries_) / sizeof(countries_[0])));
		long long expected_ = 166LL;
        assertEquals(3, expected_, solution.numGroups(k, countries));
    }

    void testCase4() {
		int k = 10;
        int countries_[] = {638074479, 717901019, 910893151, 924124222, 991874870, 919392444, 729973192, 607898881, 838529741, 907090878, 632877562, 678638852, 749258866, 949661738, 784641190, 815740520, 689809286, 711327114, 658017649, 636727234, 871088534, 964608547, 867960437, 964911023, 642411618, 868318236, 793328473, 849540177, 960039699, 998262224, 775720601, 634685437, 743766982, 826321850, 846671921, 712570181, 676890302, 814283264, 958273130, 899003369, 909973864, 921987721, 978601888, 633027021, 896400011, 725078407, 662183572, 629843174, 617774786, 695823011};
        vector<int> countries(countries_, countries_ + (sizeof(countries_) / sizeof(countries_[0])));
		long long expected_ = 3983180234LL;
        assertEquals(4, expected_, solution.numGroups(k, countries));
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
        WorldPeaceTest test;
        test.runTest(i);
    }
}
