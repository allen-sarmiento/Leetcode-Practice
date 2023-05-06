/*
    Date 5/4/2023
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> hm;     // hashmap of digits to indices
        vector<int> v;                  // stores answer
        
        // for each number in list
        for (int i = 0; i < nums.size(); i++) {

            // find matching number and check if it is in hashmap
            int diff = target-nums[i];
            auto iter = hm.find(diff);

            // if it is in the hashmap, then duplicate found
            if (iter != hm.end()) {
                v.push_back(i);
                v.push_back(iter->second);      
                return v;
            }

            // otherwise, add the number to the hashmap
            hm[nums[i]] = i;
        }
        
        // return empty list if no match found
        return v;
    }
};