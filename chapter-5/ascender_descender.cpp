#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<char> ascenders {'b', 'd', 'f', 'h', 'k', 'l', 't'};
  vector<char> descenders {'g', 'j', 'p', 'q', 'y'};
  bool has_ascender {false};
  bool has_descender {false};

  cout << "Input word: ";
  string word;
  cin >> word;

  for (auto& c: word) {
    if (find(ascenders.begin(), ascenders.end(), c) != ascenders.end())
      has_ascender = true;
    if (
      find(descenders.begin(), descenders.end(), c) !=
      descenders.end()
    )
      has_descender = true;
  }

  if (has_ascender)
    cout << "Word has ascender" << endl;

  if (has_descender)
    cout << "Word has descender" << endl;

  return 0;
}
