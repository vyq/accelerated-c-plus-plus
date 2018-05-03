#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "Name: ";
  string name;
  cin >> name;

  cout << "Space between greeting and left and right border: ";
  int padLeftRight;
  cin >> padLeftRight;

  cout << "Space between greeting and top and bottom border: ";
  int padTopBottom;
  cin >> padTopBottom;

  const string kGreeting {"Hello " + name + "!"};
  const int rows {padTopBottom * 2 + 3};
  const string::size_type columns {
    kGreeting.size() +
    padLeftRight * 2 +
    2
  };

  cout << endl;

  // Invariant: Wrote r rows so far
  for (int r = 0; r != rows; ++r) {
    string::size_type c = 0;

    if (r == padTopBottom + 1) {
      const string padding(padLeftRight, ' ');
      cout << "*" << padding << kGreeting << padding << "*";
    } else if (r == 0 || r == rows - 1) {
      const string border(columns, '*');
      cout << border;
    } else {
      const string padding(columns - 2, ' ');
      cout << "*" << padding << "*";
    }

    cout << endl;
  }

  return 0;
}
