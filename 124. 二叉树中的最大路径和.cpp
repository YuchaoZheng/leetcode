//
// Created by 郑宇超 on 2019/2/13.
//

/*
 * 给定一个非空二叉树，返回其最大路径和。
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 *
 * 思路：
 * dfs，维护每个节点的最长距离和次长距离
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int findMaxPathSum(TreeNode *root, int &ans) {
        int leftDis = 0, rightDis = 0;
        if (root->left != NULL)
            leftDis = max(leftDis, findMaxPathSum(root->left, ans));
        if (root->right != NULL)
            rightDis = max(rightDis, findMaxPathSum(root->right, ans));
        ans = max(ans, leftDis + rightDis + root->val);
        return max(leftDis, rightDis) + root->val;
    }

    int maxPathSum(TreeNode *root) {
        if (root == NULL)
            return 0;
        int ans = root->val;
        findMaxPathSum(root, ans);
        return ans;
    }
};