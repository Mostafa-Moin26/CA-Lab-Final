#include<bits/stdc++.h>

using namespace std;

int SumOfNtNum(int n) {

    if (n == 1) {
        return n;
    }
    return n + SumOfNtNum(n - 1);
}
int main() {

    int n; cin >> n;

    cout << SumOfNtNum(n) << endl;
    return 0;
}
