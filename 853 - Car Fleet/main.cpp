#include "Solution.h"
#include <iostream>

using namespace std;

int main() {
    Solution sol;
    vector<int> position{11,14,13,6};
    vector<int> speed {2,2,6,7};
    cout << sol.carFleet(16, position, speed);
    return 0;
}
