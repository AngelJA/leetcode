# https://leetcode.com/problems/single-number/
import unittest


class TestCases(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(Solution().singleNumber([2,2,1]), 1)

    def test_case2(self):
        self.assertEqual(Solution().singleNumber([4,1,2,1,2]), 4)

    def test_case3(self):
        self.assertEqual(Solution().singleNumber([1]), 1)


class Solution:
    def singleNumber(self, nums):
        ret = 0
        for num in nums:
            ret ^= num
        return ret


if __name__ == '__main__':
    unittest.main()
