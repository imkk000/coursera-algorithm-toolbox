#include <iostream>

using namespace std;

unsigned long long EuclidGcd(unsigned long long a, unsigned long long b) {
  // basis case
  if (b == 0) {
    return a;
  }

  // a'
  a %= b;

  // EuclidGcd(b, a')
  return EuclidGcd(b, a);
}

int main() {
  unsigned long long a, b;
  cin >> a >> b;
  cout << EuclidGcd(a, b) << "\n";
}
