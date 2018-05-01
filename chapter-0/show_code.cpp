#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream infile("hello_world.cpp");
  string line;

  while (getline(infile, line)) {
    cout << line << endl;
  }

  return 0;
}
