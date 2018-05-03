#include <iostream>

using namespace std;

int main() {
  cout << "First number: ";
  long long first;
  cin >> first;

  cout << "Second number: ";
  long long second;
  cin >> second;

  if (first > second)
    cout << first << " is larger than " << second << endl;
  else if (first == second)
    cout << first << " is equal to " << second << endl;
  else
    cout << first << " is smaller than " << second << endl;

  return 0;
}
