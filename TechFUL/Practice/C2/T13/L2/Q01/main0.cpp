// 自力AC

#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string res;
    for (int i=n-1; i>=0; --i) {
        for (int j=1; i-j*3+1>=0; ++j) {
            if (s.substr(i-j+1, j) != s.substr(i-j*2+1, j)) continue;
            if (s.substr(i-j*2+1, j) == s.substr(i-j*3+1, j)) res = s.substr(i-j+1, j);
        }
    }
    if (!res.empty()) cout << res << endl;
    return 0;
}
