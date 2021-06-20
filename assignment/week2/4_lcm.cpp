#include <iostream>

using namespace std;

// greatest common divisor
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

// least common multiple
unsigned long long Lcm(unsigned long long a, unsigned long long b) {
  unsigned long long gcd = EuclidGcd(a, b);
  return (a * b) / gcd;
}

int main() {
  unsigned long long a, b;
  cin >> a >> b;
  cout << Lcm(a, b) << "\n";
}
