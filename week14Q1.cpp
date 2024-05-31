#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long nthUglyNumber(int n) {
    vector<long long> ugly(n);
    ugly[0] = 1;
    int idx2 = 0, idx3 = 0, idx5 = 0;

    for (int i = 1; i < n; ++i) {
        ugly[i] = min({ugly[idx2] * 2, ugly[idx3] * 3, ugly[idx5] * 5});
        if (ugly[i] == ugly[idx2] * 2) ++idx2;
        if (ugly[i] == ugly[idx3] * 3) ++idx3;
        if (ugly[i] == ugly[idx5] * 5) ++idx5;
    }

    return ugly[n - 1];
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int n;
        cout << "Enter the value of n for test case " << i + 1 << ": ";
        cin >> n;

        cout << "For test case " << i + 1 << ", the " << n << "th ugly number is: " << nthUglyNumber(n) << endl;
    }

    return 0;
}


