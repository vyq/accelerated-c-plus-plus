#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <list>
#include <string>
#include <vector>

struct Student {
  std::string name;
  double final_grade;
};

bool Compare(const Student&, const Student&);
std::list<Student> GetFailStudents(std::list<Student>&);
std::istream& Read(std::istream&, Student&);
std::istream& ReadHomework(std::istream&, std::vector<double>&);

#endif
