#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  stringstream ss("The quick brown fox\njumped over the fence");
  string s;
  vector<string> v;

  // Invariant: Stored all segments read so far
  while (getline(ss, s, '\n'))
    v.push_back(s);

  // Invariant: Wrote all items referenced so far
  for (auto& item: v)
    cout << item << endl;

  return 0;
}
