// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;

class Solution {
 public:
    double easyMedian(const vector<int>& A, const vector<int>& B) {
        // easy median calc
        vector<int> new_vec(A);
        double median;
        for (int val : B) {
            new_vec.push_back(val);
        }
        sort(new_vec.begin(), new_vec.end());
        if (new_vec.size() % 2 == 0) {
            median = (new_vec[new_vec.size() / 2]
                    + new_vec[new_vec.size() / 2 - 1])
                    / 2.0;
        } else {
            median = new_vec[new_vec.size() / 2];
        }
        return median;
    }
    double findMedianSortedArrays(
            const vector<int>& nums1,
            const vector<int>& nums2) {
        const vector<int>* A;
        const vector<int>* B;

        // make sure A is always the smaller of the two arrays (m <= n)
        if (nums1.size() <= nums2.size()) {
            A = &nums1;
            B = &nums2;
        } else {
            A = &nums2;
            B = &nums1;
        }

        int m = A->size();
        int n = B->size();

        // binary search
        int l = 0;
        int r = m;
        int i, j;
        while (l <= r) {
            i = (l + r) / 2;
            j = (m + n) / 2 - i;

            if (i < m && j > 0 && A->at(i) < B->at(j - 1)) {
                l = i + 1;
            } else {
                if (i > 0 && j < n && A->at(i - 1) > B->at(j)) {
                    r = i - 1;
                } else {
                    break;
                }
            }
        }

        int res;
        if (i == m) {
            res = B->at(j);
        } else {
            if (j == n) {
                res = A->at(i);
            } else {
                res = min(A->at(i), B->at(j));
            }
        }

        if ((m + n) % 2 != 0) {
            return res;
        }

        if (i == 0) {
            res += B->at(j - 1);
        } else {
            if (j == 0) {
                res += A->at(i - 1);
            } else {
                res += max(A->at(i - 1), B->at(j - 1));
            }
        }
        return res / 2.0;
    }
};

int main() {
    vector<int> A;
    vector<int> B;

    Solution sol;

    double median, attempt;
    for (int i = 0; i < 100000; ++i) {
        A.clear();
        B.clear();
        int m = rand() % 5 + 1;
        int n = rand() % 5 + 1;
        int a = rand() % 100;
        int b = rand() % 100;
        for (int i = 0; i < m; ++i) {
            A.push_back(a);
            a += rand() % 10;
        }
        for (int i = 0; i < n; ++i) {
            B.push_back(b);
            b += rand() % 10;
        }

        median = sol.easyMedian(A, B);
        attempt = sol.findMedianSortedArrays(A, B);

        if (median != attempt) {
            for (int val : A) {
                cout << val << " ";
            }
            cout << endl;
            for (int val : B) {
                cout << val << " ";
            }
            cout << endl;
            cout << "median: " << median << endl;
            cout << "solution: " << attempt;
            cout << endl;
        }
    }

    return 0;
}
