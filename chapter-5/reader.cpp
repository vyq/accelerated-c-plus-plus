#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

int main() {
  ifstream file("grades_10.csv");
  string line;

  while (getline(file, line)) {
    vector<string> v {Split(line, ',')};
    string name {v[0]};
    double midterm {stod(v[1])};
    double final {stod(v[2])};
    vector<double> homework;

    // Invariant: Stored all homework read so far
    for (vector<string>::const_iterator i = v.begin() + 3; i != v.end(); ++i)
      homework.push_back(stod(*i));

    cout <<
      name <<
      " " <<
      midterm <<
      " " <<
      final;

    // Invariant: Wrote all homework read so far
    for (auto& i: homework)
      cout << " " << i;

    cout << endl;
  }

  return 0;
}
