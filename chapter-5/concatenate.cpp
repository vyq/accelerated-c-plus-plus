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
  items.insert(items.end(), bottom.begin(), bottom.end());

  return items;
}

vector<string> ConcatenateHorizontally(
  const vector<string>& left,
  const vector<string>& right
) {
  vector<string> items;

  string::size_type space {GetLongestLength(left) + 1};

  vector<string>::size_type i {0}, j {0};

  // Invariant: Have not seen all rows in left and right
  while (i != left.size() || j != right.size()) {
    string s;

    if (i != left.size())
      s = left[i++];

    s += string(space - s.size(), ' ');

    if (j != right.size())
      s += right[j++];

    items.push_back(s);
  }

  return items;
}
