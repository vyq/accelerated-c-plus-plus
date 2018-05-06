#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include "median.h"
#include "student.h"

using namespace std;

struct Student {                                                        
  string name;                                                     
  double midterm, final;                                                
  vector<double> homework;                                         
};

bool Compare(const Student&, const Student&);
double ComputeGrade(const Student&);
double ComputeGrade(double, double, double);
double ComputeGrade(double, double, const vector<double>&);
istream& Read(istream&, Student&);
istream& ReadHomework(istream&, vector<double>&);

bool Compare(const Student& x, const Student& y) {
  return x.name < y.name;
}

double ComputeGrade(const Student& s) {
  return ComputeGrade(s.midterm, s.final, s.homework);
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

istream& Read(istream& is, Student& s) {
  cout << "Student name: ";
  is >> s.name;

  cout << "Midterm and final exam grades: ";
  is >> s.midterm >> s.final;

  if (s.midterm < 0 || s.midterm > 100 || s.final < 0 || s.final > 100)
    throw domain_error("Invalid midterm or final exam grades.");

  ReadHomework(is, s.homework);

  return is;
}

istream& ReadHomework(istream& is, vector<double>& v) {
  cout << "Homework grades: ";

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
  vector<Student> students;
  Student student;
  string::size_type longest_name_length {0};

  // Invariant: students contains all student grades read so far
  while (true) {
    try {
      Read(cin, student);
      students.push_back(student);

      longest_name_length = max(
        longest_name_length,
        student.name.size()
      );
  
      cout << endl << "Input more student grades (Yes / No)? ";
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
    } catch (length_error e) {
      cout << endl << e.what() << endl;

      return 1;
    } catch (domain_error e) {
      cout << endl << e.what() << endl;

      return 1;
    }
  }

  sort(students.begin(), students.end(), Compare);

  // Invariant: Printed all grades read from students so far
  for (auto student: students) {
    cout <<
      student.name <<
      string(longest_name_length - student.name.size(), ' ') <<
      ": ";

    try {
      streamsize precision {cout.precision()};

      cout << setprecision(3) <<
      ComputeGrade(student) <<
      setprecision(precision);
    } catch (length_error e) {
      cout << e.what();
    }

    cout << endl;
  }

  return 0;
}
