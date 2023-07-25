/*
    Date: 7/26/2023
    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>

class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());     // O(nlog(n))

        int lastI = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {     // O(n)
            if (nums[i] == lastI) continue;

            int lp = i+1;
            int rp = nums.size()-1;
            while (lp < rp) {                       // O(n)
                int sum = nums[i] + nums[lp] + nums[rp];
                if (sum == 0) {
                    result.push_back({nums[i], nums[lp], nums[rp]});
                    lp++;
                    rp--;
                    while (lp < rp && nums[lp] == nums[lp-1])
                        lp++;   // Ensure that lp is unique
                    while (lp < rp && nums[rp] == nums[rp+1])
                        rp--;   // Ensure that rp is unique
                } else if (sum < 0) lp++;
                else rp--;
            }
            lastI = nums[i];
        }
        return result;
    }
};