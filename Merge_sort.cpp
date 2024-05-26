#include<bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define pb push_back

vi mergeSort(vi a) {

   if (a.size() <= 1) { // base case
      return a; 
   }

   vi b;
   vi c;

   int mid = a.size() / 2;

   for (int i = 0; i < mid; ++i) {
      b.pb(a[i]);
   }
   for (int i = mid; i < a.size(); ++i) {
      c.pb(a[i]);
   }

   vi sorted_b = mergeSort(b);
   vi sorted_c = mergeSort(c);

   int idx1 = 0, idx2 = 0;
   vector<int> ans;

   for (int i = 0; i < a.size(); ++i) {

      if (idx1 == sorted_b.size()) {
         ans.pb(sorted_c[idx2]);
         idx2++;
      } else if(idx2 == sorted_c.size()) {
         ans.pb(sorted_b[idx1]);
         idx1++;
      } else if (sorted_b[idx1] > sorted_c[idx2]) {
         ans.pb(sorted_c[idx2]);
         idx2++;
      } else {
         ans.pb(sorted_b[idx1]);
         idx1++;
      }
   }

   for (auto i : ans) {
      cout << i << " ";
   }
   cout << endl;

   return ans;
}

int main() {

    int n; cin >> n;

    vi a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];

    vi ans = mergeSort(a);

    return 0;
}
