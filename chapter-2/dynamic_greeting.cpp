#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "Name: ";
  string name;
  cin >> name;

  const string kGreeting {"Hello " + name + "!"};
  const int pad {1};
  const int rows {pad * 2 + 3};
  const string::size_type columns {kGreeting.size() + 2};

  cout << endl;

  // Invariant: Wrote r rows so far
  for (int r = 0; r != rows; ++r) {
    string::size_type c = 0;

    // Invariant: Wrote c characters so far in current row
    while (c != columns) {
      if (r == pad + 1 && c == pad) {
        cout << kGreeting;
        c += kGreeting.size();
      } else {
        if (r == 0 || r == rows - 1 || c == 0 || c == columns - 1)
          cout << "*";
        else
          cout << " ";
        ++c;
      }
    }

    cout << endl;
  }

  return 0;
}
