#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsGreaterOrEqual(int digit, int maxDigit) {
  string a = to_string(digit);
  string b = to_string(maxDigit);
  return stoi(a + b) >= stoi(b + a);
}

string LargestNumber(vector<int>& digits) {
  string answer = "";
  while (!digits.empty()) {
    int maxDigit = 0;
    int deletedIndex = 0;
    for (int i = 0; i < digits.size(); i++) {
      if (IsGreaterOrEqual(digits[i], maxDigit)) {
        maxDigit = digits[i];
        deletedIndex = i;
      }
    }
    answer += to_string(maxDigit);
    digits.erase(digits.begin() + deletedIndex);
  }
  return answer;
}

int main() {
  int n;
  cin >> n;
  vector<int> digits(n);
  for (int i = 0; i < n; i++) {
    cin >> digits[i];
  }
  cout << LargestNumber(digits) << "\n";
  return 0;
}

