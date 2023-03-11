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
private:
    ListNode *getRootNode(ListNode *head, ListNode *end) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    TreeNode *dfs(ListNode *head, ListNode *end) {
        if (head == end) return nullptr;

        ListNode *mid = getRootNode(head, end);
        TreeNode *root = new TreeNode(mid->val);

        root->left = dfs(head, mid);
        root->right = dfs(mid->next, end);

        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        return dfs(head, nullptr);
    }
};