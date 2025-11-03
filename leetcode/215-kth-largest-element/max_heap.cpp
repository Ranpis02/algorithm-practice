#include <iostream>
#include <string>
#include <vector>

using namespace std;
/**
 * Intro: Min-Heap Implementation
 * Min-Heap: A complete binary tree where the value of each node is less than the value of its children.
 * Note: The complete binary tree must be filled with nodes on all levels except the bottom level.
 */
class MinHeap
{
private:
  vector<int> heap;

  /**
   * @brief heapify up
   * 
   * 
   * @param index The index of the newly inserted element.
   * 
   * @note Time complexity: O(log n)
   */
  void heapifyUp(int index)
  {
    while (index > 0 && heap[index] < heap[(index - 1) / 2])
    {
      swap(heap[index], heap[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }

  /**
   * @brief heapify down
   * 
   * @param index the index of the element to heapify down.
   * 
   */
  void heapifyDown(int index)
  {
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;
    int smallest = index;

    if(leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
      smallest = leftChild;
    }

    if(rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
      smallest = rightChild;
    } 

    if(smallest != index) {
      swap(heap[index], heap[smallest]);
      heapifyDown(smallest);
    }
  }

public:

/**
 * Insert element
 */
void insert(int val) {
  heap.push_back(val);
  // heap.heapifyUp()
}
};

int main()
{
  return 0;
}