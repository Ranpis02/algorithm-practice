#include <iostream>
#include <vector>

using namespace std;

class BIT
{
private:
  vector<int> tree;
  int size;

public:
  // 1-based indices
  BIT(int size) : tree(size + 1, 0), size(size)
  {
  }

  int lowbit(int x)
  {
    return x & (-x);
  }

  void update(int index, int deleta)
  {
    for (int i = index; i <= size; i += lowbit(i))
    {
      tree[i] += deleta;
    }
  }

  int query(int index)
  {
    int ans = 0;
    for (int i = index; i > 0; i -= lowbit(i))
    {
      ans += tree[i];
    }

    return ans;
  }

  /**
   * Return the sum of all elements in the range [start, end].
   */
  int queryRange(int start, int end)
  {
    return query(end) - query(start - 1);
  }
};
int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6};

  BIT *bt = new BIT(nums.size());
  // Build the binary index tree.
  for (int i = 0; i < nums.size(); i++)
  {
    bt->update(i + 1, nums[i]);
  }

  // 1. Query the sum of the first four elements.
  cout << bt->query(4) << endl;

  // 2. Query the sum of the elements in the range [2, 5].
  cout << bt->queryRange(2, 5) << endl;

  // 3. Add 2 to the 3rd element.
  bt->update(3, 2);

  // 4. Query the first four elements.
  cout << bt->query(4) << endl;

  return 0;
}