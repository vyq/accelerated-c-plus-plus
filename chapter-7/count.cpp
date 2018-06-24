#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  map<string, int> counters;
  map<int, vector<string>> groups;

  // Invariant: Counted all inputs read from cin so far
  while (cin >> s)
    ++counters[s];

  cout << endl << "Word\tCount" << endl;

  // Invariant: Wrote all inputs and their associated counts so far
  for (
    map<string, int>::const_iterator iterator = counters.begin();
    iterator != counters.end();
    ++iterator
  ) {
    cout << iterator->first << "\t" << iterator->second << endl;

    groups[iterator->second].push_back(iterator->first);
  }

  cout << endl << "Count\tWord(s)" << endl;

  // Invariant: Wrote all inputs grouped by counts so far
  for (
    map<int, vector<string>>::const_iterator iterator = groups.begin();
    iterator != groups.end();
    ++iterator
  ) {
    cout << iterator->first << "\t";

    for (auto& element : iterator->second)
      cout << element << " ";

    cout << endl;
  }

  return 0;
}
