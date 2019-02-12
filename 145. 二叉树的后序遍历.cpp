//
// Created by 郑宇超 on 2019/2/12.
//

/*
 * 给定一个二叉树，返回它的 后序 遍历。
 *
 * 思路：
 * 使用栈
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        stack <pair<TreeNode *, bool>> st;
        st.push(make_pair(root, false));
        while (!st.empty()) {
            pair < TreeNode * , bool > out = st.top();
            st.pop();
            if (out.second == false) {
                st.push(make_pair(out.first, true));
                if (out.first->right != NULL)
                    st.push(make_pair(out.first->right, false));
                if (out.first->left != NULL)
                    st.push(make_pair(out.first->left, false));
            } else
                ans.push_back(out.first->val);
        }
        return ans;
    }
};