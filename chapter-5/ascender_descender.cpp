#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool HasAscender(string& w) {
  vector<char> ascenders {'b', 'd', 'f', 'h', 'k', 'l', 't'};

  for (auto& c: w) {
    if (find(ascenders.begin(), ascenders.end(), c) != ascenders.end())
      return true;

    return false;
  }
}

bool HasDescender(string& w) {
  vector<char> descenders {'g', 'j', 'p', 'q', 'y'};

  for (auto& c: w) {
    if (
      find(descenders.begin(), descenders.end(), c) !=
      descenders.end()
    )
      return true;

    return false;
  }
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

  return 0;
}
