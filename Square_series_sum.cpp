#include<bits/stdc++.h>

using namespace std;

int SQ(int i, int sum, int n) {

  if (i == 2 * n + 1) {
    sum += i * i;
    return sum;
  }

  sum += i * i;
  return SQ(i + 2, sum, n);
}

int main() {

  int n; cin >> n;

  cout << SQ(1, 0, n);

  return 0;
}