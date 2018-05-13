#ifndef STUDENT
#define STUDENT

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

struct Student {
  std::string name;
  double final_grade;
};

// typedef std::vector<Student> container_type;
typedef std::list<Student> container_type;

bool Compare(const Student&, const Student&);
container_type GetFailStudents(container_type&);
std::istream& Read(std::istream&, Student&);
std::ifstream& Read(
  std::ifstream&,
  container_type&,
  std::string::size_type&
);
std::istream& ReadHomework(std::istream&, std::vector<double>&);

#endif
