/*
    Date: 5/14/2023
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            // If c is an open
            if (c == '{' || c == '[' || c == '(')
                stk.push(c); 
            // Else c is a close
            else {
                if (stk.size() == 0) return false;
                if (
                    c == '}' && stk.top() == '{' ||
                    c == ']' && stk.top() == '[' ||
                    c == ')' && stk.top() == '(') {
                    stk.pop();
                } else return false;
            }
        }
        return (stk.size() == 0);
    }
};