#include <iostream>
using namespace std;

void printArray(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void quick_sort(int* a, int start, int end, int n) {
    if (start >= end) {
        return;
    }

    int pivot = a[start];
    int low = start + 1;
    int high = end;

    cout << "Pivot: " << pivot << endl;

    while (low <= high) {
        while (low <= high && a[low] <= pivot) {
            low++;
        }
        while (low <= high && a[high] > pivot) {
            high--;
        }
        if (low < high) {
            swap(a[low], a[high]);
            printArray(a, n);
        }
    }

    swap(a[start], a[high]);
    printArray(a, n);

    quick_sort(a, start, high - 1, n);
    quick_sort(a, high + 1, end, n);
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << "Initial array: ";
    printArray(a, n);

    quick_sort(a, 0, n - 1, n);

    cout << "Sorted array: ";
    printArray(a, n);

    return 0;
}
