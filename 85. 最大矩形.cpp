//
// Created by 郑宇超 on 2019/2/11.
//

/*
 *给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 *
 * 思路1：
 * 枚举哪两列，迭代行
 * 时间复杂度:O(n^3)

class Solution {
public:
    int maximalRectangle(vector <vector<char>> &matrix) {
        if (matrix.size() == 0)
            return 0;
        if (matrix[0].size() == 0)
            return 0;
        vector <vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++) {
                if (j == 0)
                    dp[i][j] = matrix[i][j] - '0';
                else
                    dp[i][j] = dp[i][j - 1] + matrix[i][j] - '0';
            }
        int ans = 0;
        int line = matrix[0].size();
        for (int line1 = 0; line1 < line; line1++)
            for (int line2 = line1; line2 < line; line2++) {
                int tmpAns = 0, rowLen = matrix.size();
                for (int row = 0; row < rowLen; row++) {
                    if (tmpAns + (rowLen - row) * (line2 - line1 + 1) <= ans)
                        break;
                    if ((line1 == 0 && dp[row][line2] == line2 - line1 + 1) ||
                        (line1 != 0 && dp[row][line2] - dp[row][line1 - 1] == line2 - line1 + 1))
                        tmpAns += line2 - line1 + 1;
                    else {
                        ans = max(ans, tmpAns);
                        tmpAns = 0;
                    }
                    ans = max(ans, tmpAns);
                }
            }
        return ans;
    }
};

 思路2：
 以当前列作为末尾列(这样可以降低空间复杂度)
 枚举列，单调栈维护行
 时间复杂度:O(n^2)
 */

class Solution {
public:
    int maximalRectangle(vector <vector<char>> &matrix) {
        if (matrix.size() == 0)
            return 0;
        if (matrix[0].size() == 0)
            return 0;
        vector<int> a(matrix[0].size());
        vector<int> l(matrix[0].size());
        vector<int> r(matrix[0].size());
        int ans = 0;
        int row = matrix.size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j] == '1')
                    a[j]++;
                else
                    a[j]=0;
            l[0] = 0;
            for (int j = 1; j < matrix[0].size(); j++) {
                int tmp = j;
                while (tmp != 0 && a[j] <= a[tmp - 1])
                    tmp = l[tmp - 1];
                l[j] = tmp;
            }
            int n = matrix[0].size() - 1;
            r[n] = n;
            for (int j = n - 1; j >= 0; j--) {
                int tmp = j;
                while (tmp != n && a[j] <= a[tmp + 1])
                    tmp = r[tmp + 1];
                r[j] = tmp;
            }
            for (int j = 0; j < matrix[0].size(); j++)
                ans = max(ans, a[j] * (r[j] - l[j] + 1));
        }
        return ans;
    }
};