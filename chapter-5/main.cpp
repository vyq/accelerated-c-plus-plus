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

int main() {
  container_type students;
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

  students.sort(Compare);
  container_type fail_students {GetFailStudents(students)};

  cout << "Pass students" << endl;

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
