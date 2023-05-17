#include "Solution.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    Solution sol;
    vector<string> v{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int c = sol.evalRPN(v);
    cout << c;
    return 0;
}