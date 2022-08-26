// 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> l(n);
    for (int i=0; i<n; ++i) cin >> l[i];
    int mval = *max_element(l.begin(), l.end());
    vector<int> lcnt(mval+1);
    for (int i=0; i<n; ++i) lcnt[l[i]]++;
    for (int i=0; i<mval; ++i) lcnt[i+1] += lcnt[i];
    cin >> q;
    for (int i=0; i<q; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        cout << (lcnt[min(mval,bi)]-lcnt[min(mval,ai-1)]) << endl;
    }
	return 0;
}
