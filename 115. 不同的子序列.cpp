//
// Created by 郑宇超 on 2019/2/12.
//

/*
给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

思路：
 后缀统计答案，动态规划思想，时间复杂度:O(len(s) + len(t))
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> ans(t.size() + 1, 0);
        vector <vector<int>> chPos(128);
        int tSize = t.size();
        for (int i = 0; i < tSize; i++)
            chPos[t[i]].push_back(tSize - i);
        ans[0] = 1;
        int sSize = s.size();
        for (int i = sSize; i >= 0; i--) {
            char ch = s[i];
            //避免重复叠加，id大的优先
            for (auto id:chPos[ch]) {
                if(id > sSize - i)
                    continue;
                ans[id] += ans[id - 1];
            }
        }
        return ans[t.size()];
    }
};