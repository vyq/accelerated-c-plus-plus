#include <algorithm>
#include <stdexcept>
#include <vector>
#include "median.h"

using namespace std;

double ComputeMedian(vector<double> v) {
  typedef vector<double>::size_type vector_size;
  vector_size size {v.size()};

  if (size == 0)
    throw length_error("Cannot compute median of empty vector.");

  sort(v.begin(), v.end());

  vector_size middle {size / 2};

  return size % 2 == 0 ? (v[middle] + v[middle - 1]) / 2 : v[middle];
}
