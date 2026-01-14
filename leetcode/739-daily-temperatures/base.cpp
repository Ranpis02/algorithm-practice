#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int n = temperatures.size();
    stack<pair<int, int>> st;
    st.push({temperatures[0], 0});

    vector<int> ans(n, 0);
    for (int i = 1; i < n; i++)
    {
      // auto [t, idx] = st.top();
      while (!st.empty() && temperatures[i] > st.top().first)
      {
        int idx = st.top().second;
        ans[idx] = i - idx;
        st.pop();
      }

      st.push({temperatures[i], i});
    }

    return ans;
  }
};

int main()
{

  return 0;
}