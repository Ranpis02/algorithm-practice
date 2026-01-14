#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5; // assumed data size
int arr[MAXN];            // original array
int tree[MAXN * 4];       // segment tree array

// Example for supporting point update and range sum query.

/**
 * @brief Auxiliary function: update upwards.
 */
void push_up(int node)
{
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

/**
 * @brief Builds the segment tree.
 *
 * @param node  The index of current segment tree node.
 * @param start The left boundary of current segment.
 * @param end   The right boundary of current segment.
 */
void build(int node, int start, int end)
{
  if (start == end)
  {
    tree[node] = arr[start];
    return;
  }

  int mid = (start + end) / 2;

  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);

  push_up(node);
}

/**
 * @brief Performs a single-point update on the segment tree.
 *
 * @param node  The index of current segment tree node.
 * @param start The left boundary of current segment.
 * @param end   The right boundary of current segment.
 * @param idx   The index in the original array to be updated.
 * @param val   The new value to assign.
 */
void update(int node, int start, int end, int idx, int val)
{
  if (start == end)
  {
    tree[node] = val;
    arr[idx] = val;

    return;
  }

  int mid = (start + end) / 2;
  if (idx <= mid)
  {
    update(node * 2, start, mid, idx, val);
  }
  else
  {
    update(node * 2 + 1, mid + 1, end, idx, val);
  }

  push_up(node);
}

/**
 * @brief Queries the sum over a given range [L, R].
 *
 * @param node  The index of current segment tree node.
 * @param start The left boundary of current segment.
 * @param end   The right boundary of current segment.
 * @param L     The left boundary of the query range.
 * @param R     The right boundary of the query range.
 *
 * @return The sum of elements in the range [L, R].
 */
int query(int node, int start, int end, int L, int R)
{
  if (L <= start && end <= R)
  {
    return tree[node];
  }

  int mid = (start + end) / 2;

  int sum = 0;
  if (L <= mid)
  {
    sum += query(node * 2, start, mid, L, R);
  }

  if (R > mid)
  {
    sum += query(node * 2 + 1, mid + 1, end, L, R);
  }

  return sum;
}

int main()
{
  for (int i = 1; i <= 10; i++)
  {
    arr[i] = i;
  }

  build(1, 1, 10);

  cout << "The sum of range [3, 5]: " << query(1, 1, 10, 3, 5) << endl;

  update(1, 1, 10, 4, 10);

  cout << "The sum of range [3, 5]: " << query(1, 1, 10, 3, 5) << endl;

  return 0;
}