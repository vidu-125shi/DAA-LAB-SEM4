#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
  double weight;
  double value;
  double ratio;
};

bool compareItems(const Item& a, const Item& b) {
  return a.ratio > b.ratio;
}

double fractionalKnapsack(vector<Item>& items, double capacity) {
  double totalValue = 0.0;

  sort(items.begin(), items.end(), compareItems);

  for (Item item : items) {
    if (capacity <= 0) {
      break;
    }

    double fraction = min(capacity / item.weight, 1.0);
    totalValue += fraction * item.value;
    capacity -= fraction * item.weight;

    cout << "item " << item.weight << endl;
  }
  return totalValue;
}

int main() {
  int n;
  cin >> n;

  vector<Item> items(n);

  for (int i = 0; i < n; i++) {
    cin >> items[i].weight;
  }

  for (int i = 0; i < n; i++) {
    cin >> items[i].value;
    items[i].ratio = items[i].value / items[i].weight;
  }

  double capacity;
  cin >> capacity;

  double maxValue = fractionalKnapsack(items, capacity);
  cout << "\nMaximum Value: $" << fixed << maxValue << endl;

  return 0;
}
