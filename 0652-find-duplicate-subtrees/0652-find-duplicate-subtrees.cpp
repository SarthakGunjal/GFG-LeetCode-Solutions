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
vector<TreeNode*>ans;
unordered_map<string, int> m;
string recur(TreeNode* root){
    if( root==NULL)return "";
    string left =recur ( root ->left);
    string right = recur( root->right);
    string cur = to_string ( root->val) +"left"+ left + "right" + right ;
    if( m[cur]==1)ans.push_back( root);
    m[cur]++;
    return cur;  
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string s =recur(root);
        return ans;
       
    }
};