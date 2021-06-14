#include <iostream>
#include <vector>

using namespace std;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  int n = numbers.size();
  int max_index1 = 0;
  for (int i = 1; i < n; i++) {
    if (numbers[i] > numbers[max_index1]) {
      max_index1 = i;
    }
  }
  int max_index2 = -1;
  for (int i = 0; i < n; i++) {
    if ((i != max_index1) && (numbers[i] > numbers[max_index2])) {
      max_index2 = i;
    }
  }
  return (long long)numbers[max_index1] * (long long)numbers[max_index2];
}

int main() {
  int n;
  cin >> n;
  vector<int> numbers(n);
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  cout << MaxPairwiseProduct(numbers) << "\n";

  return 0;
}

