#include <stdexcept>
#include "grade.h"
#include "student.h"

using namespace std;

bool Compare(const Student& x, const Student& y) {
  return x.name < y.name;
}

list<Student> GetFailStudents(list<Student>& s) {
  list<Student> fail;
  list<Student>::iterator iterator = s.begin();

  // Invariant: Processed iterator students so far
  while (iterator != s.end()) {
    if (IsFailGrade(*iterator)) {
      fail.push_back(*iterator);
      iterator = s.erase(iterator);
    } else
      ++iterator;
  }

  return fail;
}

istream& Read(istream& is, Student& s) {
  cout << "Student name: ";
  is >> s.name;

  cout << "Midterm and final exam grades: ";
  double midterm, final;
  is >> midterm >> final;

  if (midterm < 0 || midterm > 100 || final < 0 || final > 100)
    throw domain_error("Invalid midterm or final exam grades.");

  vector<double> homework;
  ReadHomework(is, homework);
  
  s.final_grade = ComputeGrade(midterm, final, homework);

  return is;
}

istream& ReadHomework(istream& is, vector<double>& v) {
  cout << "Homework grades: ";

  if (is) {
    v.clear();

    double x;

    // Invariant: v contains all grades read so far
    while (is >> x)
      v.push_back(x);

    is.clear();
  }

  return is;
}
