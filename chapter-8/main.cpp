#include <iostream>
#include <vector>
#include "median.cpp"

using namespace std;

int main() {
  vector<double> v1 {1, 2};
  vector<int> v2 {1, 2};

  cout << ComputeMedian(v1) << endl;
  cout << ComputeMedian(v2) << endl;
}
