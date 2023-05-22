#include "Solution.h"
#include <iostream>

using namespace std;

int main() {
    Solution sol;
    vector<int> position{10,8,0,5,3};
    vector<int> speed {2,4,1,1,3};
    cout << sol.carFleet(12, position, speed);
    return 0;
}
