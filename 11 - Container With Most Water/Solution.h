#include <vector>

using namespace std;

/*
    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store.

    Brute-force Approach:
        - Loop through each possible combination pair of lines and calculate amount of water that pair can hold.
        - Store amounts in a list and find the maximum

            vector<int> areas;
            for (int h1 = 0; h1 < height.size(); h1++) {
                for (int h2 = h1+1; h2 < height.size(); h2++) {
                    areas.push_back(min(height[h1], height[h2]) * (h2-h1));
                }
            }
            
            int maxA = INT_MIN;
            for (int a : areas) {
                if (a > maxA)
                    maxA = a;
            }
            return maxA;

    Optimized Approach:
        - Start with two pointers, left and right.
        - Find the area with these lines
        - Move the shorter of the left/right pointers
*/

class Solution {
public:

    int maxArea(vector<int>& height) {

        // lambda function for finding area based on two indices
        auto getArea = [&](int L, int R) -> int {
            int area = min(height[L], height[R]) * (R-L);
            return area;
        };
        
        vector<int> areas;
        
        int L = 0, R = height.size()-1;
        int lp = 0, rp = height.size()-1;
        int area = getArea(L, R);
        int maxArea = area;

        while (lp < rp) {
            if (height[rp] < height[lp]) {          // Find new right pointer
                while (lp < rp && getArea(L, rp) <= getArea(L, R))
                    rp--;
                area = getArea(L, rp);
            } else if (height[lp] < height[rp]) {   // Find new left pointer
                while (lp < rp && getArea(lp, R) <= getArea(L, R))
                    lp++;
                area = getArea(lp, R);         
            } else { // Find new left and right pointers
                while (lp < rp && getArea(lp + 1, R) <= getArea(L, R))
                    lp++;
                while (lp < rp && getArea(L, rp - 1) <= getArea(L, R))
                    rp--;
                area = getArea(lp, rp);
            }
            if (area > maxArea) {
                maxArea = area;
                L = lp;
                R = rp;
            }
        }
        return maxArea;
    }
};