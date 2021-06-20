#include <iostream>
#include <vector>

using namespace std;

int Fibonacci(int n) {
  vector<int> numbers(n + 1);

  // initial start elements
  numbers[0] = 0;
  numbers[1] = 1;
  for (int i = 2; i <= n; i++) {
    numbers[i] = (numbers[i - 1] + numbers[i - 2]) % 10;
  }
  return numbers[n] % 10;
}

int main() {
  int n;
  cin >> n;
  cout << Fibonacci(n) << "\n";
}
