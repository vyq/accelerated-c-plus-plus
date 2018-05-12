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
      }

      ++r;
    }
  }

  return 0;
}
