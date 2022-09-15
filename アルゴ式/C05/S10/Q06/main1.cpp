// 解説AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool res = false;
    for (int i=0; i<1<<8; ++i) {
        vector<int> vec;
        vec.push_back(1);
        for (int j=0; j<8; ++j) {
            if (i&(1<<j)) vec.back() *= j + 2;
            else vec.push_back(j+2);
        }
        if (accumulate(vec.begin(), vec.end(), 0) == n) {
            res = true;
            break;
        }
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
