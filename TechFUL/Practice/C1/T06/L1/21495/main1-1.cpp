// 解説AC1

#include <iostream>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    while (n) {
        if (n%10 == 1) --res;
        if (n < 10) res += n;
        n /= 10;
    }
    cout << res << endl;
    return 0;
}
