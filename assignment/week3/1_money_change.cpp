#include <iostream>

using namespace std;

unsigned int MinimumNumberCoin(unsigned int n) {
  return (n / 10) + ((n % 10) / 5) + ((n % 10) % 5);
}

int main() {
  unsigned int n;
  cin >> n;
  cout << MinimumNumberCoin(n) << "\n";
  return 0;
}
