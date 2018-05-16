#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string filename {"american_english_dictionary"};
  ifstream file(filename);
  string word;

  // Invariant: Processed all words read from file so far
  while (getline(file, word)) {
    string reversed_word (word.rbegin(), word.rend());

    if (word == reversed_word)
      cout << word << endl;
  }

  return 0;
}
