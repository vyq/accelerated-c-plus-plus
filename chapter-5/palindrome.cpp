#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string filename {"american_english_dictionary"};
  ifstream file(filename);
  string word;
  string longest_palindrome;
  string::size_type size {0};

  // Invariant: Processed all words read from file so far
  while (getline(file, word)) {
    string reversed_word (word.rbegin(), word.rend());

    if (word == reversed_word) {
      cout << word << endl;

      if (word.size() > size) {
        longest_palindrome = word;
        size = word.size();
      }
    }
  }

  cout << endl << "Longest palindrome: " << longest_palindrome << endl;

  return 0;
}
