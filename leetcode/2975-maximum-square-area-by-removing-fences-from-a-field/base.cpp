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

    // unordered_set<int> heights;
    unordered_set<int> heights;
    unordered_set<int> widths;

    sort(hFences.begin(), hFences.end());
    sort(vFences.begin(), vFences.end());

    for (int i = 0; i < hSize; i++)
    {
      for (int j = i + 1; j < hSize; j++)
      {
        heights.insert(hFences[j] - hFences[i]);
      }
    }

    for (int i = 0; i < vSize; i++)
    {
      for (int j = i + 1; j < vSize; j++)
      {
        widths.insert(vFences[j] - vFences[i]);
      }
    }

    long long ans = -1;
    for (auto height : heights)
    {
      if (widths.count(height))
      {
        ans = max(ans, (long long)height * height);
      }
    }

    return ans % MOD;
  }
};

int main()
{

  return 0;
}