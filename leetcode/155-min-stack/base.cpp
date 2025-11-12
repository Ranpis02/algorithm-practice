#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
private:
  stack<int> data_st;
  stack<int> min_st;

public:
  MinStack()
  {
    // Place a sentinel to avoid a crash on the first `push()` check
    min_st.push(INT_MAX);
  }

  void push(int val)
  {
    data_st.push(val);
    if (val < min_st.top())
      min_st.push(val);
    else
      min_st.push(min_st.top());
  }

  void pop()
  {
    data_st.pop();
    min_st.pop();
  }

  int top()
  {
    return data_st.top();
  }

  int getMin()
  {
    return min_st.top();
  }
};

int main()
{

  return 0;
}