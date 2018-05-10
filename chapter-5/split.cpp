#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> Split(const string& s) {
  vector<string> items;
  typedef string::size_type string_size;
  string_size i {0};

  // Invariant: Processed i characters so far
  while (i != s.size()) {
    // Invariant: Characters in [original i, current i) are all spaces
    while (i != s.size() && isspace(s[i]))
      ++i;

    string_size j {i};

    // Invariant: No whitespace characters in [original j, current j)
    while (j != s.size() && !isspace(s[i]))
      ++j;

    if (i != j) {
      items.push_back(s.substr(i, j - i));
      i = j;
    }
  }

  return items;
}

int main() {
  string s;

  while(getline(cin, s)) {
    vector<string> v = Split(s);

    // Invariant: Printed i items so far
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
      cout << v[i] << endl;
  }

  return 0;
}
