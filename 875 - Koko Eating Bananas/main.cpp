#include "Solution.h"
#include <iostream>

using namespace std;

int main() {
    Solution sol;
    vector<int> piles{1000000000,1000000000};
    int h = 3;
    cout << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}
