/*
    Date: 5/21/2023
    Time Complexity: O(n)
    Space Complexity: O(n)
        - Can be done in O(1) space
*/


#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string parse = "";
        for (char c : s)
            if (isalnum(c))
                parse += tolower(c);
        for (int i = 0; i < parse.length()/2; i++) {
            char &left = parse[i];
            char &right = parse[parse.length()-1-i];
            if (left != right)
                return false;
        }
        return true;
    }
};