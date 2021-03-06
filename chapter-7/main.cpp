#include <algorithm>
#include <chrono>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include "average.h"
#include "grade.h"
#include "median.h"
#include "student.h"

using namespace std;
using namespace std::chrono;

void ReadFromFile(
  container_type& s,
  string::size_type& l,
  vector<Student>& done,
  vector<Student>& not_done
) {
  try {
    string filename {"grades_10.csv"};
    ifstream file(filename);
    Read(file, s, l, done, not_done);
  } catch (length_error e) {
    throw e;
  } catch (domain_error e) {
    throw e;
  }
}

void ReadFromStandardInput(
  container_type& s,
  string::size_type& l,
  vector<Student>& done,
  vector<Student>& not_done
) {
  Student student;

  // Invariant: s contains all student grades read so far
  while (true) {
    try {
      Read(cin, student);
      s.push_back(student);

      if (IsHomeworkDone(student))
        done.push_back(student);
      else
        not_done.push_back(student);

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
        cout << "Invalid reply. Assume \"No\"" << endl;
        break;
      }
    } catch (length_error e) {
      throw e;
    } catch (domain_error e) {
      throw e;
    }
  }
}

void WriteComparison(
  string name,
  double Compute(string, const vector<Student>&),
  const vector<Student>& done,
  const vector<Student>& not_done
) {
  cout << endl << name << endl << "Median (did homework): ";

  try {
    cout << Compute(name, done);
  } catch (length_error) {
    cout << "All students did not do some homework";
  }

  cout << endl << "Median (did not do homework): ";

  try {
    cout << Compute(name, not_done);
  } catch (length_error) {
    cout << "All students did homework";
  }

  cout << endl;
}

int main() {
  container_type students;
  Student student;
  vector<Student> done, not_done;
  string::size_type longest_name_length {0};
  high_resolution_clock::time_point start;
  map<string, int> grade_letter_count;

  try {
    cout << "Get student grades from standard input or file?" << endl;
    cout << "Press 1 for standard input, 2 for file: ";

    int x;
    cin >> x;

    start = high_resolution_clock::now();

    if (x == 1)
      ReadFromStandardInput(
        students,
        longest_name_length,
        done,
        not_done
      );
    else if (x == 2)
      ReadFromFile(students, longest_name_length, done, not_done);
    else {
      cout << endl << "Invalid input. Assume 2." << endl << endl;

      ReadFromFile(students, longest_name_length, done, not_done);
    }
  } catch (length_error e) {
    cout << endl << e.what() << endl;

    return 1;
  } catch (domain_error e) {
    cout << endl << e.what() << endl;

    return 1;
  }

  SortStudents(students);

  container_type greater_than {
    GetFinalGreaterThanMidtermStudents(students)
  };

  cout <<
    endl <<
    "Students with final grades greater than midterm grades" <<
    endl;

  // Invariant: Output all grades read so far
  for (auto& student: greater_than) {
    cout <<
      student.name <<
      string(longest_name_length - student.name.size(), ' ') <<
      ": ";

    try {
      streamsize precision {cout.precision()};
      cout << setprecision(3) <<
      student.final_grade <<
      setprecision(precision);

      cout << "\t" << student.grade_letter;
    } catch (length_error e) {
      cout << e.what();
    }

    cout << endl;
  }

  container_type not_greater_than {
    GetFinalNotGreaterThanMidtermStudents(students)
  };

  cout <<
    endl <<
    "Students with final grades not greater than midterm grades" <<
    endl;

  // Invariant: Output all grades read so far
  for (auto& student: not_greater_than) {
    cout <<
      student.name <<
      string(longest_name_length - student.name.size(), ' ') <<
      ": ";

    try {
      streamsize precision {cout.precision()};
      cout << setprecision(3) <<
      student.final_grade <<
      setprecision(precision);

      cout << "\t" << student.grade_letter;
    } catch (length_error e) {
      cout << e.what();
    }

    cout << endl;
  }

  container_type fail_students {GetFailStudents(students)};

  cout << endl << "Pass students" << endl;

  // Invariant: Output all grades read from students so far
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

      cout << "\t" << student.grade_letter;
    } catch (length_error e) {
      cout << e.what();
    }

    cout << endl;
  }

  cout << endl << "Fail students" << endl;

  // Invariant: Output all grades read from fail_students so far
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

      cout << "\t" << student.grade_letter;
    } catch (length_error e) {
      cout << e.what();
    }

    cout << endl;
  }

  cout << endl << "Grade letter counts" << endl;

  // Invariant: Count all grade letters read so far
  for (auto& student: students)
    ++grade_letter_count[student.grade_letter];

  // Invariant: Count all grade letters read so far
  for (auto& student: fail_students)
    ++grade_letter_count[student.grade_letter];

  for (
    map<string, int>::const_iterator iterator = grade_letter_count.begin();
    iterator != grade_letter_count.end();
    ++iterator
  ) {
    cout << iterator->first << "\t" << iterator->second << endl;
  }

  high_resolution_clock::time_point end {
    high_resolution_clock::now()
  };
  WriteComparison("Median", ComputeGrade, done, not_done);
  WriteComparison(
    "Optimistic Median",
    ComputeGrade,
    done,
    not_done
  );
  WriteComparison("Average", ComputeGrade, done, not_done);

  cout <<
    endl <<
    "Execution time: " <<
    duration_cast<duration<double>>(end - start).count() <<
    " seconds" <<
    endl;

  return 0;
}
