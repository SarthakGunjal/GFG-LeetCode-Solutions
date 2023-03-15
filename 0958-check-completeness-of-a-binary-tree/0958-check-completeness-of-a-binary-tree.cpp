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
    
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        vector<TreeNode*>pre;
        bool pre_flag=false;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*>ans;
            bool flag=false;
            while(n--){
                TreeNode *temp=q.front();
                q.pop(); 
                if(temp==NULL) continue;
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                else
                   flag=true;
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                else 
                   flag=true;
                ans.push_back(temp->left);
                ans.push_back(temp->right);
            }
            if(!q.empty()){
                pre.clear();
                pre=ans;
                if(pre_flag==true) return false;
                pre_flag=flag;
            }
        } 
        int flag=false;
        for(int i=0;i<pre.size();++i){
            if(pre[i]==NULL){
                flag=true;
            }
            if(flag==true && pre[i]!=NULL)
                return false;
        } 
        return true;
    }
};