// https://leetcode.com/problems/sudoku-solver/description/
#include <iostream>
#include <vector>

#include "./util.h"

using std::vector;

class Solution {
 public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char>>& board, int i, int j) {
        int di = 0;
        int dj = 0;
        while (board[i + di][j + dj] != '.') {
            if (j + dj < 8) {
                dj++;
            } else {
                if (i + di < 8) {
                    dj = -j;
                    di++;
                } else {
                    return true;
                }
            }
        }
        for (int num = 1; num <= 9; ++num) {
            board[i + di][j + dj] = intToChar(num);
            if (valid(board, i + di, j + dj)) {
                if (solve(board, i + di, j + dj)) {
                    return true;
                }
            }
        }
        board[i + di][j + dj] = '.';
        return false;
    }

    bool valid(const vector<vector<char>>& board, int i, int j) {
        // check row
        vector<bool> nums(9);
        for (char c : board[i]) {
            if (c != '.') {
                if (nums[charIndex(c)]) {
                    return false;
                } else {
                    nums[charIndex(c)] = true;
                }
            }
        }

        // check column
        nums = vector<bool>(9);
        for (int row = 0; row < static_cast<int>(board.size()); ++row) {
            char c = board[row][j];
            if (c != '.') {
                if (nums[charIndex(c)]) {
                    return false;
                } else {
                    nums[charIndex(c)] = true;
                }
            }
        }

        // check box
        nums = vector<bool>(9);
        int box_i = i / 3;
        int box_j = j / 3;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                char c = board[3 * box_i + row][3 * box_j + col];
                if (c != '.') {
                    if (nums[charIndex(c)]) {
                        return false;
                    } else {
                        nums[charIndex(c)] = true;
                    }
                }
            }
        }

        return true;
    }

    int charIndex(char c) {
        return c - '1';
    }

    char intToChar(int i) {
        return '0' + i;
    }
};

int main() {
    std::vector<std::vector<char>> input_board {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    std::vector<std::vector<char>> expected_board {
        {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};

    Solution().solveSudoku(input_board);
    test(input_board, expected_board);

    return 0;
}
