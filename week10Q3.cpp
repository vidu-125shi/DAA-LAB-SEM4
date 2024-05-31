#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool findMajorityElement(vector<int>& arr) {
  int n = arr.size();
  if (n == 0) {
    return false;
  }

  int count = 0;
  int candidate = arr[0];

  for (int num : arr) {
    if (count == 0) {
      candidate = num;
    }
    count += (num == candidate) ? 1 : -1;
  }


  if (count > 0) {
    int majorityCount = 0;
    for (int num : arr) {
      if (num == candidate) {
        majorityCount++;
      }
    }
    return majorityCount > n / 2;
  } else {
    return false;
  }
}

double findMedian(const vector<int>& arr) {
  int n = arr.size();
  if (n % 2 == 0) {
    return (double)(arr[n / 2 - 1] + arr[n / 2]) / 2;
  } else {
    return (double)arr[n / 2];
  }
}

int main() {
  int n;
  cout << "Enter the size of the array (N): ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter the elements of the array (space-separated): ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  bool hasMajority = findMajorityElement(arr);
  cout << (hasMajority ? "yes" : "no") << " - Majority element exists" << endl;
  sort(arr.begin(), arr.end());
  double median = findMedian(arr);
  cout << "Median of the array: " << median << endl;

  return 0;
}
