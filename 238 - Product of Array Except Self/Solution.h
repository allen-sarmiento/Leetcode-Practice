/*
    Date: 5/10/2023
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // Create two lists of running products: one from the front and one from the back
        int prefixProd = 1, suffixProd = 1;
        vector<int> prefixes(nums.size()), suffixes(nums.size()), answer(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            prefixProd *= nums[i];
            suffixProd *= nums[nums.size()-1-i];
            prefixes[i] = prefixProd;
            suffixes[nums.size()-1-i] = suffixProd;
        }

        // Answer is the product of the prefix before and suffix after the index
        for (int i = 0; i < nums.size(); i++) {
            int prefix = (i-1 < 0) ? 1 : prefixes[i-1];
            int suffix = (i+1 > nums.size()-1) ? 1 : suffixes[i+1];
            answer[i] = prefix * suffix;
        }

        return answer;
    }
};