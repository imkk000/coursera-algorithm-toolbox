#include <iostream>
#include <vector>

using namespace std;

vector<int> MaximumNumberPrizes(int n) {
  vector<int> v;
  for (int i = 1; n > 0; i++) {
    if (n - i > i || n - i == 0) {
      v.push_back(i);
      n -= i;
    }
  }
  return v;
}

int main() {
  int n;
  cin >> n;
  vector<int> p = MaximumNumberPrizes(n);
  cout << p.size() << "\n";
  for (vector<int>::iterator it = p.begin(); it != p.end(); it++) {
    cout << *it << " ";
  }
  cout << "\n";
}

