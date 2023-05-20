#include <vector>
#include <stack>
#include <algorithm>
#pragma once

using namespace std;

/*
    Input:  target      = 100
            position    = [0, 2, 4]
            speed       = [4, 2, 1]
            fpos        = [x, x, 96] (x indicates > 100)
    Output: 1

    carIndexes: [4]
    numFleets = 2;
    maxSPos = 4;
    hours = 96;
*/

class Solution {
public:

    int getFpos(int index, int time, int target, vector<int>& position, vector<int>& speed) {
        int fpos = position[index] + speed[index]*time;
        fpos = (fpos > target) ? target : fpos;
        return fpos;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int> carIndexes;
        int numFleets = position.size();
        int maxSpos = distance(position.begin(), max_element(position.begin(), position.end()));
        int hours = (target - position[maxSpos])/speed[maxSpos];
        carIndexes.push(maxSpos);
        for (int i = 0; i < position.size(); i++) {
            if (i == maxSpos) continue;
            int temp = i;
            while ( !carIndexes.empty() &&
                    (getFpos(i, hours, target, position, speed) >=
                    getFpos(carIndexes.top(), hours, target, position, speed)) &&
                    position[i] < position[carIndexes.top()]) {
                numFleets--;
                if (temp == i) temp = carIndexes.top();
                carIndexes.pop();
            }
            carIndexes.push(temp);
        }
        return carIndexes.size();
    }
};