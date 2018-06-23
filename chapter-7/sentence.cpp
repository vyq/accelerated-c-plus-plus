#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rules;
typedef map<string, Rules> Grammar;

int Randomize(int maximum) {
  return maximum;
}

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

bool IsTag(const string& s) {
  return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void Expand(
  const Grammar& grammar,
  const string& word,
  vector<string>& result
) {
  if (!IsTag(word)) {
    result.push_back(word);
  } else {
    Grammar::const_iterator iterator {grammar.find(word)};

    if (iterator == grammar.end())
      throw domain_error("Invalid rule");

    const Rules& rules {iterator->second};
    const Rule& rule {rules[Randomize(rules.size())]};

    for (
      Rule::const_iterator iterator = rule.begin();
      iterator != rule.end();
      ++iterator
    ) {
      Expand(grammar, *iterator, result);
    }
  }
}

vector<string> MakeSentence(const Grammar& g) {
  vector<string> result;

  Expand(g, "<sentence>", result);

  return result;
}

int main() {


  return 0;
}
