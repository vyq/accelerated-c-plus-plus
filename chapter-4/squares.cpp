#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int upper_bound {1000};
  string::size_type length {to_string(upper_bound).length()};

  // Invariant: Computed i squares so far
  for (int i = 0; i != upper_bound; ++i)
    cout << setw(length) << i << " | " << i * i << endl;

  return 0;
}
