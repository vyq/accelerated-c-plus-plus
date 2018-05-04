#include <iostream>
#include <vector>

using namespace std;

double ComputeMedian(vector<double> v) {
  typedef vector<double>::size_type vector_size;
  vector_size size {v.size()};
  vector_size middle {size / 2};

  return size % 2 == 0 ?
    (v[middle] + v[middle - 1]) / 2 :
    v[middle];
}

int main() {
  vector<double> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const double kMedian {ComputeMedian(v)};
  vector<double> lowerHalf {v.begin(), v.end() - kMedian};
  vector<double> upperHalf {v.begin() + kMedian, v.end()};

  cout << "First quartile: " << ComputeMedian(lowerHalf) << endl;
  cout << "Second quartile: " << kMedian << endl;
  cout << "Third quartile: " << ComputeMedian(upperHalf) << endl;

  return 0;
}
