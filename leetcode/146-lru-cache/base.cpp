#include <bits/stdc++.h>

using namespace std;

struct DLinkedNode
{
  int key, val;
  DLinkedNode *next;
  DLinkedNode *prev;

  DLinkedNode() : key(0), val(0), next(nullptr), prev(nullptr) {}

  DLinkedNode(int m_key, int m_val) : key(m_key), val(m_val), next(nullptr), prev(nullptr) {}
};

class LRUCache
{
public:
  LRUCache(int capacity)
  {
    size = 0;
    cap = capacity;
    head = new DLinkedNode();
    tail = new DLinkedNode();

    head->next = tail;
    tail->prev = head;
  }

  int get(int key)
  {
    if (!cache.count(key))
    {
      return -1;
    }

    DLinkedNode *crr = cache[key];
    moveToHead(crr);

    return cache[key]->val;
  }

  void put(int key, int value)
  {
    if (cache.count(key))
    {
      DLinkedNode *crr = cache[key];
      crr->val = value;
      moveToHead(crr);
    }
    else
    {
      DLinkedNode *newAdd = new DLinkedNode(key, value);
      addNodeToHead(newAdd);
      cache[key] = newAdd;
      size++;

      if (size > cap)
      {
        DLinkedNode *last = removeTail();
        cache.erase(last->key);
        size--;

        delete last;
      }
    }
  }

  void removeNode(DLinkedNode *node)
  {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void addNodeToHead(DLinkedNode *node)
  {
    node->next = head->next;
    node->next->prev = node;

    head->next = node;
    node->prev = head;
  }

  void moveToHead(DLinkedNode *node)
  {
    removeNode(node);
    addNodeToHead(node);
  }

  DLinkedNode *removeTail()
  {
    DLinkedNode *last = tail->prev;
    removeNode(last);

    return last;
  }

private:
  int size, cap;
  // Two dummy nodes: the head and tail of list, resepctively.
  DLinkedNode *head;
  DLinkedNode *tail;

  unordered_map<int, DLinkedNode *> cache;
};

int main()
{
  LRUCache *lru = new LRUCache(2);

  lru->put(1, 100);
  lru->put(2, 200);
  lru->put(3, 300);
  lru->put(4, 400);
  lru->put(5, 500);
  lru->put(6, 600);
  lru->put(7, 700);

  cout << lru->get(6) << endl;

  return 0;
}