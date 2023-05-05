#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> hm;
        vector<int> v;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target-nums[i];
            auto iter = hm.find(diff);
            if (iter != hm.end()) {
                v.push_back(i);
                v.push_back(iter->second);
                return v;
            }
            hm[nums[i]] = i;
        }
        return v;
    }
};