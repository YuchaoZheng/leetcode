//
// Created by 郑宇超 on 2019/2/10.
//
/*
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 *
 * 思路1：
 * class node {
 *     int left, right; // left为右括号，right为左括号
 * }
 * 时间复杂度:
 * O(n^2)，超时
 * dp，node dp[i][j].left表示左边多几个右括号，右边多几个左括号
class node {
public:
    int left, right;

    node() {
        left = 0;
        right = 0;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0)
            return 0;
        vector <vector<node>> dp(s.size() + 1, vector<node>(s.size() + 1));
        int ans = 0;
        for (int i = 1; i <= s.size(); i++)
            for (int left = 0; left + i - 1 < s.size(); left++) {
                if (i == 1) {
                    if (s[left] == ')')
                        dp[left][left + i - 1].left = 1, dp[left][left + i - 1].right = 0;
                    else
                        dp[left][left + i - 1].left = 0, dp[left][left + i - 1].right = 1;
                } else {
                    dp[left][left + i - 1].left =
                            dp[left][left].left + max(dp[left + 1][i + left - 1].left - dp[left][left].right, 0);
                    dp[left][left + i - 1].right =
                            dp[left + 1][left + i - 1].right +
                            max(dp[left][left].right - dp[left + 1][i + left - 1].left, 0);
                }
                if (dp[left][left + i - 1].right == 0 && dp[left][left + i - 1].left == 0)
                    ans = max(ans, i);
            }
        return ans;
    }
};
 * 思路2：
 * 时间复杂度, O(n)
 * 贪心，从后往前遍历，如果从终点到当前位置'('多，则丢弃当前终点，设置新的终点为当前点-1
 * 如果')'多，则记录多了几个，并把对应个数的位置记录下来
 * dp[i]表示多了i个')'，且终点位置为'('的最远位置
 *
 * 其实从前到后也可以
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0)
            return 0;
        vector<int> dp(s.size() + 1, -1);
        int preRight = 0, endPos = s.size() - 1;
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(')
                preRight--;
            else
                preRight++;
            if (preRight < 0) {
                preRight = 0;
                endPos = i - 1;
                dp[preRight] = endPos + 1;
            } else {
                if (preRight != 0) {
                    if (dp[preRight] != -1 && dp[preRight] <= endPos) {
                        if(s[i] == '(')
                            ans = max(ans, dp[preRight] - i);
                        cout << i << " " << dp[preRight] - i << endl;
                    } else if (i != 0 && s[i - 1] == ')')
                        dp[preRight] = i;
                } else
                    ans = max(ans, endPos - i + 1);
            }
        }
        return ans;
    }
};