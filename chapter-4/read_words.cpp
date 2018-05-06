#include <iostream>
#include <string>
#include <vector>
#include "read_words.h"

using namespace std;

istream& ReadWords(istream& is, vector<string>& v) {
  cout << "Input words: ";

  if (is) {
    v.clear();
    string x;

    while (is >> x)
      v.push_back(x);

    is.clear();
  }

  return is;
}
