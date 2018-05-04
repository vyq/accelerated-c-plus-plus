#include <iostream>

using namespace std;

int main() {
  const int maximum {10};
  const int minimum {1};

  for (int i = minimum; i != maximum; ++i) {
    cout << i * i << endl;
  }

  return 0;
}
