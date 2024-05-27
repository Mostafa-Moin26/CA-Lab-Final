#include<bits/stdc++.h>

using namespace std;

int GU(int m, int n) {

  if (n == m) {
    return m * m;
  }

  return m * m + GU(m + 1, n);
}

int main() {

  int m, n;
  cin >> m >> n;

  cout << GU(m, n);

  return 0;
}