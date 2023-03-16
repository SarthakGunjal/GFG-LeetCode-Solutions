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

    unordered_map<int, int> search;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int in_left, int in_right, int & post_index)
    {
        if(in_left > in_right) {
            return nullptr;
        }
        
        int root_val = postorder[post_index--];
        TreeNode *root = new TreeNode(root_val);

        if(in_left == in_right) {
            return root;
        }

        int mid_index = search[root_val];        
        root->right = buildTree(inorder, postorder, mid_index+1, in_right, post_index);
        root->left = buildTree(inorder, postorder, in_left, mid_index-1, post_index);

        return root; 
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0 ; i < inorder.size(); i++) {
            search[inorder[i]] = i ;
        }
        int post_index = postorder.size()-1;
        return buildTree(inorder, postorder, 0, inorder.size()-1, post_index);
    }
};