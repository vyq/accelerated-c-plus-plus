#ifndef GRADE
#define GRADE

#include <vector>
#include "student.h"

double ComputeAverageGrade(const Student&);
double ComputeGrade(double, double, double);
double ComputeGrade(double, double, const std::vector<double>&);
double ComputeGrade(const Student&);
double ComputeAverageGradeWrapper(const Student&);
double ComputeGradeWrapper(const Student&);
bool IsFailGrade(const Student&);

#endif
