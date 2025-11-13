#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution_TLE
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    queue<int> q;
    vector<int> ans;

    int max_val = INT_MIN;
    for (int i = 0; i < k; i++)
    {
      if (nums[i] > max_val)
        max_val = nums[i];
      q.push(nums[i]);
    }
    ans.push_back(max_val);

    for (int i = k; i < nums.size(); i++)
    {
      if (nums[i] >= max_val)
      {
        max_val = nums[i];
        q.push(nums[i]);
        q.pop();
      }
      else if (q.front() == max_val)
      {
        q.pop();
        queue<int> tmp(q);
        max_val = nums[i];
        while (!tmp.empty())
        {
          if (tmp.front() > max_val)
            max_val = tmp.front();
          tmp.pop();
        }
        q.push(nums[i]);
      }
      else
      {
        q.push(nums[i]);
        q.pop();
      }

      ans.push_back(max_val);
    }

    return ans;
  }
};

int main()
{
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;

    return 0;
}