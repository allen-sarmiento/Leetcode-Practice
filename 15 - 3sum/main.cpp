#include "Solution.h"
#include <vector>
#include <iostream>

using namespace std;

void printVectorOfVectors(const vector<vector<int>>& vec) {
    for (const auto& innerVec : vec) {
        for (int num : innerVec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = sol.threeSum(nums);
    printVectorOfVectors(result);
    return 0;
}