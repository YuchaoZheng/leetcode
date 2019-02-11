//
// Created by 郑宇超 on 2019/2/11.
//
/*
 * 柱状图中最大的矩形
 *
 * 思路：
 * 单调栈，时间复杂度:O(n)
 */
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        if (heights.size() == 0)
            return 0;
        vector<int> l(heights.size());
        vector<int> r(heights.size());
        l[0] = 0;
        for (int i = 1; i < heights.size(); i++) {
            int tmp = i;
            while (tmp != 0 && heights[i] <= heights[tmp - 1])
                tmp = l[tmp - 1];
            l[i] = tmp;
        }
        int n = heights.size() - 1;
        r[n] = n;
        int ans = heights[n] * (r[n] - l[n] + 1));
        for (int i = n - 1; i >= 0; i--) {
            int tmp = i;
            while (tmp != n && heights[i] <= heights[tmp + 1])
                tmp = r[tmp + 1];
            r[i] = tmp;
            ans = max(ans, heights[i] * (r[i] - l[i] + 1);
        }
        return ans;
    }
};