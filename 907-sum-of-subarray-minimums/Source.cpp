#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// i/o hack
auto __NEEDFORSPEED__ = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
	int sumSubarrayMins(vector<int>& A) {
		// left-length of the array for which A[i] is the smallest value (including i)
		vector<int> left(A.size(), 1);
		vector<int> right(A.size(), 1);

		// keep track of 'open' subarrays (values for which we haven't found a smaller value yet, going left to right)
		stack<int> right_open;
		// same as above but going from right to left
		stack<int> left_open;

		right_open.push(0);
		for (int i = 1; i < A.size(); ++i)
		{
			while (!right_open.empty() && A[i] <= A[right_open.top()])
			{
				int j = right_open.top();
				right_open.pop();
				right[j] = i - j;
			}
			right_open.push(i);
		}

		left_open.push(A.size() - 1);
		for (int i = A.size() - 2; i >= 0; --i)
		{
			while (!left_open.empty() && A[i] < A[left_open.top()])
			{
				int j = left_open.top();
				left_open.pop();
				left[j] = j - i;
			}
			left_open.push(i);
		}

		while (!right_open.empty())
		{
			int j = right_open.top();
			right_open.pop();
			right[j] = A.size() - j;
		}

		while (!left_open.empty())
		{
			int j = left_open.top();
			left_open.pop();
			left[j] = j - -1;
		}

		long long sum = 0;
		for (int i = 0; i < A.size(); ++i)
		{
			sum += A[i] * (left[i] * right[i]);
		}
		return sum % int(pow(10, 9) + 7);
	}
};

int main()
{
	return 0;
}