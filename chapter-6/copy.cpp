#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> u(10, 100);
  vector<int> v(u.size());
  
  copy(u.begin(), u.end(), v.begin());

  for (auto& i: u)
    cout << i << " ";

  cout << endl;

  for (auto& i: v)
    cout << i << " ";

  cout << endl;

  return 0;
}
