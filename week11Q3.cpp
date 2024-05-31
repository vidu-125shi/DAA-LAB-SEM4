#include <iostream>
#include <vector>
using namespace std;

bool canPartition(const vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;

    for (int num : nums) {
        totalSum += num;
    }

    if (totalSum % 2 != 0) {
        return false;
    }

    int subsetSum = totalSum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(subsetSum + 1, false));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= subsetSum; ++j) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][subsetSum];
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    if (canPartition(nums)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
