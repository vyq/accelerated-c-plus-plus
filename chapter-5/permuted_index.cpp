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

  // Invariant: Stored all segments read so far
  while (getline(input, s, '\n')) {
    vector<string> v {Split(s)};
    vector<string>::size_type r = 0;

    // Invariant: Made r rotations so far
    while (r != v.size()) {
      if (r == 0) {
        items[s] = " ";
        cout << s << ": " << " " << endl;
      } else {
        vector<string> key(v.begin(), v.begin() + r);
        vector<string> value(v.begin() + r, v.end());
        string k, v;

        for (auto& i: key)
          k += i + " ";

        for (auto& i: value)
          v += i + " ";

        cout << k << ": " << v << endl;
      }

      ++r;
    }
  }

  return 0;
}
