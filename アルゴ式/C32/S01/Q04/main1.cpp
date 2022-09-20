// 解説AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool res = false;
    if (n%4 == 0) {
        res = true;
        if (n%100 == 0) {
            res = false;
            if (n%400 == 0) res = true;
        }
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
