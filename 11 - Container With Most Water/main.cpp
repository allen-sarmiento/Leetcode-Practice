#include "Solution.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    Solution sol;
    vector<int> nums = {2,3,4,5,18,17,6};
    int result = sol.maxArea(nums);
    cout << result << endl;
    return 0;
}