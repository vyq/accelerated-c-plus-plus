#include <iostream>

using namespace std;

int main() {
  const int maximum {10};
  const int minimum {-6};

  // Invariant: Wrote i numbers so far
  for (int i = 0; i != (maximum - minimum); ++i) {
    cout << maximum - i << endl;
  }

  return 0;
}
