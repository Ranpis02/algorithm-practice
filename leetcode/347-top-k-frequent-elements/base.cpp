#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> mp;
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    for (int num : nums)
    {
      mp[num]++;
    }

    for (auto &p : mp)
    {
      pq.push({p.second, p.first});

      if (pq.size() > k)
        pq.pop();
    }

    vector<int> ans;

    while (!pq.empty())
    {
      ans.push_back(pq.top().second);
      pq.pop();
    }

    return ans;
  }
};

int main()
{

  return 0;
}
