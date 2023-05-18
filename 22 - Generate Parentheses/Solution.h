/*
    Date: 5/17/2023
    Time Complexity: O(n*2(2n))
    Space Complexity: O(n*2(2n))

    Uses backtracking/brute force
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        addParen(n, 0, 0, "", res);
        return res;
    }

    void addParen(int n, int open, int close, string str, vector<string>& res) {
        if (open == n && close == n) {
            res.push_back(str);
            return;
        }
        if (open < n)
            addParen(n, open+1, close, str+'(', res);
        if (open > close)
            addParen(n, open, close+1, str+')', res);
    }
};