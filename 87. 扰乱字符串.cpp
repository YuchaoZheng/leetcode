//
// Created by 郑宇超 on 2019/2/12.
//
/*
给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。
下图是字符串 s1 = "great" 的一种可能的表示形式。
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。
例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
我们将 "rgeat” 称作 "great" 的一个扰乱字符串。
同样地，如果我们继续将其节点 "eat" 和 "at" 进行交换，将会产生另一个新的扰乱字符串 "rgtae" 。
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
我们将 "rgtae” 称作 "great" 的一个扰乱字符串。
给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。
 */
class Solution {
public:
    int count[1010];

    bool equal(int l1, int r1, int l2, int r2, string &s1, string &s2) {
        for (int i = l1, j = l2; i <= r1, j <= r2; i++, j++)
            if (s1[i] != s2[j])
                return false;
        return true;
    }

    bool simlar(int l1, int r1, int l2, int r2, string &s1, string &s2) {
        for (int i = l1, j = l2; i <= r1, j <= r2; i++, j++)
            count[s1[i]]++, count[s2[j]]--;
        bool flag = true;
        for (int i = l1, j = l2; i <= r1, j <= r2; i++, j++) {
            if (count[s1[i]] != 0) {
                count[s1[i]] = 0;
                flag = false;
            }
            if (count[s2[j]] != 0) {
                count[s2[j]] = 0;
                flag = false;
            }
        }
        return flag;
    }

    bool dfs(int l1, int r1, int l2, int r2, string &s1, string &s2) {
        if (equal(l1, r1, l2, r2, s1, s2))
            return true;
        if (!simlar(l1, r1, l2, r2, s1, s2))
            return false;
        for (int mid1 = l1; mid1 < r1; mid1++) {
            int leftCount = mid1 - l1 + 1, rightCount = r1 - mid1;
            if (dfs(l1, mid1, l2, l2 + leftCount - 1, s1, s2) && dfs(mid1 + 1, r1, l2 + leftCount, r2, s1, s2))
                return true;
            if (dfs(l1, mid1, l2 + rightCount, r2, s1, s2) && dfs(mid1 + 1, r1, l2, l2 + rightCount - 1, s1, s2))
                return true;
        }
        return false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        if (s1.size() == 0)
            return true;
        return dfs(0, s1.size() - 1, 0, s2.size() - 1, s1, s2);
    }
};