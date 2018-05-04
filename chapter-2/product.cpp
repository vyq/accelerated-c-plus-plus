#include <iostream>
#include <math.h>

using namespace std;

int main() {
  const int maximum {9};
  const int minimum {1};

  // Invariant: Wrote i products so far
  for (int i = 0; i != maximum; ++i) {
    cout << pow(i + minimum, 2) << endl;
  }

  return 0;
}
