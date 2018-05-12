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

void SetPaddingTopBottom(vector<string>& v, int s, string p) {
  // Invariant: Wrote i rows so far
  for (int i = 0; i != s; ++i)
    v.push_back("*" + p + "*");
}

void DrawGreeting(
  const vector<string>& v,
  int space_left_right,
  int space_top_bottom
) {
  vector<string> items;
  string::size_type length = GetLongestLength(v);
  const string::size_type columns {
    length +
    space_left_right * 2 +
    2
  };
  const string border(columns, '*');
  const string padding_top_bottom(columns - 2, ' ');
  const string padding_side(space_left_right, ' ');

  items.push_back(border);
  SetPaddingTopBottom(items, space_top_bottom, padding_top_bottom);

  // Invariant: Processed i words in v so far
  for (vector<string>::size_type i = 0; i != v.size(); ++i) {
    items.push_back(
      "*" +
      padding_side +
      v[i] +
      string(length - v[i].size(), ' ') +
      padding_side +
      "*");
  }

  SetPaddingTopBottom(items, space_top_bottom, padding_top_bottom);
  items.push_back(border);

  for (auto& item: items)
    cout << item << endl;
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
  int space_left_right;
  cin >> space_left_right;

  cout << "Space between greeting and top and bottom border: ";
  int space_top_bottom;
  cin >> space_top_bottom;
  
  cout << endl;

  DrawGreeting(Split(s), space_left_right, space_top_bottom);
  
  return 0;
}
