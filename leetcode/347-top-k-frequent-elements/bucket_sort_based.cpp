#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> mp;
    int n = nums.size();
    vector<int> ans;

    for (int val : nums)
    {
      mp[val]++;
    }

    vector<vector<int>> buckets(n + 1);

    for (auto &[num, cnt] : mp)
    {
      buckets[cnt].push_back(num);
    }

    for (int i = n; i >= 0 && ans.size() < k; i--)
    {
      for (int val : buckets[i])
      {
        ans.push_back(val);
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}