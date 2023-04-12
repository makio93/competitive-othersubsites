// 

#include <iostream>
#include <array>
using namespace std;

int main() {
    int n;
    cin >> n;
    array<bool, 2001> acnt;
    acnt.fill(false);
    int res = 0;
    for (int i=0; i<n; ++i) {
        int ai;
        cin >> ai;
        if (acnt[ai]) continue;
        acnt[ai] = true;
        ++res;
    }
    cout << res << endl;
    return 0;
}
