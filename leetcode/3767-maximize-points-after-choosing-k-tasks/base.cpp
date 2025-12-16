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
    vector<pair<int, int>> gainGap(n);

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      gainGap[i] = {technique1[i] - technique2[i], i};
      // ans += technique2[i];
    }

    sort(gainGap.begin(), gainGap.end(), [](auto &a, auto &b)
         {
      if(a.first != b.first) return a.first > b.first;
      return a.second < b.second; });

    unordered_set<int> st;

    for (int i = 0; i < k; i++)
    {
      st.insert(gainGap[i].second);
    }

    for (int i = 0; i < n; i++)
    {
      if (st.count(i))
      {
        ans += technique1[i];
      }
      else
      {
        ans += max(technique1[i], technique2[i]);
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