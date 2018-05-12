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
    vector<string> v {Split(s)};
    vector<string>::size_type r = 0;
    length = max(length, s.size());

    // Invariant: Made r rotations so far
    while (r != v.size()) {
      if (r == 0) {
        items[s] = " ";
      } else {
        vector<string> key(v.begin() + r, v.end());
        vector<string> value(v.begin(), v.begin() + r);
        string k, v;

        // Invariant: Stored all references read so far
        for (auto& i: key)
          k += i + " ";

        // Invariant: Stored all references read so far
        for (auto& i: value)
          v += i + " ";

        items[k] = v;
      }

      ++r;
    }
  }

  // Invariant: Wrote all references read so far
  for (auto& item: items)
    cout << setw(length) << item.second << "|" << item.first << endl;

  return 0;
}
