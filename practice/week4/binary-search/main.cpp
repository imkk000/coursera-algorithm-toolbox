#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int binary_search_iterative(const vector<int>& nums, int low, int high, int target) {
  while (high >= low) {
    int mid = low + (high - low) / 2;
    if (target == nums[mid]) {
      return mid;
    }
    if (target < nums[mid]) {
      high = mid - 1;
      continue;
    }
    low = mid + 1;
  }
  return -1;
}

int binary_search_recursive(const vector<int>& nums, int low, int high, int target) {
  if (high < low) {
    return -1;
  }

  int mid = low + (high - low) / 2;
  if (target == nums[mid]) {
    return mid;
  }
  if (target < nums[mid]) {
    return binary_search_recursive(nums, low, mid - 1, target);
  }
  if (target > nums[mid]) {
    return binary_search_recursive(nums, mid + 1, high, target);
  }
  return -1;
}

int main() {
  vector<int> nums {-5, -1, 0, 1, 8, 9};
  vector<int> q {0, 1, 10, -10, 5};
  // 2, 3, -1, -1, -1
  for (vector<int>::iterator it = q.begin(); it != q.end(); it++) {
    cout << binary_search_recursive(nums, 0, nums.size() - 1, *it) << " ";
    cout << binary_search_iterative(nums, 0, nums.size() - 1, *it);
    cout << "\n";
  }
  return 0;
}
