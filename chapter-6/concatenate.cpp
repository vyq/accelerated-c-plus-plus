#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include "concatenate.h"
#include "length.h"

using namespace std;

vector<string> ConcatenateVertically(
  const vector<string>& top,
  const vector<string>& bottom
) {
  vector<string> items = top;
  copy(bottom.begin(), bottom.end(), back_inserter(items));

  return items;
}

vector<string> ConcatenateHorizontally(
  const vector<string>& left,
  const vector<string>& right
) {
  vector<string> items;
  vector<string>::const_iterator left_iterator {left.begin()};
  vector<string>::const_iterator right_iterator {right.begin()};

  string::size_type space {GetLongestLength(left) + 1};

  vector<string>::size_type i {0}, j {0};

  // Invariant: Have not processed all rows in left or right
  while (left_iterator != left.end() || right_iterator != right.end()) {
    string s;

    if (left_iterator != left.end()) {
      s += *left_iterator;
      ++left_iterator;
    }

    s += string(space - s.size(), ' ');

    if (right_iterator != right.end()) {
      s += *right_iterator;
      ++right_iterator;
    }

    items.push_back(s);
  }

  return items;
}
