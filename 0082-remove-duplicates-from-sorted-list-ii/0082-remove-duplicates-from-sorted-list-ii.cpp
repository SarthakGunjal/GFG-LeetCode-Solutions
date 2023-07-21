class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p=head;
        ListNode* prevstart=NULL;
       while(p!=NULL)
       {
        ListNode* start=p;
        while(p!=NULL)
        {
           if(p->val==start->val)//update till not equal
           {
               p=p->next;
           }
           else break;
        }
        if(start==head && start->next!=p)//update head
        {
            head=p;
        }
        else if(start->next!=p) //if p is not next, link prevstart
        {
            prevstart->next=p;
        }
        else if(start->next=p) //update the prevstart
        {
            prevstart=start;
        }
        
       }
       return head;
    }
};
