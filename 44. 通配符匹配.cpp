//
// Created by 郑宇超 on 2019/2/10.
//
/*
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。


思路：
先将p中连续的*转化为一个*
动态规划，dp[i][j]表示p中前i个字符能否匹配s的前j个字符
为了动态规划方便转移，s和p前面都加了个"a"

->滚动数组进行空间优化,O(n)
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector <vector<bool>> dp(2, vector<bool>(s.size() + 1, false));
        string copyP = "a";
        string copyS = "a" + s;

        for (int i = 0; p[i] != '\0'; i++) {
            if (i > 0 && p[i - 1] == '*' && p[i] == '*')
                continue;
            copyP += p[i];
        }

        dp[0][0] = true;
        int pre = 0;
        for (int i = 1; copyP[i] != '\0'; i++) {
            for (int j = 1;; j++) {
                if (copyP[i] == '*') {
                    //不替换*
                    if (!dp[pre ^ 1][j - 1])
                        dp[pre ^ 1][j - 1] = dp[pre][j - 1];
                    // 替换*
                    if (dp[pre][j - 1] == true)
                        while (copyS[j] != '\0') {
                            dp[pre ^ 1][j] = true;
                            j++;
                        }
                } else {
                    if ((copyP[i] == copyS[j] || copyP[i] == '?') && dp[pre][j - 1] == true)
                        dp[pre ^ 1][j] = true;
                }
                if (copyS[j] == '\0')
                    break;
            }
            for (int j = 0; copyS[j] != '\0'; j++)
                dp[pre][j] = false;
            pre ^= 1;
        }
        return dp[pre][copyS.size() - 1];
    }
};
