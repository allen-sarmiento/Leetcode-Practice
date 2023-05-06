/*
    Date 5/5/2023
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {

        // negative numbers are not palindromes
        if (x < 0)
            return false;

        int temp = x;                   // original x
        unsigned long long rev = 0;     // reverse of x
        unsigned int digit;             // last digit of x

        // for each digit in x
        while (x > 0) {
            // get the last digit
            digit = x%10;
            // cut the last digit from x
            x/=10;
            // append the last digit to rev
            rev = rev*10 + digit;
        }

        // check if reverse matches original x
        return rev == temp;
    }
};