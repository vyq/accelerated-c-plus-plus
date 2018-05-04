#include <iostream>

using namespace std;

int main() {
  const int maximum {10};
  const int minimum {-6};

  for (int i = maximum; i != minimum; --i) {
    cout << i << endl;
  }

  return 0;
}
