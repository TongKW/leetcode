#include <iostream>
#include <tuple>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        ListNode* headPrev = new ListNode(0, head);
        ListNode *kthNode, *randomNode;
        bool isLtk;
        tie(isLtk, kthNode) = nNext(headPrev, k);
        if (!isLtk) return head;
        ListNode* iterNode = headPrev;
        while (isLtk) {
            iterNode = revertNextN(iterNode, k);
            tie(isLtk, randomNode) = nNext(iterNode, k);
        }
        return kthNode;
    }
private:
    ListNode* newHead;
    ListNode* revertNextN(ListNode* headPrev, int N) {
        ListNode* firstNext = headPrev->next;
        ListNode* iterNode = headPrev;
        auto revertIter = [&](ListNode* tail, int n) {
            if (n == 1) {
                firstNext->next = headPrev->next->next;
                headPrev->next->next = tail;
                return headPrev->next;
            }
            ListNode* target = headPrev->next;
            headPrev->next = target->next;
            target->next = tail;
            return target;
        };
        while (N > 0) {
            iterNode = revertIter(iterNode, N);
            N--;
        }
        return firstNext;
    }
    
    tuple<bool, ListNode*> nNext(ListNode* node, int n) {
        if (n == 0) return tuple<bool, ListNode*>{true, node};
        if (node->next == nullptr) return tuple<bool, ListNode*>{false, node};
        return nNext(node->next, n-1);
    }
};
