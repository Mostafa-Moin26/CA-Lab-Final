#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
  for (int step = 1; step < size; step++) {
    int key = arr[step];
    int j = step - 1;

    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;

    for (int i = 0; i < size; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

}

int main() {
  int n; cin >> n;

  int arr[n];

  for (int i = 0; i < n; ++i) cin >> arr[i];
  insertionSort(arr, n);

  return 0;
}