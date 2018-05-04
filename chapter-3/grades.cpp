#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cout << "Name: ";
  string name;
  cin >> name;
  cout << "Hello " << name << "!" << endl;

  cout << "Midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "Homework grades: ";
  vector<double> homework;
  double x;

  // Invariant: homework contains all grades read so far
  while (cin >> x) {
    homework.push_back(x);
  }

  typedef vector<double>::size_type vector_size;
  vector_size size = homework.size();

  if (size == 0) {
    cout << "Please input homework grades.";

    return 1;
  }

  sort(homework.begin(), homework.end());

  vector_size middle = size / 2;
  double median;
  median = size % 2 == 0 ?
    (homework[middle] + homework[middle - 1]) / 2 :
    homework[middle];

  streamsize precision = cout.precision();
  cout <<
    "Final grade: " <<
    setprecision(3) <<
    0.2 * midterm + 0.4 * final + 0.4 * median <<
    setprecision(precision) <<
    endl;

  return 0;
}
