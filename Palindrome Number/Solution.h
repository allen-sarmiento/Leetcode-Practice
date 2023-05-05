using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int temp = x;
        unsigned long long rev = 0; 
        unsigned int digit;
        while (x > 0) {
            digit = x%10;
            x/=10;
            rev = rev*10 + digit;
        }
        return rev == temp;
    }
};