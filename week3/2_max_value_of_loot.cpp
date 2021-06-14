#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pack {
  double ratio;
  int weight;
  int value;
};

bool sortPackDesc(pack const& a, pack const& b) {
  return a.ratio > b.ratio;
}

double MaximumValueLoot(vector<pack> packs, int n, int w) {
  double sum = 0;
  sort(packs.begin(), packs.end(), &sortPackDesc);
  for (int i = 0; i < n; i++) {
    if (w - packs[i].weight <= 0) {
      sum += ((double)w / (double)packs[i].weight) * (double)packs[i].value;
      break;
    }
    w -= packs[i].weight;
    sum += packs[i].value;
  }
  return sum;
}

int main() {
  int n, w;
  cin >> n >> w;
  vector<pack> packs(n);
  for (int i = 0; i < n; i++) {
    cin >> packs[i].value >> packs[i].weight;
    packs[i].ratio = ((double)packs[i].value / (double)packs[i].weight) * 1000;
  }
  cout.precision(10); 
  cout << MaximumValueLoot(packs, n, w) << "\n";
  return 0;
}
