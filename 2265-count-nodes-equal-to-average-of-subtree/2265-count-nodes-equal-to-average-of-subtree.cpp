/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,pair<int,int>> dfs(TreeNode* node) //ans,n,store
    {
        if(node == nullptr) return {0,{0,0}};
        auto l = dfs(node->left);
        auto r = dfs(node->right);

        int count = 1 + l.second.first + r.second.first;
        int sum = node->val + l.second.second + r.second.second;

        int res = l.first + r.first;
        if (node->val == sum / count) res++;

        return {res, {count, sum}};
    }
    int averageOfSubtree(TreeNode* root) {
        return dfs(root).first;
    }
};