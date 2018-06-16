#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

bool IsNotWhitespace(char c) {
  return !isspace(c);
}

bool IsWhitespace(char c) {
  return isspace(c);
}

vector<string> Split(const string& s) {
  vector<string> items;
  typedef string::const_iterator iterator;

  iterator i = s.begin();

  // Invariant: Processed i characters in s so far
  while (i != s.end()) {
    i = find_if(i, s.end(), IsNotWhitespace);

    iterator j = find_if(i, s.end(), IsWhitespace);

    if (i != s.end())
      items.push_back(string(i, j));

    i = j;
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
