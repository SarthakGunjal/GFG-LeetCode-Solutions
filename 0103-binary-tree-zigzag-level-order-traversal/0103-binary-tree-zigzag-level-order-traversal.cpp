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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        stack<int> stk;
        bool reverse = false;
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* p = q.front();
                q.pop();
                if(reverse){
                    stk.push(p->val);
                }
                else{
                    temp.push_back(p->val);
                }
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            
            while(!stk.empty()){
                temp.push_back(stk.top());
                stk.pop();
            }
            reverse = !reverse;
            result.push_back(temp);
        }
        return result;
    }
};