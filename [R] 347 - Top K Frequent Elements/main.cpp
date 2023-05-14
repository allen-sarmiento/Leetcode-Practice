#include "Solution.h"

using namespace std;
int main() {
    Solution sol;
    vector<int> v{1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = sol.topKFrequent(v, k);
    return 0;
}