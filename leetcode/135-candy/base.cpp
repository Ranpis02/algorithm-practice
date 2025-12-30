#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int candy(vector<int> &ratings)
  {
    int n = ratings.size();

    vector<int> candy(n, 1);

    for (int i = 1; i < n; i++)
    {
      if (ratings[i - 1] < ratings[i])
      {
        candy[i] = candy[i - 1] + 1;
      }
    }

    for (int i = n - 1; i > 0; i--)
    {
      if (ratings[i - 1] > ratings[i])
      {
        candy[i - 1] = max(candy[i - 1], candy[i] + 1);
      }
    }

    return reduce(candy.begin(), candy.end());
  }
};

int main()
{
  vector<int> nums = {1, 3, 4, 5, 2};

  Solution *sol = new Solution;
  sol->candy(nums);

  return 0;
}