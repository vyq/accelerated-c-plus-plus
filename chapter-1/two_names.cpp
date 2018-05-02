#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "What is your name? ";
  string name;
  cin >> name;

  cout << "Hello " << name << endl;
  cout << "What is yours? ";
  cin >> name;
  cout << endl;

  cout << "Hello " << name << ". Nice to meet you too!" << endl;

  return 0;
}
