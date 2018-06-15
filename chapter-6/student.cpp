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
  container_type::iterator iterator {
    stable_partition(s.begin(), s.end(), IsPassGrade)
  };
  container_type fail(iterator, s.end());
  s.erase(iterator, s.end());

  return fail;
}

container_type GetFinalGreaterThanMidtermStudents(container_type s) {
  container_type::iterator iterator {
    stable_partition(s.begin(), s.end(), IsFinalGreaterThanMidterm)
  };
  container_type greater_than(iterator, s.end());
  s.erase(iterator, s.end());

  return s;
}

container_type GetFinalNotGreaterThanMidtermStudents(
  container_type s
) {
  container_type::iterator iterator {
    stable_partition(s.begin(), s.end(), IsFinalNotGreaterThanMidterm)
  };
  container_type not_greater_than(iterator, s.end());
  s.erase(iterator, s.end());

  return s;
}

bool IsHomeworkDone(const Student& s) {
  return (
    find(s.homework.begin(), s.homework.end(), 0) ==
    s.homework.end()
  );
}

istream& Read(istream& is, Student& s) {
  cout << "Student name: ";
  is >> s.name;

  cout << "Midterm and final exam grades: ";
  is >> s.midterm >> s.final;

  if (s.midterm < 0 || s.midterm > 100 || s.final < 0 || s.final > 100)
    throw domain_error("Invalid midterm or final exam grades.");

  ReadHomework(is, s.homework);
  
  s.final_grade = ComputeGrade(s.midterm, s.final, s.homework);

  return is;
}

ifstream& Read(
  ifstream& fs,
  container_type& s,
  string::size_type& l,
  vector<Student>& done,
  vector<Student>& not_done
) {
  Student student;
  string line;

  while(getline(fs, line)) {
    vector<string> v {Split(line, ',')};
    student.name = v[0];
    student.midterm = stod(v[1]);
    student.final = stod(v[2]);

    if (
      student.midterm < 0 ||
      student.midterm > 100 ||
      student.final < 0 ||
      student.final > 100
    )
      throw domain_error("Invalid midterm or final exam grades.");

    // Invariant: Stored all homework read so far                       
    for (
      vector<string>::const_iterator i = v.begin() + 3;
      i != v.end();
      ++i
    )
      student.homework.push_back(stod(*i));
  
    student.final_grade = ComputeGrade(
      student.midterm,
      student.final,
      student.homework
    );

    s.push_back(student);

    l = max(l, student.name.size());

    if (IsHomeworkDone(student))
      done.push_back(student);
    else
      not_done.push_back(student);
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
