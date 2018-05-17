#include <string>
#include <vector>
#include "length.h"

using namespace std;

string::size_type GetLongestLength(const vector<string>& v) {
  string::size_type length = 0;

  // Invariant: Processed i strings so far
  for (vector<string>::size_type i = 0; i != v.size(); ++i)
    length = max(length, v[i].size());

  return length;
}
