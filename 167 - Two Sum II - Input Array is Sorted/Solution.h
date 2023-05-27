/*
    Date: 5/26/2023
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int indexL = 0, indexR = numbers.size()-1;
        while (true) {
            int sum = numbers[indexL] + numbers[indexR];   
            if (sum == target) break;
            else if (sum < target) indexL++;
            else indexR--;
        }
        return {indexL+1, indexR+1};
    }
};