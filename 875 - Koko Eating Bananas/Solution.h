#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

/*
    - vector piles represents a list of piles of bananas, with the ith pile containing piles[i] bananas
    - find th minimum bananas-per-hour speed k such that she can eat all bananas in h hours

    - Does not make sense for k to be lower than the smallest pile
    - Does not make sense to have a k higher than the largest pile

    - smallest pile < k < largest pile

    1. sort the list
        - get the smallest and largest pile to get a range for possible k

    2. iterate through the piles with each possible k and get the time it takes n to finish all the piles
    3. find the k with the smallest 

*/

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
            
            if (n > h) {        // Discard lowers
                minK = midK+1;
            } else {            // Valid k found, discard uppers
                if (midK < smallestK) smallestK = midK;
                maxK = midK-1;
            }
        }

        return smallestK;
    }

    int getN(vector<int>& piles, int h, int k) {
        int N = 0;
        for (int p : piles) {
            N += ceil(float(p)/k);
            if (N > h) return h+1;
        }
            
        return N;
    }
};