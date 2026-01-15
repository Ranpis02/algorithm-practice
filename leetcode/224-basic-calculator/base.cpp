#include <bits/stdc++.h>

using namespace std;

/**
 * Upon encountering `+` or `-`, we add the accumulated number to the result, taking care of any remaining number that has not yet been processed.
 */
class Solution
{
public:
  int calculate(string s)
  {
    long long ans = 0;
    long long sign = 1;
    long long num = 0;

    stack<int> st;

    for (char ch : s)
    {
      if (isdigit(ch))
      {
        num = num * 10 + (ch - '0');
      }
      else if (ch == '+' || ch == '-')
      {
        ans += num * sign;

        sign = ch == '+' ? 1 : -1;
        num = 0;
      }
      else if (ch == '(')
      {
        st.push(ans);
        st.push(sign);

        num = 0;
        ans = 0;
        sign = 1;
      }
      else if (ch == ')')
      {
        ans += sign * num;
        num = 0;

        int prev_sign = st.top();
        st.pop();
        int prev_ans = st.top();
        st.pop();

        prev_ans += prev_sign * ans;
        ans = prev_ans;
      }
    }

    ans += sign * num;
    return ans;
  }
};

int main()
{
  string s = "-2147483648";
  Solution *sol = new Solution;
  sol->calculate(s);

  return 0;
}