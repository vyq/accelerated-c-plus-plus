#include <iostream>
#include <string>
#include <vector>
#include "read_words.h"

using namespace std;

int main() {
  vector<string> words;

  ReadWords(cin, words);

  cout << "Word count: " << words.size() << endl;

  return 0;
}
