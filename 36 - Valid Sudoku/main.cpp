#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {

    // Create a set for each col
    vector<set<char>> colSets(9);

    // Create a set for each box. Clear boxes after every 3 rows
    vector<set<char>> boxSets(3);

    // Create iterator
    set<char>::iterator iter;

    for(int row = 0; row < 9; row++) {

        // Create a set for each row
        set<char> rowSet;

        for (int col = 0; col < 9; col++) {

            // Clear all 3 boxes after every 3 rows.
            if (row%3 == 0 && col == 0)
                for (int i = 0; i < 3; i++)
                    boxSets[i].clear();

            char c = board[row][col];

            // Skip if '.'
            if (c == '.') continue;

            // Return false if the number already exists in the row
            iter = rowSet.find(c); 
            if (iter != rowSet.end()) 
                return false;
            else rowSet.insert(c);

            // Return false if the number already exists in the corresponding col
            iter = colSets[col].find(c);
            if (iter != colSets[col].end()) 
                return false;
            else colSets[col].insert(c);

            // Get corresponding box for each cell
            int box = col/3;

            // Return false if the number already exists in the corresponding box
            iter = boxSets[box].find(c);
            if (iter != boxSets[box].end()) 
                return false;
            else boxSets[box].insert(c);
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board{ {'.','.','.','.','.','.','.','.','.'},
                                {'4','.','.','.','.','.','.','.','.'},
                                {'.','.','.','.','.','.','6','.','.'},

                                {'.','.','.','3','8','.','.','.','.'},
                                {'.','5','.','.','.','6','.','.','1'},
                                {'8','.','.','.','.','.','.','6','.'},

                                {'.','.','.','.','.','.','.','.','.'},
                                {'.','.','7','.','9','.','.','.','.'},
                                {'.','.','.','6','.','.','.','.','.'}};

    cout << boolalpha << isValidSudoku(board);
    return 0;
}