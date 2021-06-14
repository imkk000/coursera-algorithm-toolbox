#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MaximumAdvertisementRevenue(int n, const vector<int>& a, const vector<int>& b) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (long long)a[i] * (long long)b[i];
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  cout << MaximumAdvertisementRevenue(n, a, b) << "\n";
  return 0;
}
