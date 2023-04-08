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

    int minDepth(TreeNode* root) {
         if (root==NULL) return 0;
        // int left=0,right=0;
        // cout<<minDepth(root->left) ;

    int left = minDepth(root->left) + 1;
    int right = minDepth(root->right) + 1;

    if (!root->left) return right;
    if (!root->right) return left;

    return min(left, right);
    }
};