# https://leetcode.com/problems/single-number-ii/
import unittest


class TestCases(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(Solution().singleNumber([2,2,3,2]), 3)

    def test_case2(self):
        self.assertEqual(Solution().singleNumber([0,1,0,1,0,1,99]), 99)


class Solution:
    def singleNumber(self, nums):
        seen = set()
        seen_twice = set()

        for num in nums:
            if num in seen:
                seen.remove(num)
                seen_twice.add(num)
            else:
                if num not in seen_twice:
                    seen.add(num)

        return next(iter(seen))


if __name__ == '__main__':
    unittest.main()
