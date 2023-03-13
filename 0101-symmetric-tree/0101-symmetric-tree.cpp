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
    bool checkSymmetry(TreeNode* r1, TreeNode* r2) {
        if (r1 && r2) {
            return (r1->val == r2->val) && checkSymmetry(r1->left, r2->right) && checkSymmetry(r1->right, r2->left);
        } else if (r1 || r2) {
            return false;
        } else {
            return true;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return checkSymmetry(root->left, root->right);
    }
};