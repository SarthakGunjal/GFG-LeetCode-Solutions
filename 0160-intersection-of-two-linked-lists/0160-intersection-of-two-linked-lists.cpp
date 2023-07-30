class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1 = 0, length2 = 0;
        ListNode *temp = headA;
        while(temp != NULL) {
            temp = temp->next;
            length1++;
        }
        
        temp = headB;
        while(temp != NULL) {
            temp = temp->next;
            length2++;
        }

        int k = abs(length1 - length2);
        ListNode *temp1;
        ListNode *temp2;
        if(length1 <= length2) {
            temp1 = headA;
            temp2 = headB;
            while(k--) {
                temp2 = temp2->next;
            }
        }
        else {
            temp1 = headB;
            temp2 = headA;
            while(k--) {
                temp2 = temp2->next;
            }
        }
        while(temp1 != NULL) {
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};