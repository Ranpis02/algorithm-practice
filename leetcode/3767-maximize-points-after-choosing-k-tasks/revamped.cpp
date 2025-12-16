#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  long long maxPoints(vector<int> &technique1, vector<int> &technique2, int k)
  {
    int n = technique1.size();
    vector<int> diff(n);

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      diff[i] = technique1[i] - technique2[i];
      ans += technique2[i];
    }

    sort(diff.begin(), diff.end(), greater<int>());

    for (int i = 0; i < n; i++)
    {
      if (i < k || diff[i] > 0)
      {
        ans += diff[i];
      }
      else
      {
        break;
      }
    }

    return ans;
  }
};

int main()
{
  vector<int> t1 = {10, 20, 30};
  vector<int> t2 = {5, 15, 25};

  Solution *sol = new Solution;
  sol->maxPoints(t1, t2, 2);

  return 0;
}