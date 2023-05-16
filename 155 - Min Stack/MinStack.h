/*
    Date: 5/15/2023
    Time Complexity: O(1)
    Space Complexity: O(n)
*/


#include <stack>
#include <iostream>
#pragma once

using namespace std;

/*
    A minimum will only change if that minimum is removed from
    the stack. Minimums will be replaced in order of insertion.
    Use a second stack to keep track of minimums and the length
    of each current minimum.
*/

class MinStack {
public:

    // Data stack
    stack<int> stk;
    // Minimum stack. First is value, second is length.
    stack<pair<int,int>> mins;
    int min;

    MinStack() {

    }
    
    void push(int val) {
        if (stk.size() == 0 || val < min) {
            mins.emplace(val, 0);
            min = val;
        }
        stk.push(val);
        mins.top().second++;
    }
    
    void pop() {
        mins.top().second--;
        if (mins.top().second == 0) {
            mins.pop();
            min = (mins.size() == 0) ? INT_MIN : mins.top().first;
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */