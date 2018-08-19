#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template<class T>
T ComputeMedian(vector<T> v) {
  typedef typename vector<T>::size_type size_type;

  size_type size {v.size()};

  if (size == 0)
    throw domain_error("Cannot compute median of empty vector");

  sort(v.begin(), v.end());

  size_type mid {size / 2};

  return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

