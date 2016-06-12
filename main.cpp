#include "testSuit.hpp"
#include "algorithm.hpp"

using namespace myalgorithm;


int main(void) {
  
  test(bubbleSort<int>);
  test(heapSort<int>);
  test(mergeSort<int>);
  test(selectSort<int>);
  test(quickSort<int>);
  test(insertionSort<int>);
  test(shellSort<int>);

  return 0;
}
