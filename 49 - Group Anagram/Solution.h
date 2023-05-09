/*
    Date: 5/8/2023
    Time Complexity: O(n * klog(k))
        n: size of list of strings
        k: length of the largest string
    Space Complexity: O(n)
*/

#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> hm;
        
        // Get anagram id from each string
        for (string s : strs) {
            string id = s;
            sort(id.begin(), id.end());
            auto iter = hm.find(id);
            if (iter != hm.end())
                iter->second.push_back(s);
            else
                hm[id] = vector<string>{s};
        }

        // Collect vectors into ans
        vector<vector<string>> ans;
        for (auto iter = hm.begin(); iter != hm.end(); iter++)
            ans.push_back(iter->second);
        return ans;
    }
};