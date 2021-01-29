# https://leetcode.com/problems/reverse-linked-list
import unittest

class TestCases(unittest.TestCase):
    def test_from_str_and_str(self):
        ll = ListNode.from_str('1->2->3->4->5->NULL')
        self.assertEqual(str(ll), '1->2->3->4->5->NULL')

    def test_case1(self):
        head = ListNode.from_str('1->2->3->4->5->NULL')
        self.assertEqual(
                str(Solution().reverseList(head)),
                str(ListNode.from_str('5->4->3->2->1->NULL'))
        )

    def test_case2(self):
        head = ListNode()
        self.assertEqual(
                str(head),
                str(ListNode())
        )

    def test_case3(self):
        head = ListNode.from_str('1->NULL')
        self.assertEqual(
                str(Solution().reverseList(head)),
                str(ListNode.from_str('1->NULL'))
        )

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        if self.next:
            return f'{self.val}->' + str(self.next)
        else:
            return f'{self.val}->NULL'

    @staticmethod
    def from_str(string):
        assert string[-4:] == 'NULL'
        nodes = string.split('->')
        assert len(nodes) > 1
        head = ListNode(nodes[0])
        tail = head
        for val in nodes[1:-1]:
            node = ListNode(val)
            tail.next = node
            tail = node
        return head

class Solution:
    def reverseList(self, head):
        curr_node = head
        prev_node = None
        while curr_node:
            next_node = curr_node.next
            curr_node.next = prev_node
            prev_node = curr_node
            curr_node = next_node

        return prev_node

if __name__ == '__main__':
    unittest.main()
