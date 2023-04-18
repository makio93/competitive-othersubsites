// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i=0; i<n-1; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    vector<vector<int>> children(n);
    vector<int> parent(n, -1), ccnt(n);
    queue<int> que;
    que.push(0);
    parent[0] = 0;
    while (!que.empty()) {
        int vi = que.front(); que.pop();
        for (const int& ti : g[vi]) if (ti != parent[vi]) {
            que.push(ti);
            children[vi].push_back(ti);
            ccnt[vi]++;
            parent[ti] = vi;
        }
    }
    int res = 0;
    vector<bool> covered(n);
    for (int i=0; i<n; ++i) if (ccnt[i] == 0) que.push(i);
    while (!que.empty()) {
        int vi = que.front(); que.pop();
        if (!covered[vi]) {
            covered[vi] = covered[parent[vi]] = true;
            ++res;
        }
        if (ccnt[parent[vi]] > 0) {
            ccnt[parent[vi]]--;
            if (ccnt[parent[vi]] == 0) que.push(parent[vi]);
        }
    }
    cout << res << endl;
	return 0;
}
