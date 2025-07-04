// ey.gellis@gmail.com
#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

namespace contain {
template <typename K> class MyContainer;
template <typename K> class AscendingOrder {
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
  typename vector<K>::const_iterator begin() { return SORT.begin(); }
  typename vector<K>::const_iterator end() { return SORT.end(); }
};

template <typename K> class DescendingOrder {
private:
  vector<K> SORT;
  typename vector<K>::const_iterator IT;

public:
  DescendingOrder(const MyContainer<K> &container) : SORT(container.ARR) {
    std::sort(SORT.begin(), SORT.end());
    IT = SORT.end() - 1;
  }
  DescendingOrder(const DescendingOrder &other)
      : SORT(other.SORT), IT(SORT.end() - (other.SORT.end() - other.IT)) {}

  bool hasNext() const { return IT >= SORT.begin(); }
  const K &next() { return *(IT--); }
  void reset() { IT = SORT.end() - 1; }
  typename vector<K>::const_iterator begin() { return SORT.end() - 1; }
  typename vector<K>::const_iterator end() { return SORT.begin(); }
};

template <typename K> class SideCrossOrder {
private:
  vector<K> SORT;
  typename vector<K>::const_iterator IT;
  void buildOrder() {
    vector<K> newsort;
    newsort.reserve(SORT.size());
    // IT1 is ascending
    typename vector<K>::const_iterator IT1 = SORT.begin();
    // IT2 is descending
    typename vector<K>::const_iterator IT2 = SORT.end() - 1;
    while (IT1 <= IT2) {
      // iterate and take from beginning
      newsort.push_back(*IT1++);
      if (IT1 > IT2)
        break;
      // iterate and take from end
      newsort.push_back(*IT2--);
    }
    SORT = newsort;
  }

public:
  SideCrossOrder(const MyContainer<K> &container) : SORT(container.ARR) {
    std::sort(SORT.begin(), SORT.end());
    buildOrder();
    IT = SORT.begin();
  }
  SideCrossOrder(const SideCrossOrder &other)
      : SORT(other.SORT), IT(SORT.begin() + (other.IT - other.SORT.begin())) {}

  bool hasNext() const { return IT != SORT.end(); }
  const K &next() { return *(IT++); }
  void reset() {
    buildOrder();
    IT = SORT.begin();
  }
  typename vector<K>::const_iterator begin() { return SORT.begin(); }
  typename vector<K>::const_iterator end() { return SORT.end(); }
};

template <typename K> class ReverseOrder {
private:
  vector<K> VEC;
  typename vector<K>::const_iterator IT;

public:
  ReverseOrder(const MyContainer<K> &container) : VEC(container.ARR) {
    IT = VEC.end() - 1;
  }
  ReverseOrder(const ReverseOrder &other)
      : VEC(other.VEC), IT(VEC.end() - (other.VEC.end() - other.IT)) {}

  bool hasNext() const { return IT >= VEC.begin(); }
  const K &next() { return *(IT--); }
  void reset() { IT = VEC.end() - 1; }
  typename vector<K>::const_iterator begin() { return VEC.end() - 1; }
  typename vector<K>::const_iterator end() { return VEC.begin(); }
};

template <typename K> class Order {
private:
  vector<K> VEC;
  typename vector<K>::const_iterator IT;

public:
  Order(const MyContainer<K> &container) : VEC(container.ARR) {
    IT = VEC.begin();
  }
  Order(const Order &other)
      : VEC(other.VEC), IT(VEC.begin() + (other.IT - other.VEC.begin())) {}

  bool hasNext() const { return IT != VEC.end(); }
  const K &next() { return *(IT++); }
  void reset() { IT = VEC.begin(); }
  typename vector<K>::const_iterator begin() { return VEC.begin(); }
  typename vector<K>::const_iterator end() { return VEC.end(); }
};

template <typename K> class MiddleOutOrder {
private:
  vector<K> SORT;
  typename vector<K>::const_iterator IT;

  void buildOrder() {
    vector<K> newsort;
    newsort.reserve(SORT.size());
    int mid = (SORT.size() - 1) / 2;
    newsort.push_back(SORT[mid]);
    long unsigned int left = mid - 1, right = mid + 1;
    bool go_left = true;
    while (newsort.size() < SORT.size()) {
      if (go_left && left < SORT.size())
        // if left, move left and add to container
        newsort.push_back(SORT[left--]);
      else if (right < SORT.size())
        // if right, move right and add to container
        newsort.push_back(SORT[right++]);
      go_left = !go_left;
    }
    SORT = newsort;
  }

public:
  MiddleOutOrder(const MyContainer<K> &container) : SORT(container.ARR) {
    buildOrder();
    IT = SORT.begin();
  }
  MiddleOutOrder(const MiddleOutOrder &other)
      : SORT(other.SORT), IT(SORT.begin() + (other.IT - other.SORT.begin())) {}

  bool hasNext() const { return IT != SORT.end(); }
  const K &next() { return *(IT++); }
  void reset() {
    buildOrder();
    IT = SORT.begin();
  }
  typename vector<K>::const_iterator begin() { return SORT.begin(); }
  typename vector<K>::const_iterator end() { return SORT.end(); }
};
template <typename K> class MyContainer {
  friend class AscendingOrder<K>;
  friend class DescendingOrder<K>;
  friend class SideCrossOrder<K>;
  friend class ReverseOrder<K>;
  friend class Order<K>;
  friend class MiddleOutOrder<K>;

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
    typename vector<K>::const_iterator it = find(ARR.begin(), ARR.end(), item);
    if (ARR.size() == 0 || it == ARR.end())
      throw invalid_argument("Nothing to remove.");
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
#endif // MYCONTAINER_HPP
