#include <cctype>
#include <string>
#include <vector>
#include "split.h"

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
    while (j != s.size() && !isspace(s[j]))
      ++j;

    if (i != j) {
      items.push_back(s.substr(i, j - i));
      i = j;
    }
  }

  return items;
}

vector<string> Split(const string& s, const char c) {
  vector<string> items;
  typedef string::size_type string_size;
  string_size i {0};

  // Invariant: Processed i characters so far
  while (i != s.size()) {
    // Invariant: Characters in [original i, current i) are all commas
    while (i != s.size() && s[i] == c)
      ++i;

    string_size j {i};

    // Invariant: No comma characters in [original j, current j)
    while (j != s.size() && s[j] != c)
      ++j;

    if (i != j) {
      items.push_back(s.substr(i, j - i));
      i = j;
    }
  }

  return items;
}
