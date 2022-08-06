#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Data {
    int val;
    int index;
    Data(int val, int index) : val(val), index(index) {}
    friend bool operator< (Data const& d1, Data const& d2) {
        return d1.val > d2.val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i = 0; i < lists.size(); i++) {
            if (!lists[i]) continue;
            node_map[i] = lists[i];
            Data *data = new Data(lists[i]->val, i);
            min_heap.push(*data);
        }
        while (!min_heap.empty()) {
            Data const& data = min_heap.top();
            // Initialize head and current or push back to current
            if (!head) {
                head = node_map[data.index]; 
                current = node_map[data.index];
            } else {
                ListNode* next = new ListNode(data.val);
                current->next = next;
                current = next;
            }
            // Increment node map pointer
            // Push original data into min heap
            if (node_map[data.index]->next) {
                ListNode* temp = node_map[data.index]->next;
                node_map[data.index] = temp;
                Data *tempdata = new Data(temp->val, data.index);
                min_heap.push(*tempdata);
            }
            min_heap.pop();
        }
        return head;
    }
private:
    priority_queue<Data> min_heap;
    map<int, ListNode*> node_map;
    ListNode* head = nullptr;
    ListNode* current = nullptr;
};
