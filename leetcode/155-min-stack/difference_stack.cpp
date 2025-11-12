#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
private:
  stack<long long> elements;
  long long min_v;

public:
  MinStack()
  {
  }

  void push(int val)
  {
    if (elements.empty())
    {
      elements.push(0);
      min_v = val;
    }
    else
    {
      elements.push(val - min_v);
      if (val < min_v)
        min_v = val;
    }
  }

  void pop()
  {
    long long diff = elements.top();
    if (diff < 0)
    {
      min_v = min_v - diff;
    }
    elements.pop();
  }

  int top()
  {
    long long diff = elements.top();
    if (diff <= 0)
      return min_v;
    else
      return min_v + diff;
  }

  int getMin()
  {
    return min_v;
  }
};

int main()
{

  return 0;
}