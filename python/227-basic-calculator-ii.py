# https://leetcode.com/problems/basic-calculator-ii/
from collections import deque
import unittest


class TestCases(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(Solution().calculate("3+2*2"), 7)

    def test_case2(self):
        self.assertEqual(Solution().calculate(" 3/2 "), 1)

    def test_case3(self):
        self.assertEqual(Solution().calculate(" 3+5 / 2 "), 5)

    def test_case4(self):
        self.assertEqual(Solution().calculate(" 8 + 2/5 * 7- 3"), 5)

    def test_case5(self):
        self.assertEqual(Solution().calculate("8+2*5/7-3*6-4"), -13)

    def test_case6(self):
        self.assertEqual(Solution().calculate("0"), 0)

    def test_case7(self):
        self.assertEqual(Solution().calculate("14/3*2"), 8)

    def test_list_from_str1(self):
        self.assertEqual(
                Solution.list_from_str(" 8 + 2/5 * 7- 3"),
                [8, '+', 2, '/', 5, '*', 7, '-', 3]
        )


class Solution:
    operator_funcs = {
            '*': int.__mul__,
            '/': int.__floordiv__,
            '+': int.__add__,
            '-': int.__sub__,
    }

    op_priority = {
            '*': 1,
            '/': 1,
            '+': 0,
            '-': 0,
    }
    class Operation:
        def __init__(operator, l_operand, r_operand=None):
            self.operator = operator
            self.l_operand = l_operand
            self.r_operand = r_operand

    @staticmethod
    def list_from_str(input_str):
        output_list = []
        num = 0
        for char in input_str:
            if char.isdigit():
                num = num * 10 + int(char)
            else:
                if char != ' ':
                    output_list.append(num)
                    output_list.append(char)
                    num = 0
        output_list.append(num)
                
        return output_list

    @staticmethod
    def do_operation(op_stack, num_stack):
        rnum = num_stack.pop()
        f = Solution.operator_funcs[op_stack.pop()]
        lnum = num_stack.pop()
        num_stack.append(f(lnum, rnum))

    def calculate(self, input_str):
        elements = self.list_from_str(input_str)
        op_stack = deque()
        num_stack = deque()
        
        num_stack.append(elements[0])
        if len(elements) > 1:
            op_stack.append(elements[1])
            num_stack.append(elements[2])

        for op, rnum in zip(elements[3::2], elements[4::2]):
            while len(op_stack) and self.op_priority[op] <= self.op_priority[op_stack[-1]]:
                Solution.do_operation(op_stack, num_stack)

            num_stack.append(rnum)
            op_stack.append(op)

        while len(op_stack):
            Solution.do_operation(op_stack, num_stack)

        return num_stack.pop()


if __name__ == '__main__':
    unittest.main()
