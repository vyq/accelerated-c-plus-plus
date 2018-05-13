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

typedef std::list<Student> container_type;

bool Compare(const Student&, const Student&);
container_type GetFailStudents(container_type&);
std::istream& Read(std::istream&, Student&);
std::istream& ReadHomework(std::istream&, std::vector<double>&);

#endif
