#include<bits/stdc++.h>

using namespace std;

vector<int> selectionSort(vector<int> a) {

   int n = a.size();

   for (int i = 0; i < n; ++i) {

      int idx, mxx = INT_MIN;

      for (int j = 0; j < n - i; ++j) {

         if (a[j] > mxx) {
            mxx = a[j];
            idx = j;
         }
      }
      swap(a[idx], a[n - i - 1]);

      for (auto i : a) cout << i << " ";
      cout << endl;
   }
   return a;
}
int main() {

   int n; cin >> n;

   vector<int> a(n); 

   for (int i = 0; i < n; ++i) cin >> a[i];  

   vector<int> ans = selectionSort(a);
       return 0;
}