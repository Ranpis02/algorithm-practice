#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<string> generateParenthesis(int n)
  {
    ans.clear();
    s.assign(2 * n, ' ');
    st = stack<char>();
    cnt = 0;

    dfs(0, n);

    return ans;
  }

  void dfs(int idx, int n)
  {
    if (idx == 2 * n)
    {
      ans.push_back(s);
      return;
    }

    if (st.empty() || (st.top() == '(' && cnt < n))
    {
      s[idx] = '(';
      cnt++;
      st.push('(');

      dfs(idx + 1, n);

      cnt--;
      st.pop();
    }

    if (!st.empty() && st.top() == '(')
    {
      s[idx] = ')';
      st.pop();

      dfs(idx + 1, n);

      st.push('(');
    }
  }

private:
  vector<string> ans;
  string s;
  stack<char> st;
  int cnt;
};

int main()
{

  return 0;
}