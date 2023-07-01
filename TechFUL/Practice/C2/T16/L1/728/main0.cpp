// 自力AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    int li = n, ri = -1;
    for (int i=0; i<n; ++i) if (a[i] == 2) {
        li = min(li, i);
        ri = max(ri, i);
    }
    cout << max(0, ri-li+1) << endl;
    return 0;
}
