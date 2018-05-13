#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include "grade.h"
#include "student.h"

using namespace std;

void ReadFromStandardInput(container_type& s, string::size_type& l) {
  Student student;

  // Invariant: students contains all student grades read so far
  while (true) {
    try {
      Read(cin, student);
      s.push_back(student);

      l = max(
        l,
        student.name.size()
      );
  
      cout << "Input more student grades (Yes / No)? ";
      string reply;
      cin >> reply;
  
      if (reply == "Yes")
        continue;
      else if (reply == "No")
        break;
      else {
        cout << "Invalid reply. Assume \"No\"" << endl << endl;
        break;
      }
    } catch (length_error e) {
      throw e;
    } catch (domain_error e) {
      throw e;
    }
  }
}

void ReadFromFile(container_type& s, string::size_type& l) {
  try {
    ifstream file("grades_10.csv");
    Read(file, s, l);
  } catch (length_error e) {
    throw e;
  } catch (domain_error e) {
    throw e;
  }
}

int main() {
  container_type students;
  Student student;
  string::size_type longest_name_length {0};

  try {
    cout << "Get student grades from standard input or file?" << endl;
    cout << "Press 1 for standard input, 2 for file: ";

    int x;
    cin >> x;

    if (x == 1)
      ReadFromStandardInput(students, longest_name_length);
    else if (x == 2)
      ReadFromFile(students, longest_name_length);
    else {
      cout << endl << "Invalid input. Assume 1." << endl << endl;

      ReadFromStandardInput(students, longest_name_length);
    }
  } catch (length_error e) {
    cout << endl << e.what() << endl;

    return 1;
  } catch (domain_error e) {
    cout << endl << e.what() << endl;

    return 1;
  }

  students.sort(Compare);
  container_type fail_students {GetFailStudents(students)};

  cout << endl << "Pass students" << endl;

  // Invariant: Printed all grades read from students so far
  for (auto& student: students) {
    cout <<
      student.name <<
      string(longest_name_length - student.name.size(), ' ') <<
      ": ";

    try {
      streamsize precision {cout.precision()};
      cout << setprecision(3) <<
      student.final_grade <<
      setprecision(precision);
    } catch (length_error e) {
      cout << e.what();
    }

    cout << endl;
  }

  cout << endl << "Fail students" << endl;

  // Invariant: Printed all grades read from fail_students so far
  for (auto& student: fail_students) {
    cout <<
      student.name <<
      string(longest_name_length - student.name.size(), ' ') <<
      ": ";

    try {
      streamsize precision {cout.precision()};
      cout << setprecision(3) <<
      student.final_grade <<
      setprecision(precision);
    } catch (length_error e) {
      cout << e.what();
    }

    cout << endl;
  }

  return 0;
}
