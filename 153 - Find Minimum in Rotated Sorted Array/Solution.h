/*
    Date: 8/16/2023
    Time Complexity: O(log(n))
    Space Complexity: O(1)
*/

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lp = 0, rp = nums.size()-1;
        int min = lp;

        while (lp <= rp && lp <= nums.size()-1 && rp >= 0) {
            int mp = (lp+rp)/2;

            if (nums[mp] >= nums[lp]) {                 // Discard left side (increasing from left to middle)
                if (nums[lp] < nums[min]) min = lp;     // New min would be lp
                lp = mp+1;
            } else {                                    // Discard right side (decreasing from left to middle); 
                if (nums[mp] < nums[min]) min = mp;     // New min would be mp
                rp = mp-1;
            }
        }
        return nums[min];
    }
};