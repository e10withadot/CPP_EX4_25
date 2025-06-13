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

  bool hasNext() const { return IT != SORT.begin(); }
  const K &next() { return *(IT--); }
  void reset() { IT = SORT.end(); }
};

template <class K> class SideCrossOrder {
private:
  vector<K> SORT;
  typename vector<K>::const_iterator IT1;
  typename vector<K>::const_iterator IT2;
  bool is_one = true;

public:
  SideCrossOrder(const MyContainer<K> &container) : SORT(container.ARR) {
    std::sort(SORT.begin(), SORT.end());
    IT1 = SORT.begin();
    IT2 = SORT.end();
  }
  SideCrossOrder(const SideCrossOrder &other)
      : SORT(other.SORT), IT1(SORT.begin() + (other.IT1 - other.SORT.begin())),
        IT2(SORT.end() - (other.SORT.end() - other.IT2)) {}

  bool hasNext() const { return IT1 != SORT.end() || IT2 != SORT.begin(); }
  const K &next() {
    if (is_one)
      return *(IT1++);
    else
      return *(IT2--);
  }
  void reset() {
    IT1 = SORT.begin();
    IT2 = SORT.end();
  }
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

  bool hasNext() const { return IT != VEC.begin(); }
  const K &next() { return *(IT--); }
  void reset() { IT = VEC.end(); }
};
} // namespace contain
