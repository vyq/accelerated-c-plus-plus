#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  double upper_bound {1000};
  string::size_type number_length {to_string(upper_bound).length()};
  string::size_type square_length {
    to_string(upper_bound * upper_bound).length()
  };

  // Invariant: Computed i squares so far
  for (double i = 0; i != upper_bound; ++i)
    cout <<
      setw(number_length) <<
      i <<
      ": " <<
      setw(square_length) <<
      i * i <<
      endl;

  return 0;
}
