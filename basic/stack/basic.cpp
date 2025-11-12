#include <iostream>
#include <vector>
using namespace std;

/**
 * Next, I'm going to implement a stack fom scratch using a dynamic array.
 */
template <typename T>
class CustomStack
{
private:
  vector<T> elements;

public:
  void push(const T &value)
  {
    elements.push_back(value);
  }

  void pop()
  {
    if (isEmpty())
    {
      throw out_of_range("pop() called on empty stack!");
    }
    elements.pop_back();
  }

  const T &top() const
  {
    if (isEmpty())
    {
      throw out_of_range("top() called on empty stack!");
    }
    return elements.back();
  }

  bool isEmpty() const
  {
    return elements.empty();
  }

  size_t size() const
  {
    return elements.size();
  }
};

int main()
{
  CustomStack<int> st;
  st.push(10);
  st.push(20);

  cout << "Top of custom stack: " << st.top() << endl;

  st.pop();

  cout << "Top of custom stack: " << st.top() << endl;

  cout << "Size of custom stack: " << st.size() << endl;

  return 0;
}