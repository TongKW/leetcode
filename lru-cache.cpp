#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Define the Node of double linked list
struct Node
{
public:
  int key;
  int value;
  struct Node *prev;
  struct Node *next;
  Node(int key, int value)
  {
    this->key = key;
    this->value = value;
    this->prev = NULL;
    this->next = NULL;
  }
};

void swapNodes(Node *node1, Node *node2)
{
  Node *temp1 = node1->next;
  Node *temp2 = node1->prev;
  node1->next = node2->next;
  node1->prev = node2->prev;
  node2->next = temp1;
  node2->prev = temp2;
}

void removeNode(Node *node)
{
  node->prev->next = node->next;
  node->next->prev = node->prev;
}

void insertNodeBetween(Node *node, Node *front, Node *back)
{
  node->prev = front;
  node->next = back;
  front->next = node;
  back->prev = node;
}

class LRUCache
{
public:
  LRUCache(int cap)
  {
    length = 0;
    capacity = cap;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  int get(int key)
  {
    if (nodeMap.find(key) == nodeMap.end())
      return -1;
    updateToHead(key);
    return nodeMap[key]->value;
  }

  void put(int key, int value)
  {
    if (nodeMap.find(key) == nodeMap.end())
    {
      insertHead(key, value);
    }
    else
    {
      nodeMap[key]->value = value;
      updateToHead(key);
    }
  }

private:
  int length;
  int capacity;
  Node *head;
  Node *tail;
  unordered_map<int, Node *> nodeMap;

  void insertHead(int key, int value)
  {
    Node *temp = new Node(key, value);
    nodeMap[key] = temp;
    insertNodeBetween(temp, head, head->next);
    if (capacity < ++length)
      deleteTail();
  }

  void updateToHead(int key)
  {
    if (length == 1)
      return;
    Node *target = nodeMap[key];
    if (target == head->next)
      return;
    removeNode(target);
    insertNodeBetween(target, head, head->next);
  }

  void deleteTail()
  {
    if (length == 0)
      return;
    Node *temp = tail->prev;
    int key = temp->key;
    removeNode(temp);
    nodeMap.erase(key);
    delete temp;
    length--;
  }
};