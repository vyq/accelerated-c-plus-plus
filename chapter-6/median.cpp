#include <algorithm>
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "student.h"

using namespace std;

double ComputeMedian(vector<double> v) {
  typedef vector<double>::size_type vector_size;
  vector_size size {v.size()};

  if (size == 0)
    throw length_error("Cannot compute median of empty vector.");

  sort(v.begin(), v.end());

  vector_size middle {size / 2};

  return size % 2 == 0 ? (v[middle] + v[middle - 1]) / 2 : v[middle];
}

double ComputeMedian(const vector<Student>& s) {
  vector<double> grades;

  transform(
    s.begin(),
    s.end(),
    back_inserter(grades),
    ComputeGradeWrapper
  );

  return ComputeMedian(grades);
}
