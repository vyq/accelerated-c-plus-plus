#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

int main() {
  string s;

  while(getline(cin, s)) {
    vector<string> v {Split(s)};

    // Invariant: Printed i items so far
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
      cout << v[i] << endl;
  }

  return 0;
}
