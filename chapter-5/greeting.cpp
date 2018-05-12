#include <iostream>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

string::size_type GetLongestLength(const vector<string>& v) {
  string::size_type length = 0;

  // Invariant: Processed i strings so far
  for (vector<string>::size_type i = 0; i != v.size(); ++i)
    length = max(length, v[i].size());

  return length;
}

vector<string> DrawGreeting(const vector<string>& v) {
  vector<string> items;
  string::size_type length = GetLongestLength(v);
  string border(length + 4, '*');

  items.push_back(border);

  // Invariant: Processed i words in v so far
  for (vector<string>::size_type i = 0; i != v.size(); ++i) {
    items.push_back(
      "* " +
      v[i] +
      string(length - v[i].size(), ' ') +
      " *");
  }

  items.push_back(border);

  return items;
}

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

int main() {
  cout << "Input greeting: ";
  string s;
  getline(cin, s);

  cout << "Space between greeting and left and right border: ";
  int padLeftRight;
  cin >> padLeftRight;

  cout << "Space between greeting and top and bottom border: ";
  int padTopBottom;
  cin >> padTopBottom;

  const vector<string> kGreeting {Split(s)};
  const int rows {padTopBottom * 2 + 2 + kGreeting.size()};
  const string::size_type columns {
    GetLongestLength(kGreeting) +
    padLeftRight * 2 +
    2
  };

  cout << endl;

  const string border(columns, '*');
  const string padding(columns - 2, ' ');
  const string padding_side(padLeftRight, ' ');
  cout << border << endl;

  // Invariant: Wrote i rows so far
  for (int i = 0; i != padTopBottom; ++i)
    cout << "*" << padding << "*" << endl;

  for (
    vector<string>::const_iterator i = kGreeting.begin();
    i != kGreeting.end();
    ++i
  )
    cout << "*" << padding_side << *i << padding_side << "*" << endl;

  // Invariant: Wrote i rows so far
  for (int i = 0; i != padTopBottom; ++i)
    cout << "*" << padding << "*" << endl;

  cout << border << endl;

  return 0;
}
