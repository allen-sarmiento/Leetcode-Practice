/*
    Date: 7/29/2023
    Time Complexity: O(M*N)
    Space Complexity: ?
*/

class Solution {
public:
    int traverseIsland(vector<vector<int>>& grid, int row, int col) {
        int islandArea = 0;
        if (grid[row][col] == 1) {
            islandArea += 1;
            grid[row][col] = 0;
            
            if (row+1 < grid.size())
                islandArea += traverseIsland(grid, row+1, col);
            if (row-1 >= 0)
                islandArea += traverseIsland(grid, row-1, col);
            if (col+1 < grid[0].size())
                islandArea += traverseIsland(grid, row, col+1);
            if (col-1 >= 0)
                islandArea += traverseIsland(grid, row, col-1);
        }
        return islandArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, area = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1) {
                    area = traverseIsland(grid, i, j);
                    if (area > maxArea)
                        maxArea = area;
                }
        return maxArea;
    }
};