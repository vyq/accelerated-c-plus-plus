#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "Name: ";
  string name;
  cin >> name;

  const string greeting = "Hello " + name + "!";
  const string spaces(greeting.size(), ' ');
  const string padding = "* " + spaces + " *";
  const string margin(padding.size(), '*');

  cout << endl;
  cout << margin << endl;
  cout << padding << endl;
  cout << "* " << greeting << " *" << endl;
  cout << padding << endl;
  cout << margin << endl;

  return 0;
}
