#include "student.h"

using namespace std;

bool Compare(const Student& x, const Student& y) {
  return x.name < y.name;
}

istream& Read(istream& is, Student& s) {
  cout << "Student name: ";
  is >> s.name;

  cout << "Midterm and final exam grades: ";
  is >> s.midterm >> s.final;

  if (s.midterm < 0 || s.midterm > 100 || s.final < 0 || s.final > 100)
    throw domain_error("Invalid midterm or final exam grades.");

  ReadHomework(is, s.homework);

  return is;
}

istream& ReadHomework(istream& is, vector<double>& v) {
  cout << "Homework grades: ";

  if (is) {
    v.clear();

    double x;

    // Invariant: homework contains all grades read so far
    while (is >> x)
      v.push_back(x);

    is.clear();
  }

  return is;
}
