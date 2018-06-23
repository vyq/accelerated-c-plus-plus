#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rules;
typedef map<string, Rules> Grammar;

Grammar ReadGrammar(istream& in) {
  Grammar result;
  string line;

  // Invariant: Processed all lines read so far
  while (getline(in, line)) {
    vector<string> items {Split(line)};

    if (!items.empty())
      result[items[0]].push_back(Rule(items.begin() + 1, items.end()));
  }

  return result;
}

int main() {


  return 0;
}
