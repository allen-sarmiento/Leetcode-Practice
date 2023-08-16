/*
    Date: 8/15/2023
    Time Complexity: O(n*log(largestP - largestP/h))
        - largestP - largestP/h is the length of the range of possible k
    Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        sort(piles.begin(), piles.end());
        int minK = ceil(float(piles[piles.size()-1])/h);
        int maxK = piles[piles.size()-1];
        int smallestK = INT_MAX;

        while (minK <= maxK) {
            int midK = (maxK+minK)/2;
            int n = getN(piles, h, midK);
            
            if (n > h)          // Discard lowers
                minK = midK+1;
            else {              // Valid k found, discard uppers
                if (midK < smallestK) smallestK = midK;
                maxK = midK-1;
            }
        }
        return smallestK;
    }

    int getN(vector<int>& piles, int h, int k) {
        int N = 0;
        for (int p : piles) {
            N += ceil(double(p)/k);
            if (N > h) return h+1;
        }   
        return N;
    }
};