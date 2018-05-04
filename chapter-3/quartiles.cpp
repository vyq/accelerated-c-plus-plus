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

  cout << "Second quartile: " << ComputeMedian(v) << endl;

  return 0;
}
