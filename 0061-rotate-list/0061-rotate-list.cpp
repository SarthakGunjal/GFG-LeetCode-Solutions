class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        //empty LL or singly node LL
        if (!head || !head->next) {
            return head;
        }

        //compute length
        int len = 1;
        ListNode* temp = head;
        while (temp->next) {
            len++;
            temp = temp->next;
        }

        //finding effective k
        k = k % len;
        if (k == 0) {
            return head;
        }

        //access address of mew head 
        ListNode* curr = head;
        int toMove = len - k - 1;
        while (toMove != 0) {
            curr = curr->next;
            toMove--; 
        }

        //updating new head
        ListNode* newHead = curr->next;

        //updating last node address of new LL
        curr->next = NULL;

        //add rotated part to LL
        temp->next = head;

        return newHead;
    }
};