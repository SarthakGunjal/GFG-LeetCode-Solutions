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
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* node, int number){
        if(!node) return;
        if(!node->left && !node->right) {
            number = number * 10 + node->val;
            ans += number;
            return;
        }
        dfs(node->left, number * 10 + node->val);
        dfs(node->right, number * 10 + node->val);
    }
};