/*
    Date: 11/1/2023
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> unique;
        int maxLength = 0;
        int lp = 0;
        for (int i = 0; i < s.size(); i++) {
            if (unique.find(s[i]) != unique.end()) {
                // Update max length
                if (unique.size() > maxLength) maxLength = unique.size(); 
                // remove all before original  
                for (; s[lp] != s[i]; lp++) unique.erase(s[lp]);
                // remove original           
                unique.erase(s[lp]);                                        
                lp++;
            }
            unique.insert(s[i]);
        }
        if (unique.size() > maxLength) maxLength = unique.size();
        return maxLength;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("aabaab!");
}