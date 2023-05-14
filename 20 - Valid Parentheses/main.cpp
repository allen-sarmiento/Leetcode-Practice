#include <string>
#include <stack>

using namespace std;

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

int main() {

    isValid("(])");

    return 0;
}