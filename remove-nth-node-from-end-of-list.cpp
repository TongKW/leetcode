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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current_end = head;
        ListNode* current_prev = new ListNode(0, head);
        // 1. find the n th node from the start
        for (int i = 0; i < n - 1; i++) {
            current_end = current_end->next;
        }
        // 2. find the n th node from the end
        while (current_end->next) {
            current_end = current_end->next;
            current_prev = current_prev->next;
        }
        if (current_prev->next == head) return head->next;
        removeNode(current_prev);
        return head;
    }

    void removeNode (ListNode* prev) {
        ListNode* current = prev->next;
        prev->next = current->next;
        delete current;
    }
};
