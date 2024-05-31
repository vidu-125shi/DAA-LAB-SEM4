#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    unordered_map<int, pair<int, int>> product_map;
    bool found = false;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int product = arr[i] * arr[j];
            if (product_map.find(product) != product_map.end()) {
                pair<int, int> first_pair = product_map[product];
                cout << first_pair.first << " " << first_pair.second << endl;
                cout << arr[i] << " " << arr[j] << endl;
                found = true;
                break;
            } else {
                product_map[product] = {arr[i], arr[j]};
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "No pairs found" << endl;
    }

    return 0;
}
