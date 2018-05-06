#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

double ComputeMedian(vector<double> v);
double ComputeGrade(double, double, double);
double ComputeGrade(double, double, const vector<double>&);
istream& ReadHomework(istream&, vector<double>&);

double ComputeMedian(vector<double> v) {
  typedef vector<double>::size_type vector_size;
  vector_size size {v.size()};

  if (size == 0)
    throw length_error("Cannot compute median of empty vector.");

  sort(v.begin(), v.end());

  vector_size middle {size / 2};

  return size % 2 == 0 ? (v[middle] + v[middle - 1]) / 2 : v[middle];
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
    throw length_error("Homework grades required.");
  
  return ComputeGrade(midterm, final, ComputeMedian(homework));
}

istream& ReadHomework(istream& is, vector<double>& v) {
  if (is) {
    v.clear();

    double x;

    // Invariant: homework contains all grades read so far
    while (is >> x)
      v.push_back(x);

    is.clear();
  }

  return is;
}

int main() {
  map<string, double> student_grades;

  // Invariant: student_grades contains all student grades read so far
  while (true) {
    cout << "Name: ";
    string name;
    cin >> name;
    cout << "Hello " << name << "!" << endl;
  
    cout << "Midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    if (midterm < 0 || midterm > 100 || final < 0 || final > 100) {
      cout <<
        "Please input valid midterm and final exam grades." <<
        endl;

      return 1;
    }
  
    cout << "Homework grades: ";
    vector<double> homework;
    ReadHomework(cin, homework);

    try {
      double median {ComputeMedian(homework)};
      double final_grade {ComputeGrade(midterm, final, median)};
  
      student_grades[name] = final_grade;
  
      cout << endl;
      cout << "Input more student grades (Yes / No)? ";
      string reply;
      cin >> reply;
      cout << endl;
  
      if (reply == "Yes")
        continue;
      else if (reply == "No")
        break;
      else {
        cout << "Invalid reply. Assume \"No\"" << endl << endl;
        break;
      }
    } catch (length_error) {
      cout << endl << "Please input grades." << endl;

      return 1;
    }
  }

  // Invariant: Printed all grades read from student_grades so far
  for (auto student_grade: student_grades) {
    streamsize precision {cout.precision()};
    cout <<
      student_grade.first <<
      ": " <<
      setprecision(3) <<
      student_grade.second <<
      setprecision(precision) <<
      endl;
  }

  return 0;
}
