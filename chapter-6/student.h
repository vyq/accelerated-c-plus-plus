#ifndef STUDENT
#define STUDENT

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

struct Student {
  std::string name;
  std::vector<double> homework;
  double midterm, final, final_grade;
};

//typedef std::vector<Student> container_type;
typedef std::list<Student> container_type;

bool Compare(const Student&, const Student&);
container_type GetFailStudents(container_type&);
bool IsHomeworkDone(const Student&);
std::istream& Read(std::istream&, Student&);
std::ifstream& Read(
  std::ifstream&,
  container_type&,
  std::string::size_type&,
  std::vector<Student>&,
  std::vector<Student>&
);
std::istream& ReadHomework(std::istream&, std::vector<double>&);
std::list<Student>& SortStudents(std::list<Student>&);
std::vector<Student>& SortStudents(std::vector<Student>&);

#endif
