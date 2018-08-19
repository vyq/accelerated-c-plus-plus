#include <algorithm>
#include <stdexcept>
#include <vector>

template<class T>
T ComputeMedian(std::vector<T> v) {
  typedef typename std::vector<T>::size_type size_type;

  size_type size {v.size()};

  if (size == 0)
    throw std::length_error("Cannot compute median of empty vector");

  sort(v.begin(), v.end());

  size_type mid {size / 2};

  return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

