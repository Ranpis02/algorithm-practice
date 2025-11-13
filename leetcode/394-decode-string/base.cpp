#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

class Solution
{
public:
  string decodeString(string s)
  {
    stack<char> st;
    for (char ch : s)
    {
      if (ch == ']')
      {
        vector<char> ch_arr;
        string tmp = "";

        while (st.top() != '[')
        {
          ch_arr.push_back(st.top());
          st.pop();
        }

        st.pop();

        while (!st.empty() && isdigit(st.top()))
        {
          tmp += st.top();
          st.pop();
        }

        reverse(tmp.begin(), tmp.end());
        int times = stoi(tmp);

        for (int i = 0; i < times; i++)
        {
          for (int j = ch_arr.size() - 1; j >= 0; j--)
          {
            st.push(ch_arr[j]);
          }
        }
      }
      else
      {
        st.push(ch);
      }
    }

    string ans = "";
    while (!st.empty())
    {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
  }
};

int main()
{
  string s = "3[a]2[bc]";
  Solution *sol = new Solution;
  string ans = sol->decodeString(s);
  cout << ans << endl;

  return 0;
}