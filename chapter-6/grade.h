#ifndef GRADE
#define GRADE

#include <string>
#include <vector>
#include "student.h"

double ComputeAverageGrade(const Student&);
double ComputeAverageGradeWrapper(const Student&);
double ComputeGrade(double, double, double);
double ComputeGrade(double, double, const std::vector<double>&);
double ComputeGrade(const Student&);
double ComputeGrade(std::string, const std::vector<Student>&);
double ComputeGradeWrapper(const Student&);
double ComputeOptimisticMedianGrade(const Student&);
double ComputeOptimisticMedianGradeWrapper(const Student&);
bool IsFailGrade(const Student&);
bool IsPassGrade(const Student&);

#endif
