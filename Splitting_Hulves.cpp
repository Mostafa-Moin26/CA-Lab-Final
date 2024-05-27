#include<bits/stdc++.h>

using namespace std;

int SH(int m, int n) {

  int d = (m + n) / 2;
  
  if (n == m) {
    return m * m;
  }

  return SH(m, d) + SH(d + 1, n);
}

int main() {

  int m, n;
  cin >> m >> n;

  cout << SH(m, n);

  return 0;
}