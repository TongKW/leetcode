#include <iostream>
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
    ListNode* swapPairs(ListNode* head) {
        getNewHead(head);
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        if (head->next->next == nullptr) {
            ListNode* temp = head->next;
            temp->next = head;
            head->next = nullptr;
            return temp;
        }
        if (head->next->next->next == nullptr) {
            ListNode* temp = head->next;
            head->next = temp->next;
            temp->next = head;
            return temp;
        }
        ListNode* temp = head->next->next;
        head->next->next = head;
        head->next = temp->next;
        swapIter(temp);
        return newHead;
    }
    
private:
    ListNode* newHead;
    ListNode* swapIter(ListNode* node) {
        if (node->next->next == nullptr) {
            node->next->next = node;
            node->next = nullptr;
            return nullptr;
        }
        if (node->next->next->next == nullptr) {
            ListNode* temp = node->next;
            node->next = temp->next;
            temp->next = node;
            return nullptr;
        }
        ListNode* temp = node->next->next;
        node->next->next = node;
        node->next = temp->next;
        return swapIter(temp);
    }
    
    void getNewHead(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            newHead = head;
            return;
        }
        if (head->next->next == nullptr) {
            newHead = head->next;
            return;
        }
        newHead = head->next;
    }
};
