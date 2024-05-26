#include<bits/stdc++.h>

using namespace std;

int main() {

  int n;
  cin >> n;
  
  int arr[n];

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int key; 
  cin >> key;

  int left = 0, right = n - 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (arr[mid] == key) {
      cout << "value found at index no " << mid << endl;
      return 0;
    } else if (arr[mid] > key) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << "value not exist" << endl;

  return 0;
}
