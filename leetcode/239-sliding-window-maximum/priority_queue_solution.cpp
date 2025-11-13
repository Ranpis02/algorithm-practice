#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Use a max-heap storing pairs of (value, index).
 * `.first`: The element's value(nums[i]).
 * `.second`: The element's index(i).
 *
 * The index is used for "lazy deletion". We only pop the heap'top if its index is outside the current window's bound.
 */
class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {

    vector<int> ans;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++)
    {
      pq.emplace(nums[i], i);
    }

    ans.push_back(pq.top().first);

    for (int i = k; i < nums.size(); i++)
    {
      pq.emplace(nums[i], i);
      while (pq.top().second <= i - k)
      {
        pq.pop();
      }
      ans.push_back(pq.top().first);
    }

    return ans;
  }
};

int main()
{

  return 0;
}