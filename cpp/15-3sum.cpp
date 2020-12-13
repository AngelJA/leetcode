// https://leetcode.com/problems/3sum/description/
#include <iostream>
#include <vector>
#include <algorithm>

#include "./util.h"

using std::cout;
using std::vector;

class Solution {
 public:
    vector<vector<int>> threeSum(const vector<int>& nums) {
        vector<vector<int>> ret;

        if (nums.size() < 3) {
            return ret;
        }

        // make a copy so we don't modify the vector passed
        // by reference (at the expense of speed)
        vector<int> nums_copy = vector<int>(nums);
        sort(nums_copy.begin(), nums_copy.end());

        for (int i = 0; i < static_cast<int>(nums_copy.size() - 2); ++i) {
            if (i > 0 && nums_copy[i - 1] == nums_copy[i]) {
                continue;
            }
            int j = i + 1;
            int k = nums_copy.size() - 1;
            while (j < k) {
                int val = nums_copy[i] + nums_copy[j] + nums_copy[k];
                if (val == 0) {
                    ret.push_back(
                        vector<int>({
                            nums_copy[i],
                            nums_copy[j],
                            nums_copy[k]
                        }));
                    while (j < static_cast<int>(nums_copy.size() - 2)
                           && nums_copy[j] == nums_copy[j + 1]) {
                        j++;
                    }
                    while (k > 0 && nums_copy[k] == nums_copy[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                } else {
                    if (val < 0) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }

        return ret;
    }
};

int main() {
    test(Solution().threeSum({-1, 0, 1, 2, -1, -4}), {{-1, -1, 2}, {-1, 0, 1}});
    test(Solution().threeSum({}), {});
    test(Solution().threeSum({0}), {});

    return 0;
}
