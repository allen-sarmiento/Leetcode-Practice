/*
    Date: 5/16/2023
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <vector>
#include <string>
#include <stack>
#pragma once

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {
                int op1, op2;
                op2 = stk.top();
                stk.pop();
                op1 = stk.top();
                stk.pop();
                if (token[0] == '+')
                    stk.push(op1+op2);
                else if (token[0] == '-')
                    stk.push(op1-op2);
                else if (token[0] == '*')
                    stk.push(op1*op2);
                else
                    stk.push(op1/op2);
            } else
                stk.push(stoi(token));
        }
        return stk.top();
    }
};