//
// Created by 郑宇超 on 2019/2/10.
//

/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。

思路1：
记忆化搜索，dp[i]表示i位置到达终点的step，时间复杂度O(n*n)

class Solution {
public:
    int dfs(int nowPos, int endPos, vector<int> &dp, vector<int> &nums) {
        if(dp[nowPos] != -1)
            return dp[nowPos];
        if (nowPos == endPos)
            return 0;
        int step = endPos;
        for (int i = 1; i + nowPos <= endPos && i <= nums[nowPos]; i++)
            step = min(step, 1 + dfs(i + nowPos, endPos, dp, nums));
        dp[nowPos] = step;
        return step;
    }

    int jump(vector<int> &nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(0, nums.size() - 1, dp, nums);
    }
};

 思路2：
 贪心：每一个step能够到达的点肯定是一段连续的区间
 */

class Solution {
public:

    int jump(vector<int> &nums) {
        if(nums.size() == 1)
            return 0;
        int preMax = 0, step = 0, nowMax = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i + nums[i] >= nums.size() - 1)
                return step + 1;
            nowMax = max(nowMax, i + nums[i]);
            if(i == preMax) {
                step++;
                preMax = nowMax;
            }
        }
        return -1;
    }
};