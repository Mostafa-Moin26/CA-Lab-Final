#include<bits/stdc++.h>

using namespace std;

int GD(int m, int n) {

	if (n == m) {
		return n * n;
	}

	return n * n + GD(m, n - 1);
}

int main() {

	int m, n; cin >> m >> n;

	cout << GD(m, n);
}