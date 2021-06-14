#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct coordinate {
  int a, b;
};

bool sortEnd(coordinate a, coordinate b) {
  return a.b <= b.b;
}

vector<int> MinimumPoints(int n, vector<coordinate>& v) {
  vector<int> result;
  while (!v.empty()) {
    int tb = v[0].b;
    result.push_back(v[0].b);
    for (vector<coordinate>::iterator it = v.begin(); it != v.end(); it++) {
      if (tb >= it->a && tb <= it->b) {
        v.erase(it--);
      }
    }
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<coordinate> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].a >> v[i].b;
  }
  sort(v.begin(), v.end(), sortEnd);
  vector<int> minPoints = MinimumPoints(n, v);
  int l = minPoints.size();
  cout << l << "\n";
  for (int i = 0; i < l; i++) {
    cout << minPoints[i] << " ";
  }
  cout << "\n";
  return 0;
}
