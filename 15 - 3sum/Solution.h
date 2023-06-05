#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

#pragma once

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        /*
            Triplets must have either:
            - 1 Zero, and both positives and negatives of a number [-n,0,n]
            - 2 Positives and 1 negative that are equal in magnitude [-(m+n), m, n]
            - 2 negatives and 1 positive that are equal in magnitude [-m, -n, -(m+n)]
            - 3 Zeroes [0,0,0]

            i.e.

            * A triplet must have three numbers [a,b,c] where a+b = -c
            * Must have no duplicate triplet
        */

        // Stores all triplets
        vector<vector<int>> result;

        // Sort the input array in descending order
        sort(nums.rbegin(), nums.rend());

        int lastC = NULL;
        for (int c = 0; c < nums.size(); c++) {
            int a = 1, b = nums.size()-1;
            while(a < b) {
                int sum = nums[a] + nums[b];
                if (sum == -nums[0] && nums[0] != lastC) {
                    result.push_back({nums[a], nums[b], nums[0]});
                    lastC = nums[0];
                    a++;
                } 
                else if (sum < -nums[0]) b--;
                else a++;
            }
            // Swap so that c is always at index 0
            swap(nums[0], nums[c]);
            lastC = nums[0];
        }
        return result;
    }
};