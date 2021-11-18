// Contributor: Daksh Dhangar

#include <bits/stdc++.h>
using namespace std;

bool stoneGame(vector<int> &piles) {

  int n = piles.size();

  vector<vector<int>> dp(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    dp[i][i] = piles[i];
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      int parity = (i - j + n - 1) % 2;
      if (!parity) {
        dp[i][j] = max(piles[i] + dp[i + 1][j], piles[j] + dp[i][j - 1]);
      } else {
        dp[i][j] = min(-piles[i] + dp[i + 1][j], -piles[j] + dp[i][j - 1]);
      }
    }
  }
  return (dp[0][n - 1] > 0);
}
int main() {
  int n;
  cin >> n;
  vector<int> piles(n);
  for (int i = 0; i < n; i++) {
    cin >> piles[i];
  }
  if (stoneGame(piles))
    cout << "ALICE WON" << '\n';
  else
    cout << "BOB WON" << '\n';
}