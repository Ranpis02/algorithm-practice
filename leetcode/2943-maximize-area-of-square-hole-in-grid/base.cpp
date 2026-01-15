#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
  {
    int sideLen = min(findLongConsecutive(hBars), findLongConsecutive(vBars)) + 1;

    return sideLen * sideLen;
  }

  int findLongConsecutive(vector<int> &arr)
  {
    int n = arr.size();
    if (n <= 1)
      return n;

    sort(arr.begin(), arr.end());

    int maxLen = 1;
    int len = 1;
    for (int i = 1; i < n; i++)
    {
      if (arr[i] == arr[i - 1] + 1)
      {
        len++;
        maxLen = max(len, maxLen);
      }
      else
      {
        len = 1;
      }
    }

    return maxLen;
  }
};

int main()
{
  vector<int> arr = {3, 2, 4};
  Solution *sol = new Solution;
  sol->findLongConsecutive(arr);
  return 0;
}