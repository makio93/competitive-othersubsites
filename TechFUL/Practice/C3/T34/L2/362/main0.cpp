// 自力AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int ra, ca, rb, cb;
    cin >> ra >> ca >> rb >> cb;
    vector<vector<int>> a(ra, vector<int>(ca)), b(rb, vector<int>(cb));
    for (int i=0; i<ra; ++i) for (int j=0; j<ca; ++j) cin >> a[i][j];
    for (int i=0; i<rb; ++i) for (int j=0; j<cb; ++j) cin >> b[i][j];
    if (ca != rb) {
        cout << "not defined!" << endl;
        return 0;
    }
    vector<vector<int>> res(ra, vector<int>(cb));
    for (int i=0; i<ra; ++i) for (int j=0; j<cb; ++j) for (int k=0; k<ca; ++k) res[i][j] += a[i][k] * b[k][j];
    for (int i=0; i<ra; ++i) for (int j=0; j<cb; ++j) cout << res[i][j] << (j<cb-1?' ':'\n');
    return 0;
}
