#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

int main() {
  cout << "Input: ";

  vector<string> input;
  vector<string> lower;
  vector<string> upper;
  string s;

  // Invariant: Saved all words read from cin so far
  while (cin >> s)
    input.push_back(s);

  // Invariant: Processed all words read from input so far
  for (auto& word: input) {
    if (all_of(
      word.begin(),
      word.end(),
      [](char c) {return islower(c);}
    ))
      lower.push_back(word);
    else if (all_of(
      word.begin(),
      word.end(),
      [](char c) {return isupper(c);}
    ))
      upper.push_back(word);
  }

  cout << "Lowercase words:" << endl;

  // Invariant: Wrote all words read from lower so far
  for (auto& word: lower)
    cout << word << endl;

  cout << endl << "Uppercase words:" << endl;

  // Invariant: Wrote all words read from upper so far
  for (auto& word: upper)
    cout << word << endl;

  return 0;
}
