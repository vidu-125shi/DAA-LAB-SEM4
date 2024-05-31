#include <iostream>
#include <vector>

using namespace std;

int coinChange(const vector<int>& coins, int target) {
  vector<int> dp(target + 1, 0);
  dp[0] = 1;

  for (int coin : coins) {
    for (int i = coin; i <= target; ++i) {
      dp[i] += dp[i - coin]; 
    }
  }

  return dp[target];
}

int main() {
  int numCoins;
  cout << "Enter the number of available coin types: ";
  cin >> numCoins;

  vector<int> coinValues(numCoins);

  cout << "Enter the value of each coin: ";
  for (int i = 0; i < numCoins; ++i) {
    cin >> coinValues[i];
  }

  int targetSum;

  cout << "Enter the target sum you want to achieve: ";
  cin >> targetSum;

  int numWays = coinChange(coinValues, targetSum);

  cout << "The number of ways to make the sum " << targetSum << " using the given coins is: " << numWays << endl;

  return 0;
}

