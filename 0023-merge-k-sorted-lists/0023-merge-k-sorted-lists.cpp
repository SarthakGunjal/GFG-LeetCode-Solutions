/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<lists.size();i++)
        {
            ListNode *ct=new ListNode();
            ct=lists[i];
            while(ct!=NULL)
            {
                pq.push(ct->val);
                ct=ct->next;
            }
        }
     ListNode *first=new ListNode();
        if(pq.size()==0)
        return NULL;
       else{
            first->val=pq.top();
            pq.pop();
            ListNode *temp=first;
     while(!pq.empty())
       {
           ListNode *cur=new ListNode();
           int x=pq.top();
           pq.pop();
           cur->val=x;
           temp->next=cur;
        temp=temp->next;
       }
    }
    return first;
 }
};