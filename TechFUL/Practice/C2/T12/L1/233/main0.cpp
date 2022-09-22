// 自力AC

#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>
using namespace std;

const vector<int> ths = { 60, 70, 80, 90 };

int main() {
    int n;
    cin >> n;
    vector<int> m(n), s(n);
    for (int i=0; i<n; ++i) cin >> m[i] >> s[i];
    int gpt = 0;
    for (int i=0; i<n; ++i) {
        int bi = 0;
        for (int j=0; j<4; ++j) {
            if (ths[j] > s[i]) break;
            ++bi;
        }
        gpt += m[i] * bi;
    }
    int asum = accumulate(m.begin(), m.end(), 0), res = gpt * 100 / asum;
    printf("%d.%02d\n", res/100, res%100);
    return 0;
}
