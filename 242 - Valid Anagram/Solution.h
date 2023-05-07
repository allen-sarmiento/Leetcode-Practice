/*
    Date: 5/7/2023
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        unordered_map<char, int> hm;

        for (int i = 0; i < s.length(); i++) {

            // Add char from str s, increment
            auto iter = hm.find(s[i]);
            if (iter != hm.end())
                iter->second++;
            else
                hm[s[i]] = 1;

            // Add char from str t, decrement
            iter = hm.find(t[i]);
            if (iter != hm.end())
                iter->second--;
            else
                hm[t[i]] = -1;
        }

        // Check for imbalance
        for (auto iter = hm.begin(); iter != hm.end(); iter++)
            if (iter->second != 0)
                return false;
        return true;
    }
};