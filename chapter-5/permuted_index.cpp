#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  stringstream ss("The quick brown fox\njumped over the fence");
  string s;
  vector<string> v;

  while (getline(ss, s, '\n'))
    v.push_back(s);

  for (auto& item: v)
    cout << item << endl;

  return 0;
}
