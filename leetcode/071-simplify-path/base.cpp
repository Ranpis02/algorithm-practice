#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  string simplifyPath(string path)
  {
    stack<string> st;

    path.push_back('/');
    int n = path.size();
    string name = "";
    for (int i = 0; i < n; i++)
    {
      if (path[i] == '/')
      {
        if (name.empty() || name == ".")
        {
          name = "";
          continue;
        }

        if (name == "..")
        {
          if (!st.empty())
            st.pop();
        }
        else
        {
          st.push(name);
        }

        name = "";
      }
      else
      {
        name += path[i];
      }
    }

    n = st.size();
    if (n == 0)
      return "/";

    vector<string> names(n);

    for (int i = 0; i < n; i++)
    {
      names[i] = st.top();
      st.pop();
    }

    reverse(names.begin(), names.end());

    string ans = "";
    for (int i = 0; i < n; i++)
    {
      ans += '/';
      ans += names[i];
    }

    return ans;
  }
};

int main()
{

  return 0;
}