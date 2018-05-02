#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "Name: ";
  string name;
  cin >> name;

  const string kGreeting = "Hello " + name + "!";
  const string kSpaces(kGreeting.size(), ' ');
  const string kPadding = "* " + kSpaces + " *";
  const string kMargin(kPadding.size(), '*');

  cout << endl;
  cout << kMargin << endl;
  cout << kPadding << endl;
  cout << "* " << kGreeting << " *" << endl;
  cout << kPadding << endl;
  cout << kMargin << endl;

  return 0;
}
