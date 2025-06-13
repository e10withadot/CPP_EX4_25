#include <vector>
using namespace std;
#include "MyContainer.hpp"
using namespace contain;

namespace contain {
template <class K> class AscendingOrder {
private:
  vector<K> SORT;
  typename vector<K>::const_iterator IT;

public:
  AscendingOrder(const MyContainer<K> &container) : SORT(container.ARR) {
    std::sort(SORT.begin(), SORT.end());
    IT = SORT.begin();
  }
  AscendingOrder(const AscendingOrder &other)
      : SORT(other.SORT), IT(SORT.begin() + (other.IT - other.SORT.begin())) {}

  bool hasNext() const { return IT != SORT.end(); }
  const K &next() { return *(IT++); }
  void reset() { IT = SORT.begin(); }
};

template <class K> class DescendingOrder {
private:
  vector<K> SORT;
  typename vector<K>::const_iterator IT;

public:
  DescendingOrder(const MyContainer<K> &container) : SORT(container.ARR) {
    std::sort(SORT.begin(), SORT.end());
    IT = SORT.end();
  }
  DescendingOrder(const DescendingOrder &other)
      : SORT(other.SORT), IT(SORT.end() - (other.SORT.end() - other.IT)) {}

  bool hasNext() const { return IT != SORT.head(); }
  const K &next() { return *(IT--); }
  void reset() { IT = SORT.end(); }
};

template <class K> class ReverseOrder {
private:
  vector<K> VEC;
  typename vector<K>::const_iterator IT;

public:
  ReverseOrder(const MyContainer<K> &container) : VEC(container.ARR) {
    IT = VEC.end();
  }
  ReverseOrder(const ReverseOrder &other)
      : VEC(other.VEC), IT(VEC.end() - (other.VEC.end() - other.IT)) {}

  bool hasNext() const { return IT != VEC.head(); }
  const K &next() { return *(IT--); }
  void reset() { IT = VEC.end(); }
};
} // namespace contain
