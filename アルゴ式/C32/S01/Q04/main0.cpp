// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool res = true;
    if (n%4 == 0) {
        if (n%100 == 0) res = (n%400 == 0);
        else res = true;
    }
    else res = false;
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
