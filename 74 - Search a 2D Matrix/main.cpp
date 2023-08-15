#include <vector>
#include <iostream>
#include "Solution.h"
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    Solution sol;
    vector<vector<int>> matrix;
    int seed = time(0);
    srand(seed);
    int ub = RAND_MAX-1, lb = 0, rows = 100, cols = 100;
    int size = rows*cols;

    // Generate Matrix
    vector<int> nums;
    for (int i = 0; i < size; i++)
        nums.push_back((rand() % (ub-lb+1))+lb);
    sort(nums.begin(), nums.end());

    // Fill Matrix
    auto iter = nums.begin();
    vector<int> row;
    for (auto iter = nums.begin(); iter != nums.end(); iter++) {
        row.push_back(*iter);
        if (row.size() == rows) {
            matrix.push_back(row);
            row.clear();
        }
    }

    // Print Matrix
    /*
    for (vector<int> row : matrix) {
        for (int n : row)
            cout << n << "\t";
        cout << endl;
    }
    */
    

    // Generate random target row
    lb = 0, ub = rows-1;
    int r = (rand() % (ub-lb+1))+lb;
    // Generate random target col
    lb = 0, ub = cols-1;
    int c = (rand() % (ub-lb+1))+lb;

    cout << "Target (r,c): (" << r << ", " << c << ")\n";
    cout << "Target Value: " << matrix[r][c] << "\n\n";
    

    cout << "Result: " << sol.SearchMatrix(matrix, matrix[r][c]) << ", Answer: 1" << endl;
    cout << "Result: " << sol.SearchMatrix(matrix, lb-1) << ", Answer: ";

    bool found = false;
    for (vector<int> r : matrix) {
        if (found) break;
        for (int n : r) {
            if (n == lb-1) found = true;
            break;
        }
    }
    if (found) cout << "1\n";
    else cout << "0\n";
    cout << "Seed: " << seed << endl;

    return 0;
}
