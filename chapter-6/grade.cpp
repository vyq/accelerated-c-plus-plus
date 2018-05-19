#include <stdexcept>
#include <vector>
#include "average.h"
#include "grade.h"
#include "median.h"
#include "student.h"

using namespace std;

double ComputeAverageGrade(const Student& s) {
  return ComputeGrade(s.midterm, s.final, ComputeAverage(s.homework));
}

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

double ComputeGrade(const Student& s) {
  return ComputeGrade(s.midterm, s.final, s.homework);
}

double ComputeAverageGradeWrapper(const Student& s) {
  try {
    return ComputeAverageGrade(s);
  } catch (length_error) {
    return ComputeGrade(s.midterm, s.final, 0);
  }
}

double ComputeGradeWrapper(const Student& s) {
  try {
    return ComputeGrade(s);
  } catch (length_error) {
    return ComputeGrade(s.midterm, s.final, 0);
  }
}

bool IsFailGrade(const Student& s) {
  return s.final_grade < 60;
}
