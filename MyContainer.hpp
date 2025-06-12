#include <algorithm>
#include <vector>
using namespace std;

namespace contain {
template <class K> class MyContainer {
private:
  vector<K> ARR;

public:
  MyContainer() : ARR() {}
  MyContainer(K arr[], int size) { ARR = vector<K>(arr, arr + size); }

  void add(K item) { ARR.push_back(item); }
  void remove(K item) {
    ARR.erase(std::remove(ARR.begin(), ARR.end(), item), ARR.end());
  }
  int size() { return ARR.size(); }
};
} // namespace contain
