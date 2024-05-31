
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minCostMergeFiles(vector<int>& fileSizes) {
  int n = fileSizes.size();
  if (n <= 1) {
    return 0;
  }

  priority_queue<int, vector<int>, greater<int>> pq(fileSizes.begin(), fileSizes.end());

  int totalCost = 0;
  while (pq.size() > 1) {
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();

    int mergedSize = first + second;
    totalCost += mergedSize;

    pq.push(mergedSize);
  }

  return totalCost;
}

int main() {
  int n;

  cout << "Enter the number of files ";
  cin >> n;

  vector<int> fileSizes(n);

  cout << "Enter the sizes of " << n << " files ";
  for (int i = 0; i < n; i++) {
    cin >> fileSizes[i];
  }

  int minCost = minCostMergeFiles(fileSizes);
  cout << "Minimum computation cost (ignoring merging cost): " << minCost << endl;

  return 0;
}









