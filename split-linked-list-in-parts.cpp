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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // 1. initialisation
        vector<ListNode*> ans(k, nullptr);
        ListNode* last = head;

        int i = 0;

        for (int j = 0; j <= k; j++) {
            if (!last) {
                for (int l = 0; l < j; l++) ans[l]->next = nullptr;
                return ans;
            }
            if (j == k) break;
            ans[j] = last;
            last = last->next;
        }

        while (true) {
            if (!last) break;
            for (int j = i + 1; j < k; j++) {
                ans[j] = ans[j]->next;
            }
            last = last->next;
            i = (i + 1) % k;
        }

        // 2. split list
        int index = 1;
        ListNode* iter = head;
        while (iter && index < k) {
            if (iter->next == ans[index]) {
                ListNode* temp = iter;
                iter = iter->next;
                // cout << "Split at: " << temp->val << endl;
                temp->next = nullptr;
                index += 1;
            } else {
                iter = iter->next;
            }
        }

        return ans;
    }
};
