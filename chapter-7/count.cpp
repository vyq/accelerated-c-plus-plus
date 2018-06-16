#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  string s;
  map<string, int> counters;

  // Invariant: Counted all inputs read from cin so far
  while (cin >> s)
    ++counters[s];

  // Invariant: Wrote all inputs and their associated counts so far
  for (
    map<string, int>::const_iterator iterator = counters.begin();
    iterator != counters.end();
    ++iterator
  ) {
    cout << iterator->first << "\t" << iterator->second << endl;
  }

  return 0;
}
