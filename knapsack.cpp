#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
                   knapSack(W, wt, val, n - 1));
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> profit(n), weight(n);
    cout << "Enter the profit and weight for each item:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << ": ";
        cin >> profit[i] >> weight[i];
    }

    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    cout << "Maximum value: " << knapSack(W, weight.data(), profit.data(), n) << endl;

    return 0;
}

