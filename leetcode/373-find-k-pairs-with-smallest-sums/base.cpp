#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    int n = nums1.size(), m = nums2.size();

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, MyComp> pq;

    for (int i = 0; i < m; i++)
    {
      pq.push({nums1[0] + nums2[i], {0, i}});
    }

    vector<vector<int>> ans(k);

    for (int i = 0; i < k && !pq.empty(); i++)
    {
      auto cand = pq.top();
      pq.pop();

      // int  = cand.first;
      int firstIdx = cand.second.first;
      int secondIdx = cand.second.second;

      ans[i] = {nums1[firstIdx], nums2[secondIdx]};
      if (firstIdx + 1 < n)
      {
        pq.push({nums1[firstIdx + 1] + nums2[secondIdx], {firstIdx + 1, secondIdx}});
      }
    }

    return ans;
  }

private:
  struct MyComp
  {
    bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) const
    {
      return a.first > b.first;
    }
  };
};

int main()
{

  return 0;
}
