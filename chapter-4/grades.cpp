#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Student {                                                        
  string name;                                                     
  double midterm, final;                                                
  vector<double> homework;                                         
};

bool Compare(const Student&, const Student&);
double ComputeMedian(vector<double> v);
double ComputeGrade(const Student&);
double ComputeGrade(double, double, double);
double ComputeGrade(double, double, const vector<double>&);
istream& Read(istream&, Student&);
istream& ReadHomework(istream&, vector<double>&);

bool Compare(const Student& x, const Student& y) {
  return x.name < y.name;
}

double ComputeMedian(vector<double> v) {
  typedef vector<double>::size_type vector_size;
  vector_size size {v.size()};

  if (size == 0)
    throw length_error("Cannot compute median of empty vector.");

  sort(v.begin(), v.end());

  vector_size middle {size / 2};

  return size % 2 == 0 ? (v[middle] + v[middle - 1]) / 2 : v[middle];
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
  is >> s.name >> s.midterm >> s.final;

  ReadHomework(is, s.homework);

  return is;
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
  vector<Student> students;
  Student student;
  map<string, double> student_grades;

  // Invariant: student_grades contains all student grades read so far
  while (true) {
    cout << "Name: ";
    string name;
    cin >> name;
    student.name = name;
    cout << "Hello " << name << "!" << endl;
  
    cout << "Midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    student.midterm = midterm;
    student.final = final; 

    if (midterm < 0 || midterm > 100 || final < 0 || final > 100) {
      cout <<
        "Please input valid midterm and final exam grades." <<
        endl;

      return 1;
    }
  
    cout << "Homework grades: ";
    vector<double> homework;
    ReadHomework(cin, homework);
    student.homework = homework;

    try {
      double median {ComputeMedian(homework)};
      double final_grade {ComputeGrade(midterm, final, median)};
  
      student_grades[name] = final_grade;
      students.push_back(student);
  
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
    } catch (length_error) {
      cout << endl << "Please input grades." << endl;

      return 1;
    }
  }

  sort(students.begin(), students.end(), Compare);

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
