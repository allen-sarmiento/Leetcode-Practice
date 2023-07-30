/*
    Date: 7/29/2023
    Time Complexity: O(log(n))
    Space Complexity: O(log(n))
*/

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearchRecurse(nums, target, 0, nums.size()-1);
    }
private:
    int binarySearchRecurse(vector<int>& nums, int target, int low, int high) {
        int mid = (low+high)/2;
        if (nums[mid] == target)
            return mid;
        else if (low >= high)
            return -1;
        else if (nums[mid] < target)
            return binarySearchRecurse(nums, target, mid+1, high);
        else
            return binarySearchRecurse(nums, target, low, mid-1);
    }
};