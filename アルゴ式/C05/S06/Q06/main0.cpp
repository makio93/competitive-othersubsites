// 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> f;
    for (int i=0; i<30; ++i) if ((n>>i)&1) f.push_back(i);
    int x = f.size();
    cout << x << endl;
    for (int i=0; i<x; ++i) cout << f[i] << (i<x-1?' ':'\n');
	return 0;
}
