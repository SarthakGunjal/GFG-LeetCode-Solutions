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
    void help(TreeNode* root, set<int> &s){
        if(root==NULL) return;
        s.insert(root->val);
        if(root->left!=NULL) help(root->left,s);
        if(root->right!=NULL) help(root->right,s);
    }
    int minDiffInBST(TreeNode* root) {
        set<int> s;
        help(root,s);
        int prev=INT_MAX;
        int ans = INT_MAX;
        for(auto it: s){
            if(abs(it-prev)<ans){
                ans=abs(it-prev);
            }
            prev=it;
        }
        return ans;
    }
};