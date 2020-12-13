// https://leetcode.com/problems/sum-of-subarray-minimums/description/
#include <math.h>
#include <iostream>
#include <vector>
#include <stack>

#include "./util.h"

using std::pow;
using std::stack;
using std::vector;

class Solution {
 public:
    int sumSubarrayMins(const vector<int>& A) {
        // left-length of the array for which A[i] is the
        // smallest value (including i)
        vector<int> left(A.size(), 1);
        vector<int> right(A.size(), 1);

        // keep track of 'open' subarrays (values for which we haven't
        // found a smaller value yet, going left to right)
        stack<int> right_open;
        // same as above but going from right to left
        stack<int> left_open;

        right_open.push(0);
        for (int i = 1; i < static_cast<int>(A.size()); ++i) {
            while (!right_open.empty() && A[i] <= A[right_open.top()]) {
                int j = right_open.top();
                right_open.pop();
                right[j] = i - j;
            }
            right_open.push(i);
        }

        left_open.push(A.size() - 1);
        for (int i = A.size() - 2; i >= 0; --i) {
            while (!left_open.empty() && A[i] < A[left_open.top()]) {
                int j = left_open.top();
                left_open.pop();
                left[j] = j - i;
            }
            left_open.push(i);
        }

        while (!right_open.empty()) {
            int j = right_open.top();
            right_open.pop();
            right[j] = A.size() - j;
        }

        while (!left_open.empty()) {
            int j = left_open.top();
            left_open.pop();
            left[j] = j - -1;
        }

        int64_t sum = 0;
        for (int i = 0; i < static_cast<int>(A.size()); ++i) {
            sum += A[i] * (left[i] * right[i]);
        }
        return sum % static_cast<int>(pow(10, 9) + 7);
    }
};

int main() {
    test(Solution().sumSubarrayMins({3, 1, 2, 4}), 17);
    test(Solution().sumSubarrayMins({11, 81, 94, 43, 3}), 444);
            
    return 0;
}
