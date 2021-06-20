#include <iostream>
#include <vector>

using namespace std;

int MinimumRefills(int d, int m, int n, const vector<int>& stations) {
  int currRefill = 0, numRefills = 0;
  while (currRefill <= n) {
    int lastRefill = currRefill;
    while (currRefill <= n && stations[currRefill + 1] - stations[lastRefill] <= m) {
      currRefill++;
    }
    if (currRefill == lastRefill) {
      return -1;
    }
    if (currRefill <= n) {
      numRefills++;
    }
  }
  return numRefills;
}

int main() {
  int d, m, n;
  cin >> d >> m >> n;
  vector<int> stations(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> stations[i];
  }
  stations[n + 1] = d;
  cout << MinimumRefills(d, m, n, stations) << "\n";
  return 0;
}
