#include <iostream>
#include <string>
#include <vector>
#include "concatenate.h"
#include "length.h"
#include "split.h"

using namespace std;

void SetPaddingTopBottom(vector<string>& v, int s, string p) {
  // Invariant: Wrote i rows so far
  for (int i = 0; i != s; ++i)
    v.push_back("*" + p + "*");
}

vector<string> DrawGreeting(
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
      "*"
    );
  }

  SetPaddingTopBottom(items, space_top_bottom, padding_top_bottom);
  items.push_back(border);

  return items;
}

vector<string> DrawCenteredGreeting(
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
    string::size_type difference {length - v[i].size()};
    double padding_left {static_cast<double>(difference) / 2};
    double padding_right {
      difference % 2 == 0 ?
      static_cast<double>(difference) / 2 :
      static_cast<double>(difference) / 2 + 1
    };

    items.push_back(
      "*" +
      padding_side +
      string(padding_left, ' ') +
      v[i] +
      string(padding_right, ' ') +
      padding_side +
      "*"
    );
  }

  SetPaddingTopBottom(items, space_top_bottom, padding_top_bottom);
  items.push_back(border);

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

  const vector<string> kGreeting {Split(s)};
  vector<string> items {DrawGreeting(
    kGreeting,
    space_left_right,
    space_top_bottom
  )};

  for (auto& item: items)
    cout << item << endl;

  items = DrawCenteredGreeting(
    kGreeting,
    space_left_right,
    space_top_bottom
  );

  for (auto& item: items)
    cout << item << endl;

  cout << endl;

  items = ConcatenateVertically(
    kGreeting,
    DrawGreeting(kGreeting, space_left_right, space_top_bottom)
  );
  
  for (auto& item: items)
    cout << item << endl;

  cout << endl;
  
  items = ConcatenateHorizontally(
    kGreeting,
    DrawGreeting(kGreeting, space_left_right, space_top_bottom)
  );
  
  for (auto& item: items)
    cout << item << endl;

  return 0;
}
