/*
    Date 5/6/2023
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // hashset to store unique collection of numbers
        unordered_set<int> s;

        // for each number in list
        for (int n : nums) {

            // check if number is already in set
            auto iter = s.find(n);
            if (iter != s.end())
                return true;
            
            // otherwise insert number in set
            s.insert(n);
        }
        
        // return false if no duplicates found after iterating
        return false;
    }
};