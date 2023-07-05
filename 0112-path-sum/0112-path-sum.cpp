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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return traverse(root, targetSum, 0);
    }
    bool traverse(TreeNode* r, int target, int sum) {
        if (r == nullptr) {
            return false;
        }
        sum += r->val;
        if (r->left == nullptr && r->right == nullptr) {
            return target == sum;
        }
        return traverse(r->left, target, sum) || traverse(r->right, target, sum);
    }
};
