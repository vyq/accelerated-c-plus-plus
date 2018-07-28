#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include "link.h"

using namespace std;

vector<string> FindLinks(const string& s) {
  vector<string> items;
  typedef string::const_iterator iterator;
  iterator b {s.begin()}, e {s.end()};

  // Invariant: Processed all patterns read from s so far
  while (b != e) {
    b = FindProtocol(b, e);

    if (b != e) {
      iterator after {FindResource(b, e)};

      items.push_back(string(b, after));

      b = after;
    }
  }

  return items;
}

string::const_iterator FindProtocol(
  string::const_iterator b,
  string::const_iterator e
) {
  static const string separator {"://"};
  typedef string::const_iterator iterator;

  iterator separator_start = b;

  // Invariant: Processed all characters read so far
  while (
    (separator_start = search(
      separator_start,
      e,
      separator.begin(),
      separator.end())
    ) != e
  ) {
    if (
      separator_start != b &&
      separator_start + separator.size() != e
    ) {
      iterator protocol_start = separator_start;

      // Invariant: Processed all characters read so far
      while (protocol_start != b && isalpha(protocol_start[-1]))
        --protocol_start;

      if (
        protocol_start != separator_start &&
        !IsNotLinkCharacter(separator_start[separator.size()])
      )
        return protocol_start;
    }

    separator_start += separator.size();
  }

  return e;
}

string::const_iterator FindResource(
  string::const_iterator b,
  string::const_iterator e
) {
  return find_if(b, e, IsNotLinkCharacter);
}

bool IsNotLinkCharacter(char c) {
  static const string kSpecialCharacters {"~;/?:@=&$-_.+!*'(),"};

  return !(
    isalnum(c) ||
    find(
      kSpecialCharacters.begin(),
      kSpecialCharacters.end(),
      c
    ) != kSpecialCharacters.end()
  );
}

