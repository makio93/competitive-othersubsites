// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool res = false;
    for (int i=0; i<1<<8; ++i) {
        stack<int> st;
        st.push(1);
        for (int j=0; j<8; ++j) {
            if (i&(1<<j)) st.top() *= j + 2;
            else st.push(j+2);
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        if (sum == n) {
            res = true;
            break;
        }
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
