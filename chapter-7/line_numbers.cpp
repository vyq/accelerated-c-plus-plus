#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

int CountDigits(int number) {
  int count {0};

  while (number > 0) {
    number /= 10;
    ++count;
  }

  return count;
}

map<string, vector<int>> GetLineNumbers(
  istream& in,
  vector<string> FindWords(const string&) = Split 
) {
  string line;
  int line_number {0};
  map<string, vector<int>> line_numbers;

  // Invariant: Processed all lines read so far
  do {
    getline(in, line);
    ++line_number;

    vector<string> words {FindWords(line)};

    // Invariant: Saved line_number for all words processed so far
    for (
      vector<string>::const_iterator iterator {words.begin()};
      iterator != words.end();
      ++iterator
    )
      line_numbers[*iterator].push_back(line_number);
  } while (!in.eof());

  return line_numbers;
}

int main() {
  map<string, vector<int>> line_numbers {GetLineNumbers(cin)};
  const int kOutputColumns {72};
  const string kPrefix {" occurs on line(s): "};
  const string kSeparator {", "};

  // Invariant: Wrote all words processed so far
  for (
    map<string, vector<int>>::const_iterator iterator {
      line_numbers.begin()
    };
    iterator != line_numbers.end();
    ++iterator
  ) {
    int output_length {0};

    cout << iterator->first << kPrefix;
    output_length += iterator->first.length() + kPrefix.length();

    vector<int> distinct_lines {iterator->second};
    sort(distinct_lines.begin(), distinct_lines.end());
    distinct_lines.erase(
      unique(distinct_lines.begin(), distinct_lines.end()),
      distinct_lines.end()
    );

    vector<int>::const_iterator line_iterator {
      distinct_lines.begin()
    };

    if (output_length >= kOutputColumns) {
      cout << endl;
      output_length = 0;
    }

    cout << *line_iterator;
    output_length += CountDigits(*line_iterator);
    ++line_iterator;

    // Invariant: Wrote all line numbers processed so far
    while (line_iterator != distinct_lines.end()) {
      if (output_length >= kOutputColumns) {
        cout << endl;
        output_length = 0;
      }

      cout << kSeparator << *line_iterator;
      output_length +=
        kSeparator.length() +
        CountDigits(*line_iterator);
      ++line_iterator;
    }

    cout << endl;
  }

  return 0;
}
