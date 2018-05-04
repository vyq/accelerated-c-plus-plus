#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

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
    double x;
  
    // Invariant: homework contains all grades read so far
    while (cin >> x) {
      homework.push_back(x);
    }
  
    cin.clear();

    typedef vector<double>::size_type vector_size;
    vector_size size {homework.size()};
  
    if (size == 0) {
      cout << "Please input homework grades." << endl;
  
      return 1;
    }
  
    sort(homework.begin(), homework.end());
  
    vector_size middle {size / 2};
    double median {
      size % 2 == 0 ?
      (homework[middle] + homework[middle - 1]) / 2 :
      homework[middle]
    };
  
    double final_grade = 0.2 * midterm + 0.4 * final + 0.4 * median;

    student_grades[name] = final_grade;

    cout << "Input more student grades? (Yes / No) ";
    string reply;
    cin >> reply;

    cout << endl;

    if (reply == "No")
      break;
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
