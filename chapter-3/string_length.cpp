#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout << "Input words: ";
  string x;
  vector<string> words;

  while (cin >> x) {
    words.push_back(x);
  }

  string longest_word, shortest_word;
  typedef string::size_type string_size;
  string_size longest_size {0};
  string_size shortest_size {x.max_size()};

  // Invariant: Set the longest and shortest string from words so far
  for (auto word: words) {
    if (word.size() > longest_size) {
      longest_word = word;
      longest_size = word.size();
    }
    
    if (word.size() < shortest_size) {
      shortest_word = word;
      shortest_size = word.size();
    }
  }

  cout <<
    "Longest word: " <<
    longest_word <<
    " (" <<
    longest_size <<
    " characters)" <<
    endl;
  cout <<
    "Shortest word: " <<
    shortest_word <<
    " (" <<
    shortest_size <<
    " characters)" <<
    endl;

  return 0;
}
