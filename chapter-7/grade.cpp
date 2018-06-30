#include <algorithm>
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

double ComputeAverageGradeWrapper(const Student& s) {
  try {
    return ComputeAverageGrade(s);
  } catch (length_error) {
    return ComputeGrade(s.midterm, s.final, 0);
  }
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

double ComputeGrade(string name, const vector<Student>& s) {
  vector<double> grades;

  if (name == "Median")
    transform(
      s.begin(),
      s.end(),
      back_inserter(grades),
      ComputeGradeWrapper
    );
  else if (name == "Optimistic Median")
    transform(
      s.begin(),
      s.end(),
      back_inserter(grades),
      ComputeOptimisticMedianGradeWrapper
    );
  else if (name == "Average")
    transform(
      s.begin(),
      s.end(),
      back_inserter(grades),
      ComputeAverageGradeWrapper
    );
  else
    throw domain_error("Invalid central tendency.");

  return ComputeMedian(grades);
}

double ComputeGradeWrapper(const Student& s) {
  try {
    return ComputeGrade(s);
  } catch (length_error) {
    return ComputeGrade(s.midterm, s.final, 0);
  }
}

double ComputeOptimisticMedianGrade(const Student& s) {
  vector<double> non_zero;

  remove_copy(
    s.homework.begin(),
    s.homework.end(),
    back_inserter(non_zero),
    0
  );

  if (non_zero.empty())
    return ComputeGrade(
      s.midterm,
      s.final,
      0
    );
  else
    return ComputeGrade(
      s.midterm,
      s.final,
      ComputeMedian(s.homework)
    );
}

double ComputeOptimisticMedianGradeWrapper(const Student& s) {
  try {
    return ComputeOptimisticMedianGrade(s);
  } catch (length_error) {
    return ComputeGrade(s.midterm, s.final, 0);
  }
}

bool IsFailGrade(const Student& s) {
  return s.final_grade < 60;
}

bool IsPassGrade(const Student& s) {
  return !IsFailGrade(s);
}

bool IsFinalGreaterThanMidterm(const Student& s) {
  return s.final > s.midterm;
}

bool IsFinalNotGreaterThanMidterm(const Student& s) {
  return !IsFinalGreaterThanMidterm(s);
}
