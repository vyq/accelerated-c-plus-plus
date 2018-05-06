#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int upperBound {101};

  cout << "Number" << " | " << "Square" << endl;

  // Invariant: Computed i squares so far
  for (int i = 0; i != upperBound; ++i)
    cout << setw(6) << i << " | " << i * i << endl;

  return 0;
}
