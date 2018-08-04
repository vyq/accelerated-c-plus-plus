#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rules;
typedef map<string, Rules> Grammar;

int Randomize(int number) {
  random_device device;

  if (number <= 0 || number > device.max())
    throw out_of_range("Number is out of range");

  const int bucket_size {device.max() / number};
  int result;

  do result = device() / bucket_size;
  while (result >= number);
  
  return result;
}

Grammar ReadGrammar(ifstream& fs) {
  Grammar result;
  string line;

  // Invariant: Processed all lines read so far
  while (getline(fs, line)) {
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
  list<string>& result
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

list<string> MakeSentence(const Grammar& grammar) {
  list<string> result;

  Expand(grammar, "<sentence>", result);

  return result;
}

bool HasTag(const vector<string>& sentence) {
  for (
    vector<string>::const_iterator iterator = sentence.begin();
    iterator != sentence.end();
    ++iterator
  ) {
    if (IsTag(*iterator))
      return true;
  }

  return false;
}

vector<string> MakeSentenceNonRecursive(const Grammar& grammar) {
  vector<string> sentence;
  Rules rules {Rule{"<sentence>"}};

  while (!rules.empty()) {
    Rule rule = rules.back();
    rules.pop_back();

    if (HasTag(rule)) {
      for (auto& word : rule) {
        if (IsTag(word)) {
          Grammar::const_iterator iterator {grammar.find(word)};

          if (iterator == grammar.end())
            throw domain_error("Invalid rule");

          const Rules& matching_rules {iterator->second};
          const Rule& matching_rule {
            matching_rules[Randomize(matching_rules.size())]
          };
          rules.push_back(matching_rule);
        } else {
          rules.push_back(Rule{word});
        }
      }
    } else {
      for (
        Rule::const_reverse_iterator iterator = rule.rbegin();
        iterator != rule.rend();
        ++iterator
      ) {
        sentence.push_back(*iterator);
      }
    }
  }

  return sentence;
}

int main() {
  try {
    string filename {"sentence_input.txt"};
    ifstream file {filename};
    srand(time(nullptr));

    list<string> sentence {MakeSentence(ReadGrammar(file))};
    
    file.clear();
    file.seekg(0, file.beg);

    vector<string> sentence_non_recursive {
      MakeSentenceNonRecursive(ReadGrammar(file))
    };

    list<string>::const_iterator iterator {sentence.begin()};
  
    if (!sentence.empty()) {
      cout << "Recursive: " << *iterator;
      ++iterator;
    }
  
    while (iterator != sentence.end()) {
      cout << " " << *iterator;
      ++iterator;
    }
  
    cout << endl;
    cout << "Non-recursive: ";

    for (
      vector<string>::const_reverse_iterator iterator = 
        sentence_non_recursive.rbegin();
      iterator != sentence_non_recursive.rend();
      ++iterator
    ) {
      cout << *iterator << " ";
    }
    cout << endl;
  } catch (domain_error error) {
    cout << error.what() << endl;

    return 1;
  }

  return 0;
}
