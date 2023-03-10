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
private:
    ListNode *root= new ListNode();
    vector<int>vect;
public:
    Solution(ListNode* head) {
        srand(time(NULL));
        root=head;
        stack<ListNode*>stack;
        stack.push(root);
        ListNode* node=new ListNode();
        while(!stack.empty())
        {
            node=stack.top();
            stack.pop();
            vect.push_back(node->val);
            if(node->next)
                stack.push(node->next);
        }
    }
    
    int getRandom() {
        return vect[rand()%vect.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */