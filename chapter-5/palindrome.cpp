#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string filename {"american_english_dictionary"};
  ifstream file(filename);
  string word;

  while (getline(file, word)) {
    cout << word;
  }

  return 0;
}
