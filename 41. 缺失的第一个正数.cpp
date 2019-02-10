//
// Created by 郑宇超 on 2019/2/10.
//
/*
 * 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
 *
 * 思路1：
 * 利用快排的思想，二分答案
 * 时间复杂度：O(nlogn)，超过100%
 * 在最坏的情况下会被卡到O(nlogn)
 *
class Solution {
public:
    bool solve(int &start, int &end, int low, int mid, vector<int> &nums, vector<bool> &flag) {
        int pos = start, num = 0;

        vector<int> tmp;
        for (int i = start; i <= end; i++)
            if (nums[i] <= mid) {
                if (nums[i] >= low && !flag[nums[i]]) {
                    num++, flag[nums[i]] = true;
                    tmp.push_back(nums[i]);
                }
                swap(nums[i], nums[pos]);
                pos++;
            }
        for (auto u:tmp)
            flag[u] = false;
        //num表示有几个不同的数
        if (num < mid - low + 1) {
            end = pos - 1;
            return true;
        }
        start = pos;
        return false;
    }

    int firstMissingPositive(vector<int> &nums) {
        vector<bool> flag(nums.size(), false);
        int low = 1, high = nums.size(), ans = 1;
        // start,end表示位置，low,high表示数
        int start = 0, end = nums.size() - 1;
        while (high - low >= 0) {
            int mid = (low + high) >> 1;
            if (solve(start, end, low, mid, nums, flag))
                high = mid - 1, ans = mid;
            else
                low = mid + 1, ans = mid + 1;

        }
        return ans;
    }
};

思路2：
巧妙的置换
时间复杂度O(n)，每个位置最多被交换一次
*/
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i]!=nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};