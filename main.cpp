#include "MyContainer.hpp"
#include <iostream>

using namespace std;
using namespace contain;

int main() {
  // Create and populate container
  MyContainer<int> container;
  container.add(5);
  container.add(2);
  container.add(8);
  container.add(1);
  container.add(9);

  cout << "Testing different iterator orders:\n";

  cout << "\nAscending order: ";
  AscendingOrder<int> asc(container);
  while (asc.hasNext()) {
    cout << asc.next() << " ";
  }

  cout << "\nDescending order: ";
  DescendingOrder<int> desc(container);
  while (desc.hasNext()) {
    cout << desc.next() << " ";
  }

  cout << "\nOriginal order: ";
  Order<int> ord(container);
  while (ord.hasNext()) {
    cout << ord.next() << " ";
  }

  cout << "\nReverse order: ";
  ReverseOrder<int> rev(container);
  while (rev.hasNext()) {
    cout << rev.next() << " ";
  }

  cout << "\nSide cross order: ";
  SideCrossOrder<int> cross(container);
  while (cross.hasNext()) {
    cout << cross.next() << " ";
  }

  cout << "\nMiddle out order: ";
  MiddleOutOrder<int> mid(container);
  while (mid.hasNext()) {
    cout << mid.next() << " ";
  }

  cout << endl;
  return 0;
}
