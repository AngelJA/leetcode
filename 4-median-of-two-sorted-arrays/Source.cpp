// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(vector<int>& A, vector<int>& B)
	{
		// inside this class A is always the smaller array
		if (A.size() <= B.size())
		{
			this->A = &A;
			this->B = &B;
		}
		else
		{
			this->A = &B;
			this->B = &A;
		}

		// change this to binary search to get log(m + n)
		for (int i = 0; i < this->A->size(); ++i)
		{
			int query = this->isMedian(i);
			cout << " isMedian: " << query << endl;
			if (query == 0)
			{
				// don't return yet, while debugging
				//return this->A->at(i);
			}
			else
			{
				if (query > 0)
				{
					// all the values in A starting from i are too large
					// we know now where the median is in B
				}
			}
		}
		
		// all the values in A are too small
		// we know now where the median is in B

		return 0;
	}

private:
	// returns 0 if this is the median, -1 if value is less than median, 1 if greater than median
	int isMedian(int i)
	{
		// size of right half of A (if this is the median)
		int right = this->A->size() - (i + 1);
		int left = i;
		// first value in the right half of B
		int j = (this->A->size() + this->B->size() + 1) / 2 - i;

		cout << "i: " << i << " right: " << right << " j: " << j;
		if (this->A->at(i) > this->B->at(j - 1))
		{
			if (this->A->at(i) < this->B->at(j))
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return -1;
		}
	}

	vector<int>* A;
	vector<int>* B;
};

int main()
{
	vector<int> A = { 1,2,3,6,7,8 };
	vector<int> B = { 0,4,5,10 };
	cout << "solution: " << Solution().findMedianSortedArrays(A, B) << endl;
	return 0;
}