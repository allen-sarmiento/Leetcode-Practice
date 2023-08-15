#include <vector>
#pragma once

using namespace std;

/*
    You're given a m x n integer matrix 'matrix' with the following two properties:
        - Each row is sorted in non-decreasing order.
        - The first integer of each row is greater than the last integer of the previous row

    Given an integer 'target', return true if 'target' is in matrix or false otherwise

    You must write a solution O(log(m*n)) time complexity

    Solution:
        - Initialize 4 variables:
            - cLeft, cRight, cMid, rLow, rHigh, rMid
        - Two nested while-loops:
            - Outer while loop continues while rHigh > rLow && rLow >= rMid >= rHigh
                - Inner while loop continues while cRight > cLeft && cLeft >= cMid >= cRight
                    - If target == mid-mid cell, return true
                    - If target is > mid-mid cell, discard lowers
                    - If target is < mid-mid cell, discard uppers
                    - Get the index of the new middle col
                - Get the index of the new middle row
*/

class Solution {
public:
    bool SearchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = rows*cols-1, mid = right/2;

        while ((right >= left) && (mid >= left) && (mid <= right)) {
            int row = mid/cols, col = mid%cols;

            if (target == matrix[row][col]) return true;
            else if (target > matrix[row][col]) left = mid+1;
            else right = mid-1;

            mid = (right+left)/2;
        }
        return false;
    }
};