/*
    Date: 5/21/2023
    Time Complexity: O(nlog(n))
    Space Complexity: O(n)
*/

#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#pragma once

using namespace std;

class Solution {
public:
    float getTime(int target, int pos, int spd) {
        return (target - pos)/(float)spd;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();
        vector<pair<int,int>> cars;
        for (int i = 0; i < n; i++)
            cars.push_back(make_pair(position[i],speed[i]));
        sort(cars.begin(), cars.end());

        vector<pair<int,int>> fleets;

        // loop through all cars in reverse (closest to target first)
        for (int i = n-1; i >= 0; i--) {
            fleets.push_back(cars[i]);
            int k = fleets.size();
            if (k >= 2 &&
                getTime(target, fleets[k-1].first, fleets[k-1].second) <=
                getTime(target, fleets[k-2].first, fleets[k-2].second)) {
                fleets.pop_back();
            }
        }
        return fleets.size();
    }
};