/*
    Date: 7/29/2023
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <vector>

using namespace std;

/*
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
        int lp = 0, rp = height.size()-1;
        int maxArea = -1;
        while (lp < rp) {
            int area = min(height[lp], height[rp]) * (rp-lp);
            if (area > maxArea)
                maxArea = area;
            if (height[lp] > height[rp]) rp--;
            else lp++;
        }
        return maxArea;
    }
};