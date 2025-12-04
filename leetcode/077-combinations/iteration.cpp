#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> combine(int n, int k)
  {
    vector<vector<int>> ans;
    vector<int> path(k, 0);

    for (int i = 1; i <= k; i++)
      path[i - 1] = i;

    ans.push_back(path);

    while (true)
    {
      // Iterte from the end to the begining
      int i = k - 1;

      while (i >= 0 && path[i] == (n - (k - i - 1)))
        i--;

      if (i < 0)
        break;

      path[i]++;

      // Restore state
      for (int j = i + 1; j < k; j++)
        path[j] = path[j - 1] + 1;

      ans.push_back(path);
    }

    return ans;
  }
};

int main()
{

  return 0;
}