#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int matrixChainOrder(const vector<int> &dims, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;




    vector<int> dims(n * 2);
    cout << "Enter the dimensions of the matrices as a single 1D array:\n";
    for (int i = 0; i <=n; i++) {
        cin >> dims[i];
    }

    int result = matrixChainOrder(dims, n + 1);
    cout << "Minimum number of multiplications required: " << result << endl;

    return 0;
}
	










