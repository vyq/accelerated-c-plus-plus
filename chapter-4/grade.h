#ifndef GRADE
#define GRADE

#include <vector>
#include "student.h"

double ComputeGrade(const Student&);
double ComputeGrade(double, double, double);
double ComputeGrade(double, double, const std::vector<double>&);

#endif
