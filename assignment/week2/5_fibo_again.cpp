#include <iostream>
#include <vector>

using namespace std;

unsigned int PisanoPeriod(unsigned int m) {
  unsigned int a = 0, b = 1, c = a + b;
  for (int i = 0; i < m * m; i++) {
    c = (a + b) % m;
    a = b;
    b = c;
    if (a == 0 && b == 1) {
      return i + 1;
    }
  }
  return 0;
}

unsigned long long Fibonacci(unsigned long long n, unsigned int m) {
  unsigned int pisano = PisanoPeriod(m);
  vector<unsigned int> numbers(pisano + 1);

  // initial start elements
  numbers[0] = 0;
  numbers[1] = 1;
  for (int i = 2; i <= pisano; i++) {
    numbers[i] = (numbers[i - 1] + numbers[i - 2]) % m;
  }
  return numbers[n % pisano];
}

int main() {
  unsigned long long n;
  unsigned int m;
  cin >> n >> m;
  cout << Fibonacci(n, m) << "\n";
}

