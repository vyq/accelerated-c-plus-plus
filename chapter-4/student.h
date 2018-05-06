#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <string>
#include <vector>

struct Student {
  std::string name;
  double midterm, final;
  std::vector<double> homework;
};

bool Compare(const Student&, const Student&);
std::istream& Read(std::istream&, Student&);
std::istream& ReadHomework(std::istream&, std::vector<double>&);

#endif