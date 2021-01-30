# https://leetcode.com/problems/minimum-number-of-frogs-croaking/
import unittest

class TestCases(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(Solution().minNumberOfFrogs("croakcroak"), 1)

    def test_case2(self):
        self.assertEqual(Solution().minNumberOfFrogs("crcoakroak"), 2)

    def test_case3(self):
        self.assertEqual(Solution().minNumberOfFrogs("croakcrook"), -1)

    def test_case4(self):
        self.assertEqual(Solution().minNumberOfFrogs("croakcroa"), -1)

    def test_case5(self):
        with open('1419-test-case.txt', 'r') as f:
            test_str = f.readline()
            self.assertEqual(Solution().minNumberOfFrogs(test_str), 16425)


class Solution:
    def minNumberOfFrogs(self, croakOfFrogs):
        croaks = {letter: 0 for letter in 'croa'}
        prev_letter = {'r': 'c', 'o': 'r', 'a': 'o', 'k': 'a'}
        frog_count = 0
        min_frogs = 0
        for char in croakOfFrogs:
            min_frogs = max(min_frogs, frog_count)
            if char == 'c':
                croaks[char] += 1
                frog_count += 1
            else:
                if croaks[prev_letter[char]]:
                    if char != 'k':
                        croaks[char] += 1
                    else:
                        frog_count -= 1
                    croaks[prev_letter[char]] -= 1
                else:
                    return -1

        if sum(croaks.values()):
            return -1
        else:
            return min_frogs


if __name__ == '__main__':
    unittest.main()
