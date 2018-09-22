#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		solve(board, 0, 0);
	}

	bool solve(vector<vector<char>>& board, int i, int j)
	{
		int di = 0;
		int dj = 0;
		while (board[i + di][j + dj] != '.')
		{
			if (j + dj < 8)
			{
				dj++;
			}
			else
			{
				if (i + di < 8)
				{
					dj = -j;
					di++;
				}
				else
				{
					return true;
				}
			}
		}
		for (int num = 1; num <= 9; ++num)
		{
			board[i + di][j + dj] = intToChar(num);
			if (valid(board, i + di, j + dj))
			{
				if (solve(board, i + di, j + dj))
				{
					return true;
				}
			}
		}
		board[i + di][j + dj] = '.';
		return false;
	}

	bool valid(vector<vector<char>>& board, int i, int j)
	{
		// check row
		vector<bool> nums(9);
		for (char c : board[i])
		{
			if (c != '.')
			{
				if (nums[charIndex(c)])
				{
					return false;
				}
				else
				{
					nums[charIndex(c)] = true;
				}
			}
		}

		// check column
		nums = vector<bool>(9);
		for (int row = 0; row < board.size(); ++row)
		{
			char c = board[row][j];
			if (c != '.')
			{
				if (nums[charIndex(c)])
				{
					return false;
				}
				else
				{
					nums[charIndex(c)] = true;
				}
			}
		}

		// check box
		nums = vector<bool>(9);
		int box_i = i / 3;
		int box_j = j / 3;
		for (int row = 0; row < 3; ++row)
		{
			for (int col = 0; col < 3; ++col)
			{
				char c = board[3 * box_i + row][3 * box_j + col];
				if (c != '.')
				{
					if (nums[charIndex(c)])
					{
						return false;
					}
					else
					{
						nums[charIndex(c)] = true;
					}
				}
			}
		}

		return true;
	}

	int charIndex(char c)
	{
		return c - '1';
	}

	char intToChar(int i)
	{
		return '0' + i;
	}
};

int main()
{
	return 0;
}