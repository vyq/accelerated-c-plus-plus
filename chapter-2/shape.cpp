#include <iostream>

using namespace std;

int main() {
  const int kSquareLength {2};
  const int kRectangleLength {8};
  const int kRectangleWidth {4};
  const int kTriangleLength {16};

  cout << "Square" << endl << endl;

  // Invariant: Printed i rows so far
  for (int i = 0; i < kSquareLength; ++i) {
    const string square(kSquareLength, '*');
    cout << square << endl;
  }

  cout << endl;
  cout << "Rectangle" << endl << endl;

  // Invariant: Printed i rows so far
  for (int i = 0; i < kRectangleLength; ++i) {
    const string point(kRectangleWidth, '*');
    cout << point << endl;
  }

  cout << endl;
  cout << "Triangle" << endl;

  // Invariant: Printed i rows so far
  for (int i = 0; i < kTriangleLength; ++i) {
    const string point(i, '*');

    cout << point << endl;
  }

  return 0;
}
