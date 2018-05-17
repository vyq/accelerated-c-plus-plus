#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include "split.h"

using namespace std;

int main() {
  stringstream input("The quick brown fox\njumped over the fence");
  string s;
  map<string, string> items;
  string::size_type length = 0;

  // Invariant: Stored all segments read so far
  while (getline(input, s, '\n')) {
    vector<string> row {Split(s)};
    vector<string>::size_type r = 0;
    length = max(length, s.size());

    // Invariant: Made r rotations so far
    while (r != row.size()) {
      vector<string> key(row.begin() + r, row.end());
      vector<string> value(row.begin(), row.begin() + r);
      string k, v;

      // Invariant: Processed i words so far
      for (vector<string>::size_type i = 0; i != key.size(); ++i) {
        k += key[i];

        if (i + 1 != key.size())
          k += " ";
      }

      // Invariant: Processed i words so far
      for (vector<string>::size_type i = 0; i != value.size(); ++i) {
        v += value[i];

        if (i + 1 != value.size())
          v += " ";
      }

      items[k] = v;

      ++r;
    }
  }

  // Invariant: Wrote all references read so far
  for (auto& item: items)
    cout << setw(length) << item.second << " | " << item.first << endl;

  return 0;
}
