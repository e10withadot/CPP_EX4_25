#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

namespace contain {
template <class K> class MyContainer {
private:
  vector<K> ARR;

public:
  MyContainer() : ARR() {}
  MyContainer(K arr[], int size) { ARR = vector<K>(arr, arr + size); }

  /*
   * Adds a new item to the end of the container.
   */
  void add(K item) { ARR.push_back(item); }

  /*
   * Removes every instance of the item in the container.
   */
  void remove(K item) {
    ARR.erase(std::remove(ARR.begin(), ARR.end(), item), ARR.end());
  }

  /*
   * Returns the container size.
   */
  int size() { return ARR.size(); }

  friend ostream &operator<<(ostream &os, const MyContainer<K> &c) {
    os << "[ ";
    for (int i = 0; i < c->ARR.size(); i++) {
      os << c->ARR[i];
      if (i != c->ARR.size() - 1)
        os << ", ";
    }
    os << " ]\n";
    return os;
  }
};
} // namespace contain
