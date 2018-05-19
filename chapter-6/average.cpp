#include <numeric>
#include <vector>

using namespace std;

double ComputeAverage(vector<double> v) {
  return accumulate(v.begin(), v.end(), 0.0) / v.size();
}
