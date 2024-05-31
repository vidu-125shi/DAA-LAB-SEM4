#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicateWithinWindow(const vector<int>& arr, int k) {
    unordered_set<int> window;
    for (int i = 0; i < arr.size(); ++i) {
        if (window.find(arr[i]) != window.end()) {
            return true;
        }
        window.insert(arr[i]);
        if (window.size() > k) {
            window.erase(arr[i - k]);
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        if (containsDuplicateWithinWindow(arr, k)) {
            cout << "Duplicate present in window " << k << "." << endl;
        } else {
            cout << "Duplicate not present in window " << k << "." << endl;
        }
    }
    return 0;
}
