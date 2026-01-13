#include <bits/stdc++.h>

using namespace std;

class LRUCache
{
public:
  LRUCache(int capacity)
  {
    size = 0;
    limit = capacity;
  }

  int get(int key)
  {
    if (!cache.count(key))
      return -1;

    auto it = cache[key];
    lruList.splice(lruList.begin(), lruList, it);

    return it->second;
  }

  void put(int key, int value)
  {
    if (cache.count(key))
    {
      auto it = cache[key];
      it->second = value;
      lruList.splice(lruList.begin(), lruList, it);
    }
    else
    {
      size++;
      lruList.push_front({key, value});
      cache[key] = lruList.begin();

      if (size > limit)
      {
        auto it = lruList.back();
        cache.erase(it.first);
        lruList.pop_back();
        size--;
      }
    }
  }

private:
  int size, limit;
  list<pair<int, int>> lruList;
  unordered_map<int, list<pair<int, int>>::iterator> cache;
};

int main()
{

  return 0;
}