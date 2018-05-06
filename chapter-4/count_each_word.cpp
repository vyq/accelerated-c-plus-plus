#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "read_words.h"

using namespace std;

int main() {
  map<string,int> word_count;
  vector<string> words;

  ReadWords(cin, words);

  for (auto word: words)
    word_count[word] += 1;

  for (auto word: word_count)
    cout << word.first << ": " << word.second << endl;

  return 0;
}
