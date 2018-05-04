#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  cout << "Input words: ";
  vector<string> v;
  string x;

  // Invariant: v has all words read so far
  while (cin >> x) {
    v.push_back(x);
  }

  map<string, int> words;

  // Invariant: Counted all words read from v so far
  for (auto word: v) {
    words[word] += 1;
  }

  // Invariant: Printed all key-value pairs read from words so far
  for (auto word: words) {
    cout << word.first << ": " << word.second << endl;
  }

  return 0;
}
