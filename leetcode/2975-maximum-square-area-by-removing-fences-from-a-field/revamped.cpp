#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
  static constexpr int MOD = 1e9 + 7;

public:
  int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
  {
    hFences.push_back(1);
    hFences.push_back(m);

    vFences.push_back(1);
    vFences.push_back(n);
    int hSize = hFences.size(), vSize = vFences.size();

    unordered_set<int> heights;

    sort(hFences.begin(), hFences.end());
    sort(vFences.begin(), vFences.end());

    for (int i = 0; i < hSize; i++)
    {
      for (int j = i + 1; j < hSize; j++)
      {
        heights.insert(hFences[j] - hFences[i]);
      }
    }

    int maxLen = -1;

    for (int i = 0; i < vSize; i++)
    {
      for (int j = i + 1; j < vSize; j++)
      {
        int diff = vFences[j] - vFences[i];
        if (heights.count(diff))
        {
          maxLen = max(maxLen, diff);
        }
      }
    }

    return maxLen == -1 ? -1 : (long long)maxLen * maxLen % MOD;
  }
};

int main()
{
  vector<int> hFences = {2};
  vector<int> vFences = {4};

  Solution *sol = new Solution;
  sol->maximizeSquareArea(4, 5, hFences, vFences);

  return 0;
}