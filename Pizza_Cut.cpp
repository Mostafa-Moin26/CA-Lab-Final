#include<bits/stdc++.h>

using namespace std;


int pizzaCut(int n) {

    if (n == 1) {
        return 2;
    }

    return pizzaCut(n - 1) + n;
}
int main() {
    
    int n; cin >> n;

    cout << pizzaCut(n) << endl;

    return 0;
}