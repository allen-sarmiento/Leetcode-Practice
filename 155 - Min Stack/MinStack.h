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
        cout << "MinStack\n";
    }
    
    void push(int val) {
        cout << "push(" << val << ")\n";
        if (stk.size() == 0 || val < min) {
            mins.emplace(val, 0);
            min = val;
        }
        stk.push(val);
        mins.top().second++;
    }
    
    void pop() {
        cout << "pop()\n";
        mins.top().second--;
        if (mins.top().second == 0) {
            mins.pop();
            min = mins.top().first;
        }
        stk.pop();
    }
    
    int top() {
        cout << "top()\n";
        return stk.top();
    }
    
    int getMin() {
        cout << "getMin()\n";
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