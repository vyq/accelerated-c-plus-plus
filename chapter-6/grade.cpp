#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "student.h"

using namespace std;

double ComputeGrade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double ComputeGrade(
  double midterm,
  double final,
  const vector<double>& homework
) {
  if (homework.size() == 0)
    throw length_error("Homework grades not found.");

  return ComputeGrade(midterm, final, ComputeMedian(homework));
}

bool IsFailGrade(const Student& s) {
  return s.final_grade < 60;
}
