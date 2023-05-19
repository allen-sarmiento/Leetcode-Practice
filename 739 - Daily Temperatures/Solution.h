/*
    Date: 5/18/2023
    Time Complexity: O(n)
    Space Complexity: O(n)

    Monotonic Decreasing Stack
*/

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                res[stk.top()] = i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};