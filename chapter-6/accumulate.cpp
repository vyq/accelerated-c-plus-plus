#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> s {"foo", "bar", "baz"};

  cout << accumulate(s.begin(), s.end(), string("")) << endl;

  return 0;
}
