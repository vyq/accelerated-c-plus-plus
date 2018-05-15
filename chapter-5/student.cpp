#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "split.h"
#include "student.h"

using namespace std;

bool Compare(const Student& x, const Student& y) {
  return x.name < y.name;
}

container_type GetFailStudents(container_type& s) {
  container_type fail;
  container_type::iterator iterator = s.begin();

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

ifstream& Read(ifstream& fs, container_type& s, string::size_type& l) {
  Student student;
  string line;

  while(getline(fs, line)) {
    vector<string> v {Split(line, ',')};

    student.name = v[0];
    double midterm {stod(v[1])};
    double final {stod(v[2])};

    if (midterm < 0 || midterm > 100 || final < 0 || final > 100)
      throw domain_error("Invalid midterm or final exam grades.");

    vector<double> homework;

    // Invariant: Stored all homework read so far                       
    for (
      vector<string>::const_iterator i = v.begin() + 3;
      i != v.end();
      ++i
    )
      homework.push_back(stod(*i));                                     
  
    student.final_grade = ComputeGrade(midterm, final, homework);

    s.push_back(student);

    l = max(l, student.name.size());
  }

  return fs;
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

list<Student>& SortStudents(list<Student>& s) {
  s.sort(Compare);

  return s;
}

vector<Student>& SortStudents(vector<Student>& s) {
  sort(s.begin(), s.end(), Compare);

  return s;
}
