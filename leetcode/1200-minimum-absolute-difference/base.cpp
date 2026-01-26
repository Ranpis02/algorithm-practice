#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr)
  {
    int n = arr.size();

    int minVal = INT_MAX;
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for (int i = 1; i < n; i++)
    {
      int t = arr[i] - arr[i - 1];
      if (t < minVal)
      {
        ans.clear();

        minVal = t;
      }

      if (t <= minVal)
      {
        ans.push_back({arr[i - 1], arr[i]});
      }
    }

    return ans;
  }
};

int main()
{
  vector<int> arr = {4, 2, 1, 3};
  Solution *sol = new Solution;
  sol->minimumAbsDifference(arr);

  return 0;
}