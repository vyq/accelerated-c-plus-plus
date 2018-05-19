#include <algorithm>
#include <numeric>
#include <vector>
#include "average.h"
#include "grade.h"
#include "median.h"
#include "student.h"

using namespace std;

double ComputeAverage(vector<double> v) {
  return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double ComputeAverage(const vector<Student>& s) {
  vector<double> grades;
  
  transform(
    s.begin(),
    s.end(),
    back_inserter(grades),
    ComputeAverageGradeWrapper
  );

  return ComputeMedian(grades);
}
