#include <iostream>
#include <vector>

using namespace std;

long long Fibonacci(long long n) {
  if (n < 0) {
    return 0;
  }

  unsigned int pisanoPeriod10 = 60;
  unsigned int sumPeriod = 1, sumFibo = 0;
  vector<unsigned int> numbers(pisanoPeriod10 + 1);

  // initial start elements
  numbers[0] = 0;
  numbers[1] = 1;
  for (int i = 2; i <= pisanoPeriod10; i++) {
    numbers[i] = (numbers[i - 1] + numbers[i - 2]) % 10;
    sumPeriod += numbers[i];
  }
  for (int i = 1; i <= n % pisanoPeriod10; i++) {
    sumFibo += numbers[i];
  }
  return sumFibo + (sumPeriod * (n / pisanoPeriod10));
}

int main() {
  long long n, m;
  cin >> n >> m;
  cout << (Fibonacci(m) - Fibonacci(n - 1)) % 10 << "\n";
}

