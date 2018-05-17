#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome(const string& s) {
  return equal(s.begin(), s.end(), s.rbegin());
}

int main() {
  string filename {"american_english_dictionary"};
  ifstream file(filename);
  string word;
  string longest_palindrome;
  string::size_type size {0};

  // Invariant: Processed all words read from file so far
  while (getline(file, word)) {
    if (IsPalindrome(word)) {
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
