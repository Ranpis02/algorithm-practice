#include <bits/stdc++.h>

using namespace std;
class MedianFinder
{
public:
  MedianFinder()
  {
  }

  void addNum(int num)
  {
    queLeft.push(num);

    queRight.push(queLeft.top());
    queLeft.pop();

    while (queRight.size() > queLeft.size())
    {
      queLeft.push(queRight.top());
      queRight.pop();
    }
  }

  double findMedian()
  {
    if (queRight.size() != queLeft.size())
    {
      return queLeft.top();
    }

    return (queRight.top() + queLeft.top()) / 2.0;
  }

private:
  priority_queue<int, vector<int>, less<int>> queLeft;
  priority_queue<int, vector<int>, greater<int>> queRight;
};

int main()
{

  return 0;
}