#include<bits/stdc++.h>

using namespace std;


int tower(int n) {

    if (n == 1) {
        return 1;
    }

    return 2 * tower(n - 1) + 1;
}
int main() {
    
    int n; cin >> n;

    cout << tower(n) << endl;

    return 0;
}