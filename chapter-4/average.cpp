#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<double> numbers {1, 2, 3, 4, 5, 6, 7, 8};
  double sum {0};

  for (auto& n: numbers)
    sum += n;

  cout << sum / numbers.size() << endl;

  return 0;
}
