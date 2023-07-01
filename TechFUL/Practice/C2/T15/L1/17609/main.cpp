// 

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << ((n == 0) ? n : (n - 1) % 9 + 1) << endl;
    return 0;
}
