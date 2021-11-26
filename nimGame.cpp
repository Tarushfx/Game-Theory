// Contributor: Parikshit

#include <bits/stdc++.h>
using namespace std;

void nimGame(vector<int> piles) {
  int curr_nim = 0;
  for (int x : piles) {
    curr_nim ^= x;
  }
  if (!curr_nim)
    cout << "SECOND" << endl;
  else
    cout << "FIRST" << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> piles(n);
  for (int i = 0; i < n; i++) {
    cin >> piles[i];
  }
  nimGame(piles);
}