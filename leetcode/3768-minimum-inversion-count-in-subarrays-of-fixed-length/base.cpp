#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BIT
{
private:
  vector<int> tree;
  int size;

public:
  BIT(int size) : tree(size + 1, 0), size(size) {}

  int lowbit(int x)
  {
    return x & (-x);
  }

  void update(int i, int p)
  {
    while (i <= size)
    {
      tree[i] += p;
      i += lowbit(i);
    }
  }

  int query(int i)
  {
    int ans = 0;
    while (i > 0)
    {
      ans += tree[i];
      i -= lowbit(i);
    }

    return ans;
  }

  int queryRange(int start, int end)
  {
    return query(start) - query(end - 1);
  }
};

class Solution
{
public:
  long long minInversionCount(vector<int> &nums, int k)
  {
    // 1. Discretize
    int n = nums.size();
    vector<int> sortedVal(nums);

    sort(sortedVal.begin(), sortedVal.end());
    sortedVal.erase(unique(sortedVal.begin(), sortedVal.end()), sortedVal.end());

    for (int &x : nums)
    {
      x = lower_bound(sortedVal.begin(), sortedVal.end(), x) - sortedVal.begin() + 1;
    }

    long long minInv = LLONG_MAX;
    long long curInv = 0;

    BIT *bt = new BIT(n);
    for (int i = 0; i < k; i++)
    {
      curInv += (i - bt->query(nums[i]));
      bt->update(nums[i], 1);
    }

    minInv = min(minInv, curInv);

    for (int i = k; i < n; i++)
    {
      curInv -= bt->query(nums[i - k] - 1);
      bt->update(nums[i - k], -1);

      curInv += (k - bt->query(nums[i]) - 1);
      bt->update(nums[i], 1);

      minInv = min(curInv, minInv);
    }

    delete bt;

    return minInv;
  }
};

int main()
{
  vector<int> nums = {3, 1, 2, 5, 4};
  int k = 3;

  Solution *sol = new Solution;
  sol->minInversionCount(nums, k);

  return 0;
}