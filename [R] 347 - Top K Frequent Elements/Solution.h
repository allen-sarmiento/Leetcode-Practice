/*
    Date: 5/9/2023
    Time Complexity: O(nlog(k))
    Space Complexity: O(n)
*/

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Map each integer to its frequency
        unordered_map<int, int> hm;
        for (int& i : nums)
            hm[i]++;

        // Sort the priority queue based on the greater of the first of the pair
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;

        // Add each key-value pair into a priority queue, pairs are added as (value, key)
        // since we are sorting by value
        for (auto iter = hm.begin(); iter != hm.end(); iter++)
            pq.push(make_pair(iter->second, iter->first));

        // Add the front k of the queue to a vector
        vector<int> ans;
        for (;k > 0; k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
            
        return ans;
    }
};