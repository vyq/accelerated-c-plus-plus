#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool HasAscender(string& w) {
  bool has_ascender {false};
  vector<char> ascenders {'b', 'd', 'f', 'h', 'k', 'l', 't'};

  for (auto& c: w) {
    if (find(ascenders.begin(), ascenders.end(), c) != ascenders.end())
      has_ascender = true;
  }

  return has_ascender;
}

bool HasDescender(string& w) {
  bool has_descender {false};
  vector<char> descenders {'g', 'j', 'p', 'q', 'y'};

  for (auto& c: w) {
    if (
      find(descenders.begin(), descenders.end(), c) !=
      descenders.end()
    )
      has_descender = true;
  }

  return has_descender;
}

int main() {
  bool has_ascender {false};
  bool has_descender {false};

  cout << "Input word: ";
  string word;
  cin >> word;

  has_ascender = HasAscender(word);
  has_descender = HasDescender(word);

  if (has_ascender)
    cout << "Word has ascender" << endl;

  if (has_descender)
    cout << "Word has descender" << endl;

  if (!has_ascender && !has_descender)
    cout << "Word has no ascender and descender" << endl;

  string::size_type size {0};
  string longest_word;
  string filename {"american_english_dictionary"};

  ifstream file(filename);

  // Invariant: Processed all words from file so far
  while (getline(file, word)) {
    has_ascender = HasAscender(word);
    has_descender = HasDescender(word);

    if (!has_ascender && !has_descender && word.size() > size) {
      longest_word = word;
      size = word.size();
    }
  }

  cout <<
    "Longest word with no ascenders or descenders: " <<
    longest_word <<
    endl;

  return 0;
}
