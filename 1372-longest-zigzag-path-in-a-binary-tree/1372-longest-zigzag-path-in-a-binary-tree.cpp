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
    int sol = 0;
    void zigZag(TreeNode* node, int dir, int depth){
        if(!node)return;
        sol = max(sol,depth);
        if(dir){
            zigZag(node->left,0,depth+1);
            zigZag(node->right,1,1);
        }else{
            zigZag(node->right,1,depth+1);
            zigZag(node->left,0,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        zigZag(root,0,0);
        zigZag(root,1,0);
        return sol;
    }
};