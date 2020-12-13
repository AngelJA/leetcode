// https://leetcode.com/problems/longest-valid-parentheses/description/
#include <iostream>
#include <stack>
#include <algorithm>

using std::cout;
using std::endl;
using std::make_pair;
using std::max;
using std::pair;
using std::stack;
using std::string;

class Solution {
 public:
    int longestValidParentheses(string s) {
        int max_length = 0;
        stack<pair<char, int>> stack;
        stack.push(make_pair(')', -1));

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            if (s[i] == ')') {
                if (stack.top().first == '(') {
                    stack.pop();
                    max_length = max(max_length, i - stack.top().second);
                } else {
                    stack.push(make_pair(')', i));
                }
            } else {
                stack.push(make_pair('(', i));
            }
        }

        return max_length;
    }
};

int main() {
    cout << Solution().longestValidParentheses("))))((()((") << endl;
    return 0;
}
