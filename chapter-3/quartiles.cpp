#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<double> evenRange {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  typedef vector<double>::size_type vector_size;
  vector_size size {evenRange.size()};
  vector_size middle {size / 2};

  double median {
    size % 2 == 0 ?
    (evenRange[middle] + evenRange[middle - 1]) / 2 :
    evenRange[middle]
  };

  cout << "Second quartile: " << median << endl;

  return 0;
}
