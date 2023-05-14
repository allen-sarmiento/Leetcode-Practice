/*
    Date: 5/13/2023
    Time Complexity: O(n)
    Space Complexity: O(1)

    Reviewed: 5/14/2023
*/

#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // Sequence start numbers n have no number before them
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;
        for (int n : numSet) {
            if (numSet.find(n-1) == numSet.end()) {
                int seqLength = 1;
                while (numSet.find(n+seqLength) != numSet.end())
                    seqLength++;
                maxLength = max(maxLength, seqLength);
            }
        }
        return maxLength;
    }
};