#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        /*
            prices:
            7   1   5   3   6   4

            diffs:
            7   
        */

        int low = 0, high = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] > prices[high]) high = i;
            else if (prices[i] < prices[low]) low = i;
        }
        return prices[high] - prices[low];
    }
};

int main() {
    return 0;
}