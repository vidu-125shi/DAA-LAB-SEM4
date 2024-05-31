#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> weights(n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    int W;
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int maxValue = dp[n][W];
    cout << "Value = " << maxValue << endl;

    int w = W;
    vector<int> selectedWeights;
    vector<int> selectedValues;
    for (int i = n; i > 0 && maxValue > 0; --i) {
        if (maxValue == dp[i - 1][w])
            continue;
        else {
                       selectedWeights.push_back(weights[i - 1]);
            selectedValues.push_back(values[i - 1]);
            maxValue -= values[i - 1];
            w -= weights[i - 1];
        }
    }
    cout << "Weights selected: ";
    for (int i = selectedWeights.size() - 1; i >= 0; --i) {
        cout << selectedWeights[i] << " ";
    }
    cout << endl;

    cout << "Values of selected weights: ";
    for (int i = selectedValues.size() - 1; i >= 0; --i) {
        cout << selectedValues[i] << " ";
    }
    cout << endl;

    return 0;
}
